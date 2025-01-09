#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {

    char answer {};
    vector<int> num_list {};

    cout << "\nWelcome to the system!" << endl;

    do {
        cout << "\n============================" << endl;
        cout << "\nP - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "N - Display the number of times each number is in the list" << endl;
        cout << "C - Clear the list" << endl;
        cout << "Q - Quit" << endl;

        cout << "\nChoose an option: ";
        cin >> answer;
        cout << endl;

        if (answer == 'p' || answer == 'P') {
            if (num_list.empty()) {
                cout << "[] - the list is empty" << endl;
            } else {
                cout << "[";
                for (auto num:num_list) {
                    cout << " " << num << " ";
                }
                cout << "]";
                cout << endl;
            }
        } else if (answer == 'a' || answer == 'A') {
            int number {};
            cout << "Enter a number to add: ";
            cin >> number;
            cout << endl;
            num_list.push_back(number);
            cout << number << " added" << endl;
        } else if (answer == 'm' || answer == 'M') {
            if (num_list.empty()) {
                cout << "Unable to calculate the mean - no data" << endl;
            } else {
                int total {};
                for (auto number: num_list) {
                    total += number;
                }
                cout << "The mean of the list is: " << total / num_list.size() << endl; 
            }
        } else if (answer == 's' || answer == 'S') {
            if (num_list.empty()) {
                cout << "Unable to calculate the smallest number - no data" << endl;
            } else {
                auto smallest = min_element(num_list.begin(), num_list.end());
                cout << "The smallest number of the list is: " << *smallest << endl;
            }
        } else if (answer == 'l' || answer == 'L') {
            if (num_list.empty()) {
                cout << "Unable to calculate the largest number - no data" << endl;
            } else {
                auto largest = max_element(num_list.begin(), num_list.end());
                cout << "The largest number of the list is: " << *largest << endl;
            }
        } else if (answer == 'n' || answer == 'N') {
            int times_number {};
            vector<int> distinct {};
            for (auto number:num_list) {
                if (find(distinct.begin(), distinct.end(), number) == distinct.end()) {
                    int times_number {};
                    for(auto times:num_list) {
                    if (number == times) {
                        times_number += 1;
                    }
                }
                if (times_number == 1) {
                    cout << number << " appears " << times_number << " time" << endl;
                } else {
                    cout << number << " appears " << times_number << " times" << endl;
                }
                distinct.push_back(number);
                }
                
            }
        } else if (answer == 'c' || answer == 'c') {
            num_list.clear();
            cout << "Vector successfully cleaned!" << endl;
        } else if (answer == 'q' || answer == 'Q') {
            cout << "Goodbye!" << endl;
        } else {
            cout << "Unknown selection, please try again!" << endl;
        }
        
    } while (answer != 'q' && answer != 'Q');


    return 0;
}