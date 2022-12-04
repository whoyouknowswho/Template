template <typename T> struct Fenwick_Tree {

	int n;
	vector<T> f;
	
	Fenwick(int _n) : n(_n), f(_n + 1) {}

	void update(int u, T val) {
		assert(0 <= u && u < n);
		++ u;
		for (; u <= n; u += u & -u) f[u] += val;
	}

	T get(int u) const {
		assert(0 <= u && u <= n);
		T res = 0;
		for (; u > 0; u -= u & -u) res += f[u];
		return res;
	}

	T get(int l, int r) const {
		assert(0 <= l && l <= r && r <= n);
		if (l == r) return 0;
		return get(r) - get(l);
	}

	void reset() {
		fill(f.begin(), f.end(), T(0));
	}
	
};
