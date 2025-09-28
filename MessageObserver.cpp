#include "MessageObserver.h"
#include <iostream>

void MessageObserver::update(const std::string &event, const std::string &data)
{
    std::cout << "[" << observerName << " Observer] " << event << ": " << data << std::endl;
}