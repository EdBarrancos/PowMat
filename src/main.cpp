// Standard Library Imports
#include <iostream>

// Third Party Imports

// Local Imports
#include "../include/PowMat/CommonObject.h"
#include "../include/PowMat/MiddleMan.h"
#include "../include/PowMat/ErrorHandler.h"
#include "../include/PowMat/Interpreter.h"


//Namespaces
using namespace std;


int main(){
    Interpreter interpreter = Interpreter();

    string line;
    char auxLine[100];

    //TODO: Better System
    while(true){
        int ignore = scanf("%s", auxLine);
        if (!ignore)
        {
            exit(1);
        }

        line = auxLine;
        if(line == "-1"){
            break;
        }
        interpreter.InterpretOneLine(line);
    }

    error.LogErrors();

    

    return 0;
}