#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include "User.h"


class Message {
private:
    std::string content;
    User* sender;
    std::string roomName;

public:
    Message(const std::string& msgContent, User* msgSender, const std::string& room);
    ~Message() {} // Simple destructor since we don't own the User
    
    // Getters
    std::string getContent() const { return content; }
    User* getSender() const { return sender; }
    std::string getTimestamp() const;
    std::string getRoomName() const { return roomName; }
    
    // Utility methods
    bool contains(const std::string& keyword) const;
    std::string toString() const;
};

#endif