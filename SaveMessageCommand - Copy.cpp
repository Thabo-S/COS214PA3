#include "SaveMessageCommand.h"
#include "ChatRoom.h"
#include "User.h"

void SaveMessageCommand::execute()
{
    if (chatRoom && fromUser)
    {
        chatRoom->saveMessage(message, fromUser);
    }
}
