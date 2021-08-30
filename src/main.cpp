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

    cout <<  "Number you put: " << integer.GetPrintableForm() << "\n";

    cout << "NEW NUMBER\n";
    cin >> number;

    integer.SetValue(number);
    cout <<  "Number you put: " << integer.GetPrintableForm() << "\n";

    return 0;
}