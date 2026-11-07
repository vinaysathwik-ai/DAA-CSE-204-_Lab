#include <bits/stdc++.h>
using namespace std;

int matrixChain(int p[], int n) {
    int dp[n][n];

    for (int i = 1; i < n; i++)
        dp[i][i] = 0;

    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n - 1];
}

int main() {
    int n;
    cin >> n;

    int p[n];

    for (int i = 0; i < n; i++)
        cin >> p[i];

    cout << matrixChain(p, n);

    return 0;
}