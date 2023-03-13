struct Node {
	Node *left, *right;
	ll weight, size;
	ll val, sum, minx;
	bool check;
	Node(ll x) {
		left = 0LL;
		right = 0LL;
		check = 0LL;
		weight = rand();
		val = x;
		minx = x;
		sum = x;
		size = 1LL;
	}

	void pull() {
		minx = val;
		sum = val;
		size = 1LL;
		if (left) {
			minimize(minx, left->minx);
			size += left->size;
			sum += left->sum;
		}
		if (right) {
			minimize(minx, right->minx);
			size += right->size;
			sum += right->sum;
		}

	}

	void push() {
		if (check) {
			check = 0LL, swap(left, right);
			if (left) left->check ^= 1LL;
			if (right) right->check ^= 1LL;
		}
	}
} *root;

class Balance_Binary_Search_Tree {

	public:
		int size(Node *treap) {
			return treap ? treap->size : 0LL;
		}
		ll sum(Node *treap) {
			return treap ? treap->sum : 0LL;
		}
		ll minx(Node *treap) {
			return treap ? treap->minx : 0LL;
		}

		void split(Node *treap, Node *&left, Node *&right, int val) {
			if (!treap) {
				left = right = 0LL;
				return;
			}
			treap->push();
			if (size(treap->left) < val) {
				split(treap->right, treap->right, right, val - size(treap->left) - 1LL);
				left = treap;
			} else {
				split(treap->left, left, treap->left, val);
				right = treap;
			}
			treap->pull();
		}

		void merge(Node *&treap, Node *left, Node *right) {
			if (left == 0LL) {
				treap = right;
				return;
			}
			if (right == 0LL) {
				treap = left;
				return;
			}
			left->push();
			right->push();
			if (left->weight < right->weight) {
				merge(left->right, left->right, right);
				treap = left;
			} else {
				merge(right->left, left, right->left);
				treap = right;
			}
			treap->pull();
		}

		void push_back(Node *treap, ll val) {
			merge(treap, treap, new Node(val));
		}

		void erase(Node *treap, int pos) {
			Node *a, *b, *c;
			split(treap, a, b, pos - 1);
			split(b, b, c, 1LL);
			merge(treap, a, c);
		}

		void insert(Node *treap, int pos, ll val) {
			Node *a, *b;
			split(treap, a, b, pos - 1);
			pb(treap, val);
			merge(treap, a, b);
		}

		void reverse (Node *treap, ll l, ll r) {
			Node *a, *b, *c;
			split(treap, a, b, l);
			split(b, b, c, r - l + 1LL);
			b->check ^= 1LL;
			merge(treap, a, b);
			merge(treap, treap, c);
		}

		ll get_idx(Node *treap, ll val) {
			if (treap == 0LL) return 0LL;
			treap->push();
			if (treap->val == val) return size(treap->left);
			if (treap->right && treap->right->minx <= val) return 1LL + size(treap->left) + get_idx(treap->right, val);
			else return get_idx(treap->left, val);
		}
} BBST;

ostream & operator << (ostream &out, Node *treap) {
	if (!treap) return out;
	treap->push();
	out << treap->left;
	out << treap->val;
	out << treap->right;
	return out;
}
