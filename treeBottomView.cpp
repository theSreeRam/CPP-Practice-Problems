// Problem Name - Tree Bottom View
// Tags - Binary Tree

// Given a binary tree , print the nodes in left to right manner as visible from below the tree

// Input Format
// Level order input for the binary tree will be given.

// Constraints
// No of nodes in the tree can be less than or equal to 10^7

// Output Format
// A single line containing space separated integers representing the bottom view of the tree

// Sample Input
// 1 2 3 4 5 6 -1 -1 -1 -1 -1 -1 -1
// Sample Output
// 4 2 6 3
// Explanation
// The tree looks like

//              1
//           /      \
//        2           3
//     /     \       /
//    4       5     6
// (Note that 5 and 6 are at the same position so we consider the right one to lower)


#include<bits/stdc++.h>
#define ll long long
using namespace std;


class Node{
public:
	ll data;
	ll hd;
	Node *left, *right;

	Node(ll d){
		this->data = d;
		hd = 0;
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

Node *buildLevelOrder(Node *root){
	ll d;
	cin>>d;
	if(d==-1){
		return NULL;
	}
	if(root==NULL){
		root = new Node(d);
	}
	//Now we need to systematically build the level order tree

	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		Node *front = q.front();
		q.pop();
		ll l, r;
		cin>>l;
		if(l!=-1){
			front->left = new Node(l);
			q.push(front->left);
		}
		cin>>r;
		if(r!=-1){
			front->right = new Node(r);
			q.push(front->right);
		}
	}
	return root;
}

//The below code is for printing as per the preorder traversal
void printBottomView(Node *root, ll hd, map<ll,ll>&mp){
	if(root==NULL){
		return;
	}

	mp[hd] = root->data;
	printBottomView(root->left, hd-1, mp);
	printBottomView(root->right, hd+1, mp);
}

//Below code for bottom view but for level order traversal

void printBottomViewLevelOrder(Node *root, map<ll, ll> &mp){
	if(root==NULL){
		return;
	}

	queue<Node*>q;
	q.push(root);
	while(!q.empty()){
		Node *front = q.front();
		q.pop();
		// cout<<"at:"<<front->data<<endl;
		mp[front->hd] = front->data;
		if(front->left){
			front->left->hd = front->hd -1;
			q.push(front->left);
		}
		if(front->right){
			front->right->hd = front->hd +1;
			q.push(front->right);
		}
	}
}

int main(){

	Node *root = NULL;
	root = buildLevelOrder(root);
	// preorder(root);
	map<ll, ll> mp;
	// printBottomView(root, 0, mp);
	printBottomViewLevelOrder(root, mp);
	for(auto x:mp){
		cout<<x.second<<" ";
	}
	cout<<endl;
return 0;
}











