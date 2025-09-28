#include "CtrlCat.h"
#include "UserIterator.h"

CtrlCat::~CtrlCat()
{
}

void CtrlCat::registerUser(User *user)
{
     users.push_back(user);
}

void CtrlCat::removeUser(User *user)
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

void CtrlCat::sendMessage(const std::string &content, User *fromUser)
{
     for (User *user : users)
     {
          if (user != fromUser)
          {
               user->receiveMessage(content, fromUser, this);
          }
     }
}

void CtrlCat::saveMessage(const std::string &content, User *fromUser)
{
     Message *newMessage = new Message(content, fromUser, roomName);

     chatHistory.push_back(newMessage);
}

Iterator<User *> *CtrlCat::createUserIterator()
{
     return new UserIterator(users);
}