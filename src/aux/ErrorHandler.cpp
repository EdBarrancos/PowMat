// Standard Library Imports
#include <vector>
#include <iostream>

// Third Party Imports

// Local Imports
#include "../../include/PowMat/ErrorHandler.h"

//Namespaces
using namespace std;

ErrorHandler error;

string ErrorHandler::ErrorPriorityToString(ErrorPriority priority){
    switch(priority){
        case SYNTAX_ERROR:
            return "SYNTAX ERROR";
            break;
        case ERROR:
            return "ERROR";
            break;
        case WARNING:
            return "WARNING";
            break;
        default:
            return "UNKNOWN";
            break;
    }
}

void ErrorHandler::LogErrors(){
    //TODO: Sort queue by priority
    vector<Error*>::iterator it;
    for(it = _errorQueue.begin(); it != _errorQueue.end(); it++){
        if(!(*it)->Logged()){
            error.LogError(*it);
        }
    }

    for(it = _errorQueue.begin(); it != _errorQueue.end(); it++){
        if((*it)->Logged()){
            _errorQueue.erase(it);
            delete *it;
        }
    }
}

void ErrorHandler::LogError(Error *error){
    //ERROR: message here
    cout << "\x1B[31m";
    cout << this->ErrorPriorityToString(error->GetPriority());
    cout << "\033[0m:";
    cout << error->GetMessage();
    cout << "\n";

    error->Log();
}

void ErrorHandler::QueueError(Error* error){
    _errorQueue.push_back(error);
}

bool ErrorHandler::IsQueueEmpty(){
    return _errorQueue.empty();
}

Error::Error(){
    _errorMessage = "there has been an problem";
    _errorPriority = (ErrorPriority)NULL;
}

Error::Error(string errorMessage, ErrorPriority priority){
    _errorPriority = priority;
    _errorMessage = errorMessage;
}

bool Error::Greater(Error otherError){
    return this->_errorPriority >= otherError.GetPriority();
}

ErrorPriority Error::GetPriority(){
    return _errorPriority;
}

string Error::GetMessage(){
    return _errorMessage;
}

bool Error::Logged(){
    return _logged;
}

void Error::Log(){
    _logged = true;
}

