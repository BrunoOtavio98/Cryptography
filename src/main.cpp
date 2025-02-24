#include<iostream>
#include "Agent/GenericAgent.h"
#include "Channel/CommunicationChannel.h"

using namespace Channel;
using namespace Agent;

int main()
{
    
    std::shared_ptr<CommunicationChannel> channel = std::make_shared<CommunicationChannel>();
    GenericAgent agent1 = GenericAgent("agent1", channel);
    GenericAgent agent2 = GenericAgent("agent2", channel);
    GenericAgent agent3 = GenericAgent("agent3", channel);
    GenericAgent agent4 = GenericAgent("agent4", channel);
    GenericAgent agent5 = GenericAgent("agent5", channel);
    GenericAgent agent6 = GenericAgent("agent6", channel);
    GenericAgent agent7 = GenericAgent("agent7", channel);

    channel->ListenToAgent(agent1, agent2);
    channel->ListenToAgent(agent3, agent2);
    channel->ListenToAgent(agent4, agent2);
    channel->ListenToAgent(agent5, agent2);
    channel->ListenToAgent(agent6, agent2);

    channel->ListenToAllAgents(agent7);

    agent2.SendMessage("Hello from agent2\n");

    agent1.SendMessage("Hello from agent1\n");
    agent3.SendMessage("Hello from agent3\n");
    agent4.SendMessage("Hello from agent4\n");
    agent5.SendMessage("Hello from agent5\n");
    agent6.SendMessage("Hello from agent6\n");

    return 0;
}