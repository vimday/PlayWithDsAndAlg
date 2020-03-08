struct Sustainable_DSU
{
    static const int N = 1e5 + 5, M = 2e6 + 5;
    int root[N], lson[M], rson[M], fa[M], rnk[M], tot, n;

    inline void build(int &rt, int l, int r)
    {
        rt = ++tot;
        if (l == r)
        {
            fa[rt] = l;
            return;
        }
        int m = l + r >> 1;
        build(lson[rt], l, m);
        build(rson[rt], m + 1, r);
    }
    inline void init(int _n)
    {
        n = _n;
        tot = 0;
        build(root[0], 1, n);
    }
    inline void Update(int old, int &rt, int p, int v, int l, int r)
    {
        rt = ++tot;
        lson[rt] = lson[old], rson[rt] = rson[old];
        if (l == r)
        {
            fa[rt] = v;
            rnk[rt] = rnk[old];
            return;
        }
        int m = l + r >> 1;
        if (p <= m)
            Update(lson[rt], lson[rt], p, v, l, m);
        else
            Update(rson[rt], rson[rt], p, v, m + 1, r);
    }
    inline void update(int rt, int p, int l, int r)
    {
        if (l == r)
        {
            rnk[rt]++;
            return;
        }
        int m = l + r >> 1;
        if (p <= m)
            update(lson[rt], p, l, m);
        else
            update(rson[rt], p, m + 1, r);
    }
    //返回rt版本p位置fa数组下标
    inline int query(int rt, int p, int l, int r)
    {
        if (l == r)
            return rt;
        int m = l + r >> 1;
        if (p <= m)
            return query(lson[rt], p, l, m);
        else
            return query(rson[rt], p, m + 1, r);
    }
    //返回rt版本p所在并查集fa数组下标
    inline int Find(int rt, int p)
    {
        int now = query(rt, p, 1, n);
        if (fa[now] == p)
            return now;
        else
            return Find(rt, fa[now]);
    }
    //在i时刻合并x和y所在并查集
    inline void Merge(int i, int x, int y)
    {
        root[i] = root[i - 1];
        int px = Find(root[i], x), py = Find(root[i], y);
        if (fa[px] != fa[py])
        {
            if (rnk[px] > rnk[py])
                swap(px, py);
            Update(root[i - 1], root[i], fa[px], fa[py], 1, n);
            if (rnk[px] == rnk[py])
                update(root[i], fa[py], 1, n);
        }
    }
};
