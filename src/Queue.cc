/*
 * Queue
 *
 *  Created on: 2011-26-1
 *      Author: George
 */

#include "Queue.h"

namespace simple_queue {

Define_Module(Queue);

Queue::Queue()
{

}

Queue::~Queue()
{
	// delete queue;
}

void Queue::initialize()
{
	queue_length = par("queue_length").longValue();
	queue = new cQueue;

	Lenght.setName("queque lenght");

	timerMessage = new cMessage("timer");
	scheduleAt(simTime(), timerMessage);
}

void Queue::finish()
{
	Lenght.record();
	cancelAndDelete(timerMessage);
}



void Queue::UpdateDisplay(int count)
{
	char buffer[20];

	cDisplayString dispStr = getDisplayString();
	sprintf(buffer, "%d packets", count);
	dispStr.setTagArg("t", 0, buffer);
	if(count == queue_length) {
		dispStr.setTagArg("i2", 0, "status/busy");
		dispStr.setTagArg("i", 1, "red");
	}
	setDisplayString(dispStr);
}

void Queue::handleTimerMessage(cMessage *msg)
{
	Packet *pPacket;

	if(!queue->empty()) {
		pPacket = (Packet *)queue->pop();
		UpdateDisplay(queue->getLength());
		sendDelayed(pPacket, 0, "out");
	}

	Lenght.collect(queue->getLength());

	scheduleAt(simTime() + par("inter_arrival_time").doubleValue(), timerMessage);
}

void Queue::handleMessage(cMessage *msg)
{
	if (msg->isSelfMessage()) { // server process
		handleTimerMessage(msg);
	} else { // arrival process
			msg->setTimestamp();
			queue->insert(msg);
			UpdateDisplay(queue->getLength());
			Lenght.collect(queue->getLength());
	}
}

}; // namespace
