#include <iostream>
#include "client-request.h"
#include "server-response.h"
#include "custom-queue.h"

int main() {
    CustomQueue queue;

    ClientRequest clientRequest1("m1", "C1", 10);
    ServerResponse serverResponse1("m2", "S1", "4bytes,1second");
    ClientRequest clientRequest2("m3", "C2", 15);

    queue.enqueue(clientRequest1);
    queue.enqueue(serverResponse1);
    queue.enqueue(clientRequest2);

    std::cout << queue.getCountClients() << std::endl; // Output: 2
    std::cout << queue.getCountServers() << std::endl; // Output: 1

    std::string front = queue.getFront();
    std::cout << front << std::endl; // Output: "m1 C1 10"

    queue.deque();
    front = queue.getFront();
    std::cout << front << std::endl; // Output: "m2 S1 4bytes,1second"

    return {};
}