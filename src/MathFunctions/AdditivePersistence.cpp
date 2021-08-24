// Standard Library Imports

// Third Party Imports

// Local Imports
#include "../../include/PowMat/MathFunction.h"

//Namepspaces
using namespace std;

AdditivePersistence::AdditivePersistence(Integer* number){
    //TODO: Calculate Additive Persistence
    string names[] = {"additive_persistence"};
    _result = number;
}

CommonObject* AdditivePersistence::GetResult(){
    return _result;
}