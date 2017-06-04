// Problem#: 19576
// Submission#: 4957179
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>  
using namespace std;  
class Node  
{  
public:  
    Node(int a=0)  
    {  
        data=a;  
        next=NULL;  
    }  
    int data;  
    Node* next;  
      
};  
int main()  
{  
    int n;  
    for(;;)  
    {  
        cin >> n;  
        if(!n)break;  
        Node hash[13];  
        for(int i=0;i<n;i++)  
        {  
            int temp;  
            cin >> temp;  
            if(hash[temp%13].data==0)  
            {  
                hash[temp%13].next=new Node (temp);  
                hash[temp%13].data=1;  
            }  
            else  
            {  
                Node*p=hash[temp%13].next;  
                while(p->next!=NULL)  
                {  
                    p=p->next;  
                }  
                p->next=new Node (temp);  
            }  
        }  
        for(int i=0;i<13;i++)  
        {  
            if(hash[i].data==0)  
            {  
                cout << i << "#NULL" << endl;  
            }  
            else  
            {  
                cout << i << "#";  
                Node*p =hash[i].next;  
                while(p->next!=NULL)  
                {  
                    cout << p->data << " " ;  
                    p=p->next;  
                }  
                cout << p->data << endl ;  
            }  
        }  
    }  
}                                 