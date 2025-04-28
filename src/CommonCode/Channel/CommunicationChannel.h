#ifndef COMM_CHANNEL_H
#define COMM_CHANNEL_H

#include <map>
#include <string>
#include <list>

namespace Agent
{
class GenericAgent;
class MaliciousAgent;
}

namespace Channel {

class CommunicationChannel
{
public:
    CommunicationChannel();
    ~CommunicationChannel();
    void RegisterAgent(const Agent::GenericAgent &agent);
    void RegisterMaliciousAgent(const Agent::MaliciousAgent &malicious_agent);
    bool SendMessage(const Agent::GenericAgent &agent, const std::string &message, const std::string &agent_id_to_receive);

private:
    std::list<Agent::GenericAgent> agent_list_;
    std::list<Agent::MaliciousAgent> malicious_agent_list_;
};

}

#endif // COMM_CHANNEL_H