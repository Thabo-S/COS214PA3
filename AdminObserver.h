#ifndef ADMINOBSERVER_H
#define ADMINOBSERVER_H

#include "Observer.h"

/**
 * @class AdminObserver
 * @brief Observer implementation for administrative notifications.
 * 
 * Monitors system events and provides administrative alerts.
 * @author Thabo Seripe, Njabulo Nhlengethwa
 * @date 25-09-2025
 */

class AdminObserver : public Observer {
public:
    void update(const std::string& event, const std::string& data) override;
};

#endif