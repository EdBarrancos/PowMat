#pragma once

// Standard Library Imports
#include <string>

// Third Party Imports

// Local Imports
#include "./LexerToken.h"



class Interpreter{
    public:
        Interpreter();

        void Initialization();
        void InterpretOneLine(string line);
    protected:
        Lexer _lexer;
};

class Context{
    public:
        string initalLine;
        vector<Token*> tokenList;
        //Abstration Syntax Tree
        //Action Tree
}
