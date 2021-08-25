// Standard Library Imports
#include <vector>

// Third Party Imports

// Local Imports
#include "../../include/PowMat/MathFunction.h"

//Namepspaces
using namespace std;

MultiplicativePersistence::MultiplicativePersistence(Integer* number){
    //TODO: Calculate MultiplicativePersistance
    string names[] = {"mutiplicative_persistence"};
    _result = new Integer(number->GetValue() * number->GetValue());
}

vector<string> MultiplicativePersistence::c_names = {"multiplicative_persistence"};

CommonObject* MultiplicativePersistence::GetResult(){
    return _result;
}