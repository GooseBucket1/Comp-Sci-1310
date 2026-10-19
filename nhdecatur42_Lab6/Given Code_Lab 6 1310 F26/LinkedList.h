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

        // this changees the node adding on to it
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
                cout <<"\nThere are no songs in the list.\n\n";
            }
            return;
        }

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
            Node *nodePtr;
            Node *nextNode;
            int numDelete = 0;

            nodePtr = head;

            while (nodePtr){
                nextNode = (*nodePtr).next;
                delete nodePtr;

                nodePtr = nextNode;
                numDelete++;
            }
            cout << numDelete << "songs deleted\n";
        }
};

#endif