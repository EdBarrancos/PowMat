// Standard Library Imports

// Third Party Imports

// Local Imports
#include "../../include/PowMat/LexerToken.h"

Lexer::Lexer(){
    //Map CharClassifier
    //WHITE_SPACE
    _charClassifierMap[' '] = WHITE_SPACE;
    _charClassifierMap['\t'] = WHITE_SPACE;

    //END_OF_LINE
    _charClassifierMap['\n'] = END_OF_LINE;

    //CHARACTER
    for (char c = 'a'; c <= 'z'; ++c){
        _charClassifierMap[c] = CHARACTER;
    }
    for (char c = 'A'; c <= 'Z'; ++c){
        _charClassifierMap[c] = CHARACTER;
    }

    _charClassifierMap['_'] = CHARACTER;

    //NUMERICAL
    for (char c='0'; c <= '9'; ++c){
        _charClassifierMap[c] = NUMERICAL;
    }

    //SEPARATOR
    _charClassifierMap[','] = SEPARATOR;
    _charClassifierMap[';'] = SEPARATOR;
    _charClassifierMap['('] = SEPARATOR;
    _charClassifierMap[')'] = SEPARATOR;
    _charClassifierMap['{'] = SEPARATOR;
    _charClassifierMap['}'] = SEPARATOR;
    _charClassifierMap['|'] = SEPARATOR;

    //QUOTE
    _charClassifierMap['"'] = QUOTE;

    //OPERATOR
    _charClassifierMap['-'] = OPERATOR;
    _charClassifierMap['+'] = OPERATOR;
    _charClassifierMap['*'] = OPERATOR;
    _charClassifierMap['/'] = OPERATOR;
    _charClassifierMap['%'] = OPERATOR;
}

vector<Token*> Lexer::LexString(string commandLine){
    //TODO: StateMachine
}