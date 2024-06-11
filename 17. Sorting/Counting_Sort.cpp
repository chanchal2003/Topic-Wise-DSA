#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n + R)
// Space Complexity: O(n + R)
vector<int> counting_sort(vector<int> &nums)
{
    int n = nums.size();

    int R = 10; // Range of num will be in 0 to 9. Means the elements of nums will have value between 0 to R

    // Step-1: Frequency of nums
    vector<int> frequency(R, 0);
    for (int &num : nums)
        frequency[num] += 1;

    // Step-2: Cummulative Frequency of frequency vector
    vector<int> cummulativeFrequency(R, 0); // We can also edit the frequency vector but for simplicty we will create a new vector for cummulative frequency
    cummulativeFrequency[0] = frequency[0];
    for (int i = 1; i < R; i++)
        cummulativeFrequency[i] = frequency[i] + cummulativeFrequency[i - 1];

    // Step-3: Construct the Sorted array from the cummulativeFrequency vector
    vector<int> sorted_nums(n);
    for (int i = n - 1; i >= 0; i--) // We will traverse from Right to Left on nums to maintain the relative ordering of the same elements. That's why Counting sort is a Stable sorting algorithm
    {
        int index = cummulativeFrequency[nums[i]];
        sorted_nums[index - 1] = nums[i]; // cummulativeFrequency[i]-1, -1 because we have 0-based indexing
        cummulativeFrequency[nums[i]] -= 1;
    }
    return sorted_nums;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> sorted_nums = counting_sort(nums);
    for (int &num : sorted_nums)
        cout << num << " ";
    cout << endl;

    return 0;
}