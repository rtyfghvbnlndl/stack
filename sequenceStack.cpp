#include <iostream>
#define MAX_SIZE 10
using namespace std;


typedef struct{
int data[MAX_SIZE];
int top = -1;
} seq_stack;

void push(seq_stack &s, int value){
    if(s.top + 1 < MAX_SIZE){
        s.data[++s.top] = value;
    }
    else{
        throw invalid_argument("The stack is full.");
    }
}

int pop(seq_stack &s){
    if(s.top > -1){
        return s.data[s.top--];
    }
    else{
        throw invalid_argument("The stack is empty.");
    }
}

int get_top(seq_stack s){
    if(s.top > -1){
        return s.data[s.top];
    }
    else{
        throw invalid_argument("The stack is empty.");
    }
}

bool is_empty_stack(seq_stack s){
    if(s.top == -1){
        return true;
    }
    else{
        return false;
    }
}

 int main(){
    seq_stack a;
    for(int i = 0; i < MAX_SIZE; i++){
        push(a, i);
    }
    
    cout << "TOP:" << get_top(a) << endl;
    for(int i = MAX_SIZE-1; i >= 0; i--){
        cout << "OUT" << i << ":" << pop(a) << endl;
    }
    cout << "is empty stack:" << is_empty_stack(a) << endl;

    return 0;
 }