#include<iostream>
#include "Agent/GenericAgent.h"
#include "Agent/MaliciousAgent.h"
#include "Channel/CommunicationChannel.h"

using namespace Channel;
using namespace Agent;

int main()
{
    std::shared_ptr<CommunicationChannel> channel = std::make_shared<CommunicationChannel>();
    MaliciousAgent Hacker = MaliciousAgent("Hacker", channel);
    GenericAgent Joe = GenericAgent("Joe", channel);
    GenericAgent Marie = GenericAgent("Marie", channel);

    channel->RegisterMaliciousAgent(Hacker);

    Joe.SendMessage("Hello Marie", Marie.GetAgentId());

    while(true)
    {

    }

    return 0;
}