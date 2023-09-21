/// https://www.pbinfo.ro/probleme/3660/unghidrept
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
vector<int> f, cx, cy, freqx, freqy;
unordered_map<int, int> hx, hy;
vector<pair<int, int>> v;
int n, ix, iy, x, y;
long long res;
inline int Find(const int& x) {
    return (x == f[x]) ? x : (f[x] = Find(f[x]));
}
int32_t main() {
    Read(n);
    v.resize(n);
    for (pair<int, int>& P : v) {
        Read(P.first), Read(P.second);
        cx.emplace_back(P.first);
        cy.emplace_back(P.second);
    }
    sort(cx.begin(), cx.end());
    cx.erase(unique(cx.begin(), cx.end()), cx.end());
    for (const int& x : cx)
        hx[x] = ++ix;
    sort(cy.begin(), cy.end());
    cy.erase(unique(cy.begin(), cy.end()), cy.end());
    for (const int& y : cy)
        hy[y] = ++iy;
    f = freqx = freqy = vector<int>(ix + iy + 1);
    for (int i = 1; i <= ix + iy; ++i)
        f[i] = i;
    for (const pair<int, int>& P : v) {
        x = hx[P.first];
        y = hy[P.second] + ix;
        f[Find(x)] = Find(y);
    }
    for (int i = 1; i <= ix; ++i)
        ++freqx[Find(i)];
    for (int i = ix + 1; i <= ix + iy; ++i)
        ++freqy[Find(i)];
    res = -n;
    for (int i = 1; i <= ix + iy; ++i)
        res += 1LL * freqx[i] * freqy[i];
    cout << res;
    exit(0);
}
