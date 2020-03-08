#include<bits/stdc++.h>
using namespace std;
namespace DSU2 {
const static int MAXN = 100000 + 10;
int fa[MAXN], ds[MAXN], rk[MAXN];
int S[MAXN], top;
void init(int n) {

    for (int i = 1; i <= n; ++i) {

        fa[i] = i, rk[i] = ds[i] = 0;

    }

    top = 0;

}
int dis(int x) {

    int r(0);

    for (; x != fa[x]; x = fa[x]) r ^= ds[x];

    return r;

}
int get(int x) {

    while (x != fa[x]) x = fa[x];

    return fa[x];

}
void merge(int x, int y, int d) {

    x = get(x);

    y = get(y);

    if (x == y) return;

    if (rk[x] > rk[y]) std::swap(x, y);

    if (rk[x] == rk[y]) ++rk[y], S[++top] = -y;

    fa[x] = y;

    ds[x] = d;

    S[++top] = x;

}
void restore(int ed) {

    for (; top > ed; --top) {

        if (S[top] < 0) --rk[-S[top]];

        else fa[S[top]] = S[top], ds[S[top]] = 0;

    }

}
};
struct UFS {
    stack<pair<int*, int>> stk;
    int fa[N], rnk[N];
    inline void init(int n) {
        for (int i = 0; i <= n; ++i) fa[i] = i, rnk[i] = 0;
    }
    inline int Find(int x) {
        while(x ^ fa[x]) x = fa[x];
        return x;
    }
    inline void Merge(int x, int y) {
        x = Find(x), y = Find(y);
        if(x == y) return ;
        if(rnk[x] <= rnk[y]) {
            stk.push({fa + x, fa[x]});
            fa[x] = y;
            if(rnk[x] == rnk[y]) {
                stk.push({rnk + y, rnk[y]});
                rnk[y]++;
            }
        } else {
            stk.push({fa + y, fa[y]});
            fa[y] = x;
        }
    }
    inline void Undo() {
        *stk.top().first = stk.top().second;
        stk.pop();
    }
} ufs;
