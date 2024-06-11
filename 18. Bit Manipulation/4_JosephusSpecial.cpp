#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

string arePseudoEquivalent(int N, string w1, string w2) {
    // Create unordered_maps to count the occurrences of each character in both strings
    unordered_map<char, int> count_w1, count_w2;

    // Count occurrences in w1
    for (char ch : w1) {
        count_w1[ch]++;
    }

    // Count occurrences in w2
    for (char ch : w2) {
        count_w2[ch]++;
    }

    // Check if the strings are pseudo equivalent
    bool pseudoEquivalent = true;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        int diff = abs(count_w1[ch] - count_w2[ch]);
        if (diff > 3) {
            pseudoEquivalent = false;
            break;
        }
    }

    if (pseudoEquivalent) {
        // If they are pseudo equivalent, print the lexicographically smaller string
        if (w1 < w2) {
            return w1;
        } else {
            return w2;
        }
    } else {
        // If they are not pseudo equivalent, return "-1"
        return "-1";
    }
}

int main() {
    int N;
    cin >> N;

    string w1, w2;
    cin >> w1 >> w2;

    string result = arePseudoEquivalent(N, w1, w2);
    cout << result << endl;

return 0;
}