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
// You should have handle a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#include "Generator.h"

namespace simple_queue {

Define_Module(Generator);

Generator::Generator()
{

}

Generator::~Generator()
{

}

void Generator::initialize()
{
	timerMessage = new cMessage("timer");
	scheduleAt(simTime(), timerMessage);
}

void Generator::finish()
{
	cancelAndDelete(timerMessage);
}


void Generator::handleTimerMessage(cMessage *msg)
{
	Packet * pPacket = new Packet ("Packet");

	scheduleAt(simTime() +  par("inter_arrival_time").doubleValue(), timerMessage);
	sendMessage(pPacket, 0, "out");
}

void Generator::sendMessage(cMessage *msg, simtime_t tx_time, const char *gatename)
{
	sendDelayed(msg, 0, gatename);
}


void Generator::handleMessage(cMessage *msg)
{
	if (msg->isSelfMessage()) {
		handleTimerMessage(msg);
	} else {
		ASSERT(0);
	}
}


}; // namespace
