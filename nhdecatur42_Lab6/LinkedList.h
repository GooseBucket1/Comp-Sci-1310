/*
    Name: Noelle Decatur
    File Name: LinkedList.h
*/


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <list>
#include <string>
#include "track.h"
using namespace std;

class LinkedList{
    private:

        struct Node{
            Track song;
            Node* next;
        };
        Node* head;
        Node* tail;
    
    public:

        LinkedList(){
            head = NULL;
            tail = NULL;
        };

        // this changes the node adding on to it
        void appendNode(Track song){
            Node *newNode;

            newNode = new Node;
            (*newNode).song = song;
            (*newNode).next = NULL;

            if (!head){
                head = newNode;
                tail = newNode;
            }else{
                (*tail).next = newNode;
                tail = newNode;
            }
        }

        // this displays the node
        void displayNode(int pos){
            Node *nodePtr;
            int currentPos = 0;
            // checks that the head does not equal null
            if(head != NULL){
                nodePtr = head;
            
                while(nodePtr){
                    if(pos == currentPos){
                        cout << (*nodePtr).song << "\n";
                    }
                    currentPos++;
                    nodePtr = (*nodePtr).next;
                }
            }else{
                // if there are no songs in the list the it will print this
                cout <<"\nThere are no songs in the list.\n\n";
            }
            return;
        }

        // gets the length of the text
        int getLength(){
            int count = 0;
            Node *nodePtr;
            nodePtr = head;

            while(nodePtr != tail){
                count++;
                nodePtr = (*nodePtr).next;
                if(nodePtr == tail){
                    count++;
                }
            }
            return count;
        }

        ~LinkedList(){
            Node *nodePtr; // points to the list
            Node *nextNode; // points to next node
            int numDelete = 0;

            nodePtr = head;

            while (nodePtr != NULL){
                nextNode = (*nodePtr).next;
                delete nodePtr;

                nodePtr = nextNode;
                numDelete++;
            }
            cout << numDelete << " songs deleted\n";
        }
};

#endif