// Standard Library Imports
#include <vector>

// Third Party Imports

// Local Imports
#include "../../include/PowMat/MathFunction.h"
#include "../../include/PowMat/MathFunctionFabric.h"
#include "../../include/PowMat/CommonObject.h"

//Namepspaces
using namespace std;

class MiddleMan{
    protected:
        MathFunctionFabric* _mathFunctionFabric;
    public:
        MiddleMan();
        CommonObject* CalculateMathFunction(string name, vector<CommonObject*> arguments);
};
