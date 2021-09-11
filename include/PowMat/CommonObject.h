#pragma once

#include <string>

using namespace std;

class CommonObject{
    public:
        CommonObject();
        virtual string GetPrintableForm() = 0;
};

class String: public CommonObject{
    protected:
        string _value;
    public:
        //Constructor
        String();
        String(string value);
        String(String* original);

        //Getters
        string GetValue();
        string GetPrintableForm() override; 
};

class Integer: public CommonObject{
    protected:
        int _value;
    public:
        //Constructor
        Integer();
        Integer(int value);
        Integer(Integer* original);

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