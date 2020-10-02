#include <iostream>
#include <queue>
using namespace std;

//Definition of the nodes of BST
class node{
public:
	int data;
	node* left;
	node* right;
	node(int d){    // constructor for creating the node
		data =d;
		left = right=NULL;
	}
};

//For inserting a node in a non -empty BST

node* InsertInBst(node* root,int data){
	if(root == NULL){
		root = new node(data);
		return root;
	}

	if(data<=root->data){
		root->left = InsertInBst(root->left,data);
	}
	else{
		root->right = InsertInBst(root->right,data);
	}
	return root;
}

// Creating a BST from initial values
node* CreateBST(){
	node* root = NULL;
	int data;
	cin>>data;
	while(data!=-1){
		root = InsertInBst(root,data);

		cin>>data;
	}
	return root;
}

//Preorder Traversal of the BST
void PreOrder(node* root){
	if(root == NULL){
		return;
	}

	cout<<root->data<<' ';
	PreOrder(root->left);
	PreOrder(root->right);
}

// Inorder Traversal Of the BST
void InOrder(node* root){
	if(root == NULL){
		return;
	}

	InOrder(root->left);
	cout<<root->data<<' ';
	InOrder(root->right);
}

//PostOrder  Traversal of the BST
void PostOrder(node* root){
	if(root == NULL){
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	cout<<root->data<<' ';
}
// LevelOrder Traversal of the BST
void LevelOrder(node* root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		node* ans = q.front();
		q.pop();
		if(ans == NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<ans->data<<" ";
			if(ans->left){
				q.push(ans->left);
			}
			if(ans->right){
				q.push(ans->right);
			}
		}
	}
}

// Function to print the BST
void Print(node* head){
	while(head){
		cout<<head->data<<"-->";
		head = head->right;
	}
	cout<<"NULL"<<endl;
}


int main(){
	//Creating an empty BST
	node* root = NULL;
	root = CreateBST(); 
	
	 PreOrder(root);
	 cout<<endl;
	 InOrder(root);
	 cout<<endl;
	 PostOrder(root);
	 cout<<endl;
	 LevelOrder(root);
	return 0;
}
