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
    _charClassifierMap['='] = OPERATOR;
}

vector<Token> Lexer::LexString(string commandLine){
    //TODO: StateMachine
    //TODO: CheckIfErrorsThrown
    int currentPos = 0;
    vector<Token> tokenList;


    TokenType currentTokenType = TokenType::WHITE_SPACE;;
    for (string::size_type i = 0; i < commandLine.size(); i++, currentPos++) {
        TokenType newTokenType = GetTokenType(currentTokenType, GetCurrentCharClass(commandLine, i));
        if(newTokenType == TokenType::WHITE_SPACE){
            currentTokenType = newTokenType;
            continue;
        }
        if(newTokenType == TokenType::END_OF_LINE){
            tokenList.push_back(Token(END_OF_LINE,string(""), i));
            break;
        }
        if(newTokenType == currentTokenType){
            tokenList.back().AddCharToString(commandLine[i]);
        }
        if(newTokenType != currentTokenType){
            tokenList.push_back(Token(currentTokenType,string(1,commandLine[i]),i));
        }

    }

    return tokenList;
}

TokenType Lexer::GetTokenType(TokenType lastTokenType, CharClassifier currentCharClass){
    switch (currentCharClass)
    {
    case WHITE_SPACE:
        return TokenType::WHITE_SPACE;
        break;
    case END_OF_LINE:
        return TokenType::END_OF_LINE;
        break;
    case CHARACTER:
        if(lastTokenType == STRING){
            return lastTokenType;
            break;
        }
        return TokenType::IDENTIFIER;
        break;
    case NUMERICAL:
        if(lastTokenType == STRING || lastTokenType == IDENTIFIER){
            return lastTokenType;
            break;
        }
        return TokenType::NUMBER;
        break;
    case SEPARATOR:
        return TokenType::SEPARATOR;
        break;
    case QUOTE:
        return TokenType::STRING;
        break;
    case OPERATOR:
        return TokenType::OPERATOR;
        break;
    default:
        return TokenType::UNKNOWN;
        break;
    }
}

CharClassifier Lexer::GetCurrentCharClass(string line, int pos){
    return _charClassifierMap.at(line[pos]);
}