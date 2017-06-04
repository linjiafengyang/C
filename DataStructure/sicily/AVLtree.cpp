// Problem#: 19577
// Submission#: 4957138
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>  
#include <stack>  
using namespace std;  
  
struct Node {  
    int data;  
    Node *left, *right;  
    Node( int n ) { data = n; left = NULL; right = NULL; }  
};  
  
Node *root;  
stack<Node*> s;  
  
int getHeight( Node *sub );  
void insert( Node* &sub, int data );  
void rotLeft( Node *sub, Node *parent );  
void rotRight( Node *sub, Node *parent );  
void balance();  
void preorder( Node *sub );  
void release( Node* &sub );  
  
int main()  
{  
    int t;  
    int n, data;  
  
    cin >> t;  
    while ( t-- ) {  
        root = NULL;  
        cin >> n;  
        while ( n-- ) {  
            cin >> data;  
            insert( root, data );  
            balance();  
        }  
        preorder( root );  
        cout << endl;  
        release( root );  
    }  
  
    return 0;  
  
}  
  
  
int getHeight( Node* sub ) {  
    return sub != NULL ? 1 + max( getHeight( sub->left ), getHeight( sub->right ) ): 0;  
}  
  
void insert( Node* &sub, int data ) {  
    if ( sub != NULL ) {  
        s.push( sub );  
        insert( data < sub->data ? sub->left: sub->right, data );  
    }  
    else  
        sub = new Node( data );  
}  
  
void rotLeft( Node *sub, Node *parent ) {  
    Node *right = sub->right;  
    sub->right = right->left;  
    right->left = sub;  
    if ( parent == NULL )  
        root = right;  
    else  
        sub == parent->left ? parent->left = right: parent->right = right;  
}  
  
void rotRight( Node *sub, Node *parent ) {  
    Node *left = sub->left;  
    sub->left = left->right;  
    left->right = sub;  
    if ( parent == NULL )  
        root = left;  
    else  
        sub == parent->left ? parent->left = left: parent->right = left;  
}  
  
void balance() {  
    Node *sub;  
    while ( !s.empty() ) {  
        sub = s.top();  
        s.pop();  
        int LHeight = getHeight( sub->left );  
        int RHeight = getHeight( sub->right );  
        if ( LHeight - RHeight == 2 ) {  
            if ( getHeight( sub->left->right ) - getHeight( sub->left->left ) == 1 )  
                rotLeft( sub->left, sub );  
            rotRight( sub, s.empty() ? NULL: s.top() );  
        }  
        else if ( RHeight - LHeight == 2 ) {  
            if ( getHeight( sub->right->left ) - getHeight( sub->right->right ) == 1 )  
                rotRight( sub->right, sub );  
            rotLeft( sub, s.empty() ? NULL: s.top() );  
        }  
    }  
}  
  
void preorder( Node *sub ) {  
    if ( sub != NULL ) {  
        cout << sub->data << " ";  
        preorder( sub->left );  
        preorder( sub->right );  
    }  
}  
  
void release( Node* &sub ) {  
    if ( sub != NULL ) {  
        release( sub->left );  
        release( sub->right );  
        delete sub;  
    }  
}                                 