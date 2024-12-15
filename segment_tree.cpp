#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template <typename T>
class SegmentTree {
private:
    vector<T> tree;
    int n;
    T neutralValue;
    function<T(T, T)> merge;

    void build(const vector<T> &arr, int u, int l, int r) {
        if (l == r) {
            tree[u] = arr[l];
            return ;
        }
        int mid = (l+r)/2;
        build(arr, 2*u, l, mid);
        build(arr, 2*u+1, mid+1, r);
        tree[u] = merge(tree[2*u], tree[2*u+1]);
    }

    void update(int u, int l, int r, int idx, T value) {
        if (l == r) {
            tree[u] = value;
            return ;
        }
        int mid = (l+r)/2;
        if (idx <= mid) 
            update(2*u, l, mid, idx, value);
        else
            update(2*u+1, mid+1, r, idx, value);
        tree[u] = merge(tree[2*u], tree[2*u+1]);
    }

    T query(int u, int l, int r, int st, int en) {
        if (en < l || st > r)
            return neutralValue;
        if (st <= l && r <= en)
            return tree[u];
        int mid = (l+r)/2;
        T leftQuery = query(2*u, l, mid, st, en);
        T rightQuery = query(2*u+1, mid+1, r, st, en);
        return merge(leftQuery, rightQuery);
    }

public:
    SegmentTree(const vector<T> &arr, T neutral, function<T(T, T)> mergeFunc) {
        n = arr.size();
        neutralValue = neutral;
        merge = mergeFunc;
        tree.resize(4*n, neutralValue);
        build(arr, 1, 0, n - 1);
    }

    SegmentTree(int sz, T neutral, function<T(T, T)> mergeFunc) {
        neutralValue = neutral;
        merge = mergeFunc;
        tree.resize(4*sz, neutralValue);
    }

    void update(int idx, T value) {
        update(1, 0, n - 1, idx, value);
    }

    T query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    T operator[](size_t i) const {
        if (i >= tree.size()) throw out_of_range("Index out of bound");
        return tree[i];
    }
};

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9, 11};

    auto maxMerge = [](int a, int b) { return max(a, b); };
    SegmentTree<int> maxTree(arr, -1e9, maxMerge);

    cout << "Max in range [1, 4]: " << maxTree.query(1, 4) << '\n';
    maxTree.update(2, 10);
    cout << "Max in range [1, 4] after update: " << maxTree.query(1, 4) << '\n';
    cout << "maxTree[1] : " << maxTree[1] << '\n';
    return 0;
}
