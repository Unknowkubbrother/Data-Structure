   #include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class process {
public:
    int id;
    int at;
    int st;

    process() {}

    process(int id, int at, int st) {
        this->id = id;
        this->at = at;
        this->st = st;
    }
};

class stack {
public:
    int size;
    int top;
    process *arr;

    stack(int size) {
        this->size = size;
        this->top = -1;
        this->arr = new process[size];
    }

    void push(process data) {
        if (!full()) {
            this->arr[++top] = data;
        }
    }

    process pop() {
        if (!empty()) {
            return this->arr[top--];
        }
        return process();
    }

    bool full() {
        return top >= size - 1;
    }

    bool empty() {
        return top == -1;
    }
};

bool compareSort(process a, process b) {
    return a.at < b.at;
}

int main() {
    int size;
    cin >> size;
    process p[size];
    stack *s = new stack(size);
    int serviceTimeAll = 0;
    for (int i = 0; i < size; i++) {
        int id, at, st;
        cin >> id >> at >> st;
        p[i] = process(id, at, st);
        serviceTimeAll += st;
    }
    sort(p, p + size, compareSort);
    int round = 0;
    while (round < serviceTimeAll) {
        for (int i = 0; i < size; i++) {
            if (p[i].at <= round && p[i].at != -1) {
               s->push(p[i]);
               p[i].at = -1;
            }
        }
        while (!s->empty()) {
        	process temp = s->pop();
        	for(int i=0;i<temp.st ;i++){
        		cout<<temp.id<<":"<<temp.st-i<<endl;
        		round++;
			}
    	}
	}

    return 0;
}

