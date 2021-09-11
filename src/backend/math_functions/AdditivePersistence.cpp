// Standard Library Imports
#include <vector>

// Third Party Imports

// Local Imports
#include "../../../include/PowMat/MathFunction.h"

//Namepspaces
using namespace std;

AdditivePersistence::AdditivePersistence(Integer* number){
    if(typeid(number) != typeid(Integer*)){
        _result = new Error("ERROR(AdditivePersistence): Wrong Function Argument");
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