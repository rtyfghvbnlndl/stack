#include <iostream>
#include <stdlib.h>
using namespace std;

//链栈，无头结点

typedef struct lnode{
    int value;
    lnode* next;
} *linked_stack, lnode;

class linked_stack_class{
    public:
    linked_stack s = NULL;
    //从另一个栈复制，传入栈的指针。
    void super(linked_stack o){
        destroy();
        lnode** p_next = &s;
        while(o != NULL){
            lnode* n = new_node(o->value);
            insert_next(*p_next, n);
            p_next = &(n->next);
            o = o->next;
        }
    }
    //入栈
    void insert(int value){
        lnode* n = new_node(value);
        n->next = s;
        s = n;
    }
    //读取栈顶部值
    int read_top(){
        if(s != NULL){
            return s->value;
        }
        else{
            throw range_error("The stack is empty!");
        }
    }
    //出栈
    int pop(){
        if(s != NULL){
            int value = s->value;
            del_node();
            return value;
        }
        else{
            throw range_error("The stack is empty!");
        }
    }
    //删除栈
    void destroy(){
        while(s != NULL){
            del_node();
        }
    }

    private:
        void del_node(){
            lnode* p = s;
            s = p->next;
            free(p);
        }

        void insert_next(lnode* & p_next, lnode* n){
            n->next = p_next;
            p_next = n;
        }

        lnode* new_node(int value){
            lnode* n = (lnode*)malloc(sizeof(lnode));
            n->value = value;
            return n;
        }
};

int main(){
    linked_stack_class a;

    for(int i = 100; i < 2000; i += 100){
        a.insert(i);
    }
    cout << a.read_top() << endl;
    for(int i = 100; i < 2000; i += 100){
        cout << a.pop() << endl;
    }

    linked_stack_class b;
    for(int i = 100; i < 2000; i += 100){
        a.insert(i);
    }
    b.super(a.s);
    for(int i = 100; i < 2000; i += 100){
        cout << b.pop() << endl;
    }

    a.destroy();
  
}