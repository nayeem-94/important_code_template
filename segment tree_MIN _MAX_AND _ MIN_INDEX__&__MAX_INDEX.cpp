// MIN_MAX VALUE AND THEIR INDIX IN A SEGMENT TREE
//  https://codeforces.com/contest/1927/problem/D

#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

template<typename T>
void scan(vector<T> &v) {for (T &x : v) cin >> x;}

struct Node 
{
    int mn, mx, mn_idx, mx_idx;

    Node() = default;

    Node(int _mn, int _mx, int _mn_idx, int _mx_idx) {
        mn = _mn, mx = _mx, mn_idx = _mn_idx, mx_idx = _mx_idx;
    }
};

#define LN (node << 1) + 1
#define RN (node << 1) + 2

class MinMax 
{
    vector<Node> tree;
    int N;

    void build(int node, int l, int r, vector<int> const &a) 
    {
        if (l == r) 
        {
            if (l < (int) a.size()) {
                tree[node] = Node(a[l], a[l], l, l);
            }
            return;
        }

        int m = l + (r - l) / 2;
        build(LN, l, m, a);
        build(RN, m + 1, r, a);

        if (tree[LN].mn < tree[RN].mn) 
        {
            tree[node].mn = tree[LN].mn;
            tree[node].mn_idx = tree[LN].mn_idx;
        } 
        else 
        {
            tree[node].mn = tree[RN].mn;
            tree[node].mn_idx = tree[RN].mn_idx;
        }

        if (tree[LN].mx > tree[RN].mx) {
            tree[node].mx = tree[LN].mx;
            tree[node].mx_idx = tree[LN].mx_idx;
        } else {
            tree[node].mx = tree[RN].mx;
            tree[node].mx_idx = tree[RN].mx_idx;
        }
    }

    Node get(int node, int l, int r, int &x, int &y) 
    {
        if (l > y || r < x) 
        {
            return Node(INT_MAX, INT_MIN, -1, -1);
        }
        if (l >= x && r <= y) 
        {
            return tree[node];
        }

        int m = l + (r - l) / 2;
        Node r1 = get(LN, l, m, x, y);
        Node r2 = get(RN, m + 1, r, x, y);

        Node res;

        if (r1.mn < r2.mn) 
        {
            res.mn = r1.mn;
            res.mn_idx = r1.mn_idx;
        } 
        else 
        {
            res.mn = r2.mn;
            res.mn_idx = r2.mn_idx;
        }

        if (r1.mx > r2.mx) 
        {
            res.mx = r1.mx;
            res.mx_idx = r1.mx_idx;
        } 
        else 
        {
            res.mx = r2.mx;
            res.mx_idx = r2.mx_idx;
        }

        return res;
    }

public:
    MinMax(vector<int> const &a) {
        N = 1;
        while (N < (int) a.size()) {
            N <<= 1;
        }

        tree.assign(2 * N, Node(INT_MAX, INT_MIN, -1, -1));
        build(0, 0, N - 1, a);
    }

    Node get(int l, int r) 
    {
        return get(0, 0, N - 1, l, r);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LUCHADOR
    freopen("/home/joker/Documents/code/in", "r", stdin);
    freopen("/home/joker/Documents/code/out", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        scan(a);

        MinMax sg(a);

        int q;
        cin >> q;

        while (q--) {
            int l, r;
            cin >> l >> r;

            Node x = sg.get(l - 1, r - 1);
            if (x.mn == x.mx) {
                cout << "-1 -1" << endl;
            } else {
                cout << min(x.mn_idx, x.mx_idx) + 1 << " " << max(x.mn_idx, x.mx_idx) + 1 << endl;
            }
        }
        cout << endl;
    }

    return 0;
}