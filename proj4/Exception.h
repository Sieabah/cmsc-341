#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H
#include <string>

class Exceptions {
public:
    /**********************************************************************
     * Name: MyExceptions (Constructor)
     * PreCondition: String containing error description.  
     * 
     * PostCondition:  Error object
     *********************************************************************/
    Exceptions(std::string message): m_message(message) {}

    /**********************************************************************
     * Name: GetMessage
     * PreCondition: None.  
     * 
     * PostCondition:  Returns error message.
     *********************************************************************/
    const std::string GetMessage() { return m_message; }
    
private:
    
    std::string m_message; //Error message.
};

class NoPositionAvailable {
public:
    /**********************************************************************
     * Name: MyExceptions (Constructor)
     * PreCondition: String containing error description.  
     * 
     * PostCondition:  Error object
     *********************************************************************/
    NoPositionAvailable(): m_message("Failed to find position in hash table.") {}

    /**********************************************************************
     * Name: GetMessage
     * PreCondition: None.  
     * 
     * PostCondition:  Returns error message.
     *********************************************************************/
    const std::string GetMessage() { return m_message; }
    
private:
    
    std::string m_message; //Error message.
};

#endif