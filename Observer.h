#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>
#include <string>

class Observer {
public:
    virtual ~Observer() {}
    
    virtual void update(const std::string& event, const std::string& data) = 0;
};

#endif