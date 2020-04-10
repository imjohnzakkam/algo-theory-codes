#include<bits/stdc++.h>
#define ll long long int
#define vl vector<ll>
#define vpl vector<pair<ll,ll>>
#define ll max(ll x, ll y) { return (x > y)? x: y; } 
#define LL_MAX INT_MAX
#define nl cout << endl;
using namespace std; 

class node 
{ 
	public: 
	int data; 
	int liss; 
	node *left, *right; 
}; 

int LISS(node *root) 
{ 
	if (root == NULL) 
		return 0; 

	if (root->liss) 
		return root->liss; 

	if (root->left == NULL && root->right == NULL) 
		return (root->liss = 1); 
	int liss_excl = LISS(root->left) + LISS(root->right); 
	int liss_incl = 1; 
	if (root->left) 
		liss_incl += LISS(root->left->left) + LISS(root->left->right); 
	if (root->right) 
		liss_incl += LISS(root->right->left) + LISS(root->right->right); 
	root->liss = max(liss_incl, liss_excl); 
	return root->liss; 
} 

node* newNode(int data) 
{ 
	node* temp = new node(); 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	temp->liss = 0; 
	return temp; 
} 

int32_t main() 
{ 
	node *root	             = newNode(20); 
	root->left		         = newNode(8); 
	root->left->left	     = newNode(4); 
	root->left->right	     = newNode(12); 
	root->left->right->left  = newNode(10); 
	root->left->right->right = newNode(14); 
	root->right		         = newNode(22); 
	root->right->right	     = newNode(25); 
	cout << "Size of the Largest Independent Set is " << LISS(root); 
	return 0; 
} 
