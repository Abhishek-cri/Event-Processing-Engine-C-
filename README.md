#  Event Processing Engine (C++)

A multithreaded **Event Processing Engine** built in **C++17** that demonstrates the core concepts of:
- Event-Driven Architecture
- Producer-Consumer Pattern
- Thread Synchronization
- Runtime Polymorphism
- Observer Design Pattern

The system allows producers to publish events into a **thread-safe blocking queue**, while subscribed consumers process those events asynchronously.
---

##  Features
 Thread-safe Blocking Queue using mutex and conditional_variable

 Producer-Consumer Architecture
 Event-Driven Design
 Observer Pattern for event subscription
 Runtime Polymorphism using interfaces
 Asynchronous event processing using threads
 FIFO event processing
 Extensible consumer framework

---

##  High-Level Architecture

```text
                +-----------+
                | Producer  |
                +-----------+
                      |
                      v
            +-------------------+
            |  Blocking Queue   |
            +-------------------+
                      |
                      v
            +-------------------+
            | Event Processor   |
            +-------------------+
                      |
          +-----------+-----------+
          |                       |
          v                       v
+----------------+     +----------------+
| Notification   |     |   Analytics    |
|   Consumer     |     |    Consumer    |
+----------------+     +----------------+
```

---

##  Event Flow

```text
OrderCreated Event
        |
        v
+-------------------+
|  Blocking Queue   |
+-------------------+
        |
        v
+-------------------+
| Event Processor   |
+-------------------+
        |
        +------> Notification Consumer
        |
        +------> Analytics Consumer
```

---

## Components

### Event
Represents a business event containing:
- Event ID
- Event Type
- Payload

Example:

```cpp
Event(
    "1",
    "OrderCreated",
    "Order #101 Created"
);
```

---

### Producer

Responsible for publishing events into the Blocking Queue.

```cpp
producer.publish(event);
```

---

### Blocking Queue

A thread-safe queue implementation that:

- Prevents race conditions using mutexes
- Uses condition variables for efficient waiting
- Supports FIFO processing
- Blocks consumers when no events are available

---

### Event Processor

Continuously:

1. Consumes events from the Blocking Queue
2. Dispatches events to all subscribed consumers
3. Runs on a dedicated worker thread

---

### Consumers

Consumers subscribe to the Event Processor and react to incoming events.

Implemented Consumers:

- Notification Consumer
- Analytics Consumer

Adding a new consumer requires **no changes** to the Event Processor.

---

##  Design Patterns Used

| Pattern | Purpose |
|----------|----------|
| Observer Pattern | Consumer subscription mechanism |
| Producer-Consumer Pattern | Asynchronous event handling |
| Interface-based Polymorphism | Extensible consumer design |
| Blocking Queue Pattern | Safe inter-thread communication |

---

## Concepts Demonstrated

- C++ Templates
- OOP Principles
- SOLID Principles
- Runtime Polymorphism
- Multithreading
- Mutexes
- Condition Variables
- Thread Synchronization
- Event-Driven Architecture
- Concurrent Programming

---

## Technologies

- C++17
- STL
- `std::thread`
- `std::mutex`
- `std::condition_variable`
- `std::queue`
- `std::vector`

---

## 📚 Learning Outcomes

This project was built to gain hands-on experience with:

- Thread-safe data structures
- Synchronization primitives
- Event-driven systems
- Concurrent programming in C++
- Design patterns used in distributed systems

---

## Future Enhancements

- Topic-based subscriptions
- Thread Pool
- Consumer Groups
- Retry Mechanism
- Dead Letter Queue (DLQ)
- Event Persistence
- Priority-Based Events
- Event Filtering
- Metrics & Monitoring

---

## Inspiration

This project is inspired by real-world event processing systems such as:

- Apache Kafka
- RabbitMQ
- AWS EventBridge
- Google Pub/Sub

while keeping the implementation lightweight and focused on core C++ concepts.

---
