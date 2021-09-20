// Standard Library Imports
#include <vector>

// Third Party Imports

// Local Imports
#include "../../../include/PowMat/MathFunction.h"
#include "../../../include/PowMat/ErrorHandler.h"

//Namepspaces
using namespace std;

AdditivePersistence::AdditivePersistence(Integer* number){
    if(typeid(number) != typeid(Integer*)){
        error.QueueError(new Error("(AdditivePersistence): Wrong Function Argument", ERROR));
        _result = NULL;
        return;
    }
    Integer auxNum(number);
    _result = new Integer(0);
    this->_AuxAdditivePersistence(auxNum, (Integer*)_result);
}

void AdditivePersistence::_AuxAdditivePersistence(Integer num, Integer* add){
    if(num.GetNumberOfDigits() > 1){
        num.SetValue(num.GetSumOfDigits());
        add->SetValue(add->GetValue()+1);
        _AuxAdditivePersistence(num, add);
    }
    return;
}

vector<string> AdditivePersistence::s_names = {"additive_persistence"};

CommonObject* AdditivePersistence::GetResult(){
    return _result;
}

int AdditivePersistence::s_GetNumberOfArguments(){
    return 1;
}

vector<CommonObject*> AdditivePersistence::s_GetArgumentsType(){
    return vector<CommonObject*>(s_GetNumberOfArguments(), new Integer());
}