/// https://www.pbinfo.ro/probleme/3556/xorsum
/// Moca Andrei - 100p

#include <bits/stdc++.h>
using namespace std;

string const& task("beculete2");
ifstream fin(task + ".in");
ofstream fout(task + ".out");

class Beculete {
public:
    Beculete(int const& _n = 0) 
        : n(_n) {}

    inline void Compute(int const& op, int const& x, int const& y) {
        if (op == 1) {
            aibUpdate(x);
            aibUpdate(y + 1);
        }
        if (op == 2) {
            if (aibQuery(x) & 1)
                fout << "A\n";
            else fout << "S\n";
        }
    }
    
private:
    inline void aibUpdate(int const& pos) {
        for (int i = pos; i <= n; i += i & -i)
            ++aib[i];
    }

    inline int aibQuery(int const& pos) {
        int s = 0;
        for (int i = pos; i >= 1; i -= i & -i)
            s += aib[i];
        return s;
    }

    unordered_map<int, int> aib;
    int n;
};

int n, q, op, x, y;

int main() {

    fin >> n >> q;

    Beculete B(n);

    while (q--) {
        fin >> op >> x;
        if (op == 1)
            fin >> y;
        B.Compute(op, x, y);
    }

    fin.close();
    fout.close();
    return 0;
}
