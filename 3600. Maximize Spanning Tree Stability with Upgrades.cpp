#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <vector>
#include <numeric>
#include <cstring>
#include <algorithm>

using namespace std;

constexpr int MAX_NODES = 100005;
constexpr int MAX_WEIGHT = 100005;

int Rt[MAX_NODES], Rk[MAX_NODES];
int head[MAX_WEIGHT], next_e[MAX_NODES * 2]; // Assumes edges <= 2*10^5

class UnionFind {
    int component;
public:
    UnionFind(int n) : component(n) {
        memset(Rk, 0, n * sizeof(int));
        iota(Rt, Rt + n, 0);
    }
    
    inline int Find(int x) {
        int root = x;
        while (root != Rt[root]) root = Rt[root];
        int curr = x;
        while (curr != root) {
            int nxt = Rt[curr];
            Rt[curr] = root;
            curr = nxt;
        }
        return root;
    }

    inline bool Union(int x, int y) {
        x = Find(x);
        y = Find(y);
        if (x == y) return false;
        if (Rk[x] > Rk[y]) {
            Rt[y] = x;
        } else {
            Rt[x] = y;
            if (Rk[x] == Rk[y]) Rk[y]++;
        }
        component--;
        return true;
    }
    
    inline int getComponents() const { return component; }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        UnionFind G(n);
        int sMax = 0, sMin = MAX_WEIGHT;
        int score = 2e9; 
        const int E = edges.size();

        memset(head, -1, sizeof(head));

        for (int i = 0; i < E; ++i) {
            int u = edges[i][0], v = edges[i][1], s = edges[i][2], must = edges[i][3];
            if (must) {
                if (!G.Union(u, v)) return -1;
                if (s < score) score = s;
            } else {
                if (s > sMax) sMax = s;
                if (s < sMin) sMin = s;
                next_e[i] = head[s];
                head[s] = i;
            }
        }

        if (G.getComponents() == 1) return score > MAX_WEIGHT ? -1 : score;

        int used = 0, needed = G.getComponents() - 1;
        int minX2 = 2e9, minX1 = 2e9;

        for (int s = sMax; s >= sMin; --s) {
            for (int i = head[s]; i != -1; i = next_e[i]) {
                if (!G.Union(edges[i][0], edges[i][1])) continue;   
                
                used++;
                if (used == needed - k) minX1 = s;
                if (used == needed) {
                    minX2 = s * 2;
                    break;
                }
            }
            if (used == needed) break;
        }

        if (G.getComponents() > 1) return -1;

        int opt_score = minX2;
        if (needed > k && minX1 < opt_score) {
            opt_score = minX1;
        }

        int ans = min(score, opt_score);
        return ans > MAX_WEIGHT * 2 ? -1 : ans;
    }
};
