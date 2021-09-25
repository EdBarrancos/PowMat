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


    Token::TokenType currentTokenType = Token::TokenType::WHITE_SPACE;;
    for (string::size_type i = 0; i < commandLine.size(); i++, currentPos++) {
        Token::TokenType newTokenType = GetTokenType(currentTokenType, GetCurrentCharClass(commandLine, i));
        if(newTokenType == Token::TokenType::WHITE_SPACE){
            currentTokenType = newTokenType;
            continue;
        }
        if(newTokenType == Token::TokenType::END_OF_LINE){
            tokenList.push_back(Token(Token::TokenType::END_OF_LINE,string(""), currentPos));
            break;
        }
        if(newTokenType == currentTokenType){
            tokenList.back().AddCharToString(commandLine[i]);
            currentTokenType = newTokenType;
        }
        if(newTokenType != currentTokenType){
            tokenList.push_back(Token(newTokenType,string(1,commandLine[i]),currentPos));
            currentTokenType = newTokenType;
        }

    }

    return tokenList;
}

Token::TokenType Lexer::GetTokenType(Token::TokenType lastTokenType, CharClassifier currentCharClass){
    switch (currentCharClass)
    {
    case WHITE_SPACE:
        return Token::TokenType::WHITE_SPACE;
        break;
    case END_OF_LINE:
        return Token::TokenType::END_OF_LINE;
        break;
    case CHARACTER:
        if(lastTokenType == Token::TokenType::STRING){
            return lastTokenType;
            break;
        }
        return Token::TokenType::IDENTIFIER;
        break;
    case NUMERICAL:
        if(lastTokenType == Token::TokenType::STRING || lastTokenType == Token::TokenType::IDENTIFIER){
            return lastTokenType;
            break;
        }
        return Token::TokenType::NUMBER;
        break;
    case SEPARATOR:
        return Token::TokenType::SEPARATOR;
        break;
    case QUOTE:
        return Token::TokenType::STRING;
        break;
    case OPERATOR:
        return Token::TokenType::OPERATOR;
        break;
    default:
        return Token::TokenType::UNKNOWN;
        break;
    }
}

CharClassifier Lexer::GetCurrentCharClass(string line, int pos){
    return _charClassifierMap.at(line[pos]);
}