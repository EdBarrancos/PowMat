// Standard Library Imports
#include <iostream>

// Third Party Imports

// Local Imports
#include "../include/PowMat/CommonObject.h"

//Namespaces
using namespace std;


int main(){
    int number;

    int ignore = scanf("%d", &number);
    if (!ignore)
    {
        exit(1);
    }
    Integer integer(number);

    cout <<  integer.GetPrintableForm();

    return 0;
}