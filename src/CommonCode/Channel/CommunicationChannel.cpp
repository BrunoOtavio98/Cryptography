#include "Channel/CommunicationChannel.h"
#include "Agent/GenericAgent.h"

namespace Channel {

CommunicationChannel::CommunicationChannel()
{
}

CommunicationChannel::~CommunicationChannel()
{
}

void CommunicationChannel::RegisterAgent(const Agent::GenericAgent &agent)
{
    agent_mailbox_[agent] = {};
}

bool CommunicationChannel::SendMessage(const Agent::GenericAgent &agent, const std::string &message)
{    
    auto agent_receivers = agent_mailbox_.find(agent);
    if(agent_receivers != agent_mailbox_.end())
    {
        auto list_receivers = agent_mailbox_[agent];
        for(auto receiver : list_receivers)
        {
            receiver.ReceiveMessage(message);
        }
    }
    return true;
}

bool CommunicationChannel::ListenToAgent(const Agent::GenericAgent &agent, const Agent::GenericAgent &agent_to_listen)
{
    auto agent_receivers = agent_mailbox_.find(agent_to_listen);
    if(agent_receivers != agent_mailbox_.end())
    {
        agent_mailbox_[agent_to_listen].push_back(agent);
        return true;
    }
    return false;
}

}