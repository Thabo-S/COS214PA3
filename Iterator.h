#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>
#include "User.h"
#include "Message.h"

/**
 * @class Iterator
 * @brief Abstract iterator for traversing collections (Iterator pattern).
 * @author Your Name
 * @date 25-09-2025
 */

template<typename T>
class Iterator {
public:
    virtual ~Iterator() {}
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual T currentItem() const = 0;
};

#endif