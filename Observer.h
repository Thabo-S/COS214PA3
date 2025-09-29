#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>
#include <string>

/**
 * @class Observer
 * @brief Abstract observer interface (Observer pattern).
 * 
 * Defines interface for objects that should be notified
 * of changes in subjects they observe.
 * @author Thabo Seripe, Njabulo Nhlengethwa
 * @date 25-09-2025
 */

class Observer {
public:
    virtual ~Observer() {}
    
    virtual void update(const std::string& event, const std::string& data) = 0;
};

#endif