// Standard Library Imports
#include <iostream>

// Third Party Imports

// Local Imports
#include "../include/PowMat/CommonObject.h"
#include "../include/PowMat/MiddleMan.h"
#include "../include/PowMat/ErrorHandler.h"
#include "../include/PowMat/Interpreter.h"
#include "../include/PowMat/Debug.h"


//Namespaces
using namespace std;


int main(){
    Interpreter interpreter = Interpreter();

    string line;
    char auxLine[100];

    while(scanf("%[^\n]s", auxLine) != EOF){
        getchar();
        line = auxLine;
        if(line == "-1"){
            break;
        }
        interpreter.InterpretOneLine(line);
    }

    error.LogErrors();

    return 0;
}