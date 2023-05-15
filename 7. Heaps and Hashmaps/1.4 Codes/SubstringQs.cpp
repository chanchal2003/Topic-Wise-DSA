/*
Whenever we have to find substring related questions then there a partiular algorithm of acquire and release

    int n = s.size();
    int ans = 0;
    unordered_map<char,int> mp;
    int i = -1;
    int j = -1;

    while(true){
        bool flag1 = false;
        bool flag2 = false;

        //acquire
        while(i < n-1){
            i++;
            mp[s[i]]++;
            //if else condition related to qs
            flag1 = true;
        }

        //release
        while(j < i){
            flag2 = true;
            j++;
            mp[s[j]]--;
            //if else condition according to question
        }

        if(flag1==false && flag2==false){
            break;
        }
    }


*/

/*
1. Longest substring with exactly k distinct charachters
https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

2. Longest Substring with atmost k distinct charachters
https://www.codingninjas.com/codestudio/problems/longest-sub-string-with-at-most-k-distinct-characters_699944?leftPanelTab=1

*/