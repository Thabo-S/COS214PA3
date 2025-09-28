#include "User.h"
#include "ChatRoom.h"
#include "Command.h"
#include "SendMessageCommand.h"
#include "SaveMessageCommand.h"
#include "Message.h"

User::~User()
{
    clearCommands();
}

void User::sendMessage(const std::string &message, ChatRoom *room)
{
    if (room)
    {
        SendMessageCommand *sendCmd = new SendMessageCommand(room, this, message);

        addCommand(sendCmd);

        SaveMessageCommand *saveCmd = new SaveMessageCommand(room, this, message);

        addCommand(saveCmd);

        executeCommands();

        Message msg(message, this, room->getName());

        notifyObservers("MESSAGE_SENT", msg);
    }
}

void User::receiveMessage(const std::string &message, User *fromUser, ChatRoom *room)
{
    std::cout << "Notification 🔔" << std::endl;
    std::cout << "Received by " << name << " from " << fromUser->getName()
              << " in room " << room->getName() << ": " << message << "\n"
              << std::endl;
}

void User::addCommand(Command *command)
{
    commandQueue.push_back(command);
}

void User::executeCommands()
{
    for (Command *cmd : commandQueue)
    {
        if (cmd)
        {
            cmd->execute();
        }
    }

    clearCommands();
}

void User::joinRoom(ChatRoom *room)
{
    if (room)
    {
        chatRooms.push_back(room);

        room->registerUser(this);
    }
}

void User::leaveRoom(ChatRoom *room)
{
    for (auto foundRoom = chatRooms.begin(); foundRoom != chatRooms.end(); foundRoom++)
    {
        if (*foundRoom == room)
        {
            // std::cout << "** " << this->getName() << " has left the room **\n"
            //           << std::endl;

            chatRooms.erase(foundRoom);

            room->removeUser(this);

            break;
        }
    }
}

void User::notifyObservers(const std::string &event, Message message)
{
    for (Observer *observer : observers)
    {
        if (observer)
        {
            observer->update(event, message.toString());
        }
    }
}

void User::clearCommands()
{
    for (Command *cmd : commandQueue)
    {
        delete cmd;
    }
    commandQueue.clear();
}