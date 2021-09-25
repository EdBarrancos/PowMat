#pragma once

// Standard Library Imports
#include <string>

// Third Party Imports

// Local Imports
#include "./LexerToken.h"
#include "./ErrorHandler.h"



class Interpreter{
    public:
        Interpreter();

        void Initialization();
        void InterpretOneLine(string line);
    protected:
        Lexer _lexer;
};
