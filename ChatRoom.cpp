#include "ChatRoom.h"
#include "Message.h"
#include "User.h"
#include <iostream>

ChatRoom::~ChatRoom()
{
     clearUsers();
     clearMessages();
}

void ChatRoom::clearUsers()
{

     if (users.size() != 0)
     {
          users.clear();
     }
}

void ChatRoom::clearMessages()
{
     for (Message *msg : chatHistory)
     {
          delete msg;
     }
     chatHistory.clear();
}

void ChatRoom::printAllMessages() const
{
     std::cout << "\n 💬📱 Chat History for " << roomName << "📱💬 " << std::endl;

     if (chatHistory.empty())
     {
          std::cout << "No messages in this chat room." << std::endl;
          return;
     }

     for (const Message *msg : chatHistory)
     {
          if (msg && msg->getSender())
          {
               std::cout << msg->getSender()->getName() << std::endl;
               std::cout << msg->getContent() << std::endl;
               std::cout << std::endl; 
          }
     }
     std::cout << "=== End of Chat History ===" << std::endl;
}