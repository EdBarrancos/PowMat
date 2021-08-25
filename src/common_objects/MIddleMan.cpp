// Standard Library Imports

// Third Party Imports

// Local Imports
#include "../../include/PowMat/MiddleMan.h"

//Namespaces
using namespace std;

MiddleMan::MiddleMan(){
    _mathFunctionFabric = new MathFunctionFabric();
}

CommonObject* MiddleMan::CalculateMathFunction(string name, vector<CommonObject*> arguments){
    vector<string>::iterator it;

    for(it = AdditivePersistence::c_names.begin(); it != AdditivePersistence::c_names.end(); it++ ){
        if (name.compare(*it) == 0){
            return _mathFunctionFabric->CreateAdditivePersistence((Integer*)arguments[0])->GetResult();
        }
    }

    for(it = MultiplicativePersistence::c_names.begin(); it != MultiplicativePersistence::c_names.end(); it++ ){
        if (name.compare(*it) == 0){
            return _mathFunctionFabric->CreateMultiplicativePersistence((Integer*)arguments[0])->GetResult();
        }
    }

    //TODO: Better way to hande, expecially arguments
    //TODO: Throw exceptions if wrong name
    //TODO: Throw exceptions if wrong args
    return 0;
}