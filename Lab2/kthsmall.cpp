#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter k: ";
    cin >> k;

    if (k < 1 || k > n)
    {
        cout << "Invalid value of k";
        return 0;
    }

    sort(arr, arr + n);

    cout << "Kth smallest element = " << arr[k - 1];

    return 0;
}