// Standard Library Imports
#include <iostream>

// Third Party Imports

// Local Imports
#include "../include/PowMat/CommonObject.h"
#include "../include/PowMat/MiddleMan.h"

//Namespaces
using namespace std;


int main(){
    int number;
    string name;
    char aName[100];
    MiddleMan* middleMan = new MiddleMan();


    int ignore = scanf("%d", &number);
    if (!ignore)
    {
        exit(1);
    }
    Integer integer(number);


    ignore = scanf("%s", aName);
    if (!ignore)
    {
        exit(1);
    }
    name = aName;


    vector<CommonObject*> arguments = {&integer};
    cout  << middleMan->CalculateMathFunction(name, arguments)->GetPrintableForm() << "\n";

    return 0;
}