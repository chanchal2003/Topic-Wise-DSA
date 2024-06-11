/*
Right shift -> it shifts elements to right
division is done using rigt shift 

left Shift -> it shifts elements to left
multiplication is done using left shift

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Take input"<<endl;
    cin>>n;
    
    // SET ith bit (powrful is 1)
    // int i;
    // cin>>i;
    // int onMask = (1 << i);
    // cout<<onMask<<endl;
    // cout<< (onMask | n);
    
    //UNSET jth bit(powerful is 0)
    // cout<<"Unsetting"<<endl;
    // int j;
    // cin>>j;
    // int OfMask = ~(1 << j);
    // cout<< (OfMask & n)<<endl;
    
    //TOGGLE kth bith(powerful is 1)
    //xor if both are same then you get 0, else 1, and here we want to toggle that bit, we cannot use set or unset because we don't know whether that bit is set or not
    //consider that in your number you have 1 and you have to toggle it, if you and it with 1 you get 0 that is the toggled bit
    //you have to toggle 0 the if you xor 0 with 1 then you will be able to toggle ithence here powerful is 1
    // cout<<"Toggling"<<endl;
    // int k;
    // cin>>k;
    // int tmask = (1<<k) ;
    // cout<< (tmask ^ n);
    
    //check for on or off
    // cout<<"Check"<<endl;
    // int l;
    // cin>>l;
    // int cmask = (1<<l);
    // if(cmask & n){
    //     cout<<"true"<<endl;
    // }
    // else{
    //     cout<<"false"<<endl;
    // }

    return 0;
}

