// Standard Library Imports
#include <iostream>

// Third Party Imports

// Local Imports
#include "../../include/PowMat/Interpreter.h"
#include "../../include/PowMat/CommonObject.h"
#include "../../include/PowMat/MiddleMan.h"


Interpreter::Interpreter(){
    //Lexer
    //Parser
    //Action Tree

    Initialization();
}

void Interpreter::Initialization(){
    _lexer = Lexer();
}

void Interpreter::InterpretOneLine(string line){
    vector<Token> tokenList;
    tokenList = _lexer.LexString(line);
    for(vector<Token>::iterator it = tokenList.begin(); it != tokenList.end(); it++){
        cout << (*it).GetTokenTypeString() << ": " << (*it).GetTokenString() << "\n";
    }
}