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

    Node(){
        this->val=0;
        this->next=nullptr;
    }

    Node(T val){
        this->val = val;
        this->next = nullptr;
    }
};

template<class T>
void quicksort(Node<T> *&head){

    if(head == nullptr || head->next == nullptr) return;
    Node<T> *h1 = nullptr;
    Node<T> *h2 = nullptr;
    Node<T> *t1 = nullptr;
    Node<T> *t2 = nullptr;

    T x = head->val;
    Node<T> *p = head->next;

    while(p != nullptr){
        if(p->val < x){
            if(t1 == nullptr){
                h1 = p;
                t1 = p;
            } else {
                t1->next = p;
                t1 = t1->next;
            }
        } else {
            if(t2 == nullptr){
                h2 = p;
                t2 = p;
            } else {
                t2->next = p;
                t2 = t2->next;
            }
        }
        p = p->next;
    }
    if(t1 != nullptr)
    t1->next = nullptr;
    if(t2 != nullptr)
    t2->next = nullptr;

    quicksort(h1);
    quicksort(h2);

    p = h1;
    while(p != nullptr && p->next != nullptr) p = p->next;
    if(p == nullptr){
        p = head;
        h1 = head;
    }
    else{
        p->next = head;
        p = p->next;
    }
    p->next = h2;

    head = h1;
}

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
            tail = p;
        }
    }

    quicksort(head);

    auto p = head;
    while(p!=nullptr){
        cout<<p->val<<" ";
        p = p->next;
    }
}

int main(){
    #ifndef ONLINE_JUDGE 
 
    freopen("/home/devanshu/Desktop/cp/ds_algos/ds/linked_list/singly_linked_list/input.txt", "r", stdin);  
    freopen("/home/devanshu/Desktop/cp/ds_algos/ds/linked_list/singly_linked_list/output.txt", "w", stdout); 

    #endif
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    
    test();
}