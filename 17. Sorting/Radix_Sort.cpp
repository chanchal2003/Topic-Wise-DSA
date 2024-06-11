#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<int> &nums, int digit)
{
    int n = nums.size();
    int R = 10; // Range of digit will be in 0 to 9.

    // Step-1: Frequency of nums
    vector<int> frequency(R, 0);
    for (int &num : nums)
    {
        cout << (num / (int)pow(10, (digit - 1))) % 10 << " ";
        frequency[(num / (int)pow(10, (digit - 1))) % 10] += 1; // To find n-th digit from a number num we have the formula: digit_value=(num/(10^(digit-1)))%10
    }
    cout << endl;
    for (int &num : frequency)
        cout << num << " ";
    cout << endl;

    // Step-2: Cummulative Frequency of frequency vector
    vector<int> cummulativeFrequency(R, 0); // We can also edit the frequency vector but for simplicty we will create a new vector for cummulative frequency
    cummulativeFrequency[0] = frequency[0];
    for (int i = 1; i < R; i++)
        cummulativeFrequency[i] = frequency[i] + cummulativeFrequency[i - 1];

    for (int &num : cummulativeFrequency)
        cout << num << " ";
    cout << endl;

    // Step-3: Construct the Sorted array from the cummulativeFrequency vector
    vector<int> sorted_nums(n);
    for (int i = n - 1; i >= 0; i--) // We will traverse from Right to Left on nums to maintain the relative ordering of the same elements. That's why Counting sort is a Stable sorting algorithm
    {
        int index = cummulativeFrequency[(nums[i] / (int)pow(10, (digit - 1))) % 10];
        sorted_nums[index - 1] = nums[i]; // cummulativeFrequency[i]-1, -1 because we have 0-based indexing
        cummulativeFrequency[(nums[i] / (int)pow(10, (digit - 1))) % 10] -= 1;
    }

    // Copy the sorted array to nums[], so that nums[] now
    // contains sorted numbers according to current digit
    nums = sorted_nums; // For next iteration we need the digit sorted nums
    for (int &num : nums)
        cout << num << " ";
    cout << endl;
}

void radix_sort(vector<int> &nums)
{
    int n = nums.size();

    // Find the maximum number to know number of digits
    int maximumNum = *max_element(nums.begin(), nums.end());
    int noOfDigits = log10(maximumNum) + 1; // Number of Digits in the maximum number will be stored in noOfDigits
    cout << "Maximum Number: " << maximumNum << endl;
    cout << "Number of digits: " << noOfDigits << endl;
    // Do counting sort for every digit. Note that instead of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int digit = 1; digit <= noOfDigits; digit++)
    {
        counting_sort(nums, digit);
        cout << "------------------------" << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    radix_sort(nums);
    for (int &num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}