#include <iostream>
#include <vector>
using namespace std;

vector<int> find_subsidy_eligible_residents(int N, int P, vector<int> drive_info) {
    vector<int> eligible(N, 1); // Initialize a list of size N with all elements set to 1, representing that all residents are eligible for the subsidy

    for (int i = 1; i < P; i++) { // For each drive, starting from the second one
        int main_contact = drive_info[i]; // Read the ID of the resident who is the main point of contact for the drive
        while (main_contact != 0) { // Set the element at the index of the ID to 0, representing that the resident and all their superiors in the hierarchy are not eligible for the subsidy
            eligible[main_contact-1] = 0;
            main_contact = drive_info[main_contact-1];
        }
    }

    vector<int> not_eligible; // Return the list of IDs whose corresponding elements are still 1
    for (int i = 0; i < N; i++) {
        if (eligible[i] == 1) {
            not_eligible.push_back(i+1);
        }
    }
    return not_eligible;
}

int main() {
    int N = 10; // number of residents
    int P = 3; // number of drives
    vector<int> drive_info = {0, 2, 4, 8}; // IDs of the main points of contact for each drive

    vector<int> not_eligible = find_subsidy_eligible_residents(N, P, drive_info);
    cout << "Residents not eligible for the food subsidy: ";
    for (int i = 0; i < not_eligible.size(); i++) {
        cout << not_eligible[i] << " ";
    }
    cout << endl;

return 0;
}