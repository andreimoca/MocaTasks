/// https://www.pbinfo.ro/probleme/3511/bob
/// Moca Andrei - 100p

#include <bits/stdc++.h>
namespace FastRead {
    const int Dim(1e6);
    char buff[Dim];
    int rpos, len;
    inline char nc() {
        if (rpos == len) {
            rpos = 0;
            len = fread(buff, 1, Dim, stdin);
            if (!len) return EOF;
        }
        return buff[rpos++];
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
typedef long long i64;
class AIB {
    int n;
    vector<i64> aib;
public:
    AIB(const int& _n = 0) : n(_n) {
        aib = vector<i64>(n + 1);
    }
    inline void Update(const int& pos, const i64& val) {
        for (int i = pos; i <= n; i += i & -i)
            if (aib[i] < val)
                aib[i] = val;
    }
    inline i64 Query(const int& pos) {
        i64 maxi(0);
        for (int i = pos; i > 0; i -= i & -i)
            if (aib[i] > maxi)
                maxi = aib[i];
        return maxi;
    }
};
class Boaba {
    int g, p;
public:
    Boaba(const int& _g = 0, const int& _p = 0)
        : g(_g), p(_p) {}
    inline void Bread()
        { Read(g), Read(p); }
    inline void Tie(int& _g, int& _p)
        { _g = g, _p = p; }
};
int n, m, g, p;
unordered_map<int, int> pos;
vector<Boaba> BoB;
vector<int> numbers;
i64 curr, res;
int main() {
    Read(n);
    BoB = vector<Boaba>(n + 1);
    for (int i = 1; i <= n; ++i) {
        BoB[i].Bread();
        BoB[i].Tie(g, p);
        numbers.emplace_back(g);
    }
    sort(numbers.begin(), numbers.end());
    numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
    for (const int& x : numbers)
        pos[x] = ++m;
    AIB arb(m);
    for (int i = 1; i <= n; ++i) {
        BoB[i].Tie(g, p);
        g = pos[g];
        curr = arb.Query(g - 1) + p;
        arb.Update(g, curr);
        res = max(res, curr);
    }
    cout << res;
    return 0;
}
