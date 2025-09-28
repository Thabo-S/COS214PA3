#include "Dogorithm.h"
#include "UserIterator.h"
#include <iostream>

Dogorithm::~Dogorithm()
{
}

void Dogorithm::registerUser(User *user)
{
    users.push_back(user);
}

void Dogorithm::removeUser(User *user)
{
    int indexPointer = 0;

    for (User *eachUser : users)
    {
        if (eachUser == user)
        {
            users.erase(users.begin() + indexPointer);

            return;
        }

        indexPointer++;
    }
}

void Dogorithm::sendMessage(const std::string &content, User *fromUser)
{
    for (User *user : users)
    {
        if (user != fromUser)
        {
            user->receiveMessage(content, fromUser, this);
        }
    }
}

void Dogorithm::saveMessage(const std::string &content, User *fromUser)
{
    Message *newMessage = new Message(content, fromUser, roomName);

    chatHistory.push_back(newMessage);
}

Iterator<User *> *Dogorithm::createUserIterator()
{
    return new UserIterator(users);
}