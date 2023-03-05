#include "iostream"
#include "string.h"
#include "CircleList.h"
#include "../User/User.h"

using namespace std;

template<typename T>
CircleList<T>::CircleList()
{
    this->front = NULL;
    this->rear = NULL;
    this->counter = 0;
}

template<typename T>
CircleList<T>::~CircleList()
{
    while (!empty())
    {
        remove();
    }
}

template<typename T>
bool CircleList<T>::empty() const
{
    return this->front == NULL;
}

template<typename T>
void CircleList<T>::add(T data)
{
    CNode<T>* newNode = new CNode<T>(data);
    if (empty()) {
        this->front = newNode;
        this->rear = newNode;
        newNode->next = this->front;
    }
    else {
        newNode->next = this->front;
        this->rear->next = newNode;
        this->rear = newNode;
    }
    this->counter++;
}

template<typename T>
void CircleList<T>::remove()
{
    if (empty()) {
        cout << "The queue is empty!" << endl;
        return;
    }
    if (this->front == this->rear) { // only one node in the queue
        delete this->front;
        this->front = NULL;
        this->rear = NULL;
        this->counter--;
        return;
    }
    CNode<T>* temp = this->front;
    this->front = temp->next;
    this->rear->next = this->front;
    delete temp;
    this->counter--;
}

template<typename T>
void CircleList<T>::printQ()
{
    if (empty()) {
        cout << "The queue is empty!" << endl;
        return;
    }

    CNode<T>* temp = this->front;
    cout << "Queue: ";
    do {
        cout << temp->data->getName() << " -> ";
        temp = temp->next;
    } while (temp != this->front);
    cout << endl;
}

// Employee based functions for Circular LinkedList

template<typename T>
bool CircleList<T>::employeeAuth(string username, string password)
{
    CNode<T>* curr = this->front;
    while(curr != NULL)
    {
        Employee* emp = dynamic_cast<Employee*>(curr->data);
        if (emp != nullptr && emp->getUsername() == username && emp->password == password)
        {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

