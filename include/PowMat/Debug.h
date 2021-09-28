#pragma once

//Standard Library Imports
#include <string>
#include <iostream>
#include <fstream>

//Third Party Imports

//Local Imports

//Namespaces
using namespace std;

class Debug{
    public:
        Debug();
        void Log(string message);

    protected:
        string pathToDebugFile;
        ofstream debugFile;
};

extern Debug debuger;