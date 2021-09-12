// Standard Library Imports
#include <iostream>

// Third Party Imports

// Local Imports
#include "../../include/PowMat/MiddleMan.h"

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
            return new Error("ERROR(MiddleMan: Wrong Function Arguments");
        }
    }

    for(it = MultiplicativePersistence::s_names.begin(); it != MultiplicativePersistence::s_names.end(); it++ ){
        if (name.GetValue().compare(*it) == 0){
            if(this->CheckFunctionArguments(arguments, MultiplicativePersistence::s_GetNumberOfArguments())){
                return _mathFunctionFabric->CreateMultiplicativePersistence((Integer*)arguments[0])->GetResult();
            }
            return new Error("ERROR(MiddleMan: Wrong Function Arguments");
        }
    }

    return new Error("ERROR(MiddleMan): Function non Existent");

    //TODO: Better way to hande, expecially arguments
    //TODO: Not scalable
    return 0;
}

bool MiddleMan::CheckFunctionArguments(vector<CommonObject*> arguments, int numberArgs){
    if ((int)arguments.size() != numberArgs){ return false; }
    return true;
}