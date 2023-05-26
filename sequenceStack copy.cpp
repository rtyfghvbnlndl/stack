#include <iostream>
#include <stdlib.h>
using namespace std;


typedef struct{
int* data;
int top = -1;
} seq_stack;

void push(seq_stack &s, int value, int b){
    if(s.top + 1 < b){
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

 int a(int b){
    seq_stack a;
    int* d = (int*)malloc(sizeof(int)*b);
    a.data = d;

    for(int i = 0; i < b; i++){
        push(a, i, b);
    }
    
    cout << "TOP:" << get_top(a) << endl;

    cout << "is empty stack:" << is_empty_stack(a) << endl;
    free(d);
    return 0;
 }

 int main(){
    int b = 2147483647;
    while(1){
        try{
            a(-- b);
        }catch(invalid_argument){
            continue;
        }
        cout<< b <<endl;
        break;
    }
 }