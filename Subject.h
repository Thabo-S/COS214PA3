#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"

class Message;

class Subject
{
private:
public:
    // YOU HAD THE MADE THE OBSERVER LIST PUBLIC BRUH
    std::vector<Observer *> observers;

    virtual ~Subject();

    void attach(Observer *observer);
    void detach(Observer *observer);

    // ALSO CHANGE THE NOTIFY TO RECIEVE A MASSEGE OBJECT
    // INSTEAD OF THE STRING 👁️👄👁️
    virtual void notifyObservers(const std::string &event, Message msg);

    void clearObservers();
};

#endif