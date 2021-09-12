// Standard Library Imports

// Third Party Imports

// Local Imports
#include "../../include/PowMat/Interpreter.h"
#include "../../include/PowMat/CommonObject.h"
#include "../../include/PowMat/MiddleMan.h"


Interpreter::Interpreter(){
    //Lexer
    //Parser
    //Action Tree

    //Initializations if needed
}

void Interpreter::Initialization(){
    _lexer = Lexer();
}

void Interpreter::InterpretOneLine(string line){
    _lexer.LexString(line);
}