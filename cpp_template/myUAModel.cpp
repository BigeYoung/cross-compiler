
#include "myUAModel.h"


UA_StatusCode manuallyDefineCPPSProduct(UA_Server * server)
{
    UA_StatusCode retval_myNS = UA_STATUSCODE_GOOD;

    UA_UInt16 ns[4];
    ns[0] = UA_Server_addNamespace(server, "http://opcfoundation.org/UA/");
    ns[1] = UA_Server_addNamespace(server, "SCUT");
    ns[2] = UA_Server_addNamespace(server, "CPPS");
    ns[3] = UA_Server_addNamespace(server, "lzrhcj");

    /* 添加变量类型  AMLBasicVariableType  */
    UA_NodeId AMLBasicVariableType = UA_NODEID_NUMERIC(2, 3001);

    UA_VariableTypeAttributes AMLBasicVariableType_Attributes = UA_VariableTypeAttributes_default;
    AMLBasicVariableType_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"AMLBasicVariableType");

    // static UA_INLINE UA_THREADSAFE UA_StatusCode
    //
    // UA_Server_addVariableTypeNode(UA_Server *server,
    //                                  const UA_NodeId requestedNewNodeId,
    //                                  const UA_NodeId parentNodeId,
    //                                  const UA_NodeId referenceTypeId,
    //                                  const UA_QualifiedName browseName,
    //                                  const UA_NodeId typeDefinition,
    //                                  const UA_VariableTypeAttributes attr,
    //                                  void *nodeContext,
    //                                  UA_NodeId *outNewNodeId)

    UA_Server_addVariableTypeNode(server,
                                  AMLBasicVariableType,
                                  UA_NODEID_NUMERIC(0, UA_NS0ID_BASEVARIABLETYPE),
                                  UA_NODEID_NUMERIC(0, UA_NS0ID_HASSUBTYPE),
                                  UA_QUALIFIEDNAME(2, (char*)"AMLBasicVariableType"),
                                  UA_NODEID_NULL,
                                  AMLBasicVariableType_Attributes,
                                  NULL,
                                  NULL);


    /* 添加变量类型  AMLVariableType  */
    UA_NodeId AMLVariableType = UA_NODEID_NUMERIC(2, 3007);

    UA_VariableTypeAttributes AMLVariableType_Attributes = UA_VariableTypeAttributes_default;
    AMLVariableType_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"AMLVariableType");

    UA_Server_addVariableTypeNode(server,
                                  AMLVariableType,
                                  AMLBasicVariableType,
                                  UA_NODEID_NUMERIC(0, UA_NS0ID_HASSUBTYPE),
                                  UA_QUALIFIEDNAME(2, (char*)"AMLVariableType"),
                                  UA_NODEID_NULL,
                                  AMLVariableType_Attributes,
                                  NULL,
                                  NULL);


    /* 添加对象类型  CAEXBasicObjectType  */
    UA_NodeId CAEXBasicObjectType = UA_NODEID_NUMERIC(2, 1001);

    UA_ObjectTypeAttributes CAEXBasicObjectType_Attributes = UA_ObjectTypeAttributes_default;
    CAEXBasicObjectType_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"CAEXBasicObjectType");

    /*
    UA_Server_addObjectTypeNode(UA_Server *server,
        const UA_NodeId requestedNewNodeId,
        const UA_NodeId parentNodeId,
        const UA_NodeId referenceTypeId,
        const UA_QualifiedName browseName,
        const UA_ObjectTypeAttributes attr,
        void *nodeContext,
        UA_NodeId *outNewNodeId);
    */

    UA_Server_addObjectTypeNode(server,
                                CAEXBasicObjectType,
                                UA_NODEID_NUMERIC(0, UA_NS0ID_BASEOBJECTTYPE),
                                UA_NODEID_NUMERIC(0, UA_NS0ID_HASSUBTYPE),
                                UA_QUALIFIEDNAME(2, (char*)"CAEXBasicObjectType"),
                                CAEXBasicObjectType_Attributes,
                                NULL,
                                NULL);

    /* 添加对象类型  CAEXFileType  */
    UA_NodeId CAEXFileType = UA_NODEID_NUMERIC(2, 1002);

    UA_ObjectTypeAttributes CAEXFileType_Attributes = UA_ObjectTypeAttributes_default;
    CAEXFileType_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"CAEXFileType");

    /*
    UA_Server_addObjectTypeNode(UA_Server *server,
        const UA_NodeId requestedNewNodeId,
        const UA_NodeId parentNodeId,
        const UA_NodeId referenceTypeId,
        const UA_QualifiedName browseName,
        const UA_ObjectTypeAttributes attr,
        void *nodeContext,
        UA_NodeId *outNewNodeId);
    */

    UA_Server_addObjectTypeNode(server,
                                CAEXFileType,
                                CAEXBasicObjectType,
                                UA_NODEID_NUMERIC(0, UA_NS0ID_HASSUBTYPE),
                                UA_QUALIFIEDNAME(2, (char*)"CAEXFileType"),
                                CAEXFileType_Attributes,
                                NULL,
                                NULL);

    /* 添加对象类型  CAEXObjectType  */
    UA_NodeId CAEXObjectType = UA_NODEID_NUMERIC(2, 1003);

    UA_ObjectTypeAttributes CAEXObjectType_Attributes = UA_ObjectTypeAttributes_default;
    CAEXObjectType_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"CAEXObjectType");

    /*
    UA_Server_addObjectTypeNode(UA_Server *server,
        const UA_NodeId requestedNewNodeId,
        const UA_NodeId parentNodeId,
        const UA_NodeId referenceTypeId,
        const UA_QualifiedName browseName,
        const UA_ObjectTypeAttributes attr,
        void *nodeContext,
        UA_NodeId *outNewNodeId);
    */

    UA_Server_addObjectTypeNode(server,
                                CAEXObjectType,
                                CAEXBasicObjectType,
                                UA_NODEID_NUMERIC(0, UA_NS0ID_HASSUBTYPE),
                                UA_QUALIFIEDNAME(2, (char*)"CAEXObjectType"),
                                CAEXObjectType_Attributes,
                                NULL,
                                NULL);


    /* 添加对象类型  AMLAttributeType  */
    UA_NodeId AMLAttributeType = UA_NODEID_NUMERIC(2, 1008);

    UA_ObjectTypeAttributes AMLAttributeType_Attributes = UA_ObjectTypeAttributes_default;
    AMLAttributeType_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"AMLAttributeType");

    /*
    UA_Server_addObjectTypeNode(UA_Server *server,
        const UA_NodeId requestedNewNodeId,
        const UA_NodeId parentNodeId,
        const UA_NodeId referenceTypeId,
        const UA_QualifiedName browseName,
        const UA_ObjectTypeAttributes attr,
        void *nodeContext,
        UA_NodeId *outNewNodeId);
    */
    UA_Server_addObjectTypeNode(server,
                                AMLAttributeType,
                                CAEXObjectType,
                                UA_NODEID_NUMERIC(0, UA_NS0ID_HASSUBTYPE),
                                UA_QUALIFIEDNAME(2, (char*)"AMLAttributeType"),
                                AMLAttributeType_Attributes,
                                NULL,
                                NULL);


    /* 添加对象类型  AMLInternalElement  */
    UA_NodeId AMLInternalElement = UA_NODEID_NUMERIC(2, 1007);

    UA_ObjectTypeAttributes AMLInternalElement_Attributes = UA_ObjectTypeAttributes_default;
    AMLInternalElement_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"AMLInternalElement");

    /*
    UA_Server_addObjectTypeNode(UA_Server *server,
        const UA_NodeId requestedNewNodeId,
        const UA_NodeId parentNodeId,
        const UA_NodeId referenceTypeId,
        const UA_QualifiedName browseName,
        const UA_ObjectTypeAttributes attr,
        void *nodeContext,
        UA_NodeId *outNewNodeId);
    */
    UA_Server_addObjectTypeNode(server,
                                AMLInternalElement,
                                CAEXObjectType,
                                UA_NODEID_NUMERIC(0, UA_NS0ID_HASSUBTYPE),
                                UA_QUALIFIEDNAME(2, (char*)"AMLInternalElement"),
                                AMLInternalElement_Attributes,
                                NULL,
                                NULL);


    /* 添加对象类型  AMLSystemUnitClass  */
    UA_NodeId AMLSystemUnitClass = UA_NODEID_NUMERIC(2, 1006);

    UA_ObjectTypeAttributes AMLSystemUnitClass_Attributes = UA_ObjectTypeAttributes_default;
    AMLSystemUnitClass_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"AMLSystemUnitClass");

    /*
    UA_Server_addObjectTypeNode(UA_Server *server,
        const UA_NodeId requestedNewNodeId,
        const UA_NodeId parentNodeId,
        const UA_NodeId referenceTypeId,
        const UA_QualifiedName browseName,
        const UA_ObjectTypeAttributes attr,
        void *nodeContext,
        UA_NodeId *outNewNodeId);
    */
    UA_Server_addObjectTypeNode(server,
                                AMLSystemUnitClass,
                                CAEXObjectType,
                                UA_NODEID_NUMERIC(0, UA_NS0ID_HASSUBTYPE),
                                UA_QUALIFIEDNAME(2, (char*)"AMLSystemUnitClass"),
                                AMLSystemUnitClass_Attributes,
                                NULL,
                                NULL);

    /* 添加对象类型  ProductComponent  */
    UA_NodeId ProductComponent = UA_NODEID_STRING(3, (char*)"ProductComponent");

    UA_ObjectTypeAttributes ProductComponent_Attributes = UA_ObjectTypeAttributes_default;
    ProductComponent_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"ProductComponent");

    /*
    UA_Server_addObjectTypeNode(UA_Server *server,
        const UA_NodeId requestedNewNodeId,
        const UA_NodeId parentNodeId,
        const UA_NodeId referenceTypeId,
        const UA_QualifiedName browseName,
        const UA_ObjectTypeAttributes attr,
        void *nodeContext,
        UA_NodeId *outNewNodeId);
    */
    UA_Server_addObjectTypeNode(server,
                                ProductComponent,
                                AMLSystemUnitClass,
                                UA_NODEID_NUMERIC(0, UA_NS0ID_HASSUBTYPE),
                                UA_QUALIFIEDNAME(3, (char*)"ProductComponent"),
                                ProductComponent_Attributes,
                                NULL,
                                NULL);

    /* 添加对象类型  FinishedProduct  */
    UA_NodeId FinishedProduct = UA_NODEID_STRING(3, (char*)"FinishedProduct");

    UA_ObjectTypeAttributes FinishedProduct_Attributes = UA_ObjectTypeAttributes_default;
    FinishedProduct_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"FinishedProduct");
    /*
    UA_Server_addObjectTypeNode(UA_Server *server,
        const UA_NodeId requestedNewNodeId,
        const UA_NodeId parentNodeId,
        const UA_NodeId referenceTypeId,
        const UA_QualifiedName browseName,
        const UA_ObjectTypeAttributes attr,
        void *nodeContext,
        UA_NodeId *outNewNodeId);
    */
    UA_Server_addObjectTypeNode(server,
                                FinishedProduct,
                                ProductComponent,
                                UA_NODEID_NUMERIC(0, UA_NS0ID_HASSUBTYPE),
                                UA_QUALIFIEDNAME(3, (char*)"FinishedProduct"),
                                FinishedProduct_Attributes,
                                NULL,
                                NULL);

    /* 添加对象类型  Box___UDisk_OR_Wood__  */
    UA_NodeId Box___UDisk_OR_Wood___Type= UA_NODEID_STRING(3, (char*)"Box___UDisk_OR_Wood__");

    UA_ObjectTypeAttributes Box___UDisk_OR_Wood___Type_Attributes = UA_ObjectTypeAttributes_default;
    Box___UDisk_OR_Wood___Type_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"Box___UDisk_OR_Wood__");
    /*
    UA_Server_addObjectTypeNode(UA_Server *server,
        const UA_NodeId requestedNewNodeId,
        const UA_NodeId parentNodeId,
        const UA_NodeId referenceTypeId,
        const UA_QualifiedName browseName,
        const UA_ObjectTypeAttributes attr,
        void *nodeContext,
        UA_NodeId *outNewNodeId);
    */
    UA_Server_addObjectTypeNode(server,
                                Box___UDisk_OR_Wood___Type,
                                FinishedProduct,
                                UA_NODEID_NUMERIC(0, UA_NS0ID_HASSUBTYPE),
                                UA_QUALIFIEDNAME(3, (char*)"Box___UDisk_OR_Wood__"),
                                Box___UDisk_OR_Wood___Type_Attributes,
                                NULL,
                                NULL);

    /* 添加 AMLFiles 对象 */
    UA_NodeId AMLFiles = UA_NODEID_NUMERIC(2, 5001);

    UA_ObjectAttributes AMLFiles_Attributes = UA_ObjectAttributes_default;

    AMLFiles_Attributes.description = UA_LOCALIZEDTEXT((char*)"", (char*)"");
    AMLFiles_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"",  (char*)"AMLFiles");

    //
    //UA_Server_addObjectNode(UA_Server *server,
    //    const UA_NodeId requestedNewNodeId,
    //	const UA_NodeId parentNodeId,
    //	const UA_NodeId referenceTypeId,   //引用类型下面的类型
    //	const UA_QualifiedName browseName,
    //	const UA_NodeId typeDefinition,
    //	const UA_ObjectAttributes attr,
    //	void *nodeContext,
    //	UA_NodeId *outNewNodeId);
    //

    UA_Server_addObjectNode(server,
                            AMLFiles,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_ORGANIZES),
                            UA_QUALIFIEDNAME(2, (char*)"AMLFiles"),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_FOLDERTYPE),
                            AMLFiles_Attributes,
                            NULL,
                            NULL);

    /* 添加 amlprojname 对象 */
    UA_NodeId amlprojname = UA_NODEID_STRING(3, (char*)"product.aml" );

    UA_ObjectAttributes amlprojname_Attributes = UA_ObjectAttributes_default;

    amlprojname_Attributes.description = UA_LOCALIZEDTEXT((char*)"", (char*)"");
    amlprojname_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"amlprojname");

    //UA_Server_addObjectNode(UA_Server *server,
    //    const UA_NodeId requestedNewNodeId,
    //	const UA_NodeId parentNodeId,
    //	const UA_NodeId referenceTypeId,   //引用类型下面的类型
    //	const UA_QualifiedName browseName,
    //	const UA_NodeId typeDefinition,
    //	const UA_ObjectAttributes attr,
    //	void *nodeContext,
    //	UA_NodeId *outNewNodeId);

    UA_Server_addObjectNode(server,
                            amlprojname,
                            AMLFiles,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"amlprojname"),
                            CAEXFileType,
                            amlprojname_Attributes,
                            NULL,
                            NULL);

    /* 添加 InstanceHierarchies 对象 */
    UA_NodeId InstanceHierarchies = UA_NODEID_STRING(3, (char*)"product.aml@InstanceHierarchies");

    UA_ObjectAttributes InstanceHierarchies_Attributes = UA_ObjectAttributes_default;

    InstanceHierarchies_Attributes.description = UA_LOCALIZEDTEXT((char*)"", (char*)"InstanceHierarchies");
    InstanceHierarchies_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"InstanceHierarchies");

    UA_Server_addObjectNode(server,
                            InstanceHierarchies,
                            amlprojname,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"InstanceHierarchies"),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_FOLDERTYPE),
                            InstanceHierarchies_Attributes,
                            NULL,
                            NULL);

    /* 添加 AssetAdministrationShellInstanceHierarchy 对象 */
    UA_NodeId AssetAdministrationShellInstanceHierarchy = UA_NODEID_STRING(3, (char*)"AssetAdministrationShellInstanceHierarchy");

    UA_ObjectAttributes AssetAdministrationShellInstanceHierarchy_Attributes = UA_ObjectAttributes_default;

    AssetAdministrationShellInstanceHierarchy_Attributes.description = UA_LOCALIZEDTEXT((char*)"", (char*)"AssetAdministrationShellInstanceHierarchy");
    AssetAdministrationShellInstanceHierarchy_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"AssetAdministrationShellInstanceHierarchy");


    UA_Server_addObjectNode(server,
                            AssetAdministrationShellInstanceHierarchy,
                            InstanceHierarchies,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"AssetAdministrationShellInstanceHierarchy"),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_FOLDERTYPE),
                            AssetAdministrationShellInstanceHierarchy_Attributes,
                            NULL,
                            NULL);


    /* 添加 Product 对象 */
    UA_NodeId Product = UA_NODEID_STRING(3, (char*)"6e94c19a-92d5-4e67-8348-5a3edcb020cf");

    UA_ObjectAttributes Product_Attributes = UA_ObjectAttributes_default;

    Product_Attributes.description = UA_LOCALIZEDTEXT((char*)"", (char*)"");
    Product_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"Product");

    //
    //UA_Server_addObjectNode(UA_Server *server,
    //    const UA_NodeId requestedNewNodeId,
    //	const UA_NodeId parentNodeId,
    //	const UA_NodeId referenceTypeId,   //引用类型下面的类型
    //	const UA_QualifiedName browseName,
    //	const UA_NodeId typeDefinition,
    //	const UA_ObjectAttributes attr,
    //	void *nodeContext,
    //	UA_NodeId *outNewNodeId);

    UA_Server_addObjectNode(server,
                            Product,
                            AssetAdministrationShellInstanceHierarchy,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"Product"),
                            AMLInternalElement,
                            Product_Attributes,
                            NULL,
                            NULL);

    //这里除了问题
    /* 添加 Box___UDisk_OR_Wood__ 对象 */

    UA_NodeId Box___UDisk_OR_Wood___Object = UA_NODEID_STRING(3, (char*)"__PRODUCT_GUID__");

    UA_ObjectAttributes Box___UDisk_OR_Wood___Object_Attributes = UA_ObjectAttributes_default;

    Box___UDisk_OR_Wood___Object_Attributes.description = UA_LOCALIZEDTEXT((char*)"", (char*)"");
    Box___UDisk_OR_Wood___Object_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"Box___UDisk_OR_Wood__");

    //
    //UA_Server_addObjectNode(UA_Server *server,
    //    const UA_NodeId requestedNewNodeId,
    //	const UA_NodeId parentNodeId,
    //	const UA_NodeId referenceTypeId,   //引用类型下面的类型
    //	const UA_QualifiedName browseName,
    //	const UA_NodeId typeDefinition,
    //	const UA_ObjectAttributes attr,
    //	void *nodeContext,
    //	UA_NodeId *outNewNodeId);

    UA_Server_addObjectNode(server,
                            Box___UDisk_OR_Wood___Object,
                            Product,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"Box___UDisk_OR_Wood__"),
                            Box___UDisk_OR_Wood___Type,
                            Box___UDisk_OR_Wood___Object_Attributes,
                            NULL,
                            NULL);


    /* 添加 AAS 对象 */
    UA_NodeId AAS = UA_NODEID_STRING(3, (char*)"__PRODUCT_GUID__/AAS");

    UA_ObjectAttributes AAS_Attributes = UA_ObjectAttributes_default;

    AAS_Attributes.description = UA_LOCALIZEDTEXT((char*)"", (char*)"");
    AAS_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"AAS");

    //
    //UA_Server_addObjectNode(UA_Server *server,
    //    const UA_NodeId requestedNewNodeId,
    //	const UA_NodeId parentNodeId,
    //	const UA_NodeId referenceTypeId,   //引用类型下面的类型
    //	const UA_QualifiedName browseName,
    //	const UA_NodeId typeDefinition,
    //	const UA_ObjectAttributes attr,
    //	void *nodeContext,
    //	UA_NodeId *outNewNodeId);

    UA_Server_addObjectNode(server,
                            AAS,
                            Box___UDisk_OR_Wood___Object,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"AAS"),
                            AMLInternalElement,
                            AAS_Attributes,
                            NULL,
                            NULL);

    /* 添加 ProductFeature 对象 */

    UA_NodeId ProductFeature = UA_NODEID_STRING(3, (char*)"__PRODUCT_GUID__/AAS/ProductFeature");

    UA_ObjectAttributes ProductFeature_Attributes = UA_ObjectAttributes_default;

    ProductFeature_Attributes.description = UA_LOCALIZEDTEXT((char*)"", (char*)"");
    ProductFeature_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"ProductFeature");

    UA_Server_addObjectNode(server,
                            ProductFeature,
                            AAS,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"ProductFeature"),
                            AMLInternalElement,
                            ProductFeature_Attributes,
                            NULL,
                            NULL);


    /* 添加 Order_id 对象 */
    string Order_id_guid = "__PRODUCT_GUID__/AAS/Order_id";

    UA_NodeId Order_id = UA_NODEID_STRING(3, const_cast<char *>(Order_id_guid.c_str()));

    UA_ObjectAttributes Order_id_Attributes = UA_ObjectAttributes_default;

    Order_id_Attributes.description = UA_LOCALIZEDTEXT((char*)"", (char*)"");
    Order_id_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"Order_id");

    UA_Server_addObjectNode(server,
                            Order_id,
                            AAS,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"Order_id"),
                            AMLInternalElement,
                            Order_id_Attributes,
                            NULL,
                            NULL);

    /* 添加 Order_id_Value 对象 */
    UA_ObjectAttributes Value_Attributes = UA_ObjectAttributes_default;

    Value_Attributes.description = UA_LOCALIZEDTEXT((char*)"", (char*)"");
    Value_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"Value");


    std::string secondPart = ":value";

    /*   Order_id_Value 对象 */
    std::string temp_Order_id_Value = Order_id_guid + secondPart;
    //QByteArray whole_1 = temp_desc_1.toLatin1();
    char *value_Order_id_Value= const_cast<char *>(temp_Order_id_Value.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_Order_id_Value),
                            Order_id,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);


    /*   Order_id_Value_Value 变量  */

    std::string thirdPart = "@Value";

    /* 添加 Order_id_Value_Value 变量 */
    UA_VariableAttributes Order_id_Value_Value_Attr = UA_VariableAttributes_default;
    UA_String myString_Order_id_Value_Value = UA_STRING((char*)"__ORDER_ID__");

    UA_Variant_setScalar(&Order_id_Value_Value_Attr.value, &myString_Order_id_Value_Value, &UA_TYPES[UA_TYPES_STRING]);
    Order_id_Value_Value_Attr.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    Order_id_Value_Value_Attr.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    Order_id_Value_Value_Attr.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    Order_id_Value_Value_Attr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   Order_id_Value_Value  变量  */
    //std::string temp_5 = guid_FeatureDescription_5 + secondPart;
    //QByteArray whole_1 = temp_1.toLatin1();
    //char *value_5= const_cast<char *>(temp_5.c_str());

    std::string temp_Order_id_Value_Value = Order_id_guid + secondPart + thirdPart;
    //QByteArray whole_value_1 = temp_value_1.toLatin1();
    char *Order_id_Value_Value_var = const_cast<char *>(temp_Order_id_Value_Value.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, Order_id_Value_Value_var),
                              UA_NODEID_STRING(3, value_Order_id_Value),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              Order_id_Value_Value_Attr,
                              NULL,
                              NULL);


    /* 添加 Actual_Arrival_Time 对象 */
    string Actual_Arrival_Time_guid = "__PRODUCT_GUID__/AAS/Actual_Arrival_Time";

    UA_NodeId Actual_Arrival_Time = UA_NODEID_STRING(3, const_cast<char *>(Actual_Arrival_Time_guid.c_str()));

    UA_ObjectAttributes Actual_Arrival_Time_Attributes = UA_ObjectAttributes_default;

    Actual_Arrival_Time_Attributes.description = UA_LOCALIZEDTEXT((char*)"", (char*)"");
    Actual_Arrival_Time_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"Actual_Arrival_Time");

    UA_Server_addObjectNode(server,
                            Actual_Arrival_Time,
                            AAS,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"Actual_Arrival_Time"),
                            AMLInternalElement,
                            Actual_Arrival_Time_Attributes,
                            NULL,
                            NULL);


    /*   Actual_Arrival_Time_Value 对象 */
    std::string temp_Actual_Arrival_Time_Value = Actual_Arrival_Time_guid + secondPart;
    //QByteArray whole_1 = temp_desc_1.toLatin1();
    char *value_Actual_Arrival_Time_Value= const_cast<char *>(temp_Actual_Arrival_Time_Value.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_Actual_Arrival_Time_Value),
                            Actual_Arrival_Time,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);



    /* 添加 Actual_Arrival_Time_Value_Value 变量 */
    UA_VariableAttributes Actual_Arrival_Time_Value_Value_Attr = UA_VariableAttributes_default;
    UA_String myString_Actual_Arrival_Time_Value_Value = UA_STRING((char*)"");

    UA_Variant_setScalar(&Order_id_Value_Value_Attr.value, &myString_Actual_Arrival_Time_Value_Value, &UA_TYPES[UA_TYPES_STRING]);
    Order_id_Value_Value_Attr.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    Order_id_Value_Value_Attr.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    Order_id_Value_Value_Attr.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    Order_id_Value_Value_Attr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   Actual_Arrival_Time_Value_Value  变量  */
    //std::string temp_5 = guid_FeatureDescription_5 + secondPart;
    //QByteArray whole_1 = temp_1.toLatin1();
    //char *value_5= const_cast<char *>(temp_5.c_str());

    std::string temp_Actual_Arrival_Time_Value_Value = Actual_Arrival_Time_guid + secondPart + thirdPart;
    //QByteArray whole_value_1 = temp_value_1.toLatin1();
    char *Actual_Arrival_Time_Value_Value_var = const_cast<char *>(temp_Actual_Arrival_Time_Value_Value.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, Actual_Arrival_Time_Value_Value_var),
                              UA_NODEID_STRING(3, value_Actual_Arrival_Time_Value),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              Actual_Arrival_Time_Value_Value_Attr,
                              NULL,
                              NULL);


    /* 添加 Actual_Departure_Time 对象 */

    string Actual_Departure_Time_guid = "__PRODUCT_GUID__/AAS/Actual_Departure_Time";

    UA_NodeId Actual_Departure_Time = UA_NODEID_STRING(3, const_cast<char *>(Actual_Departure_Time_guid.c_str()));

    UA_ObjectAttributes Actual_Departure_Time_Attributes = UA_ObjectAttributes_default;

    Actual_Departure_Time_Attributes.description = UA_LOCALIZEDTEXT((char*)"", (char*)"");
    Actual_Departure_Time_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"Actual_Departure_Time");

    UA_Server_addObjectNode(server,
                            Actual_Departure_Time,
                            AAS,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"Actual_Arrival_Time"),
                            AMLInternalElement,
                            Actual_Departure_Time_Attributes,
                            NULL,
                            NULL);


    /*   Actual_Departure_Time_Value 对象 */
    std::string temp_Actual_Departure_Time_Value = Actual_Departure_Time_guid + secondPart;
    //QByteArray whole_1 = temp_desc_1.toLatin1();
    char *value_Actual_Departure_Time_Value= const_cast<char *>(temp_Actual_Departure_Time_Value.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_Actual_Departure_Time_Value),
                            Actual_Departure_Time,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);




    /* 添加 Actual_Departure_Time_Value_Value 变量 */
    UA_VariableAttributes Actual_Departure_Time_Value_Value_Attr = UA_VariableAttributes_default;
    UA_String myString_Actual_Departure_Time_Value_Value = UA_STRING((char*)"");

    UA_Variant_setScalar(&Order_id_Value_Value_Attr.value, &myString_Actual_Departure_Time_Value_Value, &UA_TYPES[UA_TYPES_STRING]);
    Actual_Departure_Time_Value_Value_Attr.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    Actual_Departure_Time_Value_Value_Attr.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    Actual_Departure_Time_Value_Value_Attr.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    Actual_Departure_Time_Value_Value_Attr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   Actual_Departure_Time_Value_Value  变量  */
    //std::string temp_5 = guid_FeatureDescription_5 + secondPart;
    //QByteArray whole_1 = temp_1.toLatin1();
    //char *value_5= const_cast<char *>(temp_5.c_str());

    std::string temp_Actual_Departure_Time_Value_Value = Actual_Departure_Time_guid + secondPart + thirdPart;
    //QByteArray whole_value_1 = temp_value_1.toLatin1();
    char *Actual_Departure_Time_Value_Value_var = const_cast<char *>(temp_Actual_Departure_Time_Value_Value.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, Actual_Departure_Time_Value_Value_var),
                              UA_NODEID_STRING(3, value_Actual_Departure_Time_Value),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              Actual_Departure_Time_Value_Value_Attr,
                              NULL,
                              NULL);



    /* 添加 Processing_Time 对象 */
    string Processing_Time_guid = "__PRODUCT_GUID__/AAS/Processing_Time";

    UA_NodeId Processing_Time = UA_NODEID_STRING(3, const_cast<char *>(Processing_Time_guid.c_str()));

    UA_ObjectAttributes Processing_Time_Attributes = UA_ObjectAttributes_default;

    Processing_Time_Attributes.description = UA_LOCALIZEDTEXT((char*)"", (char*)"");
    Processing_Time_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"Processing_Time");

    UA_Server_addObjectNode(server,
                            Processing_Time,
                            AAS,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"Processing_Time"),
                            AMLInternalElement,
                            Processing_Time_Attributes,
                            NULL,
                            NULL);

    /*   Processing_Time_Value 对象 */
    std::string temp_Processing_Time_Value = Processing_Time_guid + secondPart;
    //QByteArray whole_1 = temp_desc_1.toLatin1();
    char *value_Processing_Time_Value= const_cast<char *>(temp_Processing_Time_Value.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_Processing_Time_Value),
                            Processing_Time,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);



    /* 添加 Processing_Time_Value_Value 变量 */
    UA_VariableAttributes Processing_Time_Value_Value_Attr = UA_VariableAttributes_default;
    UA_String myString_Processing_Time_Value_Value = UA_STRING((char*)"");

    UA_Variant_setScalar(&Order_id_Value_Value_Attr.value, &myString_Processing_Time_Value_Value, &UA_TYPES[UA_TYPES_STRING]);
    Processing_Time_Value_Value_Attr.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    Processing_Time_Value_Value_Attr.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    Processing_Time_Value_Value_Attr.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    Processing_Time_Value_Value_Attr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   Processing_Time_Value_Value  变量  */
    //std::string temp_5 = guid_FeatureDescription_5 + secondPart;
    //QByteArray whole_1 = temp_1.toLatin1();
    //char *value_5= const_cast<char *>(temp_5.c_str());

    std::string temp_Processing_Time_Value_Value = Processing_Time_guid + secondPart + thirdPart;
    //QByteArray whole_value_1 = temp_value_1.toLatin1();
    char *Processing_Time_Value_Value_var = const_cast<char *>(temp_Processing_Time_Value_Value.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, Processing_Time_Value_Value_var),
                              UA_NODEID_STRING(3, value_Processing_Time_Value),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              Processing_Time_Value_Value_Attr,
                              NULL,
                              NULL);




    /* 添加 Feature_1 对象 */

    char *guid_Feature_1 = (char *)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_1";

    UA_NodeId Feature_1 = UA_NODEID_STRING(3, guid_Feature_1);

    UA_ObjectAttributes Feature_1_Attributes = UA_ObjectAttributes_default;

    Feature_1_Attributes.description = UA_LOCALIZEDTEXT((char*)"", (char*)"");
    Feature_1_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"Feature_1");

    //
    //UA_Server_addObjectNode(UA_Server *server,
    //    const UA_NodeId requestedNewNodeId,
    //	const UA_NodeId parentNodeId,
    //	const UA_NodeId referenceTypeId,   //引用类型下面的类型
    //	const UA_QualifiedName browseName,
    //	const UA_NodeId typeDefinition,
    //	const UA_ObjectAttributes attr,
    //	void *nodeContext,
    //	UA_NodeId *outNewNodeId);

    UA_Server_addObjectNode(server,
                            Feature_1,
                            ProductFeature,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"Feature_1"),
                            AMLInternalElement,
                            Feature_1_Attributes,
                            NULL,
                            NULL);

    /* 添加 Feature_2 对象 */

    char *guid_Feature_2 = (char *)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_2";

    UA_NodeId Feature_2 = UA_NODEID_STRING(3, guid_Feature_2);

    UA_ObjectAttributes Feature_2_Attributes = UA_ObjectAttributes_default;

    Feature_2_Attributes.description = UA_LOCALIZEDTEXT((char*)"", (char*)"");
    Feature_2_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"Feature_2");

    //
    //UA_Server_addObjectNode(UA_Server *server,
    //    const UA_NodeId requestedNewNodeId,
    //	const UA_NodeId parentNodeId,
    //	const UA_NodeId referenceTypeId,   //引用类型下面的类型
    //	const UA_QualifiedName browseName,
    //	const UA_NodeId typeDefinition,
    //	const UA_ObjectAttributes attr,
    //	void *nodeContext,
    //	UA_NodeId *outNewNodeId);

    UA_Server_addObjectNode(server,
                            Feature_2,
                            ProductFeature,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"Feature_2"),
                            AMLInternalElement,
                            Feature_2_Attributes,
                            NULL,
                            NULL);

    /* 添加 Feature_3 对象 */
    char *guid_Feature_3 = (char *)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_3";

    UA_NodeId Feature_3 = UA_NODEID_STRING(3, guid_Feature_3);

    UA_ObjectAttributes Feature_3_Attributes = UA_ObjectAttributes_default;

    Feature_3_Attributes.description = UA_LOCALIZEDTEXT((char*)"", (char*)"");
    Feature_3_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"Feature_3");

    //
    //UA_Server_addObjectNode(UA_Server *server,
    //    const UA_NodeId requestedNewNodeId,
    //	const UA_NodeId parentNodeId,
    //	const UA_NodeId referenceTypeId,   //引用类型下面的类型
    //	const UA_QualifiedName browseName,
    //	const UA_NodeId typeDefinition,
    //	const UA_ObjectAttributes attr,
    //	void *nodeContext,
    //	UA_NodeId *outNewNodeId);

    UA_Server_addObjectNode(server,
                            Feature_3,
                            ProductFeature,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"Feature_3"),
                            AMLInternalElement,
                            Feature_3_Attributes,
                            NULL,
                            NULL);

    /* 添加 Feature_4 对象 */

    char *guid_Feature_4 = (char *)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_4";

    UA_NodeId Feature_4 = UA_NODEID_STRING(3, guid_Feature_4);

    UA_ObjectAttributes Feature_4_Attributes = UA_ObjectAttributes_default;

    Feature_4_Attributes.description = UA_LOCALIZEDTEXT((char*)"", (char*)"");
    Feature_4_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"Feature_4");

    //
    //UA_Server_addObjectNode(UA_Server *server,
    //    const UA_NodeId requestedNewNodeId,
    //	const UA_NodeId parentNodeId,
    //	const UA_NodeId referenceTypeId,   //引用类型下面的类型
    //	const UA_QualifiedName browseName,
    //	const UA_NodeId typeDefinition,
    //	const UA_ObjectAttributes attr,
    //	void *nodeContext,
    //	UA_NodeId *outNewNodeId);

    UA_Server_addObjectNode(server,
                            Feature_4,
                            ProductFeature,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"Feature_4"),
                            AMLInternalElement,
                            Feature_4_Attributes,
                            NULL,
                            NULL);

    /* 添加 Feature_5 对象 */
    char *guid_Feature_5 = (char *)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_5";

    UA_NodeId Feature_5 = UA_NODEID_STRING(3, guid_Feature_5);

    UA_ObjectAttributes Feature_5_Attributes = UA_ObjectAttributes_default;

    Feature_5_Attributes.description = UA_LOCALIZEDTEXT((char*)"", (char*)"");
    Feature_5_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"Feature_5");

    //
    //UA_Server_addObjectNode(UA_Server *server,
    //    const UA_NodeId requestedNewNodeId,
    //	const UA_NodeId parentNodeId,
    //	const UA_NodeId referenceTypeId,   //引用类型下面的类型
    //	const UA_QualifiedName browseName,
    //	const UA_NodeId typeDefinition,
    //	const UA_ObjectAttributes attr,
    //	void *nodeContext,
    //	UA_NodeId *outNewNodeId);

    UA_Server_addObjectNode(server,
                            Feature_5,
                            ProductFeature,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"Feature_5"),
                            AMLInternalElement,
                            Feature_5_Attributes,
                            NULL,
                            NULL);

    /* 添加 Feature_6 对象 */
    char *guid_Feature_6 = (char *)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_6";

    UA_NodeId Feature_6 = UA_NODEID_STRING(3, guid_Feature_6);

    UA_ObjectAttributes Feature_6_Attributes = UA_ObjectAttributes_default;

    Feature_6_Attributes.description = UA_LOCALIZEDTEXT((char*)"", (char*)"");
    Feature_6_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"Feature_6");

    //
    //UA_Server_addObjectNode(UA_Server *server,
    //    const UA_NodeId requestedNewNodeId,
    //	const UA_NodeId parentNodeId,
    //	const UA_NodeId referenceTypeId,   //引用类型下面的类型
    //	const UA_QualifiedName browseName,
    //	const UA_NodeId typeDefinition,
    //	const UA_ObjectAttributes attr,
    //	void *nodeContext,
    //	UA_NodeId *outNewNodeId);

    UA_Server_addObjectNode(server,
                            Feature_6,
                            ProductFeature,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"Feature_6"),
                            AMLInternalElement,
                            Feature_6_Attributes,
                            NULL,
                            NULL);


    /* 添加 FeatureDescription 对象 */
    UA_ObjectAttributes FeatureDescription_Attributes = UA_ObjectAttributes_default;

    FeatureDescription_Attributes.description = UA_LOCALIZEDTEXT((char*)"", (char*)"");
    FeatureDescription_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"FeatureDescription");

    /*   Feature1的  */
    char *guid_FeatureDescription_1 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_1/FeatureDescription";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_FeatureDescription_1),
                            Feature_1,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureDescription"),
                            AMLInternalElement,
                            FeatureDescription_Attributes,
                            NULL,
                            NULL);

    /*   Feature2的  */
    char *guid_FeatureDescription_2 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_2/FeatureDescription";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_FeatureDescription_2),
                            Feature_2,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureDescription"),
                            AMLInternalElement,
                            FeatureDescription_Attributes,
                            NULL,
                            NULL);

    /*   Feature3的  */
    char *guid_FeatureDescription_3 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_3/FeatureDescription";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_FeatureDescription_3),
                            Feature_3,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureDescription"),
                            AMLInternalElement,
                            FeatureDescription_Attributes,
                            NULL,
                            NULL);

    /*   Feature4的  */
    char *guid_FeatureDescription_4 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_4/FeatureDescription";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_FeatureDescription_4),
                            Feature_4,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureDescription"),
                            AMLInternalElement,
                            FeatureDescription_Attributes,
                            NULL,
                            NULL);

    /*   Feature5的  */
    char *guid_FeatureDescription_5 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_5/FeatureDescription";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_FeatureDescription_5),
                            Feature_5,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureDescription"),
                            AMLInternalElement,
                            FeatureDescription_Attributes,
                            NULL,
                            NULL);

    /*   Feature6的  */
    char *guid_FeatureDescription_6 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_6/FeatureDescription";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_FeatureDescription_6),
                            Feature_6,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureDescription"),
                            AMLInternalElement,
                            FeatureDescription_Attributes,
                            NULL,
                            NULL);



    /* 添加 FeatureStarttime 对象 */
    UA_ObjectAttributes Start_time_Attributes = UA_ObjectAttributes_default;

    Start_time_Attributes.description = UA_LOCALIZEDTEXT((char*)"", (char*)"");
    Start_time_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"Start time");

    /*   Feature1的  */
    char *guid_Start_time_1 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_1/Start_time";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_Start_time_1),
                            Feature_1,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureDescription"),
                            AMLInternalElement,
                            Start_time_Attributes,
                            NULL,
                            NULL);

    /*   Feature2的  */
    char *guid_Start_time_2 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_2/Start_time";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_Start_time_2),
                            Feature_2,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureDescription"),
                            AMLInternalElement,
                            Start_time_Attributes,
                            NULL,
                            NULL);


    /*   Feature3的  */
    char *guid_Start_time_3 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_3/Start_time";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_Start_time_3),
                            Feature_3,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureDescription"),
                            AMLInternalElement,
                            Start_time_Attributes,
                            NULL,
                            NULL);


    /*   Feature4的  */
    char *guid_Start_time_4 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_4/Start_time";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_Start_time_4),
                            Feature_4,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureDescription"),
                            AMLInternalElement,
                            Start_time_Attributes,
                            NULL,
                            NULL);


    /*   Feature5的  */
    char *guid_Start_time_5 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_5/Start_time";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_Start_time_5),
                            Feature_5,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureDescription"),
                            AMLInternalElement,
                            Start_time_Attributes,
                            NULL,
                            NULL);


    /*   Feature6的  */
    char *guid_Start_time_6 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_6/Start_time";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_Start_time_6),
                            Feature_6,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureDescription"),
                            AMLInternalElement,
                            Start_time_Attributes,
                            NULL,
                            NULL);





    /* 添加 FeatureEnd_time 对象 */
    UA_ObjectAttributes End_time_Attributes = UA_ObjectAttributes_default;

    End_time_Attributes.description = UA_LOCALIZEDTEXT((char*)"", (char*)"");
    End_time_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"End time");

    /*   Feature1的  */
    char *guid_End_time_1 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_1/End_time";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_End_time_1),
                            Feature_1,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureDescription"),
                            AMLInternalElement,
                            End_time_Attributes,
                            NULL,
                            NULL);

    /*   Feature2的  */
    char *guid_End_time_2 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_2/End_time";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_End_time_2),
                            Feature_2,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureDescription"),
                            AMLInternalElement,
                            End_time_Attributes,
                            NULL,
                            NULL);


    /*   Feature3的  */
    char *guid_End_time_3 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_3/End_time";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_End_time_3),
                            Feature_3,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureDescription"),
                            AMLInternalElement,
                            End_time_Attributes,
                            NULL,
                            NULL);


    /*   Feature4的  */
    char *guid_End_time_4 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_4/End_time";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_End_time_4),
                            Feature_4,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureDescription"),
                            AMLInternalElement,
                            End_time_Attributes,
                            NULL,
                            NULL);


    /*   Feature5的  */
    char *guid_End_time_5 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_5/End_time";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_End_time_5),
                            Feature_5,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureDescription"),
                            AMLInternalElement,
                            End_time_Attributes,
                            NULL,
                            NULL);


    /*   Feature6的  */
    char *guid_End_time_6 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_6/End_time";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_End_time_6),
                            Feature_6,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureDescription"),
                            AMLInternalElement,
                            End_time_Attributes,
                            NULL,
                            NULL);






    /* 添加 FeatureParameter 对象 */
    UA_ObjectAttributes FeatureParameter_Attributes = UA_ObjectAttributes_default;

    FeatureParameter_Attributes.description = UA_LOCALIZEDTEXT((char*)"", (char*)"");
    FeatureParameter_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"FeatureParameter");

    /*   Feature1的  */
    char *guid_FeatureParameter_1 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_1/FeatureParameter";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_FeatureParameter_1),
                            Feature_1,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureParameter"),
                            AMLInternalElement,
                            FeatureParameter_Attributes,
                            NULL,
                            NULL);

    /*   Feature2的  */
    char *guid_FeatureParameter_2 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_2/FeatureParameter";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_FeatureParameter_2),
                            Feature_2,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureParameter"),
                            AMLInternalElement,
                            FeatureParameter_Attributes,
                            NULL,
                            NULL);

    /*   Feature3的  */
    char *guid_FeatureParameter_3 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_3/FeatureParameter";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_FeatureParameter_3),
                            Feature_3,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureParameter"),
                            AMLInternalElement,
                            FeatureParameter_Attributes,
                            NULL,
                            NULL);

    /*   Feature4的  */
    char *guid_FeatureParameter_4 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_4/FeatureParameter";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_FeatureParameter_4),
                            Feature_4,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureParameter"),
                            AMLInternalElement,
                            FeatureParameter_Attributes,
                            NULL,
                            NULL);

    /*   Feature5的  */
    char *guid_FeatureParameter_5 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_5/FeatureParameter";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_FeatureParameter_5),
                            Feature_5,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureParameter"),
                            AMLInternalElement,
                            FeatureParameter_Attributes,
                            NULL,
                            NULL);

    /*   Feature6的  */
    char *guid_FeatureParameter_6 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_6/FeatureParameter";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_FeatureParameter_6),
                            Feature_6,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureParameter"),
                            AMLInternalElement,
                            FeatureParameter_Attributes,
                            NULL,
                            NULL);



    /* 添加 FeatureStatus 对象 */
    UA_ObjectAttributes FeatureStatus_Attributes = UA_ObjectAttributes_default;

    FeatureStatus_Attributes.description = UA_LOCALIZEDTEXT((char*)"", (char*)"");
    FeatureStatus_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"FeatureStatus");

    /*   Feature1的  */
    char *guid_FeatureStatus_1 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_1/FeatureStatus";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_FeatureStatus_1),
                            Feature_1,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureStatus"),
                            AMLInternalElement,
                            FeatureStatus_Attributes,
                            NULL,
                            NULL);

    /*   Feature2的  */
    char *guid_FeatureStatus_2 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_2/FeatureStatus";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_FeatureStatus_2),
                            Feature_2,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureStatus"),
                            AMLInternalElement,
                            FeatureStatus_Attributes,
                            NULL,
                            NULL);

    /*   Feature3的  */
    char *guid_FeatureStatus_3 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_3/FeatureStatus";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_FeatureStatus_3),
                            Feature_3,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureStatus"),
                            AMLInternalElement,
                            FeatureStatus_Attributes,
                            NULL,
                            NULL);

    /*   Feature4的  */
    char *guid_FeatureStatus_4 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_4/FeatureStatus";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_FeatureStatus_4),
                            Feature_4,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureStatus"),
                            AMLInternalElement,
                            FeatureStatus_Attributes,
                            NULL,
                            NULL);

    /*   Feature5的  */
    char *guid_FeatureStatus_5 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_5/FeatureStatus";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_FeatureStatus_5),
                            Feature_5,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureStatus"),
                            AMLInternalElement,
                            FeatureStatus_Attributes,
                            NULL,
                            NULL);

    /*   Feature6的  */
    char *guid_FeatureStatus_6 = (char*)"__PRODUCT_GUID__/AAS/ProductFeature/Feature_6/FeatureStatus";

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, guid_FeatureStatus_6),
                            Feature_6,
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"FeatureStatus"),
                            AMLInternalElement,
                            FeatureStatus_Attributes,
                            NULL,
                            NULL);




    /* 添加 Value 对象 */
