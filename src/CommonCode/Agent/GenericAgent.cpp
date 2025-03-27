#include "Agent/GenericAgent.h"
#include "Channel/CommunicationChannel.h"
#include <iostream>

namespace Agent
{

GenericAgent::GenericAgent(const std::string &agent_id, std::shared_ptr<Channel::CommunicationChannel> channel) : 
                           agent_id_(agent_id), 
                           channel_(channel) {
    channel->RegisterAgent(*this);

    std::thread thread(&GenericAgent::ThreadFunction, this);
    thread.detach();
}

GenericAgent::~GenericAgent()
{

}

void GenericAgent::ReceiveMessage(const std::string &message, const std::string &agent_id_that_sent) 
{
    std::cout << "Agent: " << agent_id_ << " received message: " << message << " Send from: " << agent_id_that_sent <<std::endl;
}

void GenericAgent::SendMessage(const std::string &message, const std::string &agent_id_to_send) 
{
    std::cout << "Agent: " << agent_id_ << " sending message: " << message << std::endl;
    channel_->SendMessage(*this, message, agent_id_to_send);
}

void GenericAgent::ThreadFunction()
{
    while(true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(850));
    }
}

}