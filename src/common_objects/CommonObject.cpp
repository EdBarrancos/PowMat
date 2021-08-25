// Standard Library Imports

// Third Party Imports

// Local Imports
#include "../../include/PowMat/CommonObject.h"

//Namespaces
using namespace std;

CommonObject::CommonObject(){}

Integer::Integer(int value){
    _value = value;
}

string Integer::GetPrintableForm(){
    return to_string(_value);
}

int Integer::GetValue(){
    return _value;
}