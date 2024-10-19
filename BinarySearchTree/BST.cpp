#include <iostream>
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

class BST{
	public:
		Node *r;
		
		BST(){
			this->r = NULL;
		}
		
		void add(int data){
			if (r==NULL){
				r = new Node(data);
			}else{
				Node *temp = r;
				while(true){
					if (data >= temp->data && temp->right != NULL){
						temp = temp->right;
					}else if (data < temp->data && temp->left != NULL){
						temp = temp->left;
					}else if (data >= temp->data && temp->right == NULL){
						temp->right = new Node(data);
						break; 
					}else if (data < temp->data && temp->left == NULL){
						temp->left = new Node(data);
						break; 
					}else{
						break;
					}
				}
			}
		}
		
		bool search(int id) {
	        Node *n = r;
	        while (n != NULL) {
	            if (n->data > id) {
	                n = n->left;
	            } else if (n->data < id) {
	                n = n->right;
	            } else {
	                return true;
	            }
	        }
	        return false;
    }

		
		int h = 0, t_h = -1;

    void h_high(Node *b) {
        if (b != NULL) {
            t_h++;
            h_high(b->left);
            h_high(b->right);
            if (t_h > h) {
                h = t_h;
            }
            t_h--;
        }
    }

    int height(int v) {
        Node *a = r;
        while (a != NULL) {
            if (a->data > v) {
                a = a->left;
            } else if (a->data < v) {
                a = a->right;
            } else {
                h = 0;
                t_h = -1;
                h_high(a);
                return h;
            }
	    }
	        return -1;
    	}

	    void level(Node *l, int lv) {
	        if (l == NULL) {
	        	return;	
			}
	        if (lv == 0) {
	            cout << l->data << ",";
	        } else {
	            level(l->left, lv - 1);
	            level(l->right, lv - 1);
	        }
	    }
	
	    void Breadth() {
	        for (int i = 0; i <= height(r->data); i++) {
	            level(r, i);
	            cout << "|";
	        }
	        cout << endl;
	    }
		
		void deleteB(int d) {
        if (!search(d)) {
            return;
        }

        Node *p = r;
        Node *parent = NULL;


        while (p != NULL && p->data != d) {
            parent = p;
            if (p->data > d) {
                p = p->left;
            } else {
                p = p->right;
            }
        }

        if (p == NULL){
            return;
        }


        if (p->left == NULL && p->right == NULL) {
            if (p == r) {
                r = NULL;
            } else if (parent->left == p) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
            delete p;
        }

        else if (p->left == NULL || p->right == NULL) {
            Node *c = (p->left != NULL) ? p->left : p->right;
            if (p == r) {
                r = c;
            } else if (parent->left == p) {
                parent->left = c;
            } else {
                parent->right = c;
            }
            delete p;
        }

        else {
            Node *sc = p;
            Node *s = p->right;


            while (s->left != NULL) {
                sc = s;
                s = s->left;
            }

            p->data = s->data;

            if (sc->left == s) {
                sc->left = s->right;
            } else {
                sc->right = s->right;
            }
            delete s;
        }
    }
		
		void breadth(){
			for(int i=0;i<=height(r->data);i++){
				level(r,i);
				cout<<"|";
			}
			cout<<endl;
		}
		
		void preorder(Node *root){
			if(root != NULL){
				cout<<root->data<<",";
				preorder(root->left);
				preorder(root->right);
			}
		}
		
		void postorder(Node *root){
			if(root != NULL){
				postorder(root->left);
				postorder(root->right);
				cout<<root->data<<",";
			}
		}
		
		void inorder(Node *root){
			if(root != NULL){
				inorder(root->left);
				cout<<root->data<<",";
				inorder(root->right);
			}
		}
};

int main(){
	BST *B = new BST();
	char ch;
	do{
		cin>>ch;
		if(ch == 'a'){
			int num;
			cin>>num;
			B->add(num);
		}else if(ch == 'd'){
			int num;
			cin>>num;
			B->deleteB(num);
		}else if(ch == 'b'){
			B->breadth();
		}else if(ch == 'i'){
			B->inorder(B->r);
			cout<<endl;
		}else if(ch == 'p'){
			B->preorder(B->r);
			cout<<endl;
		}else if(ch == 't'){
			B->postorder(B->r);
			cout<<endl;
		}
		
	}while(ch != 'x');
	
}
