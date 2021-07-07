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

int arr[10] = {-1};

int main(){

	for(int i=0; i<10; i++){
		cout<<arr[i]<<" ";
	}
return 0;
}