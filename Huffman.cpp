#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Node{
    public:
    char c;
    int f, val;
    Node* left, *right;
    Node(char c, int f){
        this->c=c;
        this->f=f;
        this->right=NULL;
        this->left=NULL;
    }
};
class compare{
    public:
    bool operator()(Node* l,Node *r){
        return l->f>r->f;
    }
};

Node* Huffman(char data[],int freq[],int n){
    priority_queue<Node*,vector<Node*>,compare> q;
    for(int i=0;i<n;i++){
        Node* temp=new Node(data[i],freq[i]);
        q.push(temp);
    }

    Node* left,*right,*top;
    while(q.size()!=1){
        left=q.top();
        q.pop();
        right=q.top();
        q.pop();
        top=new Node('$',left->f+right->f);
        top->left=left;
        top->right=right;
        q.push(top);
    }
    return q.top();
}
void printTree(Node* head, string s) {
    if (!head) return;
    if (head->c != '$') {
        cout << head->c << ": " << s << endl;
    }
    printTree(head->left, s + '0');
    printTree(head->right, s + '1');
}

int main(){
    char data[4]={'A','B','C','D'};
    int freq[4]={5,10,12,12};
    
    Node* head= Huffman(data,freq,4);
    printTree(head,"");
    return 0;
}