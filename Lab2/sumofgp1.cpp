#include <iostream>
using namespace std;

int main()
{
    double a = 1, r, sum = 0;
    int n;

    cout << "Enter r: ";
    cin >> r;

    cout << "Enter n: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        sum = sum + a;
        a = a * r;
    }

    cout << "Sum = " << sum;

    return 0;
}