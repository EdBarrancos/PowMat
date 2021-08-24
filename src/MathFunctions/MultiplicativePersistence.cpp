// Standard Library Imports

// Third Party Imports

// Local Imports
#include "../../include/PowMat/MathFunction.h"

//Namepspaces
using namespace std;

MultiplicativePersistence::MultiplicativePersistence(Integer* number){
    //TODO: Calculate MultiplicativePersistance
    string names[] = {"mutiplicative_persistence"};
    _result = number;
}

CommonObject* MultiplicativePersistence::GetResult(){
    return _result;
}