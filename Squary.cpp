/// https://www.pbinfo.ro/probleme/3474/squary
/// Moca Andrei - 100p

#include <bits/stdc++.h>
using namespace std;
vector<int> prime{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293};
unordered_map<int64_t, int> freq;
int n, x, ind, p, res, pos[300], exponent;
int64_t mask;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    for (int i = 0; i < 62; ++i)
        pos[prime[i]] = i;
    freq[0] = 1;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        ind = 0;
        while (x > 1) {
            p = prime[ind++];
            if (p * p > x)
                p = x;
            exponent = 0;
            while (x % p == 0)
                x /= p, ++exponent;
            if (exponent & 1)
                mask ^= (1LL << pos[p]);
        }
        res += freq[mask];
        ++freq[mask];
    }
    cout << res;
    return 0;
}
