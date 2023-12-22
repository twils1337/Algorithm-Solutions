#include "core.h"
//time complexity = O(2^n)
int fib(int n)
{
	if (n <= 1)
	{
		return n;
	}
	else
	{
		return fib(n - 1) + fib(n - 2);
	}
}

//time complexity = O(n)
int it_fib(unsigned int n)
{
	if (n <= 1)
	{
		return n;
	}
	int k_1 = 1;
	int k_2 = 0;
	for (int i = 1; i < n; ++i)
	{
		int next = k_1 + k_2;
		k_2 = k_1;
		k_1 = next;
	}
	return k_1;
}


BTree* createSimpleBtree()
{
	BTree* n1 = new BTree(1);
	BTree* n3 = new BTree(3);
	BTree* n2 = new BTree(2, n1, n3);
	BTree* n5 = new BTree(5);
	BTree* n7 = new BTree(7);
	BTree* n6 = new BTree(6, n5, n7);
	BTree* n4 = new BTree(4, n2, n6);
	BTree* n9 = new BTree(9);
	BTree* n11 = new BTree(11);
	BTree* n10 = new BTree(10, n9, n11);
	BTree* n13 = new BTree(13);
	BTree* n15 = new BTree(15);
	BTree* n14 = new BTree(14, n13, n15);
	BTree* n12 = new BTree(12, n10, n14);
	BTree* root = new BTree(8, n4, n12);
	return root;
}

void del_BTree(BTree* bt)
{
	if (bt)
	{
		del_BTree(bt->left);
		del_BTree(bt->right);
		delete bt;
	}
}

bool incr_level(int popped)
{
	int powr = 0;
	while (pow(2, powr) <= popped)
		++powr;

	return pow(2, powr) - 1 == popped;
}

void BFS(BTree* t)
{
	queue<BTree*> q;
	q.push(t);
	int popped = 0, level = 0, plevel = 0;
	while (!q.empty())
	{
		BTree* e = q.front();
		if (incr_level(popped))
		{
			cout << endl;
			cout << "Level " << level << ":" << endl;
			++level;
		}
		cout << e->val << " ";
		++popped;
		q.pop();
		if (e->left) q.push(e->left);
		if (e->right) q.push(e->right);
	}
}

void DFS(BTree* root, Order o)
{
	if (root)
	{
		switch (o)
		{
		case Order::pre:
			cout << root->val << " ";
			DFS(root->left, Order::pre);
			DFS(root->right, Order::pre);
			break;
		case Order::in:
			DFS(root->left, Order::in);
			cout << root->val << " ";
			DFS(root->right, Order::in);
			break;
		case Order::post:
			DFS(root->left, Order::post);
			DFS(root->right, Order::post);
			cout << root->val << " ";
			break;
		default:
			DFS(root->left, Order::in);
			cout << root->val << " ";
			DFS(root->right, Order::in);
			break;
		}
	}
}

void DFS_I(BTree* t)
{
	stack<BTree*> s;
	BTree* current = t;
	bool done = false;
	while (!done)
	{
		if (current)
		{
			s.push(current);
			current = current->left;
		}
		else
		{
			if (!s.empty())
			{
				current = s.top();
				cout << current->val << " ";
				s.pop();
				current = current->right;
			}
			else
			{
				done = true;
			}
		}
	}
}


bool eq_Parens(string p)
{
	if (p == "") return true;
	if (p[0] == ')' || p[p.size() - 1] == '(')
	{
		return false;
	}
	if (p.size() & 1)
	{
		return false;
	}
	stack<char> s;
	for (int i = 0; i < p.size(); ++i)
	{
		if (p[i] == '(')
		{
			s.push(p[i]);
		}
		else
		{
			if (p[i] == ')' && s.top() != '(')
			{
				return false;
			}
			else
			{
				s.pop();
			}
		}
	}
	return true;

}


void print(Node* n)
{
	while (n)
	{
		cout << n->val << " ";
		n = n->next;
	}
}

//O(n) time complexity
//O(1) space complexity
Node* revLLiter(Node* l)
{
	if (!l) return nullptr;
	Node* prev = nullptr;
	Node* curr = l;
	Node* next = l->next;
	while (curr)
	{
		curr->next = prev;
		prev = curr;
		curr = next;
		next = next ? curr->next : nullptr;
	}
	return prev;
}

