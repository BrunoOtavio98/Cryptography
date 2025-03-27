#include "Agent/MaliciousAgent.h"
#include "Channel/CommunicationChannel.h"

#include <list>
#include <string>
#include <iostream>

namespace   Agent
{

MaliciousAgent::MaliciousAgent( const std::string &agent_id, std::shared_ptr<Channel::CommunicationChannel> channel ) : 
                                GenericAgent(agent_id, channel)
{
}

MaliciousAgent::~MaliciousAgent()
{
}

void MaliciousAgent::ReceiveMessage(const std::string &message, const std::string &agent_id_that_sent) 
{
    std::cout << "Malicious: " << GetAgentId() << " intercepted: " << message << " from: " << agent_id_that_sent <<std::endl;
}

void MaliciousAgent::InterceptMessage(std::string &message, const std::string &sender_id, const std::string &receiver_id)
{   
    std::cout << "Malicious: " << GetAgentId() << " is intercepting a message from " << sender_id << " to " << receiver_id << std::endl;
    message += " 1234567890";
}

void MaliciousAgent::ThreadFunction()
{   
    while(true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(850));
    }
}

}