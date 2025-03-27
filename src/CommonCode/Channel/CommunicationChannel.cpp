#include "Channel/CommunicationChannel.h"
#include "Agent/GenericAgent.h"
#include "Agent/MaliciousAgent.h"

namespace Channel {

CommunicationChannel::CommunicationChannel()
{
}

CommunicationChannel::~CommunicationChannel()
{
}

void CommunicationChannel::RegisterAgent(const Agent::GenericAgent &agent)
{
    agent_list_.push_back(agent);    
}

void CommunicationChannel::RegisterMaliciousAgent(const Agent::MaliciousAgent &malicious_agent)
{
    malicious_agent_list_.push_back(malicious_agent);
}

bool CommunicationChannel::SendMessage(const Agent::GenericAgent &agent, const std::string &message, const std::string &agent_id_to_receive)
{      
    std::string final_message = message;
    
    if( malicious_agent_list_.size() )
    {
        for (auto &malicious_agent : malicious_agent_list_)
        {
            malicious_agent.InterceptMessage(final_message, agent.GetAgentId(), agent_id_to_receive);
        }
    }

    for (auto &current_agent : agent_list_)
    {   
        if(agent_id_to_receive == current_agent.GetAgentId() )
        {
            current_agent.ReceiveMessage(final_message, agent.GetAgentId());
        }
    }
    return true;
}

}