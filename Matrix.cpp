template <typename T> struct Matrix {
	int n, m;
	vector<vector<T>> a;
	Matrix() {};
	Matrix(int _n, int _m) : n(_n), m(_m), a(n, vector<T>(m)) {};

	static Matrix identity(int n) {
		Matrix res(n, n);
		FOR (i, 0, n - 1) res.a[i][i] = 1;
		return res;
	}

	Matrix& operator *= (const Matrix& r) {
		return *this = *this * r;
	}

	Matrix operator * (const Matrix& b) const {
		assert(m == b.n);
		Matrix res(n, b.m);
		FOR(i, 0, n - 1) {
			FOR(j, 0, m - 1) {
				FOR(k, 0, b.m - 1) res.a[i][j] += a[i][k] * b.a[k][j];
			}
		}
		return res;
	}

	Matrix pow(ull _n) const {
		Matrix res = identity(n);
		Matrix a = *this;
		while(_n > 0) {
			if (_n & 1) res = res * a;
			a = a * a;
			_n /= 2;
		}
		return res;
	}

	T get(Matrix b, int idx) {
		T res = 0;
		FOR(k, 0, m - 1) res += a[idx][k] * b.a[k][0];
		return res;
	}
};
