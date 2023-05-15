#include<bits/stdc++.h>
using namespace std;

void printPairsEqualSum(vector<int> &nums){
    int n = nums.size();
    unordered_map<int,vector<pair<int,int>>> mp;

    int sum;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            sum = nums[i] + nums[j];
            mp[sum].push_back({nums[i],nums[j]});
        }
    }

    for(auto itr : mp){
        vector<pair<int,int>> temp = itr.second;
        if(temp.size() > 1){
            for(int i=0; i<temp.size(); i++){
                cout<<"("<<itr.second[i].first<<","<<itr.second[i].second<<")";
            }
            cout<<"have sum "<<itr.first<<endl;
        }
    }
}



int main(){
    int n;
    cin>>n;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        int element;
        cin>>element;
        nums.push_back(element);
    }
    printPairsEqualSum(nums);
    return 0;
}


/*
7
2 9 3 5 8 6 4
*/