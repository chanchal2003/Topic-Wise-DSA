#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1.3,5.2,9.5,3.3,7.6,4.2,2.5,0.9};
    int n = sizeof(arr)/sizeof(arr[0]);

    sort(arr, arr + n, greater<double>());
  
    cout << "Array after sorting : \n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    return 0;
}

/*to sort the array is descending order*/