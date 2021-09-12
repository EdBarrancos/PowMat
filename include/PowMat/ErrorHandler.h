#pragma once

// Standard Library Imports
#include <vector>
#include <string>

// Third Party Imports

// Local Imports

//Namespaces
using namespace std;

enum ErrorPriority
{
    ERROR,
    WARNING
};

class Error{
    public:
        Error();
        Error(string errorMessage, ErrorPriority priority);

        bool Greater(Error otherError);
        ErrorPriority GetPriority();
        string GetMessage();
        bool Logged();
    protected:
        string _errorMessage;
        ErrorPriority _errorPriority;
        bool _logged;
};

class ErrorHandler{
    public:
        void LogError(Error *error);
        void LogErrors();
        bool IsQueueEmpty();
        string ErrorPriorityToString(ErrorPriority priority);
    protected:
        vector<Error*> _errorQueue;
};

extern ErrorHandler error;

