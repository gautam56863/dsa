#include<iostream>
using namespace std;
class Lowertri{
    private:
    int n;
    int *A;
    public:
    Lowertri(){
        n=2;
        A=new int[3];
    }
    Lowertri(int n){
        this->n=n;
        A=new int[n*(n+1)/2];
    }
    void Set(int i,int j,int k);
    int Get(int i,int j);
    void Display();
    int GetDimention(){return n;}
    ~Lowertri(){delete [] A;}
};
void Lowertri::Set(int i,int j,int x){
    if(i>=j)
    A[i*(i-1)/2+j-1]=x;
}
int Lowertri::Get(int i, int j){
    if(i>=j)
    return A[i*(i-1)/2+j-1];
    else
    return 0;
}
void Lowertri::Display(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i>=j)
            cout<<A[i*(i-1)/2+j-1]<<" ";
            else
            cout<<0<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int d;
    cout<<"Enter dimendtions: "<<endl;
    cin>>d;

    Lowertri lm (d);
    int x;
    cout<<"Enter all elements: "<<endl;
    for(int i=1;i<=d;i++){
        for(int j=1;j<=d;j++){
            cin>>x;
            lm.Set(i,j,x);
        }
    }
    cout<<endl;
    lm.Display();
    return 0;
}