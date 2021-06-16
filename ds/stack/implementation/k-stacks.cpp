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

template<class T, class U>
class kStacks{
    U k,n;
    T *arr;
    U *t;
    U *next;
    U free;
    T null;
public:
    kStacks(U n, U k, T null){
        this->n = n;
        this->k = k;
        this->free = 0;
        this->arr = new T[n];
        this->next = new U[n];
        this->t = new U[k];
        this->null = null;

        for(U i=0; i<n-1; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
        for(U i=0; i<k; i++){
            t[i] = -1;
        }
    }

    bool push(T x, U sn){
        if(this->free == -1){
            return false;
        }
        U i = this->free;
        this->arr[i] = x;
        this->free = this->next[i];
        this->next[i] = this->t[sn];
        this->t[sn] = i;
        return true;
    }

    bool pop(U sn){
        if(this->t[sn] == -1) return false;
        U i = this->t[sn];
        this->t[sn] = this->next[i];
        this->next[i] = this->free;
        this->free = i;
        return true;
    }

    T top(U sn){
        U i = this->t[sn];
        if(i == -1) return this->null;
        return this->arr[i];
    }

    bool empty(U sn){
        return this->t[sn] == -1;
    }

    bool full(){
        return this->free == -1;
    }

    void debug(){
        cout<<"arr: ";
        for(int i=0; i<this->n; i++) cout<<this->arr[i]<<" ";
        cout<<endl<<"next: ";
        for(int i=0; i<this->n; i++) cout<<this->next[i]<<" ";
        cout<<endl<<"top: ";
        for(int i=0; i<this->k; i++) cout<<this->t[i]<<" ";
        cout<<endl<<endl;
    }
};

void test(){
    int k=3, n=10;
    kStacks<int, int> s(n,k,-1);

    s.push(12,0);
    s.push(34,1);
    s.push(2,0);
    s.push(23,2);
    s.push(2,0);
    s.push(5,1);
    s.push(7,1);
    s.push(2,2);
    s.push(2,0);
    s.push(2,0);
    cout<<(s.full()?"stack is full":"stack is not full")<<endl;

    for(int i=0; i<3; i++){
        cout<<"\nStack "<<i<<endl<<endl;

        while(!s.empty(i)){
            cout<<s.top(i)<<endl;
            s.pop(i);
            // s.debug();
        }
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