#ifndef GENERIC_AGENT_H
#define GENERIC_AGENT_H

#include <memory>
#include <string>

namespace Channel {
    class CommunicationChannel;
}

namespace Agent {

class GenericAgent
{
public:
    GenericAgent(const std::string &agent_id, std::shared_ptr<Channel::CommunicationChannel> channel);
    ~GenericAgent();

    GenericAgent(const GenericAgent &other) = default;

    GenericAgent& operator=(const GenericAgent &other) = default;
    GenericAgent(GenericAgent &&other) = default;
    GenericAgent& operator=(GenericAgent &&other) = default;

    std::string GetAgentId() const { return agent_id_; }
    void ReceiveMessage(const std::string &message);
    void SendMessage(const std::string &message);

    bool operator<(const GenericAgent &other) const {
        return this->agent_id_ < other.agent_id_;
    }

private:
    std::string agent_id_;
    std::shared_ptr<Channel::CommunicationChannel> channel_;
};

}

#endif // GENERIC_AGENT_H