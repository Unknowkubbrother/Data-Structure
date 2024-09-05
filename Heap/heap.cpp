#include <iostream>
using namespace std;

class heap{
	public:
		int *arr;
		int size;
		int last;
		heap(int size){
			this->size = size;
			this->arr = new int[size];
			this->last = -1;
		}
		
		void insert(int n){
			if (last <= size-1){
				arr[++last] = n;
				int i = last;
				while(i > 0 && arr[(i-1)/2] < arr[i]){
					int temp = arr[(i-1)/2];
					arr[(i-1)/2] = arr[i];
					arr[i] = temp;
					i = (i-1)/2;
				}
			}
		}
		
		int dequeue(){
			if (last >= 0){
				int top = arr[0];
				arr[0] = arr[last--];
				int p = 0;
				while(p <= size){
					int l = p*2+1;
					int r = p*2+2;
					if(l <= last && arr[l] > arr[p] && arr[l] >= arr[r]){
						int temp = arr[l];
						arr[l] = arr[p];
						arr[p] = temp;
						p = l;
					}else if(r <= last && arr[r] > arr[p] && arr[r] > arr[l]){
						int temp = arr[r];
						arr[r] = arr[p];
						arr[p] = temp;
						p = r;
					}else{
						break;
					}
				}
				return top;
			}
			return -1;
		}
		
		void printlist(){
			for(int i=0;i<=last;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
};

int main(){
	heap *h = new heap(100);
	char ch;
	do{
		cin>>ch;
		if (ch == 'a'){
			int num;
			cin>>num;
			h->insert(num);
		}else if (ch == 'p'){
			h->printlist();
		}else if (ch == 'd'){
			cout<<h->dequeue()<<endl;
		}
	}while(ch != 'e');
}


