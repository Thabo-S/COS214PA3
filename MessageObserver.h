#ifndef MESSAGEOBSERVER_H
#define MESSAGEOBSERVER_H

#include "Observer.h"

class MessageObserver : public Observer {
private:
    std::string observerName;

public:
    MessageObserver(const std::string& name) : observerName(name) {}
    void update(const std::string& event, const std::string& data) override;
};


#endif