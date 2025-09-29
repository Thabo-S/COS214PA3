#ifndef SENDMESSAGECOMMAND_H
#define SENDMESSAGECOMMAND_H

#include "Command.h"
class ChatRoom;
class User;

/**
 * @class SendMessageCommand
 * @brief Command for sending messages to chat room users.
 * 
 * Implements command pattern for broadcasting messages
 * to all users in a chat room.
 * @author Thabo Seripe, Njabulo Nhlengethwa
 * @date 25-09-2025
 */

class SendMessageCommand : public Command
{
public:
    SendMessageCommand(ChatRoom *room, User *user, const std::string &msg)
        : Command(room, user, msg) {}

    void execute() override;
};

#endif