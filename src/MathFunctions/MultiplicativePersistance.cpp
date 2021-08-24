// Standard Library Imports

// Third Party Imports

// Local Imports
#include "../../include/PowMat/MathFunction.h"

//Namepspaces
using namespace std;

MultiplicativePersistance::MultiplicativePersistance(CommonObject* number){
    //TODO: Calculate MultiplicativePersistance
    _result = number;
}

CommonObject* MultiplicativePersistance::GetResult(){
    return _result;
}