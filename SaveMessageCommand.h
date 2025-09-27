#ifndef SAVEMESSAGECOMMAND_H
#define SAVEMESSAGECOMMAND_H

#include "Command.h"

class SaveMessageCommand : public Command {
public:
    SaveMessageCommand(ChatRoom* room, User* user, const std::string& msg)
        : Command(room, user, msg) {}
    
    void execute() override;
};

#endif