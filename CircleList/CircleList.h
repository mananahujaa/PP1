#include "cstddef"
#include "string"

#ifndef CircleList_H
#define CircleList_H

using namespace std;

template <typename T>
class CNode{                          //Circular Linked List implementation
public:
    T data;                             //DATA to be stored in a node
    CNode* next;                        // next node pointer

    CNode(T data){                //Constructor
        this->data = data;
        this->next = NULL;
    }
    template<typename U>
    friend class CircleList;         //FRIEND CLASS for CLL implementation
    
};

template <typename T>
class CircleList
{
    private:
    CNode<T>* front;
    CNode<T>* rear;
    
    public:
    int counter;
    CircleList();
    ~CircleList();
    bool empty() const;
    void add(T data);
    void remove();
    void printQ();

    // Function based on employee data

    bool employeeAuth(string username, string password);
};

#endif