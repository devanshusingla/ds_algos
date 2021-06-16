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
        this->val = T();
        this->next = nullptr;
    }

    Node(T x){
        this->val = x;
        this->next = nullptr;
    }
};

template<class T>
class Stack{
    Node<T> *t;
    T null;
public:
    Stack(T null){
        this->t = nullptr;
        this->null = null;
    }

    void push(T x){
        Node<T> *p = new Node<T>(x);
        p->next = this->t;
        this->t = p;
    }

    void pop(){
        if(this->t == nullptr) return;
        Node<T> *p = this->t;
        this->t = this->t->next;
        delete p;
    }

    T top(){
        if(this->t == nullptr) return this->null;
        return t->val;
    }

    bool empty(){
        if(this->t == nullptr) return true;
        return false;
    }
};

void test(){
    int n;
    cin>>n;
    Stack<int> s(-1);
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        s.push(x);
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main(){
    #ifndef ONLINE_JUDGE 
 
    freopen("/home/devanshu/Desktop/cp/ds_algos/ds/stack/implementation/input.txt", "r", stdin);  
    freopen("/home/devanshu/Desktop/cp/ds_algos/ds/stack/implementation/output.txt", "w", stdout); 

    #endif
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    
    test();
}