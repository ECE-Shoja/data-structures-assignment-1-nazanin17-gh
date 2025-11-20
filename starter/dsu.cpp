#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sz;

int findSet(int v) {
    while(v!=parent[v])
        {
            parent[v]=parent[parent[v]];
            v=parent[v];
        }
    return v;
}

void unionSet(int a, int b) {
    int roota=findSet(a);
    int rootb=findSet(b);
    if(roota==rootb)
        return;
    if(sz[roota]<sz[rootb])
    {
        parent[roota]=rootb;
        sz[rootb]+=sz[roota];
    }
    else{
        parent[rootb]=roota;
        sz[roota]+=sz[rootb];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    parent.resize(n + 1);
    sz.resize(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    while (q--) {
        char type;
        int a, b;
        cin >> type >> a >> b;

        if (type == '+') {
            unionSet(a, b);
        } else if (type == '?') {
            if (findSet(a) == findSet(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
