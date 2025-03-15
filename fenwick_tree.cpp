#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template<typename T>
class FenwickTree{
private:
	vector<T> tree;
	int n;
	function<T(T, T)> func;

	void update(int idx, T val){
		for (;idx <= n;idx+=idx&-idx)
			tree[idx] = func(tree[idx], val);
	}

	T query(int idx){
		T res;
		for (;idx > 0;idx-=idx&-idx)
			res = func(res, tree[idx]);
		return res;
	}

public:
	FenwickTree(int sz, function<T(T, T)> fun){
		n = sz;
		tree.resize(n+1);
		func = fun;
	}

	void upd(int idx, T val){
		update(idx, val);
	}

	T qry(int idx){
		return query(idx);
	}
};

int main()
{
	int n = 5;
	auto sum = [](int a, int b) { return a+b; };
	FenwickTree<int> fw(n, sum);

	vector<int> v(n+1, 0);
	for (int i = 0;i <= n;i++)
		v[i] = i;

	for (int i = 1;i <= n;i++)
		fw.upd(i, v[i]);

	for (int i = 1;i <= n;i++){
		cout << "fw.qry(" << i << ") : " << fw.qry(i) << '\n';
	}
}