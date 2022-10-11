#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 20
char arr[20];
int top = -1;

// fungsi untuk menentukan prioritas oprator
int priority ( char alpha ){
    if(alpha == '+' || alpha =='-'){
        return 1;
    }
    if(alpha == '*' || alpha =='/'){
        return 2;
    }
    if(alpha == '$'){
        return 3;
    }
    return 0;
}

// fungsi untuk mengecek antrian sudah penuh atau belum
bool isFull(){
    if(top == MAX - 1){
        return true;
    }
    else{
        return false;
    }
}

// fungsi untuk mengecek antrian kosong atau tidak
bool isEmpty(){
    if(top == -1){
        return true;
    }
    else{
        return false;
    }
}

// prosedur untuk memasukkan operator ke stack
void push(char oper){
    if(isFull()){
        cout << "STACK PENUH" << endl;
    }
    else {
        top++;
        arr[top]=oper;
    }
}

// fungsi untuk menghapus data dari stack
char pop(){
    char ch;

    if(isEmpty()){
        cout << "STACK KOSONG" << endl;
    }
    else{
        ch=arr[top];
        top--;
        return(ch);
    }
    return 0;
}

string infixkeprefix (string infix){
    int i = 0;
    int s = infix.size();
    string pre = "";

    // infix dibalik
    reverse(infix.begin(), infix.end());

    // merubah ( menjadi ) dan ) menjadi ( dalam infix
    for (int i = 0; i < s; i++) {

        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    // perulangan selama urutan terakhir string tidak kosong
    while(infix[i]!='\0') {

        // jika bertemu alfabet, maka masukkan ke variabel
        if(infix[i]>='a' && infix[i]<='z' || (infix[i] >= 'A' && infix[i] <= 'Z')){
            pre.insert(pre.end(),infix[i]);
            i++;
        }

        // jika bertemu kurung buka, maka push ke stack
        else if(infix[i]=='('){
            push(infix[i]);
            i++;
        }

        //jika bertemu kurung tutup, maka pop dari stack
        else if(infix[i]==')'){
            if(infix[i]==')'){
                while(arr[top]!='('){
                    pre.insert(pre.end(),pop());
                }
                pop();
                i++;
            }
        }

        // permisalan jika hanya terdapat operator tanpa kurung tutup
        else{

            // jika stack kosong, push ke stack
            if(isEmpty()){
                push(infix[i]);
                i++;
            }

            // jika prioritas operator kurang dari atau sama dengan operator yang ada di top of stack
            // maka pop operator yang di stack, kemudian masukkan ke pre
            else if(priority(infix[i]) <= priority(arr[top])) {
                pre.insert(pre.end(),pop());

                // jika prioritas operator sama dengan operator di stack, maka akan di pop
                while(priority(arr[top]) == priority(infix[i])){
                    pre.insert(pre.end(),pop());
                    if(top < 0) {
                        break;
                    }
                }
                push(infix[i]);
                i++;
            }

            // jika prioritas operator lebih tinggi, push operator ke stack
            else if(priority(infix[i]) > priority(arr[top])) {
                push(infix[i]);
                i++;
            }
        }
    }

    // perulangan untuk menghapus semua operator dari stack
    while(top!=-1){
        pre.insert(pre.end(),pop());
    }
    reverse(pre.begin(), pre.end());
    cout << "Hasil konversi ke postfix : " << pre << endl;
    return pre;
}

int main(){
    string infix;

    cout << "Masukkan Infix : ";
    cin >> infix;
    cout << endl;

    infixkeprefix(infix);

    return 0;
}
