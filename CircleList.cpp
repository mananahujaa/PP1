#include "iostream"
#include "CircleList.h"

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
    if(this->front == NULL)
    {
        cout << "empty";
        return;
    }


}

template<typename T>
void CircleList<T>::remove()
{

}

template<typename T>
void CircleList<T>::printQ()
{
    CNode<T>* temp = this->front;
    if(!empty())
    {
        cout << endl << "Queue:" << endl;
        while(temp->next != this->front)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
    }
}



//https://www.geeksforgeeks.org/circular-linked-list-implementation-of-circular-queue/