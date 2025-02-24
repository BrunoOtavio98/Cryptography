#include<iostream>
#include "Agent/GenericAgent.h"
#include "Channel/CommunicationChannel.h"

using namespace Channel;
using namespace Agent;

int main()
{
    std::shared_ptr<CommunicationChannel> channel = std::make_shared<CommunicationChannel>();
    GenericAgent Joe = GenericAgent("Joe", channel);
    GenericAgent Marie = GenericAgent("Marie", channel);
    GenericAgent Hacker = GenericAgent("Hacker", channel);

    channel->ListenToAgent(Joe, Marie);
    channel->ListenToAgent(Marie, Joe);
    channel->ListenToAllAgents(Hacker);

    Marie.SendMessage("Hello from Marie\n", Joe.GetAgentId());
    Joe.SendMessage("Hello from Joe\n", GenericAgent::GetBroadcastId());
    return 0;
}