// Standard Library Imports

// Third Party Imports

// Local Imports
#include "../../include/PowMat/MathFunction.h"

//Namepspaces
using namespace std;

AdditivePersistance::AdditivePersistance(CommonObject* number){
    //TODO: Calculate Additive Persistence
    _result = number;
}

CommonObject* AdditivePersistance::GetResult(){
    return _result;
}