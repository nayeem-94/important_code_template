#include <bits/stdc++.h>
using namespace std;

vector<int> pr;

void initialize(int n)
{
    pr.clear();
    pr.resize(n);
    iota ( pr.begin() , pr.end(), 0 );
}

int find_captain(int u)
{
    if (pr[u] == u) return u;
   /* int c = find_captain(pr[u]);
    pr[u] = c;
    return c;
    */
    return pr[u] = find_captain(pr[u]); //sortcut int upper three line

}


void join ( int u , int v)
{

    int cu = find_captain(u);
    int cv = find_captain(v);
    pr[cv] = cu;

}

bool issame ( int u , int v)
{
    return  find_captain(u) == find_captain(v); 
}

int main()
{
    int n,q;
    cin >> n >> q;

    initialize(n);
    
    while(q--)
    {
        int type,u,v;
        cin >> type;
        if (type == 0) //join
        {
            cin >> u >> v;
            --u ; --v; // for zero based
            join( u , v);
        }
        if (type == 1) // is the point are same
        {
            cin >> u >> v;
            --u;--v;
            puts( issame(u,v) ? "YES" : "NO");
           
        }
    }


}
