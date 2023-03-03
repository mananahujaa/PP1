#include "CircleList.h"

template<typename T>
CircleList<T>::CircleList()
{
    this->head = NULL;
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
    return head == NULL;
}

template<typename T>
void CircleList<T>::add(T data)
{
    CNode<T>* newNode = new CNode(data);

    if(head == NULL)
    {
        newNode->next = newNode;
    }
    else
    {
        newNode->next = head->next;
        head->next = newNode;
    }

    counter++;
}

template<typename T>
void CircleList<T>::remove()
{
    CNode<T>* old = head->next;
    
    if(old == head)
    {
        head = NULL;
    }
    else
    {
        head->next = old->next;
        delete old;
    }

    counter--;
}