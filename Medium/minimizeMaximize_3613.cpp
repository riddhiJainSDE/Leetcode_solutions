class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findpar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findpar(parent[node]);
    }

    bool unite(int u, int v) {
        int pu = findpar(u);
        int pv = findpar(v);
        if (pu == pv) return false;

        if (rank[pu] < rank[pv]) parent[pu] = pv;
        else if (rank[pu] > rank[pv]) parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }
};

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(), edges.end(), [](auto &A, auto &B) {
            return A[2] < B[2];
        });

        DisjointSet dsu(n);
        vector<int> vis;

        for (auto &it : edges) {
            if (dsu.unite(it[0], it[1])) {
                vis.push_back(it[2]);
                if (vis.size() == n - 1) break;
            }
        }

        if (k >= n) return 0;
        sort(vis.begin(), vis.end());
        int ind = vis.size() - (k - 1) - 1;
        return ind >= 0 ? vis[ind] : 0;
    }
};