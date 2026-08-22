#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a = 1, r, sum;
    int n;

    cout << "Enter r: ";
    cin >> r;

    cout << "Enter n: ";
    cin >> n;

    if (r == 1)
        sum = a * n;
    else
        sum = a * (pow(r, n) - 1) / (r - 1);

    cout << "Sum = " << sum;

    return 0;
}