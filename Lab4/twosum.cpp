#include <iostream>
#include <unordered_set>
using namespace std;

bool twoSum(int arr[], int n, int T) {
    unordered_set<int> seen;

    for (int i = 0; i < n; i++) {
        int required = T - arr[i];

        if (seen.find(required) != seen.end()) {
            return true;
        }
        seen.insert(arr[i]);
    }
    return false;
}
int main() {
    int n, target; 
    cout << "Enter number of elements: "; 
    cin >> n; 
    int arr[n]; 
    cout << "Enter array elements: \n"; 
    for (int i = 0; i < n; i++) { 
        cin >> arr[i]; 
    } 
    cout << "Enter target value: "; 
    cin >> target;
    if (twoSum(arr, n, target))
        cout << "Pair exists\n";
    else
        cout << "Pair does not exist\n";

    return 0;
}