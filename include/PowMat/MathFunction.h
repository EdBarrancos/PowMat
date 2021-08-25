#pragma once 

#include "./CommonObject.h"

#include <vector>

using namespace std;

class MathFunction{
    public:
        MathFunction();
        virtual CommonObject* GetResult() = 0;
        static vector<string> c_names;
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

        //Variables
        static  vector<string> c_names;
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

        //Variables
        static  vector<string> c_names;
};