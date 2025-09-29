#ifndef USERITERATOR_H
#define USERITERATOR_H

#include "Iterator.h"

/**
 * @class UserIterator
 * @brief Concrete iterator for traversing user collections.
 * 
 * Implements iterator pattern for sequential access to
 * collections of User objects.
 * @author Thabo Seripe, Njabulo Nhlengethwa
 * @date 25-09-2025
 */

class UserIterator : public Iterator<User*> {
private:
    std::vector<User*>::iterator current;
    std::vector<User*>::iterator end;
    std::vector<User*> users;

public:
    UserIterator(const std::vector<User*>& userList);
    void first() override;
    void next() override;
    bool isDone() const override;
    User* currentItem() const override;
};

#endif