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
        Integer(int value);
        string GetPrintableForm() override;
};