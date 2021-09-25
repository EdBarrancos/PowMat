// Standard Library Imports
#include <iostream>

// Third Party Imports

// Local Imports
#include "../../include/PowMat/MiddleMan.h"
#include "../../include/PowMat/ErrorHandler.h"

//Namespaces
using namespace std;

MiddleMan middleMan;

MiddleMan::MiddleMan(){
    _mathFunctionFabric = new MathFunctionFabric();
}

CommonObject* MiddleMan::CalculateMathFunction(String name, vector<CommonObject*> arguments){
    vector<string>::iterator it;

    for(it = AdditivePersistence::s_names.begin(); it != AdditivePersistence::s_names.end(); it++ ){
        if (name.GetValue().compare(*it) == 0){
            if(this->CheckFunctionArguments(arguments, AdditivePersistence::s_GetNumberOfArguments())){
                return _mathFunctionFabric->CreateAdditivePersistence((Integer*)arguments[0])->GetResult();
            }
            error.QueueError(new Error("(MiddleMan) Wrong Function Arguments", ERROR));
            return NULL;
        }
    }

    for(it = MultiplicativePersistence::s_names.begin(); it != MultiplicativePersistence::s_names.end(); it++ ){
        if (name.GetValue().compare(*it) == 0){
            if(this->CheckFunctionArguments(arguments, MultiplicativePersistence::s_GetNumberOfArguments())){
                return _mathFunctionFabric->CreateMultiplicativePersistence((Integer*)arguments[0])->GetResult();
            }
            error.QueueError(new Error("(MiddleMan) Wrong Function Arguments", ERROR));
            return NULL;
        }
    }

    error.QueueError(new Error("(MiddleMan) Function non Existent", ERROR));
    return NULL;

    //TODO: Better way to hande, expecially arguments
    //TODO: Not scalable
    return 0;
}

bool MiddleMan::CheckFunctionArguments(vector<CommonObject*> arguments, int numberArgs){
    if ((int)arguments.size() != numberArgs){ return false; }
    return true;
}