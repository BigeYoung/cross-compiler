#ifndef MYUAMODEL_H
#define MYUAMODEL_H

#include <string>

#include "open62541.h"

using namespace std;

UA_StatusCode manuallyDefineCPPSProduct(UA_Server * server);

void manuallyDefineStudent(UA_Server * server);


#endif // MYUAMODEL_H
