# Event-Processing-Engine-C-
A multithreaded Event Processing Engine built in C++ that demonstrates the core concepts of Event-Driven Architecture, Producer-Consumer Pattern, Thread Synchronization, and Runtime Polymorphism.  The system allows producers to publish events into a thread-safe blocking queue while consumer services subscribe to and process those events asynchronously.

Features
Thread-safe Blocking Queue using std::mutex and std::condition_variable
Producer-Consumer Architecture
Event-Driven Design
Observer Pattern for event subscription
Runtime Polymorphism using interfaces
Asynchronous event processing using std::thread
FIFO event processing
Extensible consumer framework


Architecture (High Level)

Producer
    |
    v
+------------------+
| Blocking Queue   |
+------------------+
    |
    v
+------------------+
| Event Processor  |
+------------------+
    |
    +----> Notification Consumer
    |
    +----> Analytics Consumer

    Components
Event

Represents a business event containing:

Event ID
Event Type
Payload
Producer

Publishes events into the blocking queue.

Blocking Queue

A thread-safe queue implementation that:

Prevents race conditions using mutexes
Uses condition variables to efficiently block consumers when no events are available
Supports FIFO processing
Event Processor

Continuously consumes events from the queue and dispatches them to subscribed consumers.

Consumers

Independent services that react to events:

Notification Consumer
Analytics Consumer
Concepts Demonstrated
C++ Templates
OOP & SOLID Principles
Observer Design Pattern
Producer-Consumer Pattern
Multithreading
Mutexes
Condition Variables
Thread Synchronization
Runtime Polymorphism
Event-Driven Architecture


Low Level Design

OrderCreated Event
        |
        v
Blocking Queue
        |
        v
Event Processor
        |
        +----> Notification Consumer
        |
        +----> Analytics Consumer
Technologies
C++17
STL
std::thread
std::mutex
std::condition_variable
