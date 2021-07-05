// Problem Name - Find sum at Level K
// Tags - Trees
// Take input of a generic tree using buildtree() function and also take input K the level at which we need to find the sum.

// Input Format
// Take a generic tree input where you are first given the data of the node and then its no of children. The input is of preorder form and it is assured that the no of children will not exceed 2. The input of the tree is followed by a single integer K.

// Constraints
// 1 <= Nodes in tree <=1000
// 1<K<10

// Output Format
// A single line containing the sum at level K.

// Sample Input
// 1 2
// 2 2
// 3 0
// 4 0
// 5 2
// 6 0
// 7 0
// 2
// Sample Output
// 20
// Explanation
// Here the tree looks like

//                      1                                 Level 0
//                 /          \
//               2              5                         Level 1
//            /      \       /     \
//           3       4      6        7                    Level 2
// Sum at Level 2 = 3 + 4 + 6 + 7 = 20



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

void preorder(Node *root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}


Node *buildTree(Node *root){
	int d, children;
	cin>>d>>children;
	if(root==NULL){
		root = new Node(d);
	}
	if(children==1){
		root->left = buildTree(root->left);
	}
	if(children==2){
		root->left = buildTree(root->left);
		root->right = buildTree(root->right);
	}
	return root;
}

void sumAtLevelK(Node *root, int level, int k, int &sum){
	if(root==NULL){
		return;
	}
	if(level==k){
		sum+= root->data;
	}
	sumAtLevelK(root->left, level+1, k , sum);
	sumAtLevelK(root->right, level+1, k , sum);
}

int main(){

	Node *root = NULL;
	root = buildTree(root);
	int k;
	cin>>k;
	int sum = 0;
	sumAtLevelK(root,0, k, sum);
	cout<<sum<<endl;
return 0;
}





