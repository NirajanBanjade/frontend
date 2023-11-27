/*
Assignment: 4
filename: Movestack.cpp
Nirajan Banjade
Due: Nov 31,2023
*/

#include "Movestack.h"
#include <iostream>
#include <cassert>

using namespace std;

Movestack::Movestack(){
    count=0;
    head=nullptr;
}

bool Movestack::isEmpty() const{
    return count==0;
}

void Movestack::push(Move cordinate){
    Move *temp=new Move(cordinate.x,cordinate.y);
    if(isEmpty()){
        head=temp;
    }
    else{
        temp->next=head;
        head=temp;
    }
    count=count+1;
       
}
void Movestack::pop(){
    assert(!isEmpty());
    Move *holder=head;
    head=head->next;
    count=count-1;
    delete holder;
}
int Movestack::getSize(){
    return count;
}

Movestack::~Movestack(){
    while(!isEmpty()){
        pop();
    }
}
Move Movestack::top(){
    if(isEmpty()){
        cout<<"Stack is empty!!!!"<<endl;
        return Move();
    }
    else{
        return Move(head->x,head->y);
    }
}



