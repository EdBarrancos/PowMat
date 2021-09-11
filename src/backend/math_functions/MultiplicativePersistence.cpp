// Standard Library Imports
#include <vector>
#include <iostream>

// Third Party Imports

// Local Imports
#include "../../../include/PowMat/MathFunction.h"

//Namepspaces
using namespace std;

MultiplicativePersistence::MultiplicativePersistence(Integer* number){
    if(typeid(number) != typeid(Integer*)){
        _result = new Error("ERROR(MultiplicativePersistence): Wrong Function Argument");
        return;
    }
    Integer auxNum(number);
    _result = new Integer(0);
    this->_AuxMultiplicativePersistence(auxNum, (Integer*)_result);
}

void MultiplicativePersistence::_AuxMultiplicativePersistence(Integer num, Integer* mult){
    if(num.GetNumberOfDigits() > 1){
        num.SetValue(num.GetProductOfDigits());
        mult->SetValue(mult->GetValue()+1);
        _AuxMultiplicativePersistence(num,mult);
    }
    return;
}

vector<string> MultiplicativePersistence::s_names = {"multiplicative_persistence"};

CommonObject* MultiplicativePersistence::GetResult(){
    return _result;
}

int MultiplicativePersistence::s_GetNumberOfArguments(){
    return 1;
}

vector<CommonObject*> MultiplicativePersistence::s_GetArgumentsType(){
    return vector<CommonObject*>(s_GetNumberOfArguments(), new Integer());
}