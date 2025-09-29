#ifndef DOGORITHM_H
#define DOGORITHM_H

#include "ChatRoom.h"

/**
 * @class Dogorithm
 * @brief Concrete mediator for Dogorithm chat room.
 * 
 * Implements specific behavior for the Dogorithm chat room
 * including user management and message handling.
 * @author Thabo Seripe, Njabulo Nhlengethwa
 * @date 25-09-2025
 */

class Dogorithm : public ChatRoom
{
public:
    Dogorithm(const std::string &roomName) : ChatRoom(roomName) {}
    Dogorithm() : ChatRoom("Dogoritm") {}

    ~Dogorithm();

    void registerUser(User *user) override;
    void removeUser(User *user) override;
    void sendMessage(const std::string &content, User *fromUser) override;
    void saveMessage(const std::string &content, User *fromUser) override;

    virtual Iterator<User *> *createUserIterator() override;
};

#endif