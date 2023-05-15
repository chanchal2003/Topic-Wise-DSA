/*
Given an array of strings (all lowercase letters), the task is to group them in such a way that all strings in a group are shifted versions of each other. Two string S and T are called shifted if, 

S.length = T.length 
and
S[i] = T[i] + K for 
1 <= i <= S.length  for a constant integer K

Input  : str[] = {"acd", "dfg", "wyz", "yab", "mop",
                 "bdfh", "a", "x", "moqs"};

Output : a x
         acd dfg wyz yab mop
         bdfh moqs
All shifted strings are grouped together.

We can see a pattern among the string of one group, the difference between consecutive characters for all character of the string are equal. As in the above example take acd, dfg and mop
a c d -> 2 1 
d f g -> 2 1 
m o p -> 2 1
Since the differences are the same, we can use this to identify strings that belong to the same group.
*/

#include<bits/stdc++.h>
using namespace std;

string getKey(string temp){
    int k = temp.size();
    string key = "";
    for(int i=1; i<k; i++){
        int differnce = temp[i] - temp[i-1];
        if(differnce < 0){
            differnce = differnce + 26;
        }
        key += to_string(differnce);
    }
    return key;
}

void groupShiftedString(vector<string> &input,int n){
    unordered_map<string,vector<string>> mp;
    for(string temp : input){
        string key = getKey(temp);
        mp[key].push_back(temp);
    }
    cout<<mp.size()<<endl;
    for(auto itr : mp){
        vector<string> v = itr.second;
        for(string temp : v){
            cout<<temp<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<string> input;
    cout<<"Enter the size of the input vector"<<endl;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string temp;
        cin>>temp;
        input.push_back(temp);
    }
    groupShiftedString(input,n);
    return 0;
}

/*
9
acd
dfg
wyz
yab
mop
bdfh
a
x
moqs

*/