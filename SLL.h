#include <iostream>
#include "Node.h"
using namespace std;

template <class U>
class SLL {
    Node<U> * headPtr;
    int size;

    public:
    // default constructor
    SLL() {
        headPtr = nullptr;
        size = 0;}

    // destructor
    ~SLL() {
        Node<U>* current = headPtr;
        while (current != nullptr) {
            Node<U>* next = current->next;
            delete current;
            current = next;}
        headPtr = nullptr;
    }

    // insert (item1, item2) to the list
    void insert(U item1, U item2) {
        Node<U>* newNode = new Node<U>();
        newNode->SSN = item1;
        newNode->name = item2;
        newNode->next = nullptr;

        if (headPtr == nullptr) {
            headPtr = newNode;
        } 
        else {
            Node<U>* temp = headPtr;
            while (temp->next != nullptr) { temp = temp->next; }
            temp->next = newNode; }
        size++;
    }

    Node<U>* getHeadPtr(){
        return headPtr;}

    // if find the item1 value, return the pointer to the node
    // otherwise, return nullptr
    Node<U>* search(U item1) {
        Node<U>* temp = headPtr;
        while (temp != nullptr) {
        if (temp->SSN == item1) { return temp;}
        temp = temp->next;
        }
    return nullptr;
    }

    // remove the node with key value: item1
    bool remove(U item1) {
        Node<U>* current = headPtr;
        Node<U>* prev = nullptr;
        while (current != nullptr) {
            if (current->SSN == item1) {
                if (prev == nullptr) { headPtr = current->next; } 
                else { prev->next = current->next; }
                delete current;
                size--;
                return true;}
            prev = current;
            current = current->next;}
        return false;
    }

    int getSize() {
        return size;
    }
    // display the SSN values of each node in the linked list
    void display(){
        Node<U>* temp;
        temp = headPtr;
        while (temp!= nullptr) {
            cout << temp->SSN << endl;
            temp = temp->next;
        }
    }
};




