/*
1. Assume you have an array of length 'n' initialized with all 0's and are given 'q' queries to update.
2. Each query is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.
3. Return the modified array after all 'q' queries were executed.

length = 5,
updates =
{
    {1,  3,  2},
    {2,  4,  3},
    {0,  2, -2}
}

https://www.youtube.com/watch?v=fBT0VKkqvtY&t=33s
prefix jaise karna hai
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> RangeAddition(vector<vector<int>> &queries, int n)
{
    vector<int> impactArr(n + 1);
    for (vector<int> query : queries)
    {
        int start = query[0];
        int end = query[1]+1;/*if n=5, and we have to update 3 to 5 wala range then we won't change the 6th index we will leave it as it is as  end  is just to stop the addition
*/
        int val = query[2];
        impactArr[start] += val;
        if(end < n){
            impactArr[end] -= val;
        }
    }
    vector<int> result(n);
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += impactArr[i];
        impactArr[i] = sum;
    }
    return result;
}

int main()
{

    cout << "Enter the length of the array" << endl;
    int n;
    cin >> n;

    cout << "Enter the number of queries" << endl;
    int q;
    cin >> q;
    vector<vector<int>> queries;
    cout << "Enter the  queries" << endl;
    for (int i = 0; i < q; i++)
    {
        vector<int> query;
        int start, end, val;
        cin >> start;
        query.push_back(start);
        cin >> end;
        query.push_back(end);
        cin >> val;
        query.push_back(val);
        queries.push_back(query);
    }

    vector<int> result = RangeAddition(queries, n);
    for(int num : result){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
