#include<bits/stdc++.h>
using namespace std;
using node = array<int, 2>;
map<node, set<node>> adj;
void add_edge(node u, node v)
{
    adj[u].insert(v);
    adj[v].insert(u);
}
void del_edge(node u, node v)
{
    adj[u].erase(v);
    adj[v].erase(u);
}
int dfs(node v, node p, vector<node> &path)
{
    path.push_back(v);
    for(node u : adj[v])
    {
        if(u == p) continue;
        if(u == path[0]) return 1;
        if(dfs(u, v, path)) return 1;
    }

    path.pop_back();
    return 0;
}
vector<node> find_cycle(node s)
{
    vector<node> cyc;
    dfs(s, s, cyc);
    return cyc;
}
vector<vector<int>> c, x;
vector<int> a, b, U, V;
int n, m;
void find_uv(node v, node p)
{
    for (node u : adj[v]) {
        if (u == p) continue;
        cout << v[0] << "," << v[1] << endl;
        cout << u[0] << "," << u[1] << endl;

        int i = v[0], j = u[0];

        if (v[1] == 0)      
        {

            V[j] = c[i][j] - U[i];
            cout << "case row→col " << c[i][j] << " " << V[j] << endl;
        }
        else
        {
            U[i] = c[j][i] - V[j];
            cout << "case col→row " << c[j][i] << " " << U[i] << endl;
        }

        find_uv(u, v);
    }
}

int main()
{

    cin >> n >> m;
    a.assign(n, 0); U.assign(n, 0);
    b.assign(m, 0); V.assign(m, 0);
    c.assign(n, vector<int>(m));
    x.assign(n, vector<int>(m));


    for(auto &y : a) cin >> y;
    for(auto &y : b) cin >> y;
    for(auto &row : c) for(auto &y : row) cin >> y;

    node s;
    for(int i = 1; i < n + m; i++)
    {
        int k, l;
        cin >> k >> l;
        add_edge({k, 0}, {l, 1});
        s = {k, 0};
    }

    find_uv(s, s);
    for(int y : U) cout << y << " ";
    cout << endl;
    for(int y : V) cout << y << " ";

}
