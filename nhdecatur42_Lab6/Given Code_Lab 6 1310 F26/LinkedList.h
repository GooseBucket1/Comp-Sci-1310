#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include <fstream>

class LinkedList{
    private:

        struct Node{
            double value;
            Node *next;
        };
        Node *head;
        Node *tail;
    
    public:
    
        LinkedList(){
            head = NULL;
            tail = NULL;
        };

    ~LinkedList();

    };


#endif