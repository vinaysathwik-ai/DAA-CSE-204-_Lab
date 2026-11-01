#include <bits/stdc++.h>
using namespace std;
void floydWarshall(int a[100][100], int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][k] != 99999 && a[k][j] != 99999)
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    cout << "Shortest distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 99999)
                cout << "INF ";
            else
                cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}
int main() {
    int n, a[100][100];
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter adjacency matrix (use 99999 for no edge):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    floydWarshall(a, n);
    return 0;
}