/*
Suppose we have a binary array; we have to find the maximum number of consecutive 1s in this array if we can flip at most one 0.

So, if the input is like [1,0,1,1,0], then the output will be 4 because if we flip the first zero will get the maximum number of consecutive 1s. After flipping, the maximum number of consecutive 1s is 4.
*/

#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &v){
    int j = -1;
    int n = v.size();
    int zeroCount = 0;
    int maxLength = 0;
    for(int i=0; i<n; i++){
        if(v[i] == 0){
            zeroCount++;
        }
        while(zeroCount > 1){
            v[j]++;
            if(v[j] == 0){
                zeroCount--;
            }
        }
        maxLength = max(maxLength,i-j);
    }
    return maxLength;
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int element;
        cin>>element;
        v.push_back(element);
    }
    cout<<findMaxConsecutiveOnes(v)<<endl;
    return 0;
}