#include <iostream>
#include <queue>
#include <vector>
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
	}else if(data >= root->data){
		root->right = insert(root->right,data);
	}
}

Node *findmin(Node *root){
	while (root->left != NULL){
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
	}else{
		if (root->left == NULL && root->right == NULL){
			root = NULL;
		}else if (root->left != NULL && root->right == NULL){
			root = root->left;
		}else if (root->right != NULL && root->left == NULL){
			root = root->right;
		}else{
			Node *temp = findmin(root->right);
			root->data = temp->data;
			root->right = removeNode(root->right,temp->data);
		}
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
			
			if (temp->left != NULL){
				q.push(temp->left);
			}
			
			if (temp->right != NULL){
				q.push(temp->right);
			}
		}
		cout<<"|";
	}
	
	cout<<endl;
	
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

int coutNode(Node *root){
	if (root == NULL){
		return 0;
	}
	
	return 1+coutNode(root->left)+coutNode(root->right);
}

bool isComplete(Node *root){
	if (root == NULL) return true;
	
	queue <Node*> q;
	q.push(root);
	bool end = false;
	
	while(!q.empty()){
		Node *temp = q.front();
		q.pop();
		
		if (temp == NULL){
			end = true;
		}else {
			if (end) return false;
			q.push(temp->left);
			q.push(temp->right);
		}
	}
	
	return true;
	
}

void getInOrder(vector<int> &values,Node *root){
	if (root!=NULL){
		getInOrder(values,root->left);
		values.push_back(root->data);
		getInOrder(values,root->right);
		
	}
}

double Median(Node *root){
	vector<int> values;
	
	getInOrder(values,root);
	
	int n = values.size();
	if (n % 2 == 1){
		return values[n/2];
	}else {
		return (values[(n-1)/2] + values[n/2]) / 2.0;
	}
	
}

int sumInRange(Node* root, int min, int max) {
    if (root == NULL) return 0;

    int sum = 0;
    
    if (root->data >= min && root->data <= max) {
        sum += root->data;
    }
    
    
    if (root->data > min) {
        sum += sumInRange(root->left, min, max);
    }
    
    if (root->data < max) {
        sum += sumInRange(root->right, min, max);
    }
    
    return sum;
}


int main(){
	Node *root = NULL;
	char ch;
	do{
		cin>>ch;
		if (ch ==  'a'){
			int num;
			cin>>num;
			root = insert(root,num);
		}else if(ch == 'b'){
			btf(root);
		}else if (ch == 'i'){
			inOrder(root);
		}else if (ch == 'p'){
			preOrder(root);
		}else if (ch == 't'){
			postOrder(root);
		}else if (ch == 'd'){
			int num;
			cin>>num;
			root = removeNode(root,num);
		}else if (ch == 'n'){
			cout<<coutNode(root)<<endl;
		}else if ( ch == 'c'){
			if (isComplete(root)){
				cout<<"BST Complete"<<endl;
			}else{
				cout<<"BST NOT Complete"<<endl;
			}
		}else if (ch == 'm'){
			cout<<Median(root)<<endl;
		}else if (ch == 's'){
			int num1,num2;
			cin>>num1>>num2;
			cout<<sumInRange(root,num1,num2)<<endl;
		}
		
	}while(ch != 'x');
	return 0;
}

