#pragma once 

#include "./CommonObject.h"

using namespace std;

class MathFunction{
    public:
        MathFunction();
        virtual CommonObject* GetResult() = 0;
};

class MultiplicativePersistance: public MathFunction{
    /* 
    * Calculate the Multiplicative Persistance of a Number
    * 
    * Returns how many times  you do the product of the Number's 
    * digits until i reaches a single digit 
    * */
    protected:
        CommonObject* _result;
    public:
        //Constructor
        MultiplicativePersistance(CommonObject* number);

        //Getters
        CommonObject* GetResult() override;
};

class AdditivePersistance: public MathFunction{
    /* 
    * Calculate the Additive Persistance of a Number 
    * 
    * Returns how many times you do the sum of the Number's 
    * digits until it reaches a single digit
    * */
    protected:
        CommonObject* _result;
    public:
        //Constructor
        AdditivePersistance(CommonObject* number);

        //Getters
        CommonObject* GetResult() override;
};