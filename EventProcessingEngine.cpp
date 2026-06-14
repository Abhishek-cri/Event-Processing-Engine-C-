#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>

using namespace std;


class Event {
    private:
      string eventId;
      string eventType;
      string payload;
    public:
      Event (string eventId, string eventType, string payload) : 
      eventId(eventId),
      eventType(eventType), 
      payload(payload)  {}
      
      string getEventType(){
          return eventType;
      }
      
      string getEventPayload(){
          return payload;
      }
};

class ConsumerInterface{
    
    public:
       
       virtual void process(Event & event){};
       ~ConsumerInterface()= default;
};

class ConsumeAnalytics: public ConsumerInterface{
    
    public:
      void process(Event & event) override {
          
          cout<< "Analytics []"<<endl;
          cout<<event.getEventPayload()<<endl;

      }
    
};

class ConsumeNotification: public ConsumerInterface{
    
    public:
      
      void process(Event & event){
          cout<<" Notification []"<<endl;
          cout<<event.getEventPayload()<<endl;
      }
    
    
};
template<typename T>
class BlockingQueue{
    private:
      queue<T>q;
      mutex mtx;
      condition_variable cv;
      
    public:
      
      void push(T item){
          unique_lock<mutex> lock(mtx);
          q.push(item);
          cv.notify_one();
          
      }
      
      T pop(){
          unique_lock<mutex> lock(mtx);
          cv.wait(lock, [this]{
              return !q.empty();
          }
          );
          
          T item = q.front();
          q.pop();
          
          return item;
      }
};

class Producer {
    private:
      BlockingQueue<Event> & queue;
      
    public:
      Producer(BlockingQueue<Event> & queue) : queue(queue){};
      
      void publish(Event event){
          queue.push(event);
      }
};


class EventProcessor {
    private:
      BlockingQueue<Event> & queue;
      vector<ConsumerInterface *>customers;
      
    public:
      EventProcessor(BlockingQueue<Event> & queue) : queue(queue){}
      
      void subscribe(ConsumerInterface * customer) {
          customers.push_back(customer);
      }
      
      void start(){
          while(true){
              Event event = queue.pop();

              
              for(auto & customer : customers){
                  customer->process(event);
              }
          }
      }
};



int main() {
    
    BlockingQueue<Event>queue;
    
    Producer producer(queue);
    
    EventProcessor eventProcess(queue);
    
  ConsumeNotification notification;
  ConsumeAnalytics analytics;
    
    eventProcess.subscribe(&notification);
    eventProcess.subscribe(&analytics);
    
    thread worker([&] () {
        eventProcess.start();
    });
    
       producer.publish(
        Event(
            "1",
            "OrderCreated",
            "Order #101 Created"
        )
    );

    producer.publish(
        Event(
            "2",
            "PaymentSuccess",
            "Payment Successful"
        )
    );
 worker.join();
    
    
    return 0;
}