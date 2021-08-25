// Standard Library Imports
#include <vector>

// Third Party Imports

// Local Imports
#include "../../include/PowMat/MathFunction.h"

//Namepspaces
using namespace std;

AdditivePersistence::AdditivePersistence(Integer* number){
    //TODO: Calculate Additive Persistence
    _result = new Integer(number->GetValue() + number->GetValue());
}

vector<string> AdditivePersistence::s_names = {"additive_persistence"};

CommonObject* AdditivePersistence::GetResult(){
    return _result;
}