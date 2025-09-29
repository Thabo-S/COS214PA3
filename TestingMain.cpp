#include "CtrlCat.h"
#include "Dogorithm.h"
#include "UserIterator.h"
#include "SendMessageCommand.h"
#include "SaveMessageCommand.h"
#include "SaveMessageCommand.h"
#include "AdminObserver.h"
#include "MessageObserver.h"
#include <iostream>
#include <string>

using namespace std;

void mediatorTest();
void testIteratorPattern();
void testObserverPattern();

string batman = "\n⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⠀⠀⣸⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣇⠀⠀⠀⠀⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⠀⠀⣿⣿⣤⣤⣶⣶⣶⣶⣶⣶⣤⣤⣿⣿⠀⠀⠀⠀⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⢸⣿⣿⣿⠻⢿⣿⣿⣿⣿⣿⣿⡿⠟⣿⣿⣿⡇⠀⠀⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⠈⣿⣿⣿⣧⣀⣬⣽⣿⣿⣯⣥⣀⣼⣿⣿⣿⠁⠀⠀⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⠀⢸⣿⣏⠉⠛⠿⢿⣿⣿⠿⠿⠛⠉⢹⣿⡇⠀⠀⠀⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⢀⣀⣤⣤⣄⡀⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀\n"
                "⠀⠀⠀⠀⣀⣤⣾⣿⣿⣷⣄⠈⠉⠉⠉⠉⠁⣠⣴⣿⣿⣷⣤⣀⠀⠀⠀⠀\n"
                "⢀⣤⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣤⣤⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣄⡀\n"
                "⠸⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠇\n";

int main()
{
    mediatorTest();
    testObserverPattern();
    testIteratorPattern();

    return 0;
}

void mediatorTest()
{
    cout << "\n*** Testing Mediator Pattern *****" << endl;

    CtrlCat *ctrlCat = new CtrlCat("CtrlCat");
    Dogorithm *dogorithm = new Dogorithm("Dogorithm");

    User *user1 = new User("Thabo");
    User *user2 = new User("Carti");
    User *user3 = new User("BBLDrizzy");
    User *user4 = new User("Owen");

    std::cout << "Testing user registration..." << std::endl;
    user1->joinRoom(ctrlCat);
    user1->joinRoom(dogorithm);
    user2->joinRoom(dogorithm);
    user3->joinRoom(ctrlCat);
    user4->joinRoom(ctrlCat);

    std::cout << "\nTesting message sending..." << std::endl;

    user1->sendMessage("W's in Chatttt!", ctrlCat);
    user2->sendMessage("Hi " + user1->getName() + " ,this is " + user2->getName() + "!", ctrlCat);
    user1->sendMessage("How cool is this" + batman, ctrlCat);
    user4->sendMessage("This is boring, I'm OUT", ctrlCat);
    user4->leaveRoom(ctrlCat);

    user1->sendMessage("Hello Dogorithm room!", dogorithm);
    user3->sendMessage("Welcome " + user1->getName() + " to Dogorithm !", dogorithm);

    std::cout << "\n*** Printing Chat Histories ***" << std::endl;
    ctrlCat->printAllMessages();

    std::cout << "\n"
              << std::endl;
    dogorithm->printAllMessages();

    delete ctrlCat;
    delete dogorithm;
    delete user1;
    delete user2;
    delete user3;
    delete user4;
}

void testObserverPattern()
{
    ChatRoom *room = new CtrlCat("ObserverTest");
    User *sender = new User("MessageSender");
    User *listener = new User("MessageListener");

    sender->joinRoom(room);
    listener->joinRoom(room);

    cout << "👀 Creating observers..." << endl;

    AdminObserver *adminObs = new AdminObserver();
    MessageObserver *msgObs = new MessageObserver("GeneralChat");

    cout << "📎 Attaching observers to sender..." << endl;
    sender->attach(adminObs);
    sender->attach(msgObs);

    cout << "\n📢 Testing observer notifications..." << endl;
    sender->sendMessage("Regular message for everyone! 📨\n", room);

    cout << "\n🏷️ Testing mention detection..." << endl;
    sender->sendMessage("Hey @MessageListener, check this out! 👀\n", room);


    delete adminObs;
    delete msgObs;
    delete sender;
    delete listener;
    delete room;
}

void testIteratorPattern()
{
    ChatRoom *room = new CtrlCat("IteratorTest");

    User *users[] = {
        new User("Thabo"),
        new User("Drake"),
        new User("Carti"),
        new User("Owen"),
        new User("Junior")};

    cout << "👥 Adding users to room...📱" << endl;
    for (int i = 0; i < 5; i++)
    {
        users[i]->joinRoom(room);
        cout << "Added: " << users[i]->getName() << endl;
    }

    cout << "\n🔄 Testing UserIterator..." << endl;
    Iterator<User *> *userIterator = room->createUserIterator();

    cout << "Iterating through users:" << endl;
    int userCount = 0;
    for (userIterator->first(); !userIterator->isDone(); userIterator->next())
    {
        User *currentUser = userIterator->currentItem();
        if (currentUser)
        {
            cout << "User " << (userCount + 1) << ": " << currentUser->getName() << endl;
            userCount++;
        }
    }

    cout << "✅ Successfully iterated through " << userCount << " users!" << endl;

    cout << "\n💬 Creating messages for MessageIterator test..." << endl;
    users[0]->sendMessage("First message!", room);
    users[1]->sendMessage("Second message! ", room);
    users[2]->sendMessage("Third message! ", room);

    cout << "📝 Messages created and saved via commands!" << endl;

    delete userIterator;

    for (int i = 0; i < 5; i++)
    {
        delete users[i];
    }
    delete room;
}

// make docs
// make run
// make valgrind