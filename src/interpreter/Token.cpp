// Standard Library Imports

// Third Party Imports

// Local Imports
#include "../../include/PowMat/LexerToken.h"

Token::Token(TokenType tokenType, string token, int charInitialPos){
    _tokenType = tokenType;
    _token = token;
    _charInitialPos = charInitialPos;
}

TokenType Token::GetTokenType(){
    return _tokenType;
}
int Token::GetCharInitialPos(){
    return _charInitialPos;
}
string Token::GetTokenString(){
    return _token;
}

void Token::AddCharToString(char newChar){
    _token.push_back(newChar)
}

