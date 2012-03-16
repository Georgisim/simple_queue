//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 1992-2008 Andras Varga
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

//
// Simple queueing network: generator + FIFO + sink.
//
network QueueNet
{	parameters:
    submodules:
       
        
        generator: Generator {
            parameters:
                @display("p=89,100");
        }
        queue: Queue {
            parameters:
                @display("p=209,100");
        }
        server: Server {
            parameters:
                @display("p=329,100");
        }
    connections:
        generator.out --> queue.in;
        queue.out --> server.in;
}


