#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"

/**
 * @class Subject
 * @brief Abstract subject interface (Observer pattern).
 * 
 * Manages observer registration and notification for
 * objects that need to notify observers of state changes.
 * @author Thabo Seripe, Njabulo Nhlengethwa
 * @date 25-09-2025
 */

class Message;

class Subject
{

public:

    std::vector<Observer *> observers;

    virtual ~Subject();

    void attach(Observer *observer);
    void detach(Observer *observer);

    virtual void notifyObservers(const std::string &event, Message msg);

    void clearObservers();
};

#endif