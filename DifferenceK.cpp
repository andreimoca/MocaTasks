/// https://www.pbinfo.ro/probleme/3545/drumetie
/// Moca Andrei - 100p

#include <bits/stdc++.h>
using namespace std;
const int MOD(1e9 + 7);
inline void ModAdd(int& a, const int& b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}
int n, p, k, x, res;
bool t;
int main() {
    cin >> n >> p >> k >> x;
    vector<vector<int>> dp(2, vector<int>(p + 1));
    dp[0][x] = 1;
    if (!x)
        fill(dp[0].begin(), dp[0].end(), 1);
    for (int i = 2; i <= n; ++i) {
        t = !t;
        cin >> x;
        fill(dp[t].begin(), dp[t].end(), 0);
        if (!x) {
            for (int j = 1; j <= p; ++j)
                for (int r = max(1, j - k); r <= min(p, j + k); ++r)
                    ModAdd(dp[t][j], dp[!t][r]);
        }
        else for (int r = max(1, x - k); r <= min(p, x + k); ++r)
            ModAdd(dp[t][x], dp[!t][r]);
    }
    for (int j = 1; j <= p; ++j)
        ModAdd(res, dp[t][j]);
    cout << res;
    return 0;
}
