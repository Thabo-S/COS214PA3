#include "UserIterator.h"

UserIterator::UserIterator(const std::vector<User *> &userList)
    : users(userList)
{
    current = users.begin();
    end = users.end();
}

void UserIterator::first()
{
    current = users.begin();
}

void UserIterator::next()
{
    if (!isDone())
    {
        ++current;
    }
}

bool UserIterator::isDone() const
{
    return current == end;
}

User *UserIterator::currentItem() const
{
    if (!isDone())
    {
        return *current;
    }
    return nullptr;
}