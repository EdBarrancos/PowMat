// Standard Library Imports
#include <iostream>

// Third Party Imports

// Local Imports
#include "../../include/PowMat/CommonObject.h"

//Constructor

String::String(){
    _value = "";
}

String::String(string value){
    _value = value;
}

String::String(String* original){
    _value = original->GetValue();
}

//Getters

string String::GetValue(){
    return _value;
}

string String::GetPrintableForm(){
    return _value;
}

bool String::Compare(CommonObject* other){
    return this->GetValue().compare(((String*)other)->GetValue()) == 0;
}