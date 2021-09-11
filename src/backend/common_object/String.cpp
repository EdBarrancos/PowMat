// Standard Library Imports
#include <iostream>

// Third Party Imports

// Local Imports
#include "../../../include/PowMat/CommonObject.h"

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

bool String::Compare(CommonObject* one, CommonObject* two){
    return ((String*)one)->GetValue().compare(((String*)two)->GetValue()) == 0;
}