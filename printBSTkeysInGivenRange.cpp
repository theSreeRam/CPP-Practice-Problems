// Problem Name -  Print BST keys in the given range
// Tags - Binary Search Tree

// You are given an array of integers. First of all , You have to form a binary search tree from given integers. Now you have provided two integers k1 and k2. You have to print all nodes of BST within the range k1 and k2 (including k1 and k2).

// Input Format
// First line contains integer t as number of test cases. Each test case contains three lines. First line contains an integer n which is length of the array and second line contains n space separated integer. Third line contains the value of k1 and k2.

// Constraints
// 1 < t < 20
// 1 < n < 50

// Output Format
// For each test case you have to print preorder traversal of the tree first and then print all nodes within the range k1 and k2 (inclusive). Refer to the sample testcase for exact output format.

// Sample Input
// 1
// 5
// 4 3 2 5 6
// 3 5
// Sample Output
// # Preorder : 4 3 2 5 6 
// # Nodes within range are : 3 4 5 
// Explanation
// The tree looks like

//              4
//           /      \
//        3           5
//     /                \
//    2                  6
// The nodes between the range 3 to 5 are 3,4,5.



#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *left, *right;

	Node(int d){
		this->data = d;
		left=right=NULL;
	}
};

Node *buildBST(int arr[], int n, int s, int e){
	if(s>e){
		return NULL;
	}
	int mid = (s+e)/2;
	Node *root = new Node(arr[mid]);
	root->left = buildBST(arr, n, s, mid-1);
	root->right = buildBST(arr, n, mid+1, e);
	return root;
}	

void preorder(Node *root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

Node *insert(Node *root, int data){
	if(root==NULL){
		root = new Node(data);
		return root;
	}
	if(data < root->data){
		root->left = insert(root->left, data);
	} else {
		root->right = insert(root->right, data);
	}
	return root;
}

void keysInRange(Node *root, int l, int r){
	if(root==NULL){
		return;
	}
	keysInRange(root->left, l, r);
	if(root->data >=l and root->data <=r){
		cout<<root->data<<" ";
	}
	keysInRange(root->right, l, r);
}

int main(){

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		Node *root = NULL;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			root = insert(root, x);
		}
		int l, r;
		cin>>l>>r;
		cout<<"# Preorder : ";
		preorder(root);
		cout<<endl;

		cout<<"# Nodes within range are : ";
		keysInRange(root, l, r);
		cout<<endl;
	}
	
return 0;
}