/// https://www.pbinfo.ro/probleme/3543/stringpushpop
/// Moca Andrei - 100p

#include <bits/stdc++.h>
using namespace std;
deque<char> dq;
string s;
bool rev;
int q;
char op, c;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> s;
    for (const char& ch : s)
        dq.push_front(ch);
    s.clear();
    cin >> q;
    while (q--) {
        cin >> op;
        if (op == '5')
            rev = !rev;
        else if (op > '2') {
            if ((op == '3' && !rev) || (op == '4' && rev))
                dq.pop_back();
            else dq.pop_front();
        }
        else {
            cin >> c;
            if ((op == '1' && !rev) || (op == '2' && rev))
                dq.push_back(c);
            else dq.push_front(c);
        }
    }
    while (!dq.empty()) {
        if (rev)
            s += dq.front(), dq.pop_front();
        else s += dq.back(), dq.pop_back();
    }
    cout << s;
    return 0;
}
