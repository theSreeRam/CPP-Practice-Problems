// Problem Name - Level Order(Zig Zag)
// Tags- Binary Tree, stacks, BFS Tree traversal

// Given a binary tree. Print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even levels should be printed from right to left.

// Input Format
// Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

// Constraints
// None

// Output Format
// Display the values in zigzag level order in which each value is separated by a space

// Sample Input
// 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
// Sample Output
// 10 30 20 40 50 60 73 


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

void zigZag(Node *root){
	if(root==NULL){
		return;
	}
	stack<Node*> currentLevel, nextLevel;
	bool odd = true;
	currentLevel.push(root);
	while(!currentLevel.empty()){
		Node *front = currentLevel.top();
		currentLevel.pop();
		cout<<front->data<<" ";

		if(odd){
			if(front->left){
				nextLevel.push(front->left);
			}
			if(front->right){
				nextLevel.push(front->right);
			}
		} else{
			if(front->right){
				nextLevel.push(front->right);
			}
			if(front->left){
				nextLevel.push(front->left);
			}
		}

		if(currentLevel.empty()){
			odd = !odd;
			swap(currentLevel, nextLevel);
		}
	}
}

int main(){

	Node *root = NULL;
	root = buildTree(root);

	zigZag(root);

	
return 0;
}





