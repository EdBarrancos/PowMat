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
                WHITE_SPACE,
                END_OF_LINE,
                IDENTIFIER,
                SEPARATOR,
                OPERATOR,
                NUMBER,
                STRING,
                UNKNOWN
};

class Token{
    public:
        Token(TokenType tokenType, string token, int charInitialPos);

        //Getters
        TokenType GetTokenType();
        int GetCharInitialPos();
        string GetTokenString();

        void AddCharToString(char newChar);

    protected:
        TokenType _tokenType;
        int _charInitialPos;
        string _token;
};

enum CharClassifier
{
    WHITE_SPACE, //whitespace tab
    CHARACTER, //a -> z _
    NUMERICAL, //0 -> 9
    SEPARATOR, // | . ( { ) }
    QUOTE, // ""
    OPERATOR, //- + * / = %
    END_OF_LINE
};

class Lexer{
    public:
        Lexer();
        vector<Token> LexString(string commandLine);

    protected:
        map<char, CharClassifier> _charClassifierMap;
        CharClassifier GetCurrentCharClass(string line, int pos);
        TokenType GetTokenType(TokenType lastTokenType, CharClassifier currentCharClass);
};