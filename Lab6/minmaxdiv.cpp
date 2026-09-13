#include <iostream>
using namespace std;

struct Result {
    int max;
    int min;
};

Result findMaxMin(int arr[], int low, int high) {
    Result result, left, right;

    if (low == high) {
        result.max = arr[low];
        result.min = arr[low];
        return result;
    }

    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            result.max = arr[low];
            result.min = arr[high];
        } else {
            result.max = arr[high];
            result.min = arr[low];
        }
        return result;
    }

    int mid = (low + high) / 2;

    left = findMaxMin(arr, low, mid);
    right = findMaxMin(arr, mid + 1, high);

    result.max = (left.max > right.max) ? left.max : right.max;
    result.min = (left.min < right.min) ? left.min : right.min;

    return result;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Result result = findMaxMin(arr, 0, n - 1);

    cout << "Maximum element: " << result.max << endl;
    cout << "Minimum element: " << result.min << endl;

    return 0;
}