//O(n) time complexity
//O(1) space complexity
Node* revLLrec(Node* curr, Node* prev)
{
	if (!curr)
		return nullptr;
	if (!curr->next)
	{
		curr->next = prev;
		return curr;
	}
	Node* h = revLLrec(curr->next, curr);
	curr->next = prev;
	return h;
}



//O(n) time complexity
//O(1) space complexity
Node* FindMidLL(Node* n)
{
	if (!n) return nullptr;
	Node* reg = n;
	Node* fast = reg;
	while (fast->next && fast->next->next)
	{
		reg = reg->next;
		fast = fast->next->next;
	}
	return reg;
}

Node* createLL(int sz)
{
	Node* ll = nullptr;
	Node* head = nullptr;
	for (int i = 1; i <= sz; ++i)
	{
		if (!ll)
		{
			ll = new Node(i);
			head = ll;
		}
		else
		{
			Node* nxt = new Node(i);
			ll->next = nxt;
			ll = ll->next;
		}
	}
	return head;

}

//O(n) time complexity
//O(n) space complexity
BTree* LL2BST(Node*& ll, int start, int end)
{
	if (start > end || !ll) return nullptr;
	int mid = start + (end - start) / 2;
	BTree* left = LL2BST(ll, start, mid - 1);
	BTree* root = new BTree(ll->val);
	root->left = left;
	ll = ll->next;
	root->right = LL2BST(ll, mid + 1, end);
	return root;
}

BTree* convertLL(Node* ll)
{
	if (!ll) return nullptr;
	Node* it = ll;
	int sz = 0;
	for (; it != nullptr; ++sz, it = it->next) {} //get list size
	return LL2BST(ll, 0, sz - 1);
}


//O(n) time complexity
//O(n) space complexity
void BST2LL(BTree* bst, Node*& head, Node*& l)
{
	if (bst)
	{
		BST2LL(bst->left, head, l);
		if (!l)
		{
			l = new Node(bst->val);
			head = l;
		}
		else
		{
			l->next = new Node(bst->val);
			l = l->next;
		}
		BST2LL(bst->right, head, l);
	}
}

Node* convertBST2LL(BTree* b)
{
	if (!b)
	{
		return nullptr;
	}
	Node* ll = nullptr;
	Node* l = nullptr;
	BST2LL(b, ll, l);
	return ll;
}



//time complexity O(n)
//space complexity O(1)
bool cycleDetected(Node* ll)
{
	if (!ll || !ll->next) return false;
	Node* reg = ll;
	Node* fast = ll;
	while (reg && fast && fast->next && reg != fast)
	{
		reg = reg->next;
		fast = fast->next->next;
	}
	return reg == fast;
}

//time complexity O(n)
//space complexity O(1) 
Node* detectCycle(Node* head)
{
	if (!head || !head->next) return nullptr;
	Node* reg = head;
	Node* fast = head;
	while (reg && fast && fast->next && reg != fast)   //O(n)
	{
		reg = reg->next;
		fast = fast->next->next;
	}
	if (reg != fast) return nullptr;
	int k = 1;
	reg = reg->next;
	while (reg != fast) //O(n)
	{
		reg = reg->next;
		++k;
	}
	reg = head;
	fast = head;
	while (k--)       //O(n)
	{
		fast = fast->next;
	}
	while (reg != fast)  //O(n)
	{
		reg = reg->next;
		fast = fast->next;
	}
	return reg;
}

Node* merge2LL(Node* l1, Node* l2)
{
	if (!l1) return l2;
	else if (!l2) return l1;
	Node* head = l1->val < l2->val ? l1 : l2;
	Node* tail = head;
	head == l1 ? l1 = l1->next : l2 = l2->next;
	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}
	if (l1) tail->next = l1;
	else if (l2) tail->next = l2;
	return head;
}


