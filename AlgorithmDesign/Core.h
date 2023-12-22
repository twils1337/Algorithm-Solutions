#pragma once
#include <iostream>
#include <deque>
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

enum class Order
{
	pre, in, post
};

struct Node
{
	int val;
	Node* next;
	Node(int v = 0, Node* n = nullptr) : val(v), next(n) {}
};

int fib(int n);
int it_fib(unsigned int n);
BTree* createSimpleBtree();
void del_BTree(BTree* bt);
bool incr_level(int popped);
void BFS(BTree* t);
void DFS(BTree* root, Order o = Order::in);
void DFS_I(BTree* t);
bool eq_Parens(string p);
void print(Node* n);
Node* revLLiter(Node* l);
Node* revLLrec(Node* curr, Node* prev);
Node* FindMidLL(Node* n);
Node* createLL(int sz);
BTree* LL2BST(Node*& ll, int start, int end);
BTree* convertLL(Node* ll);
void BST2LL(BTree* bst, Node*& head, Node*& l);
Node* convertBST2LL(BTree* b);
bool cycleDetected(Node* ll);
Node* detectCycle(Node* head);
Node* merge2LL(Node* l1, Node* l2);
string Int2String(int num);
char* revCS(char s[]);
void revCSV(char s[]);
long long factorial_it(long long n);
long long factorial_rec(long long n);
long long fib_it(long long n);
long long fib_rec(long long n);
int checkBalanced(BTree* root);
bool isBalanced(BTree* b);
