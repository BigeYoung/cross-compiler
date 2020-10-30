
#include "open62541.h"
#include "myUAModel.h"

#include <signal.h>
#include <stdlib.h>

static volatile UA_Boolean running = true;

static void stopHandler(int sig)
{
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "received ctrl-c");
    running = false;
}


static UA_StatusCode
exitExitMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId,void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_String *inputStr = (UA_String*)input->data;
    UA_String tmp = UA_STRING_ALLOC("exit ");
    if(inputStr->length > 0)
    {
        tmp.data = (UA_Byte *)UA_realloc(tmp.data, tmp.length + inputStr->length);
        memcpy(&tmp.data[tmp.length], inputStr->data, inputStr->length);
        tmp.length += inputStr->length;
    }
    UA_Variant_setScalarCopy(output, &tmp, &UA_TYPES[UA_TYPES_STRING]);
    UA_String_clear(&tmp);
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "exit was called");

    auto i = system("cp /etc/consul.d/services.json.backup /etc/consul.d/services.json");
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "copy service file" + i);
    
    Sleep(1000);

    auto i = system("consul services register /etc/consul.d/services.json");
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "consul service register" + i);

    Sleep(2000);

    running = false;

    return UA_STATUSCODE_GOOD;

}

static void
addExitMethod(UA_Server *server)
{

//    UA_Argument inputArgument;
//    UA_Argument_init(&inputArgument);
//    inputArgument.description = UA_LOCALIZEDTEXT("en-US", "A String");
//    inputArgument.name = UA_STRING("MyInput");
//    inputArgument.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
//    inputArgument.valueRank = UA_VALUERANK_SCALAR;

//    UA_Argument outputArgument;
//    UA_Argument_init(&outputArgument);
//    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "A String");
//    outputArgument.name = UA_STRING("MyOutput");
//    outputArgument.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
//    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes exitAttr = UA_MethodAttributes_default;
    exitAttr.description = UA_LOCALIZEDTEXT((char *)"en-US",(char *)"exit");
    exitAttr.displayName = UA_LOCALIZEDTEXT((char *)"en-US",(char *)"exit");
    exitAttr.executable = true;
    exitAttr.userExecutable = true;

    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62541),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, (char *)"exit"),
                            exitAttr, &exitExitMethodCallback,
                            0, NULL, 0, NULL, NULL, NULL);

}


int main(void)
{
    signal(SIGINT, stopHandler);
    signal(SIGTERM, stopHandler);

    UA_Server *server = UA_Server_new();
    UA_ServerConfig_setDefault(UA_Server_getConfig(server));

    UA_ServerConfig *config = UA_Server_getConfig(server);
    UA_ServerConfig_setMinimal(config, 4844, NULL);

    manuallyDefineCPPSProduct(server);

    addExitMethod(server);


    UA_StatusCode retval = UA_Server_run(server, &running);

    UA_Server_delete(server);
    return retval == UA_STATUSCODE_GOOD ? EXIT_SUCCESS : EXIT_FAILURE;
}
