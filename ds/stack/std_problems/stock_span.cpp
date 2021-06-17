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
V(T) stock_span(V(T) &v){
    V(T) a;
    St(int) s;
    for(int i=0; i<v.size(); i++){
        while(!s.empty() && v[s.top()] <= v[i]) s.pop();
        if(s.empty()) a.pb(i+1);
        else a.pb(i - s.top());
        s.push(i);
    }
    return a;
}

void test(){
    int n;
    cin>>n;
    V(int) v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    auto ans = stock_span(v);
    for(int i=0; i<n; i++) cout<<ans[i]<<" ";
}

int main(){
    #ifndef ONLINE_JUDGE 
 
    freopen("/home/devanshu/Desktop/cp/ds_algos/ds/stack/std_problems/input.txt", "r", stdin);  
    freopen("/home/devanshu/Desktop/cp/ds_algos/ds/stack/std_problems/output.txt", "w", stdout); 

    #endif
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    
    test();
}