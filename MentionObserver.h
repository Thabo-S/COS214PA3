#ifndef MENTIONOBSERVER_H
#define MENTIONOBSERVER_H

#include "Observer.h"

class MentionObserver : public Observer {
private:
    std::string usernameToWatch;

public:
    MentionObserver(const std::string& username) : usernameToWatch(username) {}
    void update(const std::string& event, const std::string& data) override;
};

#endif