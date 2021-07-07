// Problem Name - Is_Balanced(Binary Tree)
// Tags - Binary Tree

// Given a Binary tree check if it is balanced i.e. depth of the left and right sub-trees of every node differ by 1 or less.

// Input Format
// Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

// Constraints
// 1 <= No of nodes <= 10^5

// Output Format
// Display the Boolean result

// Sample Input
// 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
// Sample Output
// true
// Explanation
// The tree looks like

//              10
//           /       \
//        20           30
//     /     \       /     \
//    40      50    60      73
// The given tree is clearly balanced as depths of the left and right sub-trees of every node differ by 1 or less.


#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *left, *right;
	Node(int d){
		this->data = d;
		left = right = NULL;
	}
};



void preorder(Node *root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

Node *buildTree(Node *root){
	int d;
	cin>>d;
	if(root==NULL){
		root = new Node(d);
	}
	string l, r;
	cin>>l;
	if(l=="true"){
		root->left = buildTree(root->left);
	}
	cin>>r;
	if(r=="true"){
		root->right = buildTree(root->right);
	}
	return root;
}

int isBalanced(Node *root){
	if(root==NULL){
		return 0;
	}
	int ls = isBalanced(root->left);
	int rs = isBalanced(root->right);
	if(ls==-1 or rs==-1){
		return -1;
	}
	if(abs(ls-rs)<=1){
		return max(ls, rs) + 1;
	} else {
		return -1;
	}
}

int main(){

	Node *root = NULL;
	root = buildTree(root);
	if(isBalanced(root)==-1){
		cout<<"false"<<endl;
	} else {
		cout<<"true"<<endl;
	}

return 0;
}









