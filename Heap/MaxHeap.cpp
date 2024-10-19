#include <iostream>
using namespace std;

class Heap{
	public:
		int *arr;
		int size;
		int last;
		
		Heap(int size){
			this->arr = new int[size];
			this->size = size;
			this->last = -1;
		}
		
		void insert(int data){
			if (last < size-1){
				arr[++last] = data;
				int i = last;
				while(i > 0 && arr[i] > arr[(i-1)/2]){
					int temp = arr[i];
					arr[i] = arr[(i-1)/2];
					arr[(i-1)/2] = temp;
					i = (i-1)/2;
				}
			}
		}
		
		int remove(){
			if (last >= 0){
				int temp = arr[0];
				arr[0] = arr[last--];
				int i = 0;
				while(i < size-1){
					int l = i*2+1;
					int r = i*2+2;
					if (l <= last && arr[i] < arr[l] && arr[l] >= arr[r]){
						int temp = arr[i];
						arr[i] = arr[l];
						arr[l] = temp;
						i = l;
					}else if (r <= last && arr[i] < arr[r] && arr[r] > arr[l]){
						int temp = arr[i];
						arr[i] = arr[r];
						arr[r] = temp;
						i = r;
					}else{
						break;
					}					
				}
				return temp;
			}
		}
		
		void print(){
			for(int i=0;i<=last;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
};


int main(){
	Heap *h = new Heap(30);
	char ch;
	do{
		cin>>ch;
		if (ch == 'a'){
			int num;
			cin>>num;
			h->insert(num);
		}else if (ch=='p'){
			h->print();
		}else if (ch == 'd'){
			cout<<h->remove()<<endl;
		}
	}while(ch!='e');
	return 0;
}

