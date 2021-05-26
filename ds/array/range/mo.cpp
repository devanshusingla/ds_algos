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

int rootn;

template<class T>
struct comp {
    bool operator()(P(T,T) x, P(T, T) y) const {
        if(x.F/rootn == y.F/rootn){
            return x.S < y.S;
        } else return x.F < y.F;
    }
};

template<class T, class U>
V(U) mo(V(U) &a, MS(P(T,T),comp<T>) &q){
    T l=0, r=-1;
    U sum=0;
    V(U) v;
    for(auto i:q){
        T cl = i.F;
        T cr = i.S;
        while(l!=cl || r!=cr){
            if(r<cr){
                sum += a[++r];
            }
            if(r>cr){
                sum -= a[r--];
            }
            if(l<cl){
                sum -= a[l++];
            }
            if(l>cl){
                sum += a[--l];
            }
        }
        v.pb(sum);
    }
    return v;
}

void test(){
    int n;
    cin>>n;
    rootn = (int)sqrt(n);
    V(int) a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    int m;
    cin>>m;
    MS(P(int,int), comp<int>) q;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        q.insert({x,y});
    }

    V(int) v = mo(a,q);
    auto itr = q.begin();
    for(int i=0; i<m; i++){
        cout<<(*itr).F<<" "<<(*itr).S<<endl;
        cout<<v[i]<<endl;
        itr++;
    }
}

int main(){
    #ifndef ONLINE_JUDGE 
 
    freopen("/home/devanshu/Desktop/cp/ds_algos/ds/array/range/input.txt", "r", stdin);  
    freopen("/home/devanshu/Desktop/cp/ds_algos/ds/array/range/output.txt", "w", stdout); 

    #endif
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    
    test();
}