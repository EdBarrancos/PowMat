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

    while(auxLine[0] != EOF){
        int ignore = scanf("%s", auxLine);
        if (!ignore)
        {
            exit(1);
        }

        cout << auxLine << "\n";
        line = auxLine;
        interpreter.InterpretOneLine(line);
    }

    

    return 0;
}