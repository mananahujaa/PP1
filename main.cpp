//
//  main.cpp
//  PP1
//
//  Created by Manan Ahuja on 2/22/23.
//

#include <iostream>
#include <string>

using namespace std;  //Using standards


class TheatersInArea{               //class to see theaters in a certain area
public:
    string Moviename;               //movie names showing now
    string Theatername;             //theaters showing movies
    string Movietime;               //time of movie
};

class Theater : public TheatersInArea {
public:                             //particular theater name
    int NumSeats;                   //num of seats in theater
    
};



typedef string Elem ;
class CNode{                          //Circular Linked List implementation
public:
    Elem data;                       //DATA to be stored in a node
    CNode* next;                     //next node
    CNode(Elem data){                //Constructor
        this-> data=data;
        this->next=NULL;
    }
    friend class CircleList;         //FRIEND CLASS for CLL implementation
    
};

class CircleList{
private:
    CNode* head;            //head node(cursor)
    
public:
    CircleList() : head(NULL){};        //constructor
    
    ~CircleList(){                      //destructor
        while(!empty()){
            remove();
        }
    }
        
    bool empty(){                       //check if list empty
        return head==NULL;
    }
    
    const Elem& peek(){                 //peek a particular node
        return head->data;
    }
    
    const Elem& nxtpeek(){              //peek next node
        return head->next->data;
    }
    
    void advnode(){                     //move node to next
        head=head->next;
    }
    
    void add(const Elem& e) {           //add node
        CNode* NewNode = new CNode(e);
        
        
        if (head == NULL) {            //if NULL return new node = head
            NewNode->next = NewNode;
            head = NewNode;
        }
        else {
            NewNode->next = head->next;     //head->NewNode->next(which was previously head->next)
            head->next = NewNode;
            
        }
    }
    
    void remove(){         //remove node
        CNode* old = head->next;
        if (old == head){
            head = NULL;
        }
        else
            head->next = old->next; delete old;
    }
    
};

typedef string Elem;
class LinkedQueue{
    
private:
    CircleList C;
    int num;
    
public:
    
    LinkedQueue(): C(), num(0) {};
    
    
    
    int size() {
        return num;
    }
    
    bool empty() const{
        return num == 0;
    }
    
    const Elem& nxtpeek() {
        if(empty()){
         // add a return can't figure out what to return
        }
        
        return C.nxtpeek();
    }
    
    void EnQ(const Elem& newdata){
        C.add(newdata);
        C.advnode();
        num++;
        
    }
    
    void DeQ(){
        if (empty()){
            // add a return can't figure out what to return
        }
        C.remove();
        num--;
    }
    
    
};
