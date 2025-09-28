#ifndef DOGORITHM_H
#define DOGORITHM_H

#include "ChatRoom.h"

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

    // CHANGE THIS IN THE DIAGRAM YOU MADE IT ABSTRACT
    // BUT NOTHING INHERITES FROM THIS CLASS 👁️👄👁️
    // ALSO YOU HAVE WAY TO MANY ITERATORS BRUHH😭😭
    virtual Iterator<User *> *createUserIterator() override;
};

#endif