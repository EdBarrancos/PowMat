//Standard Library Imports

//Third Party Imports

//Local Imports
#include "../../include/PowMat/Debug.h"

//Namespaces
using namespace std;

Debug debuger;

Debug::Debug(){
    pathToDebugFile = "debug/debug";
    debugFile.open(pathToDebugFile);
}

void Debug::Log(string message, bool newLine){
    debugFile << message;
    if(newLine){
        debugFile << "\n";
    }
}

