
#include <iostream>

#include <queue>

#include <stack>

#include <cmath>

#include <string>

#include <unordered_map>

using namespace std;



struct BTree

{

	int val;

	BTree* left;

	BTree* right;

	BTree(int v, BTree* l = nullptr, BTree* r = nullptr) :val(v), left(l), right(r) {}

};



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



enum class Order

{

	pre, in, post

};



void DFS(BTree* root, Order o = Order::in)

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

	s.push(t);

	while (!s.empty())

	{

		BTree* sTop = s.top();

		cout << sTop->val << " ";

		s.pop();

		//Pre-Order

		if (sTop->right) s.push(sTop->right);

		if (sTop->left) s.push(sTop->left);

	}

}



void DFS_Test()

{

	BTree* r1 = createSimpleBtree();

	cout << "Pre order:" << endl;

	DFS(r1, Order::pre);

	cout << endl;

	cout << "In order:" << endl;

	DFS(r1);

	cout << endl;

	cout << "Post order:" << endl;

	DFS(r1, Order::post);

	cout << endl;

	cout << "Iter: " << endl;

	DFS_I(r1);

	cout << endl;

	del_BTree(r1);

}



void BFS_Test()

{

	BTree* r1 = createSimpleBtree();

	BFS(r1);

	del_BTree(r1);

}



void Rtime()

