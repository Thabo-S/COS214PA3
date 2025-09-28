#include "AdminObserver.h"
#include <iostream>

void AdminObserver::update(const std::string &event, const std::string &data)
{
    std::cout << "[ADMIN ALERT] " << event << ": " << data << std::endl;
}