//    UA_ObjectAttributes Value_Attributes = UA_ObjectAttributes_default;

//    Value_Attributes.description = UA_LOCALIZEDTEXT((char*)"", (char*)"");
//    Value_Attributes.displayName = UA_LOCALIZEDTEXT((char*)"", (char*)"Value");


//    std::string secondPart = ":value";

    /*   Feature Description 的Value对象  */

    /*   Feature1的Value  */

    std::string temp_desc_1 = guid_FeatureDescription_1 + secondPart;
    //QByteArray whole_1 = temp_desc_1.toLatin1();
    char *value_desc_1= const_cast<char *>(temp_desc_1.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_desc_1),
                            UA_NODEID_STRING(3, guid_FeatureDescription_1),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);

    /*   Feature2的Value  */
    std::string temp_desc_2 = guid_FeatureDescription_2 + secondPart;
    //QByteArray whole_1 = temp_desc_1.toLatin1();
    char *value_desc_2= const_cast<char *>(temp_desc_2.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_desc_2),
                            UA_NODEID_STRING(3, guid_FeatureDescription_2),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);

    /*   Feature3的Value  */
    std::string temp_desc_3 = guid_FeatureDescription_3 + secondPart;
    //QByteArray whole_1 = temp_desc_1.toLatin1();
    char *value_desc_3= const_cast<char *>(temp_desc_3.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_desc_3),
                            UA_NODEID_STRING(3, guid_FeatureDescription_3),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);

    /*   Feature4的Value  */
    std::string temp_desc_4 = guid_FeatureDescription_4 + secondPart;
    //QByteArray whole_1 = temp_desc_1.toLatin1();
    char *value_desc_4= const_cast<char *>(temp_desc_4.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_desc_4),
                            UA_NODEID_STRING(3, guid_FeatureDescription_4),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);

    /*   Feature5的Value  */
    std::string temp_desc_5 = guid_FeatureDescription_5 + secondPart;
    //QByteArray whole_1 = temp_desc_1.toLatin1();
    char *value_desc_5= const_cast<char *>(temp_desc_5.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_desc_5),
                            UA_NODEID_STRING(3, guid_FeatureDescription_5),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);

    /*   Feature6的Value  */
    std::string temp_desc_6 = guid_FeatureDescription_6 + secondPart;
    //QByteArray whole_1 = temp_desc_1.toLatin1();
    char *value_desc_6= const_cast<char *>(temp_desc_6.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_desc_6),
                            UA_NODEID_STRING(3, guid_FeatureDescription_6),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);


    /* 添加 Value 对象 */


    /*   Feature1的Value  */

    std::string temp_parm_1 = guid_FeatureParameter_1 + secondPart;
    //QByteArray whole_1 = temp_parm_1.toLatin1();
    char *value_parm_1= const_cast<char *>(temp_parm_1.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_parm_1),
                            UA_NODEID_STRING(3, guid_FeatureParameter_1),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value_parm"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);

    /*   Feature2的value_parm  */
    std::string temp_parm_2 = guid_FeatureParameter_2 + secondPart;
    //QByteArray whole_1 = temp_parm_1.toLatin1();
    char *value_parm_2= const_cast<char *>(temp_parm_2.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_parm_2),
                            UA_NODEID_STRING(3, guid_FeatureParameter_2),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value_parm"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);

    /*   Feature3的value_parm  */
    std::string temp_parm_3 = guid_FeatureParameter_3 + secondPart;
    //QByteArray whole_1 = temp_parm_1.toLatin1();
    char *value_parm_3= const_cast<char *>(temp_parm_3.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_parm_3),
                            UA_NODEID_STRING(3, guid_FeatureParameter_3),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value_parm"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);

    /*   Feature4的value_parm  */
    std::string temp_parm_4 = guid_FeatureParameter_4 + secondPart;
    //QByteArray whole_1 = temp_parm_1.toLatin1();
    char *value_parm_4= const_cast<char *>(temp_parm_4.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_parm_4),
                            UA_NODEID_STRING(3, guid_FeatureParameter_4),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value_parm"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);

    /*   Feature5的value_parm  */
    std::string temp_parm_5 = guid_FeatureParameter_5 + secondPart;
    //QByteArray whole_1 = temp_parm_1.toLatin1();
    char *value_parm_5= const_cast<char *>(temp_parm_5.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_parm_5),
                            UA_NODEID_STRING(3, guid_FeatureParameter_5),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value_parm"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);

    /*   Feature6的value_parm  */
    std::string temp_parm_6 = guid_FeatureParameter_6 + secondPart;
    //QByteArray whole_1 = temp_parm_1.toLatin1();
    char *value_parm_6= const_cast<char *>(temp_parm_6.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_parm_6),
                            UA_NODEID_STRING(3, guid_FeatureParameter_6),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value_parm"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);


    /*  -------------      */

    std::string temp_status_1 = guid_FeatureStatus_1 + secondPart;
    //QByteArray whole_1 = temp_status_1.toLatin1();
    char *value_status_1= const_cast<char *>(temp_status_1.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_status_1),
                            UA_NODEID_STRING(3, guid_FeatureStatus_1),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value_status"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);

    /*   Feature2的value_status  */
    std::string temp_status_2 = guid_FeatureStatus_2 + secondPart;
    //QByteArray whole_1 = temp_status_1.toLatin1();
    char *value_status_2= const_cast<char *>(temp_status_2.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_status_2),
                            UA_NODEID_STRING(3, guid_FeatureStatus_2),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value_status"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);

    /*   Feature3的value_status  */
    std::string temp_status_3 = guid_FeatureStatus_3 + secondPart;
    //QByteArray whole_1 = temp_status_1.toLatin1();
    char *value_status_3= const_cast<char *>(temp_status_3.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_status_3),
                            UA_NODEID_STRING(3, guid_FeatureStatus_3),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value_status"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);

    /*   Feature4的value_status  */
    std::string temp_status_4 = guid_FeatureStatus_4 + secondPart;
    //QByteArray whole_1 = temp_status_1.toLatin1();
    char *value_status_4= const_cast<char *>(temp_status_4.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_status_4),
                            UA_NODEID_STRING(3, guid_FeatureStatus_4),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value_status"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);

    /*   Feature5的value_status  */
    std::string temp_status_5 = guid_FeatureStatus_5 + secondPart;
    //QByteArray whole_1 = temp_status_1.toLatin1();
    char *value_status_5= const_cast<char *>(temp_status_5.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_status_5),
                            UA_NODEID_STRING(3, guid_FeatureStatus_5),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value_status"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);

    /*   Feature6的value_status  */
    std::string temp_status_6 = guid_FeatureStatus_6 + secondPart;
    //QByteArray whole_1 = temp_status_1.toLatin1();
    char *value_status_6= const_cast<char *>(temp_status_6.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_status_6),
                            UA_NODEID_STRING(3, guid_FeatureStatus_6),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value_status"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);


    ////////

    /*   Feature Start_time 的Value对象  */

    /*   Feature1的Value  */

    std::string temp_Start_time_1 = guid_Start_time_1 + secondPart;
    //QByteArray whole_1 = temp_Start_time_1.toLatin1();
    char *value_Start_time_1= const_cast<char *>(temp_Start_time_1.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_Start_time_1),
                            UA_NODEID_STRING(3, guid_Start_time_1),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);

    /*   Feature2的Value  */
    std::string temp_Start_time_2 = guid_Start_time_2 + secondPart;
    //QByteArray whole_1 = temp_Start_time_1.toLatin1();
    char *value_Start_time_2= const_cast<char *>(temp_Start_time_2.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_Start_time_2),
                            UA_NODEID_STRING(3, guid_Start_time_2),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);

    /*   Feature3的Value  */
    std::string temp_Start_time_3 = guid_Start_time_3 + secondPart;
    //QByteArray whole_1 = temp_Start_time_1.toLatin1();
    char *value_Start_time_3= const_cast<char *>(temp_Start_time_3.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_Start_time_3),
                            UA_NODEID_STRING(3, guid_Start_time_3),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);

    /*   Feature4的Value  */
    std::string temp_Start_time_4 = guid_Start_time_4 + secondPart;
    //QByteArray whole_1 = temp_Start_time_1.toLatin1();
    char *value_Start_time_4= const_cast<char *>(temp_Start_time_4.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_Start_time_4),
                            UA_NODEID_STRING(3, guid_Start_time_4),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);

    /*   Feature5的Value  */
    std::string temp_Start_time_5 = guid_Start_time_5 + secondPart;
    //QByteArray whole_1 = temp_Start_time_1.toLatin1();
    char *value_Start_time_5= const_cast<char *>(temp_Start_time_5.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_Start_time_5),
                            UA_NODEID_STRING(3, guid_Start_time_5),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);

    /*   Feature6的Value  */
    std::string temp_Start_time_6 = guid_Start_time_6 + secondPart;
    //QByteArray whole_1 = temp_Start_time_1.toLatin1();
    char *value_Start_time_6= const_cast<char *>(temp_Start_time_6.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_Start_time_6),
                            UA_NODEID_STRING(3, guid_Start_time_6),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);


    //////

    /*   Feature End_time 的Value对象  */

    /*   Feature1的Value  */

    std::string temp_End_time_1 = guid_End_time_1 + secondPart;
    //QByteArray whole_1 = temp_End_time_1.toLatin1();
    char *value_End_time_1= const_cast<char *>(temp_End_time_1.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_End_time_1),
                            UA_NODEID_STRING(3, guid_End_time_1),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);

    /*   Feature2的Value  */
    std::string temp_End_time_2 = guid_End_time_2 + secondPart;
    //QByteArray whole_1 = temp_End_time_1.toLatin1();
    char *value_End_time_2= const_cast<char *>(temp_End_time_2.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_End_time_2),
                            UA_NODEID_STRING(3, guid_End_time_2),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);

    /*   Feature3的Value  */
    std::string temp_End_time_3 = guid_End_time_3 + secondPart;
    //QByteArray whole_1 = temp_End_time_1.toLatin1();
    char *value_End_time_3= const_cast<char *>(temp_End_time_3.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_End_time_3),
                            UA_NODEID_STRING(3, guid_End_time_3),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);

    /*   Feature4的Value  */
    std::string temp_End_time_4 = guid_End_time_4 + secondPart;
    //QByteArray whole_1 = temp_End_time_1.toLatin1();
    char *value_End_time_4= const_cast<char *>(temp_End_time_4.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_End_time_4),
                            UA_NODEID_STRING(3, guid_End_time_4),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);

    /*   Feature5的Value  */
    std::string temp_End_time_5 = guid_End_time_5 + secondPart;
    //QByteArray whole_1 = temp_End_time_1.toLatin1();
    char *value_End_time_5= const_cast<char *>(temp_End_time_5.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_End_time_5),
                            UA_NODEID_STRING(3, guid_End_time_5),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);

    /*   Feature6的Value  */
    std::string temp_End_time_6 = guid_End_time_6 + secondPart;
    //QByteArray whole_1 = temp_End_time_1.toLatin1();
    char *value_End_time_6= const_cast<char *>(temp_End_time_6.c_str());

    UA_Server_addObjectNode(server,
                            UA_NODEID_STRING(3, value_End_time_6),
                            UA_NODEID_STRING(3, guid_End_time_6),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(3, (char*)"value"),
                            AMLAttributeType,
                            Value_Attributes,
                            NULL,
                            NULL);



    /////


    /* ----------------------------------- */

    //std::string thirdPart = "@Value";

    /* 添加 Value_1 变量 */
    UA_VariableAttributes valueAttr_1 = UA_VariableAttributes_default;
    UA_String myString_desc_1 = UA_STRING((char*)"Box,Upper,Pallet");

    UA_Variant_setScalar(&valueAttr_1.value, &myString_desc_1, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_1.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_1.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_1.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_1.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   Value_1变量  */
    //std::string temp_5 = guid_FeatureDescription_5 + secondPart;
    //QByteArray whole_1 = temp_1.toLatin1();
    //char *value_5= const_cast<char *>(temp_5.c_str());

    std::string temp_value_1 =guid_FeatureDescription_1 + secondPart + thirdPart;
    //QByteArray whole_value_1 = temp_value_1.toLatin1();
    char *value_var_1 = const_cast<char *>(temp_value_1.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_var_1),
                              UA_NODEID_STRING(3, value_desc_1),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_1,
                              NULL,
                              NULL);

    /* 添加 Value_2 变量 */
    UA_VariableAttributes valueAttr_2 = UA_VariableAttributes_default;
    UA_String myString_desc_2 = UA_STRING((char*)"__UDisk_OR_Wood__,Upper,Pallet");

    UA_Variant_setScalar(&valueAttr_2.value, &myString_desc_2, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_2.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_2.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_2.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_2.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   Value_2变量  */
    std::string temp_value_2 =guid_FeatureDescription_2 + secondPart + thirdPart;
    //QByteArray whole_value_1 = temp_value_1.toLatin1();
    char *value_var_2 = const_cast<char *>(temp_value_2.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_var_2),
                              UA_NODEID_STRING(3, value_desc_2),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_2,
                              NULL,
                              NULL);

    /* 添加 Value_3 变量 */
    UA_VariableAttributes valueAttr_3 = UA_VariableAttributes_default;
    UA_String myString_desc_3 = UA_STRING((char*)"__Lasering_OR_Carving__,Picture,__UDisk_OR_Wood__");

    UA_Variant_setScalar(&valueAttr_3.value, &myString_desc_3, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_3.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_3.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_3.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_3.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   Value_3变量  */
    std::string temp_value_3 =guid_FeatureDescription_3 + secondPart + thirdPart;
    //QByteArray whole_value_1 = temp_value_1.toLatin1();
    char *value_var_3 = const_cast<char *>(temp_value_3.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_var_3),
                              UA_NODEID_STRING(3, value_desc_3),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_3,
                              NULL,
                              NULL);

    /* 添加 Value_4 变量 */
    UA_VariableAttributes valueAttr_4 = UA_VariableAttributes_default;
    UA_String myString_desc_4 = UA_STRING((char*)"__UDisk_OR_Wood__,Inside,Box");

    UA_Variant_setScalar(&valueAttr_4.value, &myString_desc_4, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_4.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_4.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_4.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_4.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   Value_4变量  */
    std::string temp_value_4 =guid_FeatureDescription_4 + secondPart + thirdPart;
    //QByteArray whole_value_1 = temp_value_1.toLatin1();
    char *value_var_4 = const_cast<char *>(temp_value_4.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_var_4),
                              UA_NODEID_STRING(3, value_desc_4),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_4,
                              NULL,
                              NULL);


    /* 添加 Value_5 变量 */
    UA_VariableAttributes valueAttr_5 = UA_VariableAttributes_default;
    UA_String myString_desc_5 = UA_STRING((char*)"Cover,Upper,Box");

    UA_Variant_setScalar(&valueAttr_5.value, &myString_desc_5, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_5.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_5.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_5.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_5.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   Value_5变量  */
    std::string temp_value_5 =guid_FeatureDescription_5 + secondPart + thirdPart;
    //QByteArray whole_value_1 = temp_value_1.toLatin1();
    char *value_var_5 = const_cast<char *>(temp_value_5.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_var_5),
                              UA_NODEID_STRING(3, value_desc_5),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_5,
                              NULL,
                              NULL);


    /* 添加 Value_6 变量 */
    UA_VariableAttributes valueAttr_6 = UA_VariableAttributes_default;
    UA_String myString_desc_6 = UA_STRING((char*)"Box,Under,Pallet");

    UA_Variant_setScalar(&valueAttr_6.value, &myString_desc_6, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_6.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_6.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_6.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_6.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   Value_6变量  */
    std::string temp_value_6 =guid_FeatureDescription_6 + secondPart + thirdPart;
    //QByteArray whole_value_1 = temp_value_1.toLatin1();
    char *value_var_6 = const_cast<char *>(temp_value_6.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_var_6),
                              UA_NODEID_STRING(3, value_desc_6),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_6,
                              NULL,
                              NULL);



    /* 添加 Value_1 变量 */

    UA_String myString_parm_1 = UA_STRING((char*)"__FEATURE_1__");

    UA_Variant_setScalar(&valueAttr_1.value, &myString_parm_1, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_1.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_1.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_1.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_1.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    std::string temp_value_parm1 =guid_FeatureParameter_1 + secondPart + thirdPart;
    //QByteArray whole_value_parm1 = temp_value_parm1.toLatin1();
    char *value_parmvar_1 = const_cast<char *>(temp_value_parm1.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_parmvar_1),
                              UA_NODEID_STRING(3, value_parm_1),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_1,
                              NULL,
                              NULL);

    /* 添加 value_parm2 变量 */

    UA_String myString_parm_2 = UA_STRING((char*)"");

    UA_Variant_setScalar(&valueAttr_2.value, &myString_parm_2, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_2.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_2.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_2.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_2.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   value_parm2变量  */
    std::string temp_value_parm2 =guid_FeatureParameter_2 + secondPart + thirdPart;
    //QByteArray whole_value_parm1 = temp_value_parm1.toLatin1();
    char *value_parmvar_2 = const_cast<char *>(temp_value_parm2.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_parmvar_2),
                              UA_NODEID_STRING(3, value_parm_2),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_2,
                              NULL,
                              NULL);

    /* 添加 value_parm3 变量 */

    UA_String myString_parm_3 = UA_STRING((char*)"__FEATURE_3__");

    UA_Variant_setScalar(&valueAttr_3.value, &myString_parm_3, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_3.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_3.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_3.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_3.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   value_parm3变量  */
    std::string temp_value_parm3 =guid_FeatureParameter_3 + secondPart + thirdPart;
    //QByteArray whole_value_parm1 = temp_value_parm1.toLatin1();
    char *value_parmvar_3 = const_cast<char *>(temp_value_parm3.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_parmvar_3),
                              UA_NODEID_STRING(3, value_parm_3),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_3,
                              NULL,
                              NULL);

    /* 添加 value_parm4 变量 */

    UA_String myString_parm_4 = UA_STRING((char*)"");

    UA_Variant_setScalar(&valueAttr_4.value, &myString_parm_4, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_4.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_4.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_4.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_4.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   value_parm4变量  */
    std::string temp_value_parm4 =guid_FeatureParameter_4 + secondPart + thirdPart;
    //QByteArray whole_value_parm1 = temp_value_parm1.toLatin1();
    char *value_parmvar_4 = const_cast<char *>(temp_value_parm4.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_parmvar_4),
                              UA_NODEID_STRING(3, value_parm_4),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_4,
                              NULL,
                              NULL);


    /* 添加 value_parm5 变量 */

    UA_String myString_parm_5 = UA_STRING((char*)"__FEATURE_5__");

    UA_Variant_setScalar(&valueAttr_5.value, &myString_parm_5, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_5.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_5.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_5.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_5.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   value_parm5变量  */
    std::string temp_value_parm5 =guid_FeatureParameter_5 + secondPart + thirdPart;
    //QByteArray whole_value_parm1 = temp_value_parm1.toLatin1();
    char *value_parmvar_5 = const_cast<char *>(temp_value_parm5.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_parmvar_5),
                              UA_NODEID_STRING(3, value_parm_5),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_5,
                              NULL,
                              NULL);


    /* 添加 value_parm6 变量 */

    UA_String myString_parm_6 = UA_STRING((char*)"");

    UA_Variant_setScalar(&valueAttr_6.value, &myString_parm_6, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_6.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_6.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_6.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_6.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   value_parm6变量  */
    std::string temp_value_parm6 = guid_FeatureParameter_6 + secondPart + thirdPart;
    //QByteArray whole_value_parm1 = temp_value_parm1.toLatin1();
    char *value_parmvar_6 = const_cast<char *>(temp_value_parm6.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_parmvar_6),
                              UA_NODEID_STRING(3, value_parm_6),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_6,
                              NULL,
                              NULL);



    /*----------------------------*/
    /* 添加 Value_1 变量 */

    UA_String myString_status_1 = UA_STRING((char*)"");

    UA_Variant_setScalar(&valueAttr_1.value, &myString_status_1, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_1.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_1.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_1.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_1.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    std::string temp_value_status1 =guid_FeatureStatus_1 + secondPart + thirdPart;
    //QByteArray whole_value_status1 = temp_value_status1.toLatin1();
    char *value_statusvar_1 = const_cast<char *>(temp_value_status1.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_statusvar_1),
                              UA_NODEID_STRING(3, value_status_1),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_1,
                              NULL,
                              NULL);

    /* 添加 value_status2 变量 */

    UA_String myString_status_2 = UA_STRING((char*)"");

    UA_Variant_setScalar(&valueAttr_2.value, &myString_status_2, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_2.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_2.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_2.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_2.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   value_status2变量  */
    std::string temp_value_status2 =guid_FeatureStatus_2 + secondPart + thirdPart;
    //QByteArray whole_value_status1 = temp_value_status1.toLatin1();
    char *value_statusvar_2 = const_cast<char *>(temp_value_status2.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_statusvar_2),
                              UA_NODEID_STRING(3, value_status_2),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_2,
                              NULL,
                              NULL);

    /* 添加 value_status3 变量 */

    UA_String myString_status_3 = UA_STRING((char*)"");

    UA_Variant_setScalar(&valueAttr_3.value, &myString_status_3, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_3.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_3.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_3.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_3.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   value_status3变量  */
    std::string temp_value_status3 =guid_FeatureStatus_3 + secondPart + thirdPart;
    //QByteArray whole_value_status1 = temp_value_status1.toLatin1();
    char *value_statusvar_3 = const_cast<char *>(temp_value_status3.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_statusvar_3),
                              UA_NODEID_STRING(3, value_status_3),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_3,
                              NULL,
                              NULL);

    /* 添加 value_status4 变量 */

    UA_String myString_status_4 = UA_STRING((char*)"");

    UA_Variant_setScalar(&valueAttr_4.value, &myString_status_4, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_4.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_4.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_4.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_4.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   value_status4变量  */
    std::string temp_value_status4 =guid_FeatureStatus_4 + secondPart + thirdPart;
    //QByteArray whole_value_status1 = temp_value_status1.toLatin1();
    char *value_statusvar_4 = const_cast<char *>(temp_value_status4.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_statusvar_4),
                              UA_NODEID_STRING(3, value_status_4),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_4,
                              NULL,
                              NULL);


    /* 添加 value_status5 变量 */

    UA_String myString_status_5 = UA_STRING((char*)"");

    UA_Variant_setScalar(&valueAttr_5.value, &myString_status_5, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_5.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_5.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_5.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_5.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   value_status5变量  */
    std::string temp_value_status5 =guid_FeatureStatus_5 + secondPart + thirdPart;
    //QByteArray whole_value_status1 = temp_value_status1.toLatin1();
    char *value_statusvar_5 = const_cast<char *>(temp_value_status5.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_statusvar_5),
                              UA_NODEID_STRING(3, value_status_5),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_5,
                              NULL,
                              NULL);


    /* 添加 value_status6 变量 */

    UA_String myString_status_6 = UA_STRING((char*)"");

    UA_Variant_setScalar(&valueAttr_6.value, &myString_status_6, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_6.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_6.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_6.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_6.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   value_status6变量  */
    std::string temp_value_status6 = guid_FeatureStatus_6 + secondPart + thirdPart;
    //QByteArray whole_value_status1 = temp_value_status1.toLatin1();
    char *value_statusvar_6 = const_cast<char *>(temp_value_status6.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_statusvar_6),
                              UA_NODEID_STRING(3, value_status_6),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_6,
                              NULL,
                              NULL);



    ////////////

    /*----------------------------*/
    /* 添加 Value_1 变量 */

    UA_String myString_Start_time_1 = UA_STRING((char*)"");

    UA_Variant_setScalar(&valueAttr_1.value, &myString_Start_time_1, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_1.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_1.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_1.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_1.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    std::string temp_value_Start_time1 =guid_Start_time_1 + secondPart + thirdPart;
    //QByteArray whole_value_Start_time1 = temp_value_Start_time1.toLatin1();
    char *value_Start_timevar_1 = const_cast<char *>(temp_value_Start_time1.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_Start_timevar_1),
                              UA_NODEID_STRING(3, value_Start_time_1),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_1,
                              NULL,
                              NULL);

    /* 添加 value_Start_time2 变量 */

    UA_String myString_Start_time_2 = UA_STRING((char*)"");

    UA_Variant_setScalar(&valueAttr_2.value, &myString_Start_time_2, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_2.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_2.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_2.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_2.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   value_Start_time2变量  */
    std::string temp_value_Start_time2 =guid_Start_time_2 + secondPart + thirdPart;
    //QByteArray whole_value_Start_time1 = temp_value_Start_time1.toLatin1();
    char *value_Start_timevar_2 = const_cast<char *>(temp_value_Start_time2.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_Start_timevar_2),
                              UA_NODEID_STRING(3, value_Start_time_2),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_2,
                              NULL,
                              NULL);

    /* 添加 value_Start_time3 变量 */

    UA_String myString_Start_time_3 = UA_STRING((char*)"");

    UA_Variant_setScalar(&valueAttr_3.value, &myString_Start_time_3, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_3.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_3.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_3.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_3.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   value_Start_time3变量  */
    std::string temp_value_Start_time3 =guid_Start_time_3 + secondPart + thirdPart;
    //QByteArray whole_value_Start_time1 = temp_value_Start_time1.toLatin1();
    char *value_Start_timevar_3 = const_cast<char *>(temp_value_Start_time3.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_Start_timevar_3),
                              UA_NODEID_STRING(3, value_Start_time_3),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_3,
                              NULL,
                              NULL);

    /* 添加 value_Start_time4 变量 */

    UA_String myString_Start_time_4 = UA_STRING((char*)"");

    UA_Variant_setScalar(&valueAttr_4.value, &myString_Start_time_4, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_4.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_4.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_4.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_4.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   value_Start_time4变量  */
    std::string temp_value_Start_time4 =guid_Start_time_4 + secondPart + thirdPart;
    //QByteArray whole_value_Start_time1 = temp_value_Start_time1.toLatin1();
    char *value_Start_timevar_4 = const_cast<char *>(temp_value_Start_time4.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_Start_timevar_4),
                              UA_NODEID_STRING(3, value_Start_time_4),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_4,
                              NULL,
                              NULL);


    /* 添加 value_Start_time5 变量 */

    UA_String myString_Start_time_5 = UA_STRING((char*)"");

    UA_Variant_setScalar(&valueAttr_5.value, &myString_Start_time_5, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_5.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_5.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_5.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_5.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   value_Start_time5变量  */
    std::string temp_value_Start_time5 =guid_Start_time_5 + secondPart + thirdPart;
    //QByteArray whole_value_Start_time1 = temp_value_Start_time1.toLatin1();
    char *value_Start_timevar_5 = const_cast<char *>(temp_value_Start_time5.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_Start_timevar_5),
                              UA_NODEID_STRING(3, value_Start_time_5),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_5,
                              NULL,
                              NULL);


    /* 添加 value_Start_time6 变量 */

    UA_String myString_Start_time_6 = UA_STRING((char*)"");

    UA_Variant_setScalar(&valueAttr_6.value, &myString_Start_time_6, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_6.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_6.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_6.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_6.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   value_Start_time6变量  */
    std::string temp_value_Start_time6 = guid_Start_time_6 + secondPart + thirdPart;
    //QByteArray whole_value_Start_time1 = temp_value_Start_time1.toLatin1();
    char *value_Start_timevar_6 = const_cast<char *>(temp_value_Start_time6.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_Start_timevar_6),
                              UA_NODEID_STRING(3, value_Start_time_6),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_6,
                              NULL,
                              NULL);

    /*----------------------------*/
    /* 添加 Value_1 变量 */

    UA_String myString_End_time_1 = UA_STRING((char*)"");

    UA_Variant_setScalar(&valueAttr_1.value, &myString_End_time_1, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_1.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_1.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_1.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_1.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    std::string temp_value_End_time1 =guid_End_time_1 + secondPart + thirdPart;
    //QByteArray whole_value_End_time1 = temp_value_End_time1.toLatin1();
    char *value_End_timevar_1 = const_cast<char *>(temp_value_End_time1.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_End_timevar_1),
                              UA_NODEID_STRING(3, value_End_time_1),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_1,
                              NULL,
                              NULL);

    /* 添加 value_End_time2 变量 */

    UA_String myString_End_time_2 = UA_STRING((char*)"");

    UA_Variant_setScalar(&valueAttr_2.value, &myString_End_time_2, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_2.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_2.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_2.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_2.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   value_End_time2变量  */
    std::string temp_value_End_time2 =guid_End_time_2 + secondPart + thirdPart;
    //QByteArray whole_value_End_time1 = temp_value_End_time1.toLatin1();
    char *value_End_timevar_2 = const_cast<char *>(temp_value_End_time2.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_End_timevar_2),
                              UA_NODEID_STRING(3, value_End_time_2),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_2,
                              NULL,
                              NULL);

    /* 添加 value_End_time3 变量 */

    UA_String myString_End_time_3 = UA_STRING((char*)"");

    UA_Variant_setScalar(&valueAttr_3.value, &myString_End_time_3, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_3.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_3.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_3.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_3.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   value_End_time3变量  */
    std::string temp_value_End_time3 =guid_End_time_3 + secondPart + thirdPart;
    //QByteArray whole_value_End_time1 = temp_value_End_time1.toLatin1();
    char *value_End_timevar_3 = const_cast<char *>(temp_value_End_time3.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_End_timevar_3),
                              UA_NODEID_STRING(3, value_End_time_3),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_3,
                              NULL,
                              NULL);

    /* 添加 value_End_time4 变量 */

    UA_String myString_End_time_4 = UA_STRING((char*)"");

    UA_Variant_setScalar(&valueAttr_4.value, &myString_End_time_4, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_4.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_4.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_4.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_4.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   value_End_time4变量  */
    std::string temp_value_End_time4 =guid_End_time_4 + secondPart + thirdPart;
    //QByteArray whole_value_End_time1 = temp_value_End_time1.toLatin1();
    char *value_End_timevar_4 = const_cast<char *>(temp_value_End_time4.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_End_timevar_4),
                              UA_NODEID_STRING(3, value_End_time_4),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_4,
                              NULL,
                              NULL);


    /* 添加 value_End_time5 变量 */

    UA_String myString_End_time_5 = UA_STRING((char*)"");

    UA_Variant_setScalar(&valueAttr_5.value, &myString_End_time_5, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_5.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_5.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_5.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_5.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   value_End_time5变量  */
    std::string temp_value_End_time5 =guid_End_time_5 + secondPart + thirdPart;
    //QByteArray whole_value_End_time1 = temp_value_End_time1.toLatin1();
    char *value_End_timevar_5 = const_cast<char *>(temp_value_End_time5.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_End_timevar_5),
                              UA_NODEID_STRING(3, value_End_time_5),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_5,
                              NULL,
                              NULL);


    /* 添加 value_End_time6 变量 */

    UA_String myString_End_time_6 = UA_STRING((char*)"");

    UA_Variant_setScalar(&valueAttr_6.value, &myString_End_time_6, &UA_TYPES[UA_TYPES_STRING]);
    valueAttr_6.description = UA_LOCALIZEDTEXT((char*)"",(char*)"");
    valueAttr_6.displayName = UA_LOCALIZEDTEXT((char*)"",(char*)"Value");
    valueAttr_6.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    valueAttr_6.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;


    /*   value_End_time6变量  */
    std::string temp_value_End_time6 = guid_End_time_6 + secondPart + thirdPart;
    //QByteArray whole_value_End_time1 = temp_value_End_time1.toLatin1();
    char *value_End_timevar_6 = const_cast<char *>(temp_value_End_time6.c_str());

    UA_Server_addVariableNode(server,
                              UA_NODEID_STRING(3, value_End_timevar_6),
                              UA_NODEID_STRING(3, value_End_time_6),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                              UA_QUALIFIEDNAME(3, (char*)"Value"),
                              AMLVariableType,
                              valueAttr_6,
                              NULL,
                              NULL);



    ////////////


    return retval_myNS;
}
