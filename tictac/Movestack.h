/*
Assignment: 4
filename: Movestack.h
Nirajan Banjade
Due: Nov 31,2023
*/

#ifndef Movestack_h
#define Movestack_h

using namespace std;

// a struct data type which has two member variable of int type
// there are two consrtuctor for default case and initialized parameter.

struct Move
{
    int x;
    int y;

    Move()
    {
        x = 0;
        y = 0;
    }
    Move(int a, int b)
    {
        x = a;
        y = b;
    }
    Move *next;
};

// class Movestack has a head pointer of Move type as private member to keep the track of stack as well as to
// implement encapsulation in stack. The elements are stacked using linked list where head keeps the track of   the file
// all other thing are basic stack implementation in 2D input as (x cordinate and y cordinate);
class Movestack
{
private:
    Move *head;

    int count;

public:
    Movestack();
    ~Movestack();
    void push(Move move);
    void pop();
    int getSize();
    bool isEmpty() const;
    Move top();
};

#endif