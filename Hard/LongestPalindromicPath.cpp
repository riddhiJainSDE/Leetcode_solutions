
class Solution {
    bool isConnected[14][14];
    int dp[1<<14][14][14];
    int helper(vector<vector<int>>& adj, const string &s, int u, int v, int mask) {
        if (u == v) 
            return 1;
        int &res = dp[mask][u][v];
        if (res != -1) 
            return res;
        int best = 0;   
        for (int nu : adj[u]) {      
            if (mask & (1<<nu)) continue;
            for (int nv : adj[v]) {
                if (mask & (1<<nv)) continue;            
                if (s[nu] != s[nv]) continue;          
                int val = helper(adj, s, nu, nv, mask | (1<<nu) | (1<<nv));
                best = max(best, val);
            }
        }
        if (best == 0 && isConnected[u][v]) {
            return res = 2;
        }
        return res = (best > 0 ? best + 2 : 0);
    }

public:
    int maxLen(int n, vector<vector<int>>& edges, string label) {
       
        memset(isConnected, 0, sizeof(isConnected));
        memset(dp, -1, sizeof(dp));
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            int a = e[0], b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            isConnected[a][b] = isConnected[b][a] = true;
        }

        int answer = 1; 
      
        for (int u = 0; u < n; u++) {
            for (int v = u+1; v < n; v++) {
                if (label[u] == label[v]) {
                    int len = helper(adj, label, u, v, (1<<u)|(1<<v));
                    answer = max(answer, len);
                }
            }
        }
        return answer;
    }
};