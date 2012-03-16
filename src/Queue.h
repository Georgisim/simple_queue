/*
 * Buffer.h
 *
 *  Created on: 2009-11-1
 *      Author: George
 */

#ifndef Queue_H_
#define Queue_H_

#include <omnetpp.h>

#include "Packet_m.h"

namespace simple_queue {


class Queue : public cSimpleModule
{
private:
	int queue_length;
	cMessage* timerMessage;
	long double inter_arrival_time;

	bool bServerBusy;
	cQueue *queue;

public:
	Queue();
	virtual ~Queue();

protected:
	virtual void initialize();
	virtual void finish();
	virtual void handleMessage(cMessage *msg);
	virtual void UpdateDisplay(int count);
	void handleTimerMessage(cMessage *msg);
	cStdDev Lenght;
};

}; // namespace switch4x

#endif /* Queue_H_ */
