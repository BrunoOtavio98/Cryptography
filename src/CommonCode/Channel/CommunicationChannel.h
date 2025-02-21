#ifndef COMM_CHANNEL_H
#define COMM_CHANNEL_H

#include <map>
#include <string>
#include <list>

namespace Agent
{
class GenericAgent;    
}

namespace Channel {

class CommunicationChannel
{
public:
    CommunicationChannel();
    ~CommunicationChannel();
    void RegisterAgent(const Agent::GenericAgent &agent);
    bool SendMessage(const Agent::GenericAgent &agent, const std::string &message);
    bool ListenToAgent(const Agent::GenericAgent &agent, const Agent::GenericAgent &agent_to_listen);

private:
    std::map<Agent::GenericAgent, std::list<Agent::GenericAgent>> agent_mailbox_;
};

}

#endif // COMM_CHANNEL_H