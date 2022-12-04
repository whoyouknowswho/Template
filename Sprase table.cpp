template <typename T> struct Sprase_table {
    vector<vector<T>> MIN, MAX, GCD;
    
	Sprase_table(int _n, int _m) : MIN(_n, vector<T>(_m)), MAX(_n, vector<T>(_m), GCD(_n, vector<T>(_m) {};
    
    void build() {
        FOR(i, 1, n) MIN[i][0] = a[i], MAX[i][0] = a[i], GCD[i][0] = a[i];
        FOR(k, 1, log2(n)) {
            FOR(i, 1, n + 1 - mask(k)) {
                MAX[i][k] = max(MAX[i][k - 1], MAX[i + (1 << (k - 1))][k - 1]);
                MIN[i][k] = min(MIN[i][k - 1], MIN[i + (1 << (k - 1))][k - 1]);
                GCD[i][k] = __gcd(GCD[i][k - 1], GCD[i + (1 << (k - 1))][k - 1]);
            }
        }
    }

    T get(ll l, ll r, string type) {
        ll k = log2(r - l + 1);
        if (type == "gcd") return __gcd(GCD[l][k], GCD[r - mask(k) + 1][k]);
        if (type == "min") return min(MIN[l][k], MIN[r - mask(k) + 1][k]);
        if (type == "max") return max(MAX[l][k], MAX[r - mask(k) + 1][k]);
    }

};
