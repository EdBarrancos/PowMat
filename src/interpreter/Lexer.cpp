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
    _charClassifierMap[';'] = END_OF_LINE;

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
    _charClassifierMap['.'] = SEPARATOR;
    _charClassifierMap[','] = SEPARATOR;
    _charClassifierMap['('] = DOUBLE_SEPERATOR_B;
    _charClassifierMap[')'] = DOUBLE_SEPERATOR_E;
    _charClassifierMap['{'] = DOUBLE_SEPERATOR_B;
    _charClassifierMap['}'] = DOUBLE_SEPERATOR_E;
    _charClassifierMap['|'] = SEPARATOR;

    //QUOTE
    _charClassifierMap['"'] = QUOTE;

    //OPERATOR
    _charClassifierMap['-'] = OPERATOR;
    _charClassifierMap['+'] = OPERATOR;
    _charClassifierMap['*'] = OPERATOR;
    _charClassifierMap['/'] = OPERATOR;
    _charClassifierMap['%'] = OPERATOR;
    _charClassifierMap['='] = OPERATOR;
}

vector<Token> Lexer::LexString(string commandLine){
    //TODO: StateMachine
    int currentChar = 0;
    vector<Token> tokenList;

    Token token = GetToken(commandLine, &currentChar);

    while(token.GetTokenType() != LINE_END){
        tokenList.push_back(token);
        token = GetToken(commandLine, &currentChar);
    }

    return tokenList;
}

Token Lexer::GetToken(string line, int* currentChar){
    switch(GetCurrentCharClass(line, *currentChar)){
        case WHITE_SPACE:
            *currentChar ++;
            return GetToken(line, currentChar);
            break;
        case CHARACTER:
            break;
        case NUMERICAL:
            break;
        case SEPARATOR:
            break;
        case DOUBLE_SEPERATOR_B:
            break;
        case DOUBLE_SEPERATOR_E:
            break;
        case QUOTE:
            break;
        case OPERATOR:
            break;
        case END_OF_LINE:
            return Token(LINE_END, "", *currentChar);
            break;
    }
}

CharClassifier Lexer::GetCurrentCharClass(string line, int pos){
    return _charClassifierMap.at(line[pos]);
}