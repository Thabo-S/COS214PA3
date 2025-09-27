#ifndef ADMINOBSERVER_H
#define ADMINOBSERVER_H

#include "Observer.h"

class AdminObserver : public Observer {
public:
    void update(const std::string& event, const std::string& data) override;
};

#endif