/*
In any sorting algorithm that checks the condidtion of smaller or greater and then swapping of elements is done
This was done to swap numbers 

In inbuilt sorting algorithm if arr[i] > arr[j], this will mean that we need to swap the numbers for ascending arrangment of elements

hence when we want to arrange elements in desending order if(arr[j] > arr[i]) we need to swap so as arr[j] is not at its correct position

every sort function has swap function
our in built swap function is sorted in ascending order
to make it descending we write comparator function

if a=1 and b=3, a is less than b this true this will mean that we need to place b before a that is we will swap positions of a and b
*/

#include<bits/stdc++.h>
using namespace std;

/*
asending order
*/
// void sort_arr(vector<int> &arr,int n){
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             if(arr[i] > arr[j]){
//                 swap(arr[i],arr[j]); 
//                 /*we will swap elements*/
//             }
//         }
//     }
// }

/*descending order*/

void sort_arr(vector<int> &arr,int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] < arr[j]){
                swap(arr[i],arr[j]); 
                /*we will swap elements*/
            }
        }
    }
}

bool cmp(int a,int b){
    if(a > b){
        return true; //this will mean that a>b then we need to swap positions of a and b, that is b wshould be plcaed before a 
    }
    return false;
}

void sort_arr_func(vector<int> &arr,int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(cmp(arr[i],arr[j])){
                swap(arr[i],arr[j]); 
                /*we will swap elements*/
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0; i<n; i++){
        int element;
        cin>>element;
        arr.push_back(element);
    }
    // sort_arr(arr,n);
    sort_arr_func(arr,n);
    
    //this fundtion is basically defining the behaviour of swap function
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

/*
6
1 3 6 5 4 2
*/
