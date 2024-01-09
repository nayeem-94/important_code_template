//codeforces/contest/131/problem/C

#include<bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int M = 1e9 + 7;
const int N = 40 + 13;

li C[N][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //calculate ncr
    C[0][0] = 1;
    for(int i = 1; i < N; i++) 
    {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }

    // for (int i = 0; i < N; ++i)
    // {
    //     for (int j = 0; j < N; ++j)
    //     {
    //         cout<<C[i][j]<<" ";
    //     }
    // }
    cout<<C[5][4];
    int n, m, t;
    cin >> n >> m >> t;

    li ans = 0;
    for(int x = 4; x + 1 <= t; x++) 
    {
        int y = t - x;
        if(x > n || y > m)
            continue;

        ans += C[n][x] * C[m][y];
    }

    //cout << ans << endl;
}
