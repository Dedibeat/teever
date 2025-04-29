#include<bits/stdc++.h>
using namespace std;
int n, m, suma = 0, sumb = 0, add = 0;
int main()
{
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        suma += a[i];
    }
    for(int j = 0; j < m; j++)
    {
        cin >> b[j];
        sumb += b[j];
    }
    if(suma < sumb)
    {
        cout << "Niit nuuts hureltsehgui baina\n";
        return 0;
    }
    if(suma > sumb)
    {
        b.push_back(suma - sumb);
        add = 1;
    }

    vector<vector<int>> c(n, vector<int>(m + add));
    vector<vector<int>> x(n, vector<int>(m + add));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> c[i][j];
    
    set<array<int, 3>> st;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m + add; j++)
            st.insert({c[i][j], i, j});
    
    auto remove_row = [&](int i)
    {
        for(int j = 0; j < m + add; j++)
        {
            if(st.count({c[i][j], i, j}))
                st.erase({c[i][j], i, j});
        }
    };

    auto remove_col = [&](int j)
    {
        for(int i = 0; i < n; i++)
        {
            if(st.count({c[i][j], i, j}))
                st.erase({c[i][j], i, j});
        }
    };

    auto alloc = [&](int i, int j)
    {
        int amnt = min(a[i], b[j]);
        a[i] -= amnt;
        b[j] -= amnt;

        if(a[i] == 0)
            remove_row(i);
        if(b[j] == 0)
            remove_col(j);

        x[i][j] = amnt;
    };


    while(!st.empty())
    {
        auto [_, i, j] = *st.begin();
        alloc(i, j);
    }


    int total_cost = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            total_cost += c[i][j] * x[i][j];
    }

    cout << "Zardal :" << total_cost << "\n";
}
