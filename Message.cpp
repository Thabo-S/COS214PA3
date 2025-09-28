#include "Message.h"

Message::Message(const std::string &msgContent, User *msgSender, const std::string &room)
    : content(msgContent), sender(msgSender), roomName(room)
{
}

std::string Message::toString() const
{
    std::string string;

    string = sender->getName() + " in " + roomName + ": " + content;

    return string;
}