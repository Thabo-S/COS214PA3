#include "SendMessageCommand.h"
#include "ChatRoom.h"
#include "User.h"

void SendMessageCommand::execute()
{
    if (chatRoom && fromUser)
    {
        chatRoom->sendMessage(message, fromUser);
    }
}