template <typename T> struct Lowest_common_ancestor {
	vector<vector<T>> parent;
	vector<T> d;
	T LOG;

	Lowest_common_ancestor(int _n) : parent(log2(_n), vector<T>(_n)), d(_n), LOG(log2(_n) - 1) {};

	void dfs (int u) {
		for (auto v : adj[u]) {
			if (v == parent[0][u]) continue;
			d[v] = d[u] + 1, parent[0][v] = u, dfs(v);
		}
	}

	void build(int u) {
		dfs(u);
		FOR (k, 1, LOG) FOR(i, 1, n) parent[k][i] = parent[k - 1][parent[k - 1][i]];
	}

	T jump(ll u, ll d) const {
		FORD(i, LOG, 0) if (bit(d, i)) u = parent[i][u];
		return u;
	}

	T get_lca (int u, int v) const {
		if (d[u] < d[v]) swap(u, v);
		u = jump(u, d[u] - d[v]);
		if (u != v) {
			FORD(i, LOG, 0) {
				if (parent[i][u] != parent[i][v]) u = parent[i][u], v = parent[i][v];
			}
		} else return u;
		return parent[0][u];
	}

	T get_dist(int u, int v) const {
		return d[u] + d[v] - 2 * d[get_lca(u, v)];
	}

};
