// Standard Library Imports
#include <vector>

// Third Party Imports

// Local Imports
#include "../../include/PowMat/MathFunction.h"

//Namepspaces
using namespace std;

AdditivePersistence::AdditivePersistence(Integer* number){
    //TODO: Calculate Additive Persistence
    string names[] = {"additive_persistence"};
    _result = new Integer(number->GetValue() + number->GetValue());
}

vector<string> AdditivePersistence::c_names = {"additive_persistence"};

CommonObject* AdditivePersistence::GetResult(){
    return _result;
}