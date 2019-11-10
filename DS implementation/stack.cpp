#include <iostream>
#define maxsize 20
using namespace std;

class Stack{
    int top;
    int a[maxsize];
public:
    Stack();
    bool isfull();
    bool isempty();
    void push(int x);
    void pop();
    void display();
    void Top();
    void Size();
};

Stack::Stack(){
    top=0;
}

bool Stack::isfull(){
    if(top==maxsize) return true;
    else return false;
}

bool Stack::isempty(){
    if(top==0) 
        return true;
    else 
        return false;
}

void Stack::push(int x){
    if(isfull()){
        cout << "Stack is full" <<'\n';
        return; 
    }
    else{
        a[top]=x;
        top++;
    }
}

void Stack::pop(){
    if(isempty()){
        cout << "nothing in list" << '\n';
        return;
    }
    else 
    {
      top--;
      cout<< "pops " << a[top] <<'\n';  
    }

}

void Stack::display(){
    if(top==0){
        cout << "nothing to display" << '\n';
    }
    else{
        cout << "the elements in stack are" <<'\n';
        for(int i=0;i<top;i++){
            cout << a[i] <<'\n';
        }
    }

}

void Stack::Top(){
    cout << "top is " << a[top-1] << '\n';
}

void Stack::Size(){
    cout << "size of stack is " << top << '\n';
}

int main()
{
     Stack s;
    int ch,element;
    
    cout<<"*--------------------------------------------------------------------*"<< '\n';
    cout<<"1.PUSH  2.POP  3.DISPLAY  4.ISFULL  5.ISEMPTY  6.TOP  7.SIZE  0.EXIT "<< '\n';
    cout<<"*--------------------------------------------------------------------*"<< '\n';
    
    cin >> ch;
    while(ch){
        if(ch==1){
            cout << "enter a element " << '\n';
            cin >> element;
            s.push(element);
        }
        else if(ch==2)
        {
        s.pop();
        }
        else if(ch==3)
        {
        s.display();
        }   
        else if(ch==4)
        {
        if(s.isfull())
            cout<<"STACK IS FULL"<<'\n';
        else
            cout<<"STACK IS NOT FULL"<< '\n' <<"YOU CAN PUSH"<<'\n';
        }   
        else if(ch==5)
        {
        if(s.isempty())
            cout<<"STACK IS EMPTY"<<'\n';
        else
            cout<<"STACK IS NOT EMPTY" <<'\n' <<"YOU CAN POP"<<'\n';
        }
        else if(ch==6)
        {
        s.Top();
        }
        else if(ch==7)
        {
        s.Size();
        }
        else{
           break; 
        }
        cin >> ch;
    }
   
    return 0;
}
