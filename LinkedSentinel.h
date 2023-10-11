#include <iostream>
#include <cstdlib>
#include <cmath>
#include "sentinel.h"
using namespace std;

class LinkedSentinel : public Sentinel{

    int size;
    node *head, *tail;

    void addAll(int num, node* pred, node* succ){

        node* temp = (node*) malloc( sizeof(node));

        temp->data = num;
        temp->prev = pred; 
        temp->next = succ; 

        pred->next = temp; 
        succ->prev = temp; 
        size++;
    }

    void removeNode(node* n){

        node* pred = n->prev;
        node* succ = n->next;
        free(n);
        pred->next = succ;
        succ->prev = pred;

    }

    public:

    LinkedSentinel(){
        head = (node*) calloc(1,sizeof(node));
        tail = (node*) calloc(1,sizeof(node));
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

     void menuz(string name){

        cout << "\nHello " << name << " here is the table of choices." << endl;
        cout << "\n1 - addFirst" << endl;
        cout << "2 - addLast" << endl;
        cout << "3 - print" << endl;
        cout << "4 - removeAt" << endl;
        cout << "5 - removeNum" << endl;

        return;
    }

    void addHead(int num){
        addAll(num,head,head->next);
    }

    void addTail(int num){
        addAll(num,tail->prev,tail);
    }

    void print(){

        node* curr = (node*) malloc( sizeof(node) );

        curr = head->next;
        while(curr != tail){
            cout << "[" << curr->data << "] " ;
            curr = curr->next;
        }
        cout << endl;
        return;
    }

    int removeAt(int pos){
        int index = 1;

        node* curr = head->next;

        if(pos > size + 1){
            pos = size + 1;
        }
        
        while(index != pos){
            curr = curr->next;
            index++;
        }
        removeNode(curr);
        return index;
    }

    int removeNum(int num){
        int index;

        node* curr = head->next;

        while(curr){
            if(curr->data == num){
            index = curr->data;
            removeNode(curr);
            return index;
            }
            curr = curr->next;
        }
        
        return -1;
    }

};