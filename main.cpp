//
//  main.cpp
//  PP1
//
//  Created by Manan Ahuja on 2/22/23.
//

#include <iostream>
using namespace std;

// Forward declaration of Queue class
template <typename T>
class Queue;

// Ticket class
class Ticket {
private:
    int number;
public:
    Ticket(int n) : number(n) {}
    int getNumber() { return number; }
    void print() { cout << "Ticket number: " << number << endl; }
};

// QueueNode class
template <typename T>
class QueueNode {
private:
    T data;
    QueueNode<T>* next;
public:
    QueueNode(T d) : data(d), next(NULL) {}
    friend class Queue<T>;
};

// Queue class
template <typename T>
class Queue {
private:
    QueueNode<T>* rear;
    int size;
public:
    Queue() : rear(NULL), size(0) {}
    
    ~Queue(){
        while(!isEmpty()){
            dequeue();
        }
    }
    
    bool isEmpty() {
        return rear == NULL;
    }
    
    int getSize() {
        return size;
    }

    //Enqueue operation
    void enqueue(T d){
        QueueNode<T>* newNode = new QueueNode<T>(d);
        if (isEmpty()) {
            rear = newNode;
            rear->next = rear;
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }
    
    // Dequeue operation
    void dequeue(){
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        QueueNode<T>* temp = rear->next;
        rear->next = temp->next;
        cout << "Ticket processed: ";
        temp->data.print();
        delete temp;
        size--;
    }
    // Print operation
    void print(){
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        QueueNode<T>* temp = rear->next;
        cout << "Queue contents: ";
        do {
            temp->data.print();
            temp = temp->next;
        } while (temp != rear->next);
    };
};




// Main function
int main() {
    // Create a ticket queue
    Queue<Ticket> ticketQueue;
    
    // Add some tickets to the queue
    Ticket t1(1), t2(2), t3(3);
    ticketQueue.enqueue(t1);
    ticketQueue.enqueue(t2);
    ticketQueue.enqueue(t3);
    
    // Process some tickets
    ticketQueue.dequeue();
    ticketQueue.dequeue();
    
    // Add more tickets to the queue
    Ticket t4(4), t5(5);
    ticketQueue.enqueue(t4);
    ticketQueue.enqueue(t5);
    
    // Process the rest of the tickets
    ticketQueue.dequeue();
    ticketQueue.dequeue();
    ticketQueue.dequeue();
    
    // Print the final state of the queue
    ticketQueue.print();
    
    return 0;
}
