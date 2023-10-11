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
        size--;
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
        cout << "3 - removeAt" << endl;
        cout << "4 - removeNum" << endl;
        cout << "5 - retain" << endl;
        cout << "6 - removeRedundant" << endl;
        cout << "7 - corner" << endl;
        cout << "8 - sortList by Descending" << endl;
        cout << "9 - sortList by Ascending" << endl;
        cout << "10 - print" << endl;

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
        cout << "Size is: " << size << endl;
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

    int retain(int num){
        int ctr = 0;

        node* curr = head->next;
        node* temp = curr;

        while(curr != tail){
            if(curr->data < num){
                temp = curr->next;
                removeNode(curr);
                curr = temp;
                ctr++;
            }else{
                curr = curr->next;
            }
        }
        return ctr;
    }

    int removeRedundant(){

        int ctr = 0;

        node* curr = head->next;
        

        while(curr->next != tail){
            node* trav = curr->next;
        while(trav != tail){
            if(curr->data == trav->data){
                node* temp = trav->next;
                removeNode(trav);
                trav = temp;
                ctr++;
            }else{
                trav = trav->next;
            }
        }
        curr = curr->next;
        }
        return ctr;
    }

    int corner(int left,int right){

            int ctr = 0;
            int flag = 0;

            node* curr = head->next;
            node* temp = curr;

            while(ctr < left){
                ctr++;
                curr = curr->next;
            }

            temp = curr;
            right = (size - right);

            while(ctr < right){
                temp = temp->next;
                removeNode(curr);
                curr = temp;
                flag++;
                ctr++;
            }
            return flag;
    }

    void sortDList(){

        node* curr = head->next;

        while(curr->next != tail){
           node* trav = curr->next;
            while(trav != tail){
                if(trav->data > curr->data){
                    int temp = trav->data;
                    trav->data = curr->data;
                    curr->data = temp;
                }
                trav = trav->next;
            }
            curr = curr->next;
        }
        cout << "Success!" << endl;
    }

    void sortAList(){

        node* curr = head->next;

        while(curr->next != tail){
           node* trav = curr->next;
            while(trav != tail){
                if(trav->data < curr->data){
                    int temp = trav->data;
                    trav->data = curr->data;
                    curr->data = temp;
                }
                trav = trav->next;
            }
            curr = curr->next;
        }
        cout << "Success!" << endl;
    }

};