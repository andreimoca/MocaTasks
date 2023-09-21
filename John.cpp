/// https://www.pbinfo.ro/probleme/3523/john
/// Moca Andrei - 100p

#include <bits/stdc++.h>
namespace FastRead {
    const int Dim(1e5);
    char buff[Dim];
    int pos, len;
    inline char nc() {
        if (pos == len) {
            pos = 0;
            len = fread(buff, 1, Dim, stdin);
            if (!len) return EOF;
        }
        return buff[pos++];
    }
    template<class T> inline void Read(T& x) {
        char ch;
        int sgn(1);
        while (!isdigit(ch = nc()))
            if (ch == '-')
                sgn = -1;
        x = ch - '0';
        while (isdigit(ch = nc()))
            x = x * 10 + (ch - '0');
        x *= sgn;
    }
}
using namespace FastRead;
using namespace std;
using VI     = vector<int>;
using VVI    = vector<VI>;
using BITSET = bitset<1001>;
using VB     = vector<BITSET>;
int n, m, x, mmax, cmax, curr;
VI v;
VVI retin;
VB f1, f2;
unordered_map<int, int> mp;
int main() {
    Read(n), Read(m);
    retin = VVI(n + 1, VI(m));
    for (int i = 1; i <= n; ++i)
        for (int& x : retin[i]) {
            Read(x);
            v.emplace_back(x);
        }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (const int& x : v)
        mp[x] = ++curr;
    f1 = VB(curr + 1);
    f2 = VB(n + 1);
    for (int i = 1; i <= n; ++i)
        for (int& x : retin[i]) {
            x = mp[x];
            f1[x].set(i);
            f2[i].set(x);
        }
    for (int i = 1; i <= curr; ++i)
        mmax = max(mmax, static_cast<int>(f1[i].count()));
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            cmax = max(cmax, static_cast<int>((f2[i] & f2[j]).count()));
    cout << mmax << '\n' << cmax;
    exit(0);
}
