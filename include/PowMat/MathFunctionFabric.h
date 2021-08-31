#ifndef MATHFUNCTIONFABRIC
#define MATHFUNCTIONFABRIC

// Standard Library Imports

// Third Party Imports

// Local Imports
#include "./MathFunction.h"

//Namepspaces
using namespace std;

class MathFunctionFabric{
    public:
        MathFunctionFabric();
        MultiplicativePersistence* CreateMultiplicativePersistence(Integer* num);
        AdditivePersistence* CreateAdditivePersistence(Integer* num);
};

#endif