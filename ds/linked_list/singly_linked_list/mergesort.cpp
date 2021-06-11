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
void mergesort(Node<T> *&head){
    if(head == nullptr || head->next == nullptr) return;
    Node<T> *p2 = head;
    Node<T> *temp = head->next;

    while(temp->next != nullptr){
        p2 = p2->next;
        temp = temp->next;
        if(temp->next!=nullptr) temp = temp->next;
    }
    temp = p2;
    p2 = p2->next;
    temp->next = nullptr;
    Node<T> *p1 = head;

    auto p = p1;

    mergesort(p1);
    mergesort(p2);

    head = nullptr;
    Node<T> *tail = nullptr;

    if(p1 != nullptr && p2 != nullptr){
        if(p1->val < p2->val){
            head = p1;
            tail = head;
            p1 = p1->next;
            tail->next = nullptr;
        } else {
            head = p2;
            tail = head;
            p2 = p2->next;
            tail->next = nullptr;
        }
    }

    while(p1 != nullptr && p2 != nullptr){
        if(p1->val < p2->val){
            tail->next = p1;
            tail = tail->next;
            p1 = p1->next;
        } else {
            tail->next = p2;
            tail = tail->next;
            p2 = p2->next;
        }
    }

    while(p1 != nullptr){
        tail->next = p1;
        tail = tail->next;
        p1 = p1->next;
    }

    while(p2 != nullptr){
        tail->next = p2;
        tail = tail->next;
        p2 = p2->next;
    }

    tail->next = nullptr;
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

    mergesort(head);

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