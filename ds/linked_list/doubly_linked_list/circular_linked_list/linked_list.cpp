/************************************************************
/  AUTHOR :  DEVANSHU SINGLA                                /
/  NICK :  DSINGLA                                          /
/  INSTITUTE :  IITK                                        /
************************************************************/
//                     TEMPLATE                            //

#include <bits/stdc++.h>
#define ll long long
#define N 100005
#define MOD 1000000007
#define pb push_back
#define F first
#define S second
#define V(T...) vector<T>
#define P(T...) pair<T>
#define M(T...) map<T>
#define MM(T...) multimap<T>
#define MS(T...) multiset<T>
#define Q(T...) queue<T>
#define St(T...) stack<T>
#define PQ(T...) priority_queue<T>

// use cin.ignore() after cin statement.
using namespace std ;

template<class T>
class Node{
public:
    T val;
    Node<T> *next;
    Node<T> *prev;

    Node(){
        this->val=0;
        this->next=nullptr;
        this->prev=nullptr;
    }

    Node(T val){
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

void test(){
    Node<int> *head = nullptr;
    Node<int> *tail = nullptr;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        Node<int> *p = new Node<int>(x);
        if(tail == nullptr){
            head = p;
            tail = p;
        } else {
            tail->next = p;
            p->prev = tail;
            tail = p;
        }
    }

    auto p = head;
    while(p!=nullptr){
        cout<<p->val<<" ";
        p = p->next;
    }
}

int main(){
    #ifndef ONLINE_JUDGE 
 
    freopen("/home/devanshu/Desktop/cp/ds_algos/ds/linked_list/circular_linked_list/input.txt", "r", stdin);  
    freopen("/home/devanshu/Desktop/cp/ds_algos/ds/linked_list/circular_linked_list/output.txt", "w", stdout); 

    #endif
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    
    test();
}