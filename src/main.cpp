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
    MiddleMan* middleMan = new MiddleMan();

    cout << "number\n";
    int ignore = scanf("%d", &number);
    if (!ignore)
    {
        exit(1);
    }
    Integer integer(number);

    cout << "function\n";
    cin >> name;

    cout <<  "Number you put: " << integer.GetPrintableForm() << "\n";

    vector<CommonObject*> arguments;
    arguments.push_back(&integer);
    cout << "Result: " << middleMan->CalculateMathFunction(name, arguments)->GetPrintableForm() << "\n";

    return 0;
}