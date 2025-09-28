#include "Subject.h"
#include "Message.h"

Subject::~Subject()
{
    clearObservers();
}

void Subject::attach(Observer *observer)
{
    if (observer)
    {
        for (Observer *existingObserver : observers)
        {
            if (existingObserver == observer)
            {
                return;
            }
        }
        observers.push_back(observer);
    }
}

void Subject::detach(Observer *observer)
{
    if (observer)
    {
        for (auto foundObserver = observers.begin(); foundObserver != observers.end(); ++foundObserver)
        {
            if (*foundObserver == observer)
            {
                observers.erase(foundObserver);
                break;
            }
        }
    }
}

void Subject::notifyObservers(const std::string &event, Message msg)
{
    for (Observer *observer : observers)
    {
        if (observer)
        {
            observer->update(event, msg.toString());
        }
    }
}

void Subject::clearObservers()
{
    observers.clear();
}