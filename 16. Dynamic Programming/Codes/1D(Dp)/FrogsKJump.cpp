/*
https://takeuforward.org/data-structure/dynamic-programming-frog-jump-with-k-distances-dp-4/

f(ind){
    if(ind == 0){
        return 0;
    }
    minsteps = INT_MAX;
    for(int j=1; j<=k; j++){
        if(ind-j>=0){
            minsteps = min(minsteps,f(ind-k)+heights[j]-heights[ind-j]);
        }
    }
    return minsteps;
}
*/