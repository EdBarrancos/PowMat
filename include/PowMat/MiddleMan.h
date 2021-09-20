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

    private:
        bool CheckFunctionArguments(vector<CommonObject*> arguments, int numberOfArgs);
    public:
        MiddleMan();
        CommonObject* CalculateMathFunction(String name, vector<CommonObject*> arguments);
};

extern MiddleMan middleMan;
