#ifndef USER_H
#define USER_H

#include <vector>
#include <string>
#include <iostream>

#include "Subject.h"

class ChatRoom;
class Command;
class Message;


/**
 * @class User
 * @brief Represents a user in the PetSpace system (Colleague in Mediator, Invoker in Command).
 *
 * Users can join chat rooms, send/receive messages via commands, and act as subjects for observers.
 * @author Thabo Seripe, Njabulo Nhlengethwa
 * @date 25-09-2025
 */

class User : public Subject
{
private:
    std::string name;
    std::vector<ChatRoom *> chatRooms;
    std::vector<Command *> commandQueue;

public:
    User(const std::string &userName) : name(userName) {}
    ~User();

    void sendMessage(const std::string &message, ChatRoom *room);
    void receiveMessage(const std::string &message, User *fromUser, ChatRoom *room);

    void addCommand(Command *command);
    void executeCommands();

    // Manage chat rooms
    void joinRoom(ChatRoom *room);
    void leaveRoom(ChatRoom *room);

    std::string getName() const { return name; }

    const std::vector<ChatRoom *> &getChatRooms() const { return chatRooms; }

    void notifyObservers(const std::string &event, Message msg) override;

    void clearCommands();
};

#endif