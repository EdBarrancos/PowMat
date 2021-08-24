// Standard Library Imports

// Third Party Imports

// Local Imports
#include "../../include/PowMat/MathFunctionFabric.h"

//Namepspaces
using namespace std;

MathFunctionFabric::MathFunctionFabric(){}

MultiplicativePersistence* MathFunctionFabric::CreateMultiplicativePersistence(Integer* num){
    return new MultiplicativePersistence(num);
}

AdditivePersistence* MathFunctionFabric::CreateAdditivePersistence(Integer* num){
    return new AdditivePersistence(num);
}