#ifndef SENDMESSAGECOMMAND_H
#define SENDMESSAGECOMMAND_H

#include "Command.h"
class ChatRoom;
class User;

class SendMessageCommand : public Command
{
public:
    SendMessageCommand(ChatRoom *room, User *user, const std::string &msg)
        : Command(room, user, msg) {}

    void execute() override;
};

#endif