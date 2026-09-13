#include <iostream>
using namespace std;

struct Subarray {
    int left;
    int right;
    int sum;
};

Subarray maxCrossing(int arr[], int low, int mid, int high) {
    int leftSum = -1000000000;
    int sum = 0;
    int maxLeft = mid;

    for (int i = mid; i >= low; i--) {
        sum += arr[i];

        if (sum > leftSum) {
            leftSum = sum;
            maxLeft = i;
        }
    }

    int rightSum = -1000000000;
    sum = 0;
    int maxRight = mid + 1;

    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];

        if (sum > rightSum) {
            rightSum = sum;
            maxRight = i;
        }
    }

    return {maxLeft, maxRight, leftSum + rightSum};
}

Subarray maxSubarray(int arr[], int low, int high) {
    if (low == high)
        return {low, high, arr[low]};

    int mid = (low + high) / 2;

    Subarray left = maxSubarray(arr, low, mid);
    Subarray right = maxSubarray(arr, mid + 1, high);
    Subarray cross = maxCrossing(arr, low, mid, high);

    if (left.sum >= right.sum && left.sum >= cross.sum)
        return left;

    if (right.sum >= left.sum && right.sum >= cross.sum)
        return right;

    return cross;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Subarray result = maxSubarray(arr, 0, n - 1);

    cout << "Maximum subarray: ";

    for (int i = result.left; i <= result.right; i++)
        cout << arr[i] << " ";

    cout << endl;
    cout << "Maximum sum: " << result.sum << endl;

    return 0;
}