#pragma once

// Standard Library Imports
#include <vector>
#include <string>
#include <map>

// Third Party Imports

// Local Imports

// Namespace
using namespace std;

enum TokenType{
                LINE_END,
                IDENTIFIER,
                SEPARATOR,
                OPERATOR,
                LITERAL,
                UNKNOWN
            };

class Token{
    public:
        Token(TokenType tokenType, string token, int charInitialPos);

        //Getters
        TokenType GetTokenType();
        int GetCharInitialPos();
        string GetTokenString();

    protected:
        TokenType _tokenType;
        int _charInitialPos;
        string _token;
};

enum CharClassifier
{
    WHITE_SPACE,
    CHARACTER, //a -> z _
    NUMERICAL, //0 -> 9
    SEPARATOR, //, ; ( ) { } // 
    QUOTES, // ""
    OPERATOR, //- + * / =
    END_OF_LINE
};

class Lexer{
    public:
        Lexer();
        vector<Token*> LexString(string commandLine);

    protected:
        map<CharClassifier, char> _charClassifierMap;
};