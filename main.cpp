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
    int counter;
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
        CNode* NewNode = new CNode(e);      //create new node with value
        
        
        if (head == NULL) {            //if NULL return new node = head
            NewNode->next = NewNode;
            head = NewNode;
        }
        else {
            NewNode->next = head->next;     //head->NewNode->next(which was previously head->next)
            head->next = NewNode;
            
        }
        counter++;      //count increased
    }
    
    void remove(){         //remove node
        CNode* old = head->next;            //store value of next of head
        if (old == head){                   //if list only has head, delete
            head = NULL;
        }
        else
            head->next = old->next;             //now head->next will be head->next->next
        delete old;                             //delete the value of head->next
       
        counter--;                              //count is reduced
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
    
int main(){
TheatersInArea New_Delhi;
    New_Delhi.setMovieName("Top Gun");
    New_Delhi.setTheaterName("PVR");
    New_Delhi.setMovieTime("12:30p.m");
    New_Delhi.setNextMovieTime("3:30p.m");
    
    //pseudo code
/* set num of seats for the particular theater you're working on.
 For each show start adding people in a queue as it is a first-come-first serve theater.
 if counter (inClinkedLists) == numseats(in Theater) then return list is filled.
 when list is filled, the next entry will be given the first spot in the queue for next movie time.
 
 */
        
        
        
        
        
        
    return 0;
}

