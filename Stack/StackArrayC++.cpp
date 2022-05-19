#include<iostream>
using namespace std;

class Stack{
    private:
    int size;
    int top;
    int *s;
    public:
    Stack(int size){
        this->size=size;
        top=-1;
        s=new int[size];
    };
    ~Stack(){delete [ ] s;}
    void create();
    void Display();
    void push(int x);
    int pop();
    int peek(int pos);
    int stackTop();
    int isEmpty();
    int isFull();
};
void Stack::create(){
    cout<<"Enter Size"<<endl;
    cin>>size;
    top=-1;
    s=new int[size];
}
void Stack::Display(){
    for(int i=top;i>=0;i--){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
void Stack::push(int x){
    if(top==size-1){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        top++;
        s[top]=x;
    }
}
int Stack::pop(){
    int x=-1;
    if(top==-1)
    cout<<"Stack Underflow"<<endl;
else{
    x=s[top--];
}
return x;
}
int Stack::peek(int pos){
    int x=-1;
    if(top-pos+1<0)
    cout<<"Invalid Position"<<endl;
    else
    x=s[top-pos+1];
    return x;
}
int Stack::stackTop(){
    if(top==-1)
    return -1;
    else
    return s[top];
}
int Stack::isEmpty(){
    if(top==-1)
    return 1;
    else 
    return 0;
}
int Stack::isFull(){
    if(top==size-1)
    return 1;
    else
    return 0;
}

int main (){
    Stack st(0);
    st.create();
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.Display();
    cout<<st.peek(2)<<endl;
    cout<<st.stackTop()<<endl;
    cout<<st.isFull()<<endl;


    return 0;
}