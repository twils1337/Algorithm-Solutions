#include "Tests.h"

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
	vector<string> v = { "I", "am", "studying", "for", "this", "interview", "tomorrow" };
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

void LLtoBSTtest()
{
	Node* ll = createLL(10);
	BTree* bst = convertLL(ll);
	cout << endl;
	BFS(bst);
	cout << endl;
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
	cout << "1,234 is " << s << endl;
	s = Int2String(12345);
	cout << "12,345 is " << s << endl;
	s = Int2String(123456);
	cout << "123,456 is " << s << endl;
	s = Int2String(1234567);
	cout << "1,234,567 is " << s << endl;
	s = Int2String(12345678);
	cout << "12,345,678 is " << s << endl;
	s = Int2String(123456789);
	cout << "123,456,789 is " << s << endl;
	s = Int2String(2147483647);
	cout << "2,147,483,647 is " << s << endl;
	s = Int2String(10);
	cout << "10 is " << s << endl;
	s = Int2String(101);
	cout << "101 is " << s << endl;
	s = Int2String(10000001);
	cout << "10,000,001 is " << s << endl;
	s = Int2String(99999999);
	cout << "99,999,999 is " << s << endl;
}

void revCStest()
{
	char s[] = "Hello World!!";
	cout << "B4: " << s << endl;
	revCSV(s);
	cout << "Reverse: " << s << endl;
	cout << "Changed?: " << s << endl;
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