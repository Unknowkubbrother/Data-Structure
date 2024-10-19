#include <iostream>
#include <queue>
using namespace std;


class Node{
	public:
		int data;
		Node *left;
		Node *right;
		
		Node(int data){
			this->data = data;
			this->left = NULL;
			this->right = NULL;
		}
};


Node *insert(Node *root, int data){
	if (root == NULL){
		return new Node(data);
	}
	
	if (data < root->data){
		root->left = insert(root->left,data);
	}else if (data >= root->data){
		root->right = insert(root->right,data);
	}
}

void btf(Node *root){
	if (root == NULL){
		return;
	}
	
	queue <Node*> q;
	q.push(root);
	
	while(!q.empty()){
		int level = q.size();
		for(int i=0;i<level;i++){
			Node *temp = q.front();
			q.pop();
			
			cout<<temp->data<<",";
			
			if (temp->left != NULL){
				q.push(temp->left);
			}
			
			if (temp->right != NULL){
				q.push(temp->right);
			}
		}
		cout<<"|";
	}
}

void preOrder(Node *root){
	if (root != NULL){
		cout<<root->data<<",";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(Node *root){
	if (root != NULL){
		inOrder(root->left);
		cout<<root->data<<",";
		inOrder(root->right);
	}
}

void postOrder(Node *root){
	if (root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<",";
	}
}

Node *findMin(Node *root){
	while(root->left != NULL){
		root = root->left;
	}
	return root;
}

Node *removeNode(Node *root, int data){
	if (root == NULL){
		return root;
	}
	
	if (data < root->data){
		root->left = removeNode(root->left,data);
	}else if (data > root->data){
		root->right = removeNode(root->right,data);
	}else {
		if (root->left == NULL && root->right == NULL){
			root = NULL;
		}else if (root-> left != NULL && root->right == NULL){
			root = root->left;
		}else if (root->right != NULL && root->left == NULL){
			root = root->right;
		}else {
			Node *temp = findMin(root->right);
			root->data = temp->data;
			root->right = removeNode(root->right,temp->data);
		}
	}

}


int main(){
	Node *root = NULL;
	char ch;
	do{
		cin>>ch;
		if (ch == 'a'){
			int data;
			cin>>data;
			root = insert(root,data);
		}else if (ch == 'i'){
			inOrder(root);
			cout<<endl;
		}else if (ch == 't'){
			postOrder(root);
			cout<<endl;
		}else if (ch == 'p'){
			preOrder(root);
			cout<<endl;
		}else if (ch == 'b'){
			btf(root);
			cout<<endl;
		}else if (ch == 'd'){
			int data;
			cin>>data;
			root = removeNode(root,data);
		}
	}while(ch != 'x');
	return 0;
}
