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
    SYNTAX_ERROR,
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
        void Log();
    protected:
        string _errorMessage;
        ErrorPriority _errorPriority;
        bool _logged;
};

class ErrorHandler{
    public:
        void LogErrors();

        void QueueError(Error *error);


        bool IsQueueEmpty();
        string ErrorPriorityToString(ErrorPriority priority);
    protected:
        vector<Error*> _errorQueue;
        void LogError(Error *error);
};

extern ErrorHandler error;

