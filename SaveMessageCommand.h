#ifndef SAVEMESSAGECOMMAND_H
#define SAVEMESSAGECOMMAND_H

#include "Command.h"
class ChatRoom;
class User;

/**
 * @class SaveMessageCommand
 * @brief Command for saving messages to chat history.
 * 
 * Implements command pattern for saving messages to
 * persistent chat history storage.
 * @author Thabo Seripe, Njabulo Nhlengethwa
 * @date 25-09-2025
 */

class SaveMessageCommand : public Command {
public:
    SaveMessageCommand(ChatRoom* room, User* user, const std::string& msg)
        : Command(room, user, msg) {}
    
    void execute() override;
};

#endif