string intToString(int num)
{
	if (num == 0) {
		return "zero";
	}
	const unordered_map<int, string> constMap = { 
		{ 1000000000, "billion" }, { 1000000,"million" }, { 1000, "thousand" }, { 100, "hundred" },
		{ 90, "ninety" }, { 80,"eighty" }, { 70,"seventy" }, { 60,"sixty" }, { 50, "fifty" },
		{ 40,"forty" }, { 30,"thirty" }, { 20,"twenty" }, { 19,"nineteen" }, { 18,"eighteen" },
		{ 17,"seventeen" }, { 16,"sixteen" }, { 15,"fifteen" }, { 14,"fifteen" }, { 13,"thirteen" },
		{ 12,"twelve" }, { 11,"eleven" }, { 10,"ten" }, { 9,"nine" }, { 8,"eight" }, { 7,"seven" },
		{ 6,"six" }, { 5,"five" }, { 4,"four" }, { 3,"three" }, { 2,"two" }, { 1,"one" } 
	};

	if (constMap.find(num) != constMap.end()) 
	{
		return constMap.at(num);
	}

	auto numStr = to_string(abs(num));
	int start = numStr.length() >= 3 ? numStr.length() - 3 : 0;
	int end = numStr.length() - 1;
	if (end < 0) 
	{
		return "Error: invalid";
	}
	auto dec = 0;
	stack<string> conversions;

	while (end >= 0)
	{
		string windowConversion = convertNumberWindow(constMap, numStr, start, end);

		conversions.push(windowConversion);
		if (start - 3 > 0) 
		{
			start -= 3;
		}
		else 
		{
			start = 0;
		}
		end -= 3;
	}

	string result = num < 0 ? "negative ": "";
	auto thousandMultiple = 1000;
	auto kPow = 0;
	while (!conversions.empty()) {
		auto top = conversions.top();
		if (top != "") {
			result += conversions.top() + " ";
			if (conversions.size() > 1) {
				auto s = pow(1000, conversions.size() - 1);
				result += constMap.at(pow(1000, conversions.size() - 1)) + " ";
			}
		}
		conversions.pop();
	}
	return result;
}

string convertNumberWindow(const unordered_map<int, string>& constMap, const string num, const int start, const int end) {
	string windowStr = "";
	auto winSize = end - start + 1;
	auto tensSpot = winSize == 3 ? start + 1 : (winSize == 2 ? start : -1);
	auto onesSpot = winSize == 3 ? end : (winSize == 2 ? start + 1 : (winSize == 1 ? start : -1));
	if (winSize == 3)
	{
		if (num[start] != '0') {
			windowStr += (constMap.at(num[start] - '0')) + " hundred ";
		}
		else if (num[start + 1] == '0' && num[end] == '0') {
			return windowStr;
		}
	}
	if (tensSpot >= 0) {
		if (num[tensSpot] == '1') {
			auto rest = 10 + (num[end] - '0');
			windowStr += constMap.at(rest);
			return windowStr;
		}
		else if(num[tensSpot] != '0'){
			windowStr += constMap.at((num[tensSpot] - '0') * 10) + " ";
		}
	}
	if(onesSpot >= 0) {
		windowStr += constMap.at(num[onesSpot] - '0');
	}
	return windowStr;
}


char* revCS(char s[])
{
	char* rev = new char[strlen(s)];
	for (int i = 0, j = strlen(s) - 1; j >= 0; ++i, --j)
	{
		rev[i] = s[j];
	}
	rev[strlen(s)] = 0;
	return rev;
}

void revCSV(char s[])
{
	for (int i = 0, j = strlen(s) - 1; i < j; ++i, --j)
	{
		char c = s[i];
		s[i] = s[j];
		s[j] = c;	
	}
}



long long factorial_it(long long n)
{
	long long res = 1;
	for (int i = 1; i <= n; ++i)
	{
		res *= i;
	}
	return res;
}

long long factorial_rec(long long n)
{
	return n <= 1 ? 1 : n * factorial_rec(n - 1);
}

//time complexity = O(n)
long long fib_it(long long n)
{
	if (n <= 1) return n;
	int f_2 = 0, f_1 = 1, f_n;
	for (int i = 1; i < n; ++i)
	{
		f_n = f_1 + f_2;
		f_2 = f_1;
		f_1 = f_n;
	}
	return f_n;
}
//time complexity = O(2^n)
long long fib_rec(long long n)
{
	return n <= 1 ? n : fib_rec(n - 1) + fib_rec(n - 2);
}


int checkBalanced(BTree* root)
{
	if (!root) return 0;
	int left = checkBalanced(root->left), right = checkBalanced(root->right);
	if (left == -1 || right == -1 || abs(left - right) > 1) return -1;
	else return left > right ? left + 1 : right + 1;
}

bool isBalanced(BTree* b)
{
	if (!b) return true;
	int bal = checkBalanced(b);
	return bal > 1 ? true : false;
}