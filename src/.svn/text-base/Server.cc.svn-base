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

#include "Server.h"

namespace simple_queue {

Define_Module(Server);

Server::Server()
{

}

Server::~Server()
{

}

void Server::initialize()
{
    Latency.setName("Latengy");

}

void Server::finish()
{
	Latency.record();
}




void Server::handleMessage(cMessage *msg)
{
	if (msg->isSelfMessage()) {
		ASSERT(0);
	} else {
		Latency.collect( msg->getArrivalTime() - msg->getCreationTime());
		delete msg;
	}
}


}; // namespace
