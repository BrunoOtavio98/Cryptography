#include "Agent/GenericAgent.h"
#include "Channel/CommunicationChannel.h"
#include <iostream>

namespace Agent
{

GenericAgent::GenericAgent(const std::string &agent_id, std::shared_ptr<Channel::CommunicationChannel> channel) : 
                           agent_id_(agent_id), 
                           channel_(channel) {
    channel->RegisterAgent(*this);
}

GenericAgent::~GenericAgent() {

}

void GenericAgent::ReceiveMessage(const std::string &message) {
    std::cout << "Agent: " << agent_id_ << " received message: " << message << std::endl;
}

void GenericAgent::SendMessage(const std::string &message) {
    std::cout << "Agent: " << agent_id_ << " sending message: " << message << std::endl;
    channel_->SendMessage(*this, message);
}

}