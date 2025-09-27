#ifndef COMMAND_H
#define COMMAND_H

#include "ChatRoom.h"
#include "User.h"
#include <string>

/**
 * @class Command
 * @brief Abstract command for actions (Command pattern).
 * @author Your Name
 * @date 25-09-2025
 */

class Command {
protected:
    ChatRoom* chatRoom;
    User* fromUser;
    std::string message;

public:
    Command(ChatRoom* room, User* user, const std::string& msg)
        : chatRoom(room), fromUser(user), message(msg) {}
    
    virtual ~Command() {}
    virtual void execute() = 0;
    
    ChatRoom* getChatRoom() const { return chatRoom; }
    User* getUser() const { return fromUser; }
    std::string getMessage() const { return message; }
};



#endif 