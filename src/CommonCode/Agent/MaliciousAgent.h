#ifndef MALICIOUNS_AGENT_H
#define MALICIOUS_AGENT_H

#include "Agent/GenericAgent.h"

namespace Agent
{

class MaliciousAgent : public GenericAgent
{
public:
    MaliciousAgent(const std::string &agent_id, std::shared_ptr<Channel::CommunicationChannel> channel);
    ~MaliciousAgent();
    void ReceiveMessage(const std::string &message, const std::string &agent_id_that_sent) override;
    void InterceptMessage(std::string &message, const std::string &sender_id, const std::string &receiver_id);

protected:
    void ThreadFunction() override;
};

}

#endif // MALICIOUS_AGENT_H