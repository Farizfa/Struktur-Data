#include <iostream>
using namespace std;

#define MAX_STACK 25
char tumpuk[MAX_STACK]={'H', 'A', '*', '*', '*', 'L', '*', 'O', 'A', 'P', '*', '*', '*', 'A', '*', 'K', 'A', 'B', '*', 'A', '*', '*', '*', 'R'};
char hasil[MAX_STACK];
int top=-1;

bool isFull(){
    if(top == MAX_STACK-1){
        return true;
    }
    else{
        return false;
    }
}

bool isEmpty(){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}

void push(int i)
{
    if(isFull() == 0){
        top++;
        hasil[top] = tumpuk[i];
    }
    else
         cout << "stack penuh";
}

void pop(){
    char x;
    if(isEmpty()==0){
        x = hasil[top];
        hasil[top] = NULL;
        top --;
    }
    else {
        cout << "Stack Kosong" << endl;
    }
}

int main (){
    int a = sizeof(tumpuk)/sizeof(char);
    for(int i = 0; i<a; i++){
        if(tumpuk[i] != '*'){
            push(i);
        }
    }
    int b = sizeof(tumpuk)/sizeof(char);
    for(int j = 0; j < b; j++){
        cout << hasil[j];
    }
    return 0;
}
