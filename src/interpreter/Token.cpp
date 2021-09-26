// Standard Library Imports

// Third Party Imports

// Local Imports
#include "../../include/PowMat/LexerToken.h"

Token::Token(Token::TokenType tokenType, string token, int charInitialPos){
    _tokenType = tokenType;
    _token = token;
    _charInitialPos = charInitialPos;
}

Token::TokenType Token::GetTokenType(){
    return _tokenType;
}
string Token::GetTokenTypeString(){
    switch(_tokenType){
        case Token::TokenType::WHITE_SPACE:
            return "white_space";
            break;
        case Token::TokenType::END_OF_LINE:
            return "end_of_line";
            break;
        case Token::TokenType::IDENTIFIER:
            return "identifier";
            break;
        case Token::TokenType::SEPARATOR:
            return "separator";
            break;
        case Token::TokenType::OPERATOR:
            return "operator";
            break;
        case Token::TokenType::NUMBER:
            return "number";
            break;
        case Token::TokenType::STRING:
            return "string";
            break;
        default:
            return "unknown";
            break;
    }
}
int Token::GetCharInitialPos(){
    return _charInitialPos;
}
string Token::GetTokenString(){
    return _token;
}

void Token::AddCharToString(char newChar){
    _token.push_back(newChar);
}

