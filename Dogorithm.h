#ifndef DOGORITHM_H
#define DOGORITHM_H

#include "ChatRoom.h"
#include "User.h"
#include "Message.h"

class Dogorithm : public ChatRoom {
public:
    Dogorithm() : ChatRoom("Dogorithm") {}
    ~Dogorithm();
    
    void registerUser(User* user) override;
    void removeUser(User* user) override;
    void sendMessage(const std::string& content, User* fromUser) override;
    void saveMessage(const std::string& content, User* fromUser) override;
    
    virtual Iterator<User*>* createUserIterator() = 0;
};

#endif