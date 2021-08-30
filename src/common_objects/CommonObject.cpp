// Standard Library Imports

// Third Party Imports

// Local Imports
#include "../../include/PowMat/CommonObject.h"

//Namespaces
using namespace std;


//CONSTRUCTOR

CommonObject::CommonObject(){}

Integer::Integer(int value){
    _value = value;
}


//GETTERS

string Integer::GetPrintableForm(){
    return to_string(_value);
}

int Integer::GetValue(){
    return _value;
}

int Integer::GetMostSignificantDigit(){
    return _value % 10;
}

int Integer::GetNumberOfDigits(){
    int number = _value;
    int digits = 0;
    while (number){
        number /= 10;
        digits ++;
    }
    return digits;
}

int Integer::GetProductOfDigits(){
    int mult = 1;
    while (this->GetNumberOfDigits()){
        mult *= this->GetMostSignificantDigit();
        this->ShiftRight();
    }
    return mult;
}

int Integer::GetSumOfDigits(){
    int sum = 1;
    while (this->GetNumberOfDigits()){
        sum += this->GetMostSignificantDigit();
        this->ShiftRight();
    }
    return sum;
}


//SETTERS

void Integer::ShiftRight(){
    _value /= 10;
}

void Integer::SetValue(int value){
    _value = value;
}