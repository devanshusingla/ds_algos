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
T greatest_area(V(T) &v){
    T ans = 0;
    St(T) s;
    for(int i=0; i<v.size(); i++){
        while(!s.empty() && v[s.top()] >= v[i]){
            T h = v[s.top()];
            s.pop();
            if(!s.empty()) ans = max(ans, h*(i-s.top()-1));
            else ans = max(ans, h*i);
        }
        s.push(i);
    }
    while(!s.empty()){
        T h = v[s.top()];
        s.pop();
        if(!s.empty()) ans = max(ans, h*(T)(v.size()-s.top()-1));
        else ans = max(ans,h*(T)v.size());
    }

    return ans;
}

void test(){
    int n;
    cin>>n;
    V(int) v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    auto ans = greatest_area(v);
    cout<<ans;
}

int main(){
    #ifndef ONLINE_JUDGE 
 
    freopen("/home/devanshu/Desktop/cp/ds_algos/ds/stack/misc/input.txt", "r", stdin);  
    freopen("/home/devanshu/Desktop/cp/ds_algos/ds/stack/misc/output.txt", "w", stdout); 

    #endif
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    
    test();
}