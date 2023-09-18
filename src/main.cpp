#include <iostream>
#include "client-request.h"
#include "server-response.h"
#include "custom-queue.h"


int main() {
    CustomQueue queue;

    // Enqueue some ClientRequests and ServerResponses
    ClientRequest clientRequest1("m1", "C1", 10);
    ServerResponse serverResponse1("m2", "S1", "4bytes,1second");
    ClientRequest clientRequest2("m3", "C2", 15);

    queue.enqueue(clientRequest1);
    queue.enqueue(serverResponse1);
    queue.enqueue(clientRequest2);

    // Test getCountClients and getCountServers
    std::cout << "Count of Clients: " << queue.getCountClients() << std::endl; // Output: 2
    std::cout << "Count of Servers: " << queue.getCountServers() << std::endl; // Output: 1

    // Test getFront and dequeue
    std::string front = queue.getFront();
    std::cout << "Front of Queue: " << front << std::endl; // Output: "m1 C1 10"
    queue.dequeue();

    front = queue.getFront();
    std::cout << "Front of Queue after dequeue: " << front << std::endl; // Output: "m2 S1 4bytes,1second"

    // Enqueue more elements and test again
    ServerResponse serverResponse2("m4", "S2", "8bytes,2seconds");
    ClientRequest clientRequest3("m5", "C3", 20);

    queue.enqueue(serverResponse2);
    queue.enqueue(clientRequest3);

    // Test getCountClients and getCountServers again
    std::cout << "Count of Clients: " << queue.getCountClients() << std::endl; // Output: 2 
    std::cout << "Count of Servers: " << queue.getCountServers() << std::endl; // Output: 2

    // Test getFront and dequeue again
    front = queue.getFront();
    std::cout << "Front of Queue: " << front << std::endl; // Output: "m2 S1 4bytes,1second"
    queue.dequeue();

    front = queue.getFront();
    std::cout << "Front of Queue after dequeue: " << front << std::endl; // Output: "m3 C2 15"

    return 0;
}