#pragma once 

#include "./CommonObject.h"

using namespace std;

class MathFunction{
    public:
        string* names;
    public:
        MathFunction();
        virtual CommonObject* GetResult() = 0;
};

class MultiplicativePersistence: public MathFunction{
    /* 
    * Calculate the Multiplicative Persistence of a Number
    * 
    * Returns how many times  you do the product of the Number's 
    * digits until i reaches a single digit 
    * */
    protected:
        CommonObject* _result;
    public:
        //Constructor
        MultiplicativePersistence(Integer* number);

        //Getters
        CommonObject* GetResult() override;
};

class AdditivePersistence: public MathFunction{
    /* 
    * Calculate the Additive Persistence of a Number 
    * 
    * Returns how many times you do the sum of the Number's 
    * digits until it reaches a single digit
    * */
    protected:
        CommonObject* _result;
    public:
        //Constructor
        AdditivePersistence(Integer* number);

        //Getters
        CommonObject* GetResult() override;
};