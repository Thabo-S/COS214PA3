#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"

class Subject {
private:
    std::vector<Observer*> observers;

public:
    virtual ~Subject();
    
    void attach(Observer* observer);
    void detach(Observer* observer);
    virtual void notifyObservers(const std::string& event, const std::string& data);

    void clearObservers();
};

#endif