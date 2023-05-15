#include<bits/stdc++.h>
using namespace std;

class Node
{
private:
    int data;
    Node* next;
    Node* prev;

public:
    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
    friend class DoublyLinkedlist;

};

class DoublyLinkedlist
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    DoublyLinkedlist(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    //Adding at first
    //ask about size
    void addFirstNode(Node* node){
        if(size==0){
            head = node;
            tail = node;
        }
        else{
            node->next = head;
            head->prev = node;
            head = node;
        }
    }
    void addFirst(int val){
        Node* node = new Node(val);
        addFirstNode(node);
    }

    //adding at last
    void addLastNode(Node* node){
        if(size==0){
            head = node;
            tail = node;
        }
        else{
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    void addLast(int val){
        Node* node = new Node(val);
        addLastNode(node);
    }

    //Add at an index
    void addNodeAt(Node* node,int index){
        if(index==0){
            addFirstNode(node);
        }
        else if(size==index){
            addLastNode(node);
        }
        else{
            Node* curNode = getNodeAt(index);
            Node* preNode = curNode->prev;
            
            preNode->next = node;
            node->next = curNode;

            node->prev = preNode;
            curNode->prev = node;

            size++;
        }
    }

    void addAt(int index,int val){
        
        if((index<0) || (index>=size+1)){
            return;
        }

        Node* node = new Node(val);
        addNodeAt(node,index);
    }

    //REMOVE IN DOUBLY LINKEDLIST
    void removeFirst(){
        if(size==0){
            return;
        }
        else if(size==1){
            head=tail=NULL;
        }
        else{
            Node* currNode = head->next;
            currNode->prev = NULL;
            delete head;
            head = currNode;
        }
    }

    void removeLast(){
        if(size==0){
            return;
        }
        else if(size==1){
            head=tail=NULL;
        }
        else{
            Node* prevNode = tail->prev;
            delete tail;
            prevNode->next = NULL;
            tail = prevNode;
        }
    }

    void removeAt(int index){
        if((index<0) || (index>size+1)){
            return;
        }
        else if(index==0){
            removeFirst();
        }
        else if(index==size){
            removeLast();
        }
        else{
            Node* currNode = getNodeAt(index);
            Node* prevNode = currNode->prev;
            Node* nextNode = currNode->next;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            
            delete currNode;
        }
    }

    int sizeLL(){
            return this->size;
    }

    bool isEmpty(){
        return (this->size==0);
    }

    int getFirst(){
        if(size==0){
            cout<<"List is Empty"<<endl;
            return -1;
        }
        else{
            return head->data;
        }
    }

    int getLast(){
        if(size==0){
            cout<<"List is Empty"<<endl;
            return -1;
        }
        else{
            return tail->data;
        }
    }
    
    Node* getNodeAt(int index){
        Node *current = head;
        while (index-- > 0)
        {
            current = current->next;
        }
        return current;
    }

    int getAt(int index){
        if(size==0){
            return -1;
        }
        if ((index < 0) || (index >= size)) // Index Is Invalid Exception
        {
            return -1;
        }

        return getNodeAt(index)->data;
    }
};


int main(){
    return 0;
}