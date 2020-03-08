#include<vector>
struct DSU {
    std::vector<int> data;
    void init(int n) {

        data.assign(n, -1);

    }
    bool unionSet(int y, int x) {

        x = root(x);

        y = root(y);

        if (x != y) {

            if (data[y] < data[x]) std::swap(x, y);

            data[x] += data[y];

            data[y] = x;

        }

        return x != y;

    }
    bool same(int x, int y) {

        return root(x) == root(y);

    }
    int root(int x) {

        return data[x] < 0 ? x : data[x] = root(data[x]);

    }
    int size(int x) {

        return -data[root(x)];

    }
};
