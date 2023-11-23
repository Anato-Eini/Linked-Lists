#include <iostream>
#include "Abstract.h"
using namespace std;
class LinkedList: public List{
    Node* head, *tail;
    int size;
public:
    LinkedList(){
        head = new Node{0, nullptr};
        tail = new Node{0, nullptr};
        size = 0;
    }
    void addLast(int num){
        Node* n = new Node{num, nullptr};
        if(size == 0){
            head->next = n;
            tail->next = n;
        }else{
            tail->next->next = n;
            tail->next = n;
        }
        size++;
    }
    void addFirst(int num){
        Node* n = new Node{num, head->next};
        if(size == 0){
            head->next = n;
            tail->next = n;
        }else{
            n->next = head->next;
            head->next = n;
        }
        size++;
    }
    void flip(){
        if(size == 0){
            cout << "Empty List" << endl;
        }else{
            Node* prev = nullptr, *curr = head->next, *forw = head->next;
            while(forw){
                forw = forw->next;
                curr->next = prev;
                prev = curr;
                curr = forw;
            }
            Node* temp = head->next;
            head->next = tail->next;
            tail->next = temp;
        }
    }
    void removeNode(int num){
        if(size == 0){
            cout << "The list is empty" << endl;
            return;
        }else if(num < 0 || num >= size){
            cout << "Invalid Position" << endl;
        }else{
            Node* curr = head->next, *prev = head;
            int i = 0;
            while(i < num){
                prev = curr;
                curr = curr->next;
                i++;
            }
            prev->next = curr->next;
            if(curr == tail->next){
                tail->next = prev;
            }
            size--;
        }
    }
    void combineLists(LinkedList* linkedList){
        if(linkedList->size == 0){
            return;
        }else if(size == 0){
            size = linkedList->getSize();
            linkedList->size = 0;
            head = linkedList->head;
            tail = linkedList->tail;
        }else{
            tail->next->next = linkedList->head->next;
            tail->next = linkedList->tail->next;
        }
    }
    int getSize(){
        return size;
    }
    void print(){
        Node* curr = head->next;
        while(curr){
            cout << curr->elem << " ";
            curr = curr->next;
        }
        cout << endl;
        delete curr;
    }
};