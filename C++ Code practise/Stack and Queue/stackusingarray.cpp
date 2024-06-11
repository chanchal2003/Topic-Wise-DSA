#include <bits/stdc++.h>
using namespace std;

class StackUsingArray
{
    int *data;
    int nextIndex;
    int capacity;
public:
    StackUsingArray(int totalSize) 
    // scope is inside constructor
    {
        data=new int[totalSize];
        nextIndex=0;
        capacity=totalSize;
    }
    
    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return size()==0;
    }

    // insert element
    void push(int element)
    {
        if(nextIndex == capacity){
            //we cannot totalSize directly but why
            cout<<"StackFull"<<endl;
            return;
        }
        data[nextIndex]=element;
        nextIndex++;
    }
    // delete element
    int pop()
    {
        if(nextIndex==0){
            cout<<"Stack is Empty"<<endl;
            return INT_MIN;
        }
        // delete data[nextIndex];
        nextIndex--;
        return data[nextIndex];
    }

    // to return the top element of the stack
    int top()
    {
        if(nextIndex==0){
            cout<<"Stack is Empty"<<endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }
};