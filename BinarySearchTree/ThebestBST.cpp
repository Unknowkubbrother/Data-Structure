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


Node *insert(Node *root,int data){
	if (root == NULL){
		return new Node(data);
	}
	
	if (data < root->data){
		root->left = insert(root->left,data);
	}else if(data >= root->data){
		root->right = insert(root->right,data);
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

void btf(Node *root){
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
			if(temp->right != NULL){
				q.push(temp->right);
			}
		}
		cout<<"|";
	}
}

Node *findMin(Node *root){
    while(root->left != NULL) {
        root = root->left;
    }
    return root;
}


void removeNode(Node *&root,int data){
	
	if (root == NULL){
		return;
	}
	
	if (data < root->data){
		removeNode(root->left,data);
	}else if(data > root->data){
		removeNode(root->right,data);
	}else{
		if (root->left == NULL && root->right == NULL){
			root = NULL;
		}else if (root->left != NULL && root->right == NULL){
			root = root->left;
		}else if (root->left == NULL && root->right != NULL){
			root = root->right;
		}else {
			Node *temp = findMin(root->right);
			root->data = temp->data;
			removeNode(root->right, temp->data);
		}
	}	
}

bool search(Node *root,int data){
	if (root == NULL){
		return false;
	}
	
	if (data < root->data){
		search(root->left,data);
	}else if (data > root->data){
		search(root->right,data);
	}else{
		return true;
	}
}


int minNode(Node *root){
	while(root->left != NULL){
		root=root->left;
	}
	
	return root->data;
}

int maxNode(Node *root){
	while(root->right != NULL){
		root=root->right;
	}
	
	return root->data;
}

bool isComplete(Node* root) {
    if (root == NULL) return true;

    queue<Node*> q;
    q.push(root);
    bool end = false;

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            end = true;
        } else {
            if (end) return false;
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return true;
}

int countNodes(Node* root) {
    if (root == NULL) return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
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
			removeNode(root,data);
		}else if ( ch == 's'){
			int num;
			cin>>num;
			cout<< (search(root,num) ? "found" : "not found" )<<endl;
		}else if (ch == 'm'){
			cout<<maxNode(root)<<endl;
		}
		else if (ch == 'n'){
			cout<<minNode(root)<<endl;
		}else if (ch == 'c') {
            if (isComplete(root)) {
                cout << "BST complete" << endl;
            } else {
                cout << "BST not complete" << endl;
            }
        }else if (ch == 'j'){
        	cout<<countNodes(root)<<endl;
		}
	}while(ch != 'x');
	return 0;
}
