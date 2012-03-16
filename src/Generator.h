//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#ifndef __GENERATOR_H__
#define __GENERATOR_H__

#include <omnetpp.h>

#include "Packet_m.h"


namespace simple_queue {


class Generator : public cSimpleModule
{
private:
	cMessage* timerMessage;
	long double inter_arrival_time;

protected:
	virtual void initialize();
	virtual void finish();
	virtual void handleMessage(cMessage *msg);

	void sendMessage(cMessage *msg, simtime_t delay, const char *gatename);


	void handleTimerMessage(cMessage *msg);


public:
	Generator();
	virtual ~Generator();


};

}; // namespace

#endif