{

	int r = 0;

	for (int i = 1; i < 5; ++i)

	{

		cout << "i: " << i << endl;

		for (int j = 1; j <= i; ++j)

		{

			cout << "\tj: " << i << endl;

			for (int k = j; k <= i + j; ++k)

			{

				cout << "\t\tk: " << k << endl;

				for (int l = 0; l < i + j - k; l++)

				{

					cout << "\t\t\tl: " << l << endl;

					++r;

				}

			}

		}

	}

	cout << endl << "R: " << r << endl;

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



void eqPtest()

{

	cout << "(" << endl;

	cout << eq_Parens("(") << endl;

	cout << ")" << endl;

	cout << eq_Parens(")") << endl;

	cout << "(Empty)" << endl;

	cout << eq_Parens("") << endl;

	cout << "())" << endl;

	cout << eq_Parens("())") << endl;

	cout << "((())())()" << endl;

	cout << eq_Parens("((())())()") << endl;

	cout << ")()(" << endl;

	cout << eq_Parens(")()(") << endl;

	cout << "(())" << endl;

	cout << eq_Parens("(())") << endl << endl;

	cout << "(())())" << endl;

	cout << eq_Parens("(())())") << endl << endl;

}



struct Node

{

	int val;

	Node* next;

	Node(int v = 0, Node* n = nullptr) : val(v), next(n) {}

};



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



void RevLLtest()

{

	cout << "Before iter:" << endl << "1 2 3 4 5" << endl;

	Node* n1 = new Node(1);

	Node* n2 = new Node(2);

	Node* n3 = new Node(3);

	Node* n4 = new Node(4);

	Node* n5 = new Node(5);

	n1->next = n2;

	n2->next = n3;

	n3->next = n4;

	n4->next = n5;

	Node* rev = revLLiter(n1);

	cout << "After iter:" << endl;

	if (rev == nullptr)

		cout << "NULL!!!" << endl;

	else

		print(rev);

	cout << endl << endl;

	cout << "Before rec:" << endl << "1 2 3 4 5" << endl;

	Node* m1 = new Node(1);

	Node* m2 = new Node(2);

	Node* m3 = new Node(3);

	Node* m4 = new Node(4);

	Node* m5 = new Node(5);

	m1->next = m2;

	m2->next = m3;

	m3->next = m4;

	m4->next = m5;

	Node* rev1 = revLLrec(m1, nullptr);

	cout << "After:" << endl;

	if (rev1 == nullptr)

		cout << "NULL!!!" << endl;

	else

		print(rev1);

	cout << endl;

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



void midTest()

{

	Node* m1 = new Node(1);

	Node* m2 = new Node(2);

	Node* m3 = new Node(3);

	Node* m4 = new Node(4);

	Node* m5 = new Node(5);

	Node* m6 = new Node(6);

	m1->next = m2;

	m2->next = m3;

	m3->next = m4;

	m4->next = m5;

	m5->next = m6;

	cout << "Mid of:" << endl;

	print(m1);

	cout << endl << "Is " << FindMidLL(m1)->val << endl;

}



//O(n) time complexity

//O(1) space complexity

void revSentTest()

{

	vector<string> v = { "I", "am", "owning", "this", "interview", "tomorrow" };

	for (int i = 0, j = v.size() - 1; i < j; ++i, --j)

	{

		string t = v[i];

		v[i] = v[j];

		v[j] = t;

	}

	for (int i = 0; i < v.size(); ++i)

	{

		cout << v[i] << " ";

	}

	cout << endl;

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





void LLtoBSTtest()

{

	Node* ll = createLL(10);

	BTree* bst = convertLL(ll);

	cout << endl;

	BFS(bst);

	cout << endl;

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





void BSTtoLLTest()

{

	BTree* bst = createSimpleBtree();

	BFS(bst);

	cout << endl << endl;

	Node* ll = convertBST2LL(bst);

	print(ll);

	cout << endl << endl;

	Node* ns = createLL(10);

	BTree* bst1 = convertLL(ns);

	convertBST2LL(bst1);

	BFS(bst1);

	cout << endl;

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

Node *detectCycle(Node *head)

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



void testCycleLL()

{

	Node* n1 = new Node(1);

	Node* n2 = new Node(2);

	Node* n3 = new Node(3);

	Node* n4 = new Node(4);

	Node* n5 = new Node(5);

	Node* n6 = new Node(6);

	n1->next = n2;

	n2->next = n3;

	n3->next = n4;

	n4->next = n5;

	n5->next = n6;

	n6->next = n1;

	bool cycle = cycleDetected(n1);

	cout << "Does LL have a cycle? " << cycle << endl;

	Node* c = detectCycle(n1);

	cout << "Where does the cycle start? " << (c ? c->val : -1) << endl;

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



void Merge2LLTest()

{

	Node* n1 = new Node(1);

	Node* n2 = new Node(2);

	Node* n3 = new Node(3);

	Node* n4 = new Node(4);

	Node* n5 = new Node(5);

	Node* n6 = new Node(6);

	n1->next = n3;

	n3->next = n5;

	n2->next = n4;

	n4->next = n6;

	cout << "Merging:" << endl;

	print(n1);

	cout << endl;

	print(n2);

	cout << endl;

	Node* merge = merge2LL(n1, n2);

	print(merge);

	cout << endl;

}



string Int2String(int num)

{

	if (num == 0) return "zero";

	unordered_map<int, string> um = { { 1000000000, "billion" },{ 1000000,"million" },{ 1000, "thousand" },{ 100, "hundred" },{ 90, "ninety" },

	{ 80,"eighty" },{ 70,"seventy" },{ 60,"sixty" },{ 50, "fifty" },{ 40,"forty" },{ 30,"thirty" },{ 20,"twenty" },

	{ 19,"nineteen" },{ 18,"eighteen" },{ 17,"seventeen" },{ 16,"sixteen" },{ 15,"fifteen" },{ 14,"fifteen" },{ 13,"thirteen" },

	{ 12,"twelve" },{ 11,"eleven" },{ 10,"ten" },{ 9,"nine" },{ 8,"eight" },{ 7,"seven" },{ 6,"six" },{ 5,"five" },{ 4,"four" },

	{ 3,"three" },{ 2,"two" },{ 1,"one" } };

	queue<int> q;

	int dec = 1000000000;

	string result = "";

	if (num < 0)

	{

		result += "negative ";

		num *= -1;

	}

	int counter = 0;

	while (num - dec < 0)

	{

		dec /= 10;

	}

	while (num >= 0 && dec)

	{

		if ((num - dec) >= 0)

		{

			num -= dec;

			++counter;

		}

		else

		{

			q.push(counter);

			counter = 0;

			if (dec != 10 && dec != 100 && um.find(dec) != um.end())

			{

				bool ThreeZeros = true;

				int top = q.front();

				q.pop();

				switch (q.size())

				{

				case 2:

					if (top > 0) //there's a hundred's spot

					{

						result += um[top] + " " + um[100] + " ";

						ThreeZeros = false;

					}

					top = q.front();

					q.pop();

					if (top > 0) //there's a ten's spot

					{

						int next = q.front();

						q.pop();

						if (top >= 2) //it's teens or below

						{

							result += um[top * 10 + next] + " ";

							if (next > 0)

								result += um[next] + " ";

							ThreeZeros = false;

						}

						else // 20 <= num <=99

						{

							result += um[top * 10] + " ";

							if (next > 0)

								um[next] + " ";

							ThreeZeros = false;

						}

					}

					else

					{

						if (q.front() > 0)

							result += um[q.front()] + " ";

						q.pop();

					}

					break;

				case 1:

					if (top > 0) //there's a ten's spot

					{

						ThreeZeros = false;

						int next = q.front();

						q.pop();

						if (top < 2) //it's teens or below

						{

							result += um[top * 10 + next] + " ";

						}

						else // 20 <= num <=99

						{

							result += um[top * 10] + " " + um[next] + " ";

						}

					}

					break;

				case 0:

					result += um[top] + " ";

					break;

				}

				if (dec > 100 && um.find(dec) != um.end() && !ThreeZeros)

				{

					result += um[dec] + " ";

				}

			}

			dec /= 10;

		}

	}

	return result;

}



void Int2StringTest()

{

	string s = Int2String(0);

	cout << "0 is " << s << endl;

	s = Int2String(1);

	cout << "1 is " << s << endl;

	s = Int2String(12);

	cout << "12 is " << s << endl;

	s = Int2String(123);

	cout << "123 is " << s << endl;

	s = Int2String(1234);

	cout << "1234 is " << s << endl;

	s = Int2String(12345);

	cout << "12345 is " << s << endl;

	s = Int2String(123456);

	cout << "123456 is " << s << endl;

	s = Int2String(1234567);

	cout << "1234567 is " << s << endl;

	s = Int2String(12345678);

	cout << "12345678 is " << s << endl;

	s = Int2String(123456789);

	cout << "123456789 is " << s << endl;

	s = Int2String(2147483647);

	cout << "2147483647 is " << s << endl;

	s = Int2String(10);

	cout << "10 is " << s << endl;

	s = Int2String(101);

	cout << "101 is " << s << endl;

	s = Int2String(10000001);

	cout << "10000001 is " << s << endl;

	s = Int2String(99999999);

	cout << "99999999 is " << s << endl;

}



char* revCS(char s[])

{

	char* rev = new char[strlen(s)];

	for (int i = 0, j = strlen(s) - 1; j >= 0; ++i, --j)

	{

		rev[i] = s[j];

	}

	return rev;

}



void revCSV(char s[])

{

	for (int i = 0, j = strlen(s) - 1; i < j; ++i, --j)

	{

		char c = s[i];

		s[j] = c;

	}

}



void revCStest()

{

	char s[] = "Hello World!!";

	cout << "B4: " << s << endl;

	revCSV(s);

	cout << "Reverse: " << s << endl;

	cout << "Changed?: " << s << endl;

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



void fact_test()

{

	long long a = 1, b = 2, c = 3, d = 10, e = 20;

	cout << "Fact. of " << a << ": " << factorial_it(a) << endl;

	cout << "Fact. of " << b << ": " << factorial_it(b) << endl;

	cout << "Fact. of " << c << ": " << factorial_it(c) << endl;

	cout << "Fact. of " << d << ": " << factorial_it(d) << endl;

	cout << "Fact. of " << e << ": " << factorial_it(e) << endl;

	cout << "=====================================================" << endl;

	cout << "Fact. of " << a << ": " << factorial_rec(a) << endl;

	cout << "Fact. of " << b << ": " << factorial_rec(b) << endl;

	cout << "Fact. of " << c << ": " << factorial_rec(c) << endl;

	cout << "Fact. of " << d << ": " << factorial_rec(d) << endl;

	cout << "Fact. of " << e << ": " << factorial_rec(e) << endl;

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



void fib_test()

{

	long long z = 0, a = 1, b = 2, c = 3, d = 10, e = 20;

	cout << "Fib. of " << z << ": " << fib_it(z) << endl;

	cout << "Fib. of " << a << ": " << fib_it(a) << endl;

	cout << "Fib. of " << b << ": " << fib_it(b) << endl;

	cout << "Fib. of " << c << ": " << fib_it(c) << endl;

	cout << "Fib. of " << d << ": " << fib_it(d) << endl;

	cout << "Fib. of " << e << ": " << fib_it(e) << endl;

	cout << "=====================================================" << endl;

	cout << "Fib. of " << z << ": " << fib_rec(z) << endl;

	cout << "Fib. of " << a << ": " << fib_rec(a) << endl;

	cout << "Fib. of " << b << ": " << fib_rec(b) << endl;

	cout << "Fib. of " << c << ": " << fib_rec(c) << endl;

	cout << "Fib. of " << d << ": " << fib_rec(d) << endl;

	cout << "Fib. of " << e << ": " << fib_rec(e) << endl;

	cout << "=====================================================" << endl;

	cout << "Fib. of " << z << ": " << fib(z) << endl;

	cout << "Fib. of " << a << ": " << fib(a) << endl;

	cout << "Fib. of " << b << ": " << fib(b) << endl;

	cout << "Fib. of " << c << ": " << fib(c) << endl;

	cout << "Fib. of " << d << ": " << fib(d) << endl;

	cout << "Fib. of " << e << ": " << fib(e) << endl;

	cout << "=====================================================" << endl;

	cout << "Fib. of " << z << ": " << it_fib(z) << endl;

	cout << "Fib. of " << a << ": " << it_fib(a) << endl;

	cout << "Fib. of " << b << ": " << it_fib(b) << endl;

	cout << "Fib. of " << c << ": " << it_fib(c) << endl;

	cout << "Fib. of " << d << ": " << it_fib(d) << endl;

	cout << "Fib. of " << e << ": " << it_fib(e) << endl;



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



void isBalancedBSTTest()

{

	BTree* root = new BTree(5);

	root->left = new BTree(10);

	root->right = new BTree(15);

	root->left->left = new BTree(20);

	root->left->right = new BTree(25);

	root->right->left = new BTree(30);

	root->right->right = new BTree(35);

	cout << "Is tree balanced? " << isBalanced(root) << endl;

	root->right->right->right = new BTree(40);

	root->right->right->right->right = new BTree(45);

	cout << "Is tree balanced? " << isBalanced(root) << endl;

}

void main()

{

	//DFS_Test();

	//cout << endl;

	//BFS_Test();

	//eqPtest();

	//Rtime();

	//RevLLtest();

	//midTest();

	//revSentTest();

	//LLtoBSTtest();

	//BSTtoLLTest();

	//testCycleLL();

	//Merge2LLTest();

	//Int2StringTest();

	//revCStest();

	//fact_test();

	//fib_test();

	isBalancedBSTTest();

	system("pause");

}