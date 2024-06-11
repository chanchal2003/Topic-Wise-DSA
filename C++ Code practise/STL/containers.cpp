/*
STL: Standard template library: generic classes and functions
Componenets:
1.Containers:object that stores data.Implemented classes.Use template classes.
i)sequence: linear fashion
    a)vector-random access is fast,insertion,deletion is fast
    b)list-random access is slow,insertion,deletion is fast
    c)deqeue-
ii)associative: direct access(map,multimap,dictionary,set,list).all operations is fast. except random access
iii)derived: real world modelling(stack,queue,priority queue)

2.Algorithm: Procedure to store data.Sorting ,searching, merging

3.Iterators: it is a object that points to a element in the conatainer.Handled just like pointers.Connects algorithms with conatiners.moves as instructed by algo.  
*/

/*vector*/
#include<iostream>
#include<vector>
using namespace std;

int main(){ 
    vector<int> vec1;
    int element, size;
    cout<<"Enter the size of your vector"<<endl;
    cin>>size;
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter an element to add to this vector: ";
        cin>>element;
        vec1.push_back(element);
    }
    //vec1.pop_back();
    
    vector<int> ::iterator iter;
    for(iter=vec1.begin(); iter!=vec1.end(); iter++ ){
        cout<<(*iter)<<endl;
    }

    /*insert*/
    vec1.insert(iter+2,566); 

    return 0;
}
