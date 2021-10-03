#pragma once

// Standard Library Imports
#include <vector>
#include <string>

// Third Party Imports

// Local Imports
#include "./ErrorHandler.h"
#include "./LexerToken.h"

// Namespace
using namespace std;

class ParsingElem: public Element{
    public:
        ParsingElem();
        ParsingElem(string name);

        string GetElemName();
    protected:
        string _name;
};


class Parser{};