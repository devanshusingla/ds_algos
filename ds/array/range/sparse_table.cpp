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

/* Only applicable with functions f: X^N -> X s.t. for n,k1,k2,...,km \in N, \sum k_i = n and

        f(x) = x
        f(x_1,...,x_n) = f(f(x_1,..,x_k1),f(x_{k1+1},...,f(x_{k1+k2}),...,f(x_{n-km},...,f(x_n)))

        eg: gcd, min, max, sum, etc
*/

/*
    initial setup time: O(nlog n)
    memory: O(nlog n)
    query lookup time: O(log n)

    Total time complexity: O((n+m)log n)
*/

template<class T, class F>
V(V(T)) sparse_table(V(T) &a, F f){
    V(V(T)) st;
    st.pb(a);
    auto n = a.size();
    auto k = 0*n + 1;
    auto m = 0*n + 1;
    while(2*k<n){
        auto j = k;
        st.pb(V(T)());
        while(j<st[m-1].size()){
            st[m].pb(f(st[m-1][j-k],st[m-1][j]));
            j++;
        }
        k*=2;
        m++;
    }
    return st;
}

template<class T, class U, class F>
T query(U l, U r, V(V(T)) &st, F f){
    U n = r-l;
    U k=0;
    U p=1;
    T ans;
    bool flag = false;
    while(n!=0){
        if(n%2){
            if(flag){
                ans = f(ans, st[k][r-p]);
            } else {
                ans = st[k][r-p];
                flag = true;
            }
            r-=p;
        }
        n/=2;
        p<<=1;
        k++;
    }
    return ans;
}

int f(int x, int y){
    return max(x,y);
}

void test(){
    int n;
    cin>>n;
    V(int) a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    V(V(int)) st = sparse_table(a,f);
    // for(auto i:st){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    
    int m;
    cin>>m;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        cout<<query(x,y,st,f)<<endl;
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