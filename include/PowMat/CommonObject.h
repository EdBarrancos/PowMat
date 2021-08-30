#pragma once

#include <string>

using namespace std;

class CommonObject{
    public:
        CommonObject();
        virtual string GetPrintableForm() = 0;
};

class Integer: public CommonObject{
    protected:
        int _value;
    public:
        //Constructor
        Integer(int value);

        //Getters
        int GetValue();
        int GetMostSignificantDigit();
        int GetNumberOfDigits();
        string GetPrintableForm() override;
        int GetProductOfDigits();
        int GetSumOfDigits();

        //Setters
        void ShiftRight();
        void SetValue(int value);
};