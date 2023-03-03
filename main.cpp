//
//  main.cpp
//  PP1
//
//  Created by Manan Ahuja on 2/22/23.
//Project partners- Manan Ahuja and Arwin Swapna

#include <iostream>
using namespace std;

// Forward declaration of Queue class
template <typename T>
class Queue;

//Movie theaters in area
class TheatersInArea{               //class to see theaters in a certain area
public:
    string Moviename;               //movie names showing now
    string Theatername;             //theaters showing movies
    string Movietime;               //time of movie
    string NextMovietime;
    
    void setMovieName(string Moviename){  //set Movie Name
        cin>>Moviename;
    }
    
    string getMovieName(){              //get Movie Name
        return Moviename;
    }
    
    void setTheaterName(string Theatername){        //set Movie Theater
        cin>>Theatername;
    }
    
    string getTheaterName(){                    //get Movie Theater
        return Theatername;
    }
    
    void setMovieTime(string Movietime){            //set Movie Time
        cin>>Movietime;
    }
    
    string getMovieTime(){          //get Movie Time
        return Movietime;
    }
    
    void setNextMovieTime(string NextMovietime){            //set Next Movie Time
        cin>>NextMovietime;
    }
    
    string getNextMovieTime(){      //get Next Movie Time
        return NextMovietime;
    }
};

//particular theater
class Theater : public TheatersInArea {
public:                             //particular theater name
    int NumSeats;                   //num of seats in theater
    void setNumOfSeats(string NumSeats){            //set number of seats in the theater
        cin>>NumSeats;
    }
    
    int getNumOfSeats(){
        return NumSeats;
    }
};

// Ticket class
class Ticket: public Theater {
private:
    int number;
public:
    Ticket(int n) : number(n) {}
    int getNumber() {
        return number;
        
    }
    void print() {
        cout << "Ticket number: " << number << endl;
        
    }
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

