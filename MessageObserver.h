#ifndef MESSAGEOBSERVER_H
#define MESSAGEOBSERVER_H

#include "Observer.h"

/**
 * @class MessageObserver
 * @brief Observer implementation for message notifications.
 * 
 * Monitors message events and provides customized notifications.
 * @author Thabo Seripe, Njabulo Nhlengethwa
 * @date 25-09-2025
 */

class MessageObserver : public Observer {
private:
    std::string observerName;

public:
    MessageObserver(const std::string& name) : observerName(name) {}
    void update(const std::string& event, const std::string& data) override;
};


#endif