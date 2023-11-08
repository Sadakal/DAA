#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isSafe(int row,int col,int **board,int n){
    for(int i=0;i<row;i++){
        if(board[i][col]==1) return false;
    }
    int i =row;
    int j =col;
    while(i>-0 && j>=0){
        if(board[i][j]==1){
            return false;
        }
        i--;
        j--;
    }
    i=row;
    j=col;
    while(i>=0 && j<n){
        if(board[i][j]==1) return false;
        i--;
        j++;
    }
    return true;
}
bool nQueens(int **board,int x , int n ){
    if(x>=n) return true;

    for(int col=0;col<n;col++){
        if(isSafe(x,col,board,n)){
            board[x][col]=1;
            if(nQueens(board,x+1,n)){
                return true;
            }
            else{
                board[x][col]=0;
            }
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    int** board;
    board=new int*[n];
    for(int i=0;i<n;i++){
        board[i]=new int[n];
        for(int j =0;j<n;j++){
            board[i][j]=0;
        }
    }    
    nQueens(board,0,n);
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            if(board[i][j]==1){
                cout<<" 1 ";
            }
            else {
                cout<< " 0 ";
            }
        }
        cout<<endl;
    }
    return 0;
}