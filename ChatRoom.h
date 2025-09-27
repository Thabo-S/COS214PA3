#ifndef CHATROOM_H
#define CHATROOM_H

#include <vector>
#include <string>
#include <iostream>
#include "User.h"
#include "Iterator.h"

/**
 * @class ChatRoom
 * @brief Abstract mediator for chat rooms (Mediator pattern).
 * 
 * Manages users and message delivery/history.
 * @author habo Seripe, Njabulo Nhlengethwa
 * @date 25-09-2025
 */

class ChatRoom {
protected:
    std::vector<User*> users;
    std::vector<Message*> chatHistory;
    std::string roomName;

public:
    ChatRoom(const std::string& name) : roomName(name) {}
    virtual ~ChatRoom();
    
    virtual void registerUser(User* user) = 0;
    virtual void removeUser(User* user) = 0;
    virtual void sendMessage(const std::string& content, User* fromUser) = 0;
    virtual void saveMessage(const std::string& content, User* fromUser) = 0;
    
    virtual Iterator<User*>* createUserIterator() = 0;
    
    std::string getName() const { return roomName; }
    
    virtual void clearUsers();
    virtual void clearMessages();
};

#endif 