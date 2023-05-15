#include<bits/stdc++.h>
using namespace std;

int maxLength = 0;

void helper(string s1,string s2,int n1,int n2,int length){
    if(n1==0 || n2==0){
        return;
    }
    if(s1[n1-1] == s2[n2-1]){
        maxLength = max(maxLength,length+1);
        helper(s1,s2,n1-1,n2-1,length+1);
    }
    else{
        helper(s1,s2,n1-1,n2,0);
        helper(s1,s2,n1,n2-1,0);
    }
}

int LongestCommonSubstr(string s1,string s2){
    int n1 = s1.length();
    int n2 = s2.length();
    helper(s1,s2,n1,n2,0);
    return maxLength;
}

int main(){

    string s1,s2;
    cin>>s1>>s2;
    cout<<LongestCommonSubstr(s1,s2)<<endl;

    return 0;
}

/*
GeeksforGeeks
GeeksQuiz

zxabcdezy
yzabcdezx
*/