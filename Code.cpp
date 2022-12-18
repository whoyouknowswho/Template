/*-------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                  |
|  Author: Who you knows Who                                                                                                                       |
|  //My Profile: https://whoyouknowswho.carrd.co/                                                                                                    |
|                                                                                                                                                  |
|               _                                                _                                                                 _               |
|              | |    	                                        | |                                                               | |              |
|              | |                                              | |  __                                                           | |              |
| __        __ | |__    _____      __    __  _____   _   _      | | / /  _____   _____  __        __       ___       __        __ | |__    _____   |
| \ \  /\  / / |  _  \ /  _  \     \ \  / / /  _  \ | | | |     | |/ /  /  _  \ /  _  \ \ \  /\  / / __  /  _ \      \ \  /\  / / |  _  \ /  _  \  |
|  \ \/  \/ /  | | | | | |_| |      \ \/ /  | |_| | | |_| |     |    \  | | | | | |_| |  \ \/  \/ /  \ \_\ \ \_\      \ \/  \/ /  | | | | | |_| |  |
|   \__/\__/   |_| |_| \_____/       \  /   \_____/ \_____/     |_|\__\ |_| |_| \_____/   \__/\__/    \____/           \__/\__/   |_| |_| \_____/  |
|                                    / /                                                                                                           |
|                                   /_/                                                                                                            |
|                                                                                                                                                  |
+-------------------------------------------------------------------------------------------------------------------------------------------------*/

//-----------------[HEADER]-----------------//
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

#pragma               GCC   target ("avx2")
#pragma               GCC   optimization ("O2")
#pragma               GCC   optimization ("O3")
#pragma               GCC   optimize("Ofast")

//-----------------[DEFINE & USING]-----------------//
#define      FOR(i, l, r)   for(long long i = (l); i <= (r); i ++)
#define     FORD(i, l, r)   for(long long i = (l); i >= (r); i --)
#define             sz(x)   (long long)(x).size()
#define            uni(a)   ((a).erase(unique(all(a)), (a).end()))
#define            all(a)   (a).begin(), (a).end()
#define                mp   make_pair
#define                fi   first
#define                se   second
#define                pb   push_back
#define              base   31
#define             fs(a)   fixed << setprecision(a)
#define           mask(i)   (1LL << (i))
#define           full(i)   (mask(i) - 1)
#define         bit(x, i)   ((x) >> (i) & 1LL)
#define     cnt_bit(mask)   __builtin_popcountll(mask)
#define     reset(x, val)   memset(x, val, sizeof(x))
#define Who_you_knows_Who   int main
#define               Yes   cout << "Yes"
#define               YES   cout << "YES"
#define                No   cout << "No"
#define                NO   cout << "NO"

using                  ll = long long;
using                 ull = unsigned long long;
using                  ld = long double;
using                 cll = const long long;
using                 cld = const long double;
using                 pll = pair <ll, ll>;
using                 tll = tuple<ll, ll, ll>;
using                  vl = vector <ll>;
using                 vvl = vector <vl>;
using                vvvl = vector<vvl>;
using                vpll = vector <pll>;

//-----------------[CONSTANTS]-----------------//
clock_t             start = clock();
cll                   MOD = 1e9 + 7;
cll                     N = 1000005;
cll                    NN = 1005;
cll                    oo = 1e17;
cll                    PI = acos(-1.0);

