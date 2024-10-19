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

int max (int a , int b){
	return (a>b) ? a : b;
}

int height(Node *root){
	if (root == NULL){
		return -1;
	}
	
	int heightLeft = height(root->left);
	int heightRight = height(root->right);
	
	return max( heightLeft ,heightRight ) + 1;
}


int getBalance(Node *root){
	if (root == NULL){
		return 0;
	}
	
	return height(root->left) - height(root->right);
}

Node *rotateRight(Node *n){
	Node *left = n->left;
	Node *leftRight = left->right;
	
	left->right = n;
	n->left = leftRight;
	
	return left;
}


Node *rotateLeft(Node *n){
	Node *right = n->right;
	Node *rightLeft = right->left;
	
	right->left = n;
	n->right = rightLeft;
	
	return right;
}

Node *balance(Node *root){
	int factor = getBalance(root);
	
	if (factor > 1 && getBalance(root->left) >= 0){
		return rotateRight(root);
	}
	
	if (factor < -1 && getBalance(root->right) <= 0){
		return rotateLeft(root);
	}
	
	if (factor > 1 && getBalance(root->left) < 0){
		root->left = rotateLeft(root->left);
		return rotateRight(root);
	}
	
	if (factor < -1 && getBalance(root->right) > 0){
		root->right = rotateRight(root->right);
		return rotateLeft(root);
	}
	
	return root;
}


Node *insert(Node *root,int data){
	if (root == NULL){
		return new Node(data);
	}
	
	if (data < root->data){
		root->left = insert(root->left,data);
	}else if (data >= root->data){
		root->right = insert(root->right,data);
	}
	
	return balance(root);
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
	if (root !=  NULL){
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<",";
	}
}

void btf(Node *root){
	if (root == NULL){
		return;
	}
	
	queue<Node*> q;
	q.push(root);
	
	while(!q.empty()){
		int level = q.size();
		for(int i=0;i<level;i++){
			Node *temp = q.front();
			q.pop();
			
			cout<<temp->data<<",";
			
			if(temp->left != NULL){
				q.push(temp->left);
			}
			
			if (temp->right != NULL){
				q.push(temp->right);
			}
		}
		cout<<"|";
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
	}else if(data > root->data){
		root->right = removeNode(root->right,data);
	}else {
		if (root->left == NULL && root->right == NULL){
			root = NULL;
		}else if (root->left != NULL && root->right == NULL){
			root = root->left;
		}else if (root->left == NULL && root->right != NULL){
			root = root->right;
		}else{
			
			Node *temp = findMin(root->right);
			root->data = temp->data;
			root->right = removeNode(root->right,temp->data);
		}
	}
	
	return balance(root);
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
		}else if ( ch == 'h'){
			cout<<height(root)<<endl;
		}
	}while(ch != 'x');
	return 0;
}
