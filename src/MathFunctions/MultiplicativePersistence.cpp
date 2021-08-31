// Standard Library Imports
#include <vector>
#include <iostream>

// Third Party Imports

// Local Imports
#include "../../include/PowMat/MathFunction.h"

//Namepspaces
using namespace std;

MultiplicativePersistence::MultiplicativePersistence(Integer* number){
    //TODO: Calculate MultiplicativePersistance
    Integer auxNum;
    number->CloneInteger(&auxNum);
    _result = new Integer(0);

    this->_AuxMultiplicativePersistence(auxNum, _result);
    cout << _result->GetValue();
}

void MultiplicativePersistence::_AuxMultiplicativePersistence(Integer num, Integer* mult){
    cout << "LEz go\n";
    cout << num.GetNumberOfDigits() << "\n";

    if(num.GetNumberOfDigits() >= 1){
        num.SetValue(num.GetProductOfDigits());
        mult->SetValue(mult->GetValue()+1);
        cout << mult->GetValue();
        _AuxMultiplicativePersistence(num,mult);
    }
    return;
}

vector<string> MultiplicativePersistence::s_names = {"multiplicative_persistence"};

CommonObject* MultiplicativePersistence::GetResult(){
    return _result;
}