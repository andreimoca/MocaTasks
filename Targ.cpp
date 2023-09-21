/// https://www.pbinfo.ro/probleme/3993/targ
/// Moca Andrei - 100p

#include <bits/stdc++.h>
using namespace std;
const int N(66), INF(1e9);
int n;
int64_t x, a[N];
map<int, int64_t> dp[N];
inline int64_t DP(int const& k, int64_t const& s) {
    if (!s) return 0;
    if (!k) return INF;
    if (dp[k][s]) return dp[k][s];
    int64_t p = s / a[k];
    return dp[k][s] = min(DP(k - 1, s - p * a[k]) + p, DP(k - 1, (p + 1) * a[k] - s) + p + 1);
}
int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cout << DP(n, x);
    return 0;
}
