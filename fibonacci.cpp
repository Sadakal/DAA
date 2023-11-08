#include<iostream>
using namespace std;
int Fib(int n){
    if(n==1||n==2) return n-1;
    int curr=1;
    int prev=1;
    for(int i=2;i<n;i++){
        int temp=curr+prev;
        prev=curr;
        curr=temp;
    }
    return curr;
}

int FibR(int n){
    if(n==0 || n==1) return n;
    return FibR(n-1)+FibR(n-2);
}

int main(){
    int n;
    cin>>n;
    cout<< Fib(n)<<endl;
    cout<< FibR(n)<<endl;
}