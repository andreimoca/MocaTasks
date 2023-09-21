/// https://www.pbinfo.ro/probleme/4111/triangle-dp
/// Moca Andrei - 100p

#include <iostream>
using namespace std;

int const N(255);

int n, v[N];
int64_t dp[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int len = 3; len <= n; ++len)
        for (int i = 1; i <= n; ++i) {
            int j = i + len - 1;
            if (j > n) break;
            for (int k = i + 1; k <= j - 1; ++k)
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + 1LL * v[i] * v[j] * v[k]);
        }
    cout << dp[1][n];
    return 0;
}
