/// https://www.pbinfo.ro/probleme/3491/fill-1221
/// Moca Andrei - 100p

#include <bits/stdc++.h>
using namespace std;
const int di[] {-1,  0, 1, 0};
const int dj[] { 0, -1, 0, 1};
const int N(1005);
char mat[N][N], *nl;
int n, m, iv, jv, cnt;
inline void FilleazaVecini(int i, int j);
inline void Fill(int i, int j);
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; ++i)
        gets(mat[i] + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (mat[i][j] == '.')
                Fill(i, j);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (mat[i][j] == '.') {
                printf("%s", "altadata");
                return 0;
            }
    for (int i = 1; i <= n; ++i)
        printf("%s\n", mat[i] + 1);
    return 0;
}
void FilleazaVecini(int i, int j) {
    for (int dir = 0; dir < 4; ++dir) {
        iv = i + di[dir];
        jv = j + dj[dir];
        if (mat[iv][jv] == '.')
            Fill(iv, jv);
    }
}
void Fill(int i, int j) {
    cnt = 0;
    for (int dir = 0; dir < 4; ++dir) {
        iv = i + di[dir];
        jv = j + dj[dir];
        cnt += (mat[iv][jv] == '.');
    }
    if (cnt == 1) {
        if (mat[i-1][j] == '.') {
            mat[i-1][j] = '^', mat[i][j] = 'v';
            FilleazaVecini(i - 1, j);
        }
        if (mat[i][j-1] == '.') {
            mat[i][j-1] = '<', mat[i][j] = '>';
            FilleazaVecini(i, j - 1);
        }
        if (mat[i+1][j] == '.') {
            mat[i][j] = '^', mat[i+1][j] = 'v';
            FilleazaVecini(i + 1, j);
        }
        if (mat[i][j+1] == '.') {
            mat[i][j] = '<', mat[i][j+1] = '>';
            FilleazaVecini(i, j + 1);
        }
    }
}