//-----------------[TEMPLATES]-----------------//
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
template <typename T1, typename T2> ll gcd(T1 a, T2 b) {
	return b == 0 ? a : gcd(b, a % b);
}
template <typename T1, typename T2> ll lcm(T1 a, T2 b) {
	return a * b / gcd(a, b);
}
template <typename T1, typename T2> ll min(T1 a, T2 b) {
	return (a < b) ? a : b;
}
template <typename T1, typename T2> ll max(T1 a, T2 b) {
	return (a > b) ? a : b;
}
template <typename T>  using pqg = priority_queue<T, vector<T>, greater<T>>;
template <typename T>  using ordered_set = tree<pair<T, T>, null_type, less<pair<T, T>>, rb_tree_tag, tree_order_statistics_node_update>;
template <int MD> struct ModInt {
		int x;
		constexpr ModInt() : x(0) {}
		constexpr ModInt(ll v) {
			_set(v % MD + MD);
		}
		constexpr static int mod() {
			return MD;
		}
		constexpr explicit operator bool() const {
			return x != 0;
		}
		constexpr ModInt   operator + (const ModInt& a) const {
			return ModInt()._set((ll) x + a.x);
		}
		constexpr ModInt   operator - (const ModInt& a) const {
			return ModInt()._set((ll) x - a.x + MD);
		}
		constexpr ModInt   operator * (const ModInt& a) const {
			return ModInt()._set((ll) x * a.x % MD);
		}
		constexpr ModInt   operator / (const ModInt& a) const {
			return ModInt()._set((ll) x * a.inv().x % MD);
		}
		constexpr ModInt   operator - () const {
			return ModInt()._set(MD - x);
		}
		constexpr ModInt&  operator += (const ModInt& a) {
			return *this = *this + a;
		}
		constexpr ModInt&  operator -= (const ModInt& a) {
			return *this = *this - a;
		}
		constexpr ModInt&  operator *= (const ModInt& a) {
			return *this = *this * a;
		}
		constexpr ModInt&  operator /= (const ModInt& a) {
			return *this = *this / a;
		}
		friend constexpr ModInt operator + (ll a, const ModInt& b) {
			return ModInt()._set(a % MD + b.x);
		}
		friend constexpr ModInt operator - (ll a, const ModInt& b) {
			return ModInt()._set(a % MD - b.x + MD);
		}
		friend constexpr ModInt operator * (ll a, const ModInt& b) {
			return ModInt()._set(a % MD * b.x % MD);
		}
		friend constexpr ModInt operator / (ll a, const ModInt& b) {
			return ModInt()._set(a % MD * b.inv().x % MD);
		}
		constexpr bool operator == (const ModInt& a) const {
			return x == a.x;
		}
		constexpr bool operator != (const ModInt& a) const {
			return x != a.x;
		}
		friend std::istream& operator >> (std::istream& is, ModInt& x) {
			ll val;
			is >> val;
			x = ModInt(val);
			return is;
		}
		constexpr friend std::ostream& operator << (std::ostream& os, const ModInt& x) {
			return os << x.x;
		}
		constexpr ModInt pow(ll k) const {
			ModInt ans = 1, tmp = x;
			while (k) {
				if (k & 1) ans *= tmp;
				tmp *= tmp;
				k >>= 1;
			}
			return ans;
		}
		constexpr ModInt inv() const {
			if (x < 1000111) {
				_precalc(1000111);
				return invs[x];
			}
			int a = x, b = MD, ax = 1, bx = 0;
			while (b) {
				int q = a / b, t = a % b;
				a = b;
				b = t;
				t = ax - bx * q;
				ax = bx;
				bx = t;
			}
			assert (a == 1);
			if (ax < 0) ax += MD;
			return ax;
		}
		static std::vector<ModInt> factorials, inv_factorials, invs;
		constexpr static void _precalc(int n) {
			if (factorials.empty()) {
				factorials = {1};
				inv_factorials = {1};
				invs = {0};
			}
			if (n > MD) n = MD;
			int old_sz = factorials.size();
			if (n <= old_sz) return;
			factorials.resize(n);
			inv_factorials.resize(n);
			invs.resize(n);
			FOR(i, old_sz, n - 1) factorials[i] = factorials[i - 1] * i;
			inv_factorials[n - 1] = factorials.back().pow(MD - 2);
			FORD(i, n - 2, old_sz) inv_factorials[i] = inv_factorials[i + 1] * (i + 1);
			FORD(i, n - 1, old_sz) invs[i] = inv_factorials[i] * factorials[i - 1];
		}
		static int get_primitive_root() {
			static int primitive_root = 0;
			if (!primitive_root) {
				primitive_root = [&]() {
					std::set<int> fac;
					int v = MD - 1;
					for (ll i = 2; i * i <= v; i++) while (v % i == 0) fac.insert(i), v /= i;
					if (v > 1) fac.insert(v);
					FOR(g, 1, MD - 1) {
						bool ok = true;
						for (auto i : fac) if (ModInt(g).pow((MD - 1) / i) == 1) {
								ok = false;
								break;
							}
						if (ok) return g;
					}
					return -1;
				}
				();
			}
			return primitive_root;
		}
	private:
		constexpr inline __attribute__((always_inline)) ModInt& _set(ll v) {
			x = v >= MD ? v - MD : v;
			return *this;
		}
};
template <int MD> std::vector<ModInt<MD>> ModInt<MD>::factorials = {1};
template <int MD> std::vector<ModInt<MD>> ModInt<MD>::inv_factorials = {1};
template <int MD> std::vector<ModInt<MD>> ModInt<MD>::invs = {0};
using mi = ModInt<998244353>;

//-----------------[GRAPH ON MATRIX]-----------------//
ll                  d4x[] = { -1, 1,  0, 0 };
ll                  d4y[] = {  0, 0, -1, 1 };

ll                  d8x[] = { -1,  1,   0, 0, -1, -1,  1, 1 };
ll                  d8y[] = {  0,  0,  -1, 1, -1,  1, -1, 1 };

bool            MULTITEST = false;
string               name = "";

//-----------------[READFILE]-----------------//
void file(string name) {
	if (name == "") return;
	freopen((name + ".inp").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

//----------------------------------[PROBLEM SOLUTION]----------------------------------//

void solve() {
	
}

Who_you_knows_Who() {
	file(name);
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	//-----------------[BUILD TESTCASE]-----------------//
	int testcase;
	if (!MULTITEST) testcase = 1;
	else cin >> testcase;
	//=================================================//

	FOR(i, 1, testcase) {
		solve();
		cout << endl;
	}
}
