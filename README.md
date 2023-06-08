<img src="./media/Honeywell_Spot_Red+BlackTagline_Right_PNG.png" alt="Honeywell Logo" />

## Hello #FutureShaper
I am glad that you passed the first stages of the interview process 🎉🥳. Now is the time to show us what you got! 

# Problem description:
There are two classes of messages in a particular network: *ServerResponse* and *ClientRequest*. Both inherit the *Message* class.

```cpp
class Message {
public:
    string messageId;
    Message(){}
};

class ServerResponse : public Message{
public:
    string serverId;
    string metadata;
    ServerResponse(string messageId, string serverId, string metadata){
        this->messageId = messageId;
        this->serverId = serverId;
        this->metadata = metadata;
    }
};

class ClientRequest : public Message{
public:
    string clientId;
    int requestTime;
    ClientRequest(string messageId, string clientId, int requestTime){
        this->messageId = messageId;
        this->clientId = clientId;
        this->requestTime = requestTime;
    }
};
```
Implement a *customQueue* that supports *enqeue* and *deque* operations for both types. Basically, it should support 4 operations.

- *void enqeueue(ServerResponse e)*: Returns nothing and enqueues the element *e* at the end of the queue.
- *void enqeueue(ClientRequest e)*: Returns nothing and enqueues the element *e* at the end of the queue.
- *void deque()*: Returns nothing and deletes the front element of the queue.
- *string getFront()*: Returns the front element of the queue as a string. 
    - If the front element is a ServerResponse then the output string should be formatted as <*messageId*> <*serverId*> <*metadata*>.
    - If the front element is a ClientRequest then the output string should be formatted as <*messageId*> <*clientId*> <*requestTime*>.
Note that different words in *getFront()* are separated by a single space. It is guaranteed that all the queries are valid.

Example
Consider the following 5 queries
1. Enqueue a ClientRequest with *messageId* = "m1", *clientId* = "C1" and *requestTime* = 10
2. Enqueue a ServerRequest with *messageId* = "m2", *serverId* = "S1" and *metadata* = "4bytes,1second"
3. Get the front element.
4. Pop.
5. Get the front element.
 

The output for the third query is "m1 C1 10" and for the fifth query, "m2 S1 4bytes,1second".

Constraints

- 2 ≤ number of queries ≤ 1000
- 3 ≤ length of each query string ≤ 100
- 1 ≤ |*messageId*|  ≤ 50
- 1 ≤ |*clientId*|  ≤ 50
- 1 ≤ |*serverId*|  ≤ 50
- 1 ≤ |*metadata*|  ≤ 50
- 1 ≤ *requestTime*  ≤ 1000
- It is guaranteed that there is at least one "*Top*" query.

# Submission
- You should submit your code in a GitHub fork repository
-	Commit as much as you want, remember to show good practices. 
- Try to code as clean as possible. Think of it as if you were tasked in real life.

Good Luck!