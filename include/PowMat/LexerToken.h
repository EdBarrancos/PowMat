#pragma once

// Standard Library Imports
#include <vector>

// Third Party Imports

// Local Imports

// Namespace
using namespace std;

class Token{
    protected:
        enum TokenType{
            LINE_END,
            IDENTIFIER,
            SEPARATOR,
            OPERATOR,
            LITERAL,
            UNKNOWN
        };
        TokenType tokenType;
        int charPos;
    public:
        Token();
};

class Lexer{
    public:
        Lexer();
        vector<Token*> LexString(string commandLine);
};