// Problem Name - Structurally Identical (Binary Tree)
// Tags - Binary Tree

// Given two trees check if they are structurally identically. Structurally identical trees are trees that have same structure. They may or may not have the same data though.

// Input Format
// Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

// Constraints
// 1 <= N <= 10^4

// Output Format
// Display the Boolean result

// Sample Input
// 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
// 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
// Sample Output
// true
// Explanation
// The given two trees have the exact same structure and hence we print true.



#include<bits/stdc++.h>
using namespace std;

class Node{
public:

	int data;
	Node *left, *right;

	Node(int data){
		this->data = data;
		left = right = NULL;
	}
};

Node *buildTree(Node *root){
	int d;
	cin>>d;
	if(root==NULL){
		root = new Node(d);
	}
	string left, right;
	cin>>left;
	if(left=="true"){
		root->left = buildTree(root->left);
	}
	cin>>right;
	if(right=="true"){
		root->right = buildTree(root->right);
	}
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

bool compare(Node *root1, Node *root2){
	
	if(root1==NULL and root2==NULL){
		return true;
	}

	if(root1==NULL or root2==NULL){
		return false;
	}

	// if((root1->data)!=(root2->data)){
	// 	return false;
	// }

	bool checkLeft = compare(root1->left, root2->left);
	bool checkRight = compare(root1->right, root2->right);

	return checkRight and checkLeft;
}

int main(){

	Node *root1 = NULL, *root2 = NULL;
	root1 = buildTree(root1);
	root2 = buildTree(root2);

	// preorder(root1);
	// cout<<endl;
	// preorder(root2);

	if(compare(root1,root2)){
		cout<<"true"<<endl;
	} else {
		cout<<"false"<<endl;
	}
	
return 0;
}