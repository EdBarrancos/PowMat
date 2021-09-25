// Standard Library Imports
#include <iostream>

// Third Party Imports

// Local Imports
#include "../../include/PowMat/CommonObject.h"

//Constructor

Error::Error(){
    _value = "";
}

Error::Error(string value){
    _value = value;
}

Error::Error(String* original){
    _value = original->GetValue();
}

//Getters

string Error::GetPrintableForm(){
    return "\x1B[31m" + _value + "\033[0m";
}

bool Error::Compare(CommonObject* other){
    return true;
}