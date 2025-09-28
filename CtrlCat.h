#ifndef CTRLCAT_H
#define CTRLCAT_H

#include "ChatRoom.h"

/**
 * @class CtrlCat
 * @brief Concrete mediator for CtrlCat room.
 * @author Your Name
 * @date 25-09-2025
 */

class CtrlCat : public ChatRoom
{
public:
    CtrlCat(const std::string &roomName) : ChatRoom(roomName) {};
    CtrlCat() : ChatRoom("CtrlCat") {};
    ~CtrlCat();

    void registerUser(User *user) override;
    void removeUser(User *user) override;

    void sendMessage(const std::string &content, User *fromUser) override;
    void saveMessage(const std::string &content, User *fromUser) override;

    // CHANGE THIS IN THE DIAGRAM YOU MADE IT ABSTRACT
    // BUT NOTHING INHERITES FROM THIS CLASS 👁️👄👁️
    // ALSO YOU HAVE WAY TO MANY ITERATORS BRUHH😭😭
    virtual Iterator<User *> *createUserIterator() override;
};

#endif