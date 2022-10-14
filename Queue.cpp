#include<iostream>
using namespace std;

#define MAX 10

struct Antrian {
    int data[MAX];
    int head;
    int tail;
};

Antrian antre;
void create();
bool isEmpty();
bool isFull();
void enqueue();
void dequeue();
void tampil();
void menu(int pil);


int main(){
    int pilih;
    create();
    do{
        cout << "[1] Enqueue" << endl;
        cout << "[2] Dequeue" << endl;
        cout << "[3] Tampil" << endl;
        cout << "[0] Exit" << endl;
        cout << "Masukkan pilihan anda : ";
        cin >> pilih;
        menu(pilih);
    }while(pilih!=0);

    return 0;
}

void menu(int pil) {
    switch(pil){
        case 1 : enqueue(); break;
        case 2 : dequeue(); break;
        case 3 : tampil(); break;
        case 0 : exit(0); break;
        default: cout << "Pilihan tidak tersedia." << endl;
        system("cls");break;
    }
}

void create(){
    antre.head = antre.tail =-1;
}

bool isEmpty(){
    if(antre.tail == -1){
        return true;
    }
    else {
        return false;
    }
}

bool isFull(){
    if(antre.tail == MAX - 1){
        return true;
    }
    else {
        return false;
    }
}

void enqueue(){
    int data;
    cout << "Input data : ";
    cin >> data;
    if(isEmpty()== true){
        antre.head = antre.tail = 0;
        antre.data[antre.tail] = data;
        cout << "data masuk : " << antre.data[antre.tail] << endl;
    }
    else if (isFull() == false){
        antre.tail++;
        antre.data[antre.tail] = data;
        cout << "data masuk " << antre.data[antre.tail] << endl;
    }
    else{
        cout << "Queue penuh " << endl;
    }
    cout << endl;

}

void dequeue(){
    int i, e;
    e = antre.data[antre.head];
    if (isEmpty() == true){
        cout << "Data Kosong " << endl;
    }
    else {
        for(i = antre.head;i <= antre.tail - 1; i++){
        antre.data[i] = antre.data[i+1];
        }
        antre.tail--;
        cout << "data keluar :" << e << endl;
    }
    cout << endl;

}

void tampil(){
    if(isEmpty()== false){
        for(int i = antre.head; i <= antre.tail; i++){
            cout <<antre.data[i] << " " ;
        }
    }
    else{
        cout<<"data kosong";
    }
    cout << endl << endl;
}

