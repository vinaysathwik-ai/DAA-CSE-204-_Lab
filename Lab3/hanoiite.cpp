#include <iostream>
#include <stack>
using namespace std;

void moveDisk(stack<int>& a, stack<int>& b, char A, char B)
{
    if (a.empty())
    {
        int disk = b.top();
        b.pop();
        a.push(disk);
        cout << "Move disk " << disk << " from " << B << " to " << A << endl;
    }
    else if (b.empty())
    {
        int disk = a.top();
        a.pop();
        b.push(disk);
        cout << "Move disk " << disk << " from " << A << " to " << B << endl;
    }
    else if (a.top() < b.top())
    {
        int disk = a.top();
        a.pop();
        b.push(disk);
        cout << "Move disk " << disk << " from " << A << " to " << B << endl;
    }
    else
    {
        int disk = b.top();
        b.pop();
        a.push(disk);
        cout << "Move disk " << disk << " from " << B << " to " << A << endl;
    }
}

void towerOfHanoi(int n)
{
    stack<int> A, B, C;

    for (int i = n; i >= 1; i--)
        A.push(i);

    int totalMoves = (1 << n) - 1;

    if (n % 2 == 0)
    {
        for (int i = 1; i <= totalMoves; i++)
        {
            if (i % 3 == 1)
                moveDisk(A, B, 'A', 'B');
            else if (i % 3 == 2)
                moveDisk(A, C, 'A', 'C');
            else
                moveDisk(B, C, 'B', 'C');
        }
    }
    else
    {
        for (int i = 1; i <= totalMoves; i++)
        {
            if (i % 3 == 1)
                moveDisk(A, C, 'A', 'C');
            else if (i % 3 == 2)
                moveDisk(A, B, 'A', 'B');
            else
                moveDisk(B, C, 'B', 'C');
        }
    }
}

int main()
{
    int n;

    cout << "Enter number of disks: ";
    cin >> n;

    towerOfHanoi(n);

    return 0;
}