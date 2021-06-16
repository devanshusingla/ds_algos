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
class Stack{
    int n;
    T *arr;
    int t;
    T null;
    T min;
public:
    Stack(int n, T null){
        this->n = n;
        this->arr = new T[n];
        this->t = -1;
        this->null = null;
        this->min = null;
    }

    bool push(T x){
        if(this->t == this->n-1) return false;
        if(this->t == -1) this->min = x;
        if(x >= this->min) this->arr[++this->t] = x;
        else {
            this->arr[++this->t] = 2*x - this->min;
            this->min = x;
        }
        return true;
    }

    bool pop(){
        if(this->t == -1) return false;
        if(this->arr[this->t] >= this->min){
            this->t--;
        } else {
            this->min = 2*this->min - this->arr[this->t--];
        }
        if(this->t == -1) this->min = this->null;
        return true;
    }

    T top(){
        if(this->t == -1) return this->null;
        if(this->arr[this->t] >= this->min) return this->arr[this->t];
        else return 2*this->min - this->arr[this->t];
    }

    T min_el(){
        return this->min;
    }

    bool empty(){
        return this->t==-1;
    }

    bool full(){
        return this->t==this->n-1;
    }
};

void test(){
    int n;
    cin>>n;
    Stack<int> s(n,-1);
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        s.push(x);
    }
    while(!s.empty()){
        cout<<s.min_el()<<endl;
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