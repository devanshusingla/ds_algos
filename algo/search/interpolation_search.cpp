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
#define V(T) vector<T>
#define P(T) pair<X,Y>
#define M(T) map<X,Y>
#define MM(T) multimap<X,Y>
#define MS(T) multiset<T>
#define Q(T) queue<T>
#define St(T) stack<T>
#define PQ(T) priority_queue<T>

// use cin.ignore() after cin statement.
using namespace std ;

template<class RandomAccessIterator, typename T>
RandomAccessIterator interpolation_search(RandomAccessIterator first, RandomAccessIterator last, T& x){
    auto end = distance(first, last);
    auto beg = 0*end;
    while(beg <= end){
        if(first[beg] == first[end]){
            if(first[beg] == x) return first+beg;
            else return last;
        }
        auto pos = beg + (end-beg)*(x-first[beg])/(first[end]-first[beg]);
        if(first[pos] == x) return first + pos;
        else if(first[pos] < x) beg = pos+1;
        else end = pos-1;
    }
    return last;
}

void test(){
    int a[10];
    for(int i=0; i<10; i++) cin>>a[i];
    int x;
    cin>>x;
    cout<<*interpolation_search(a,a+10,x);
}

int main(){
    #ifndef ONLINE_JUDGE 
 
    freopen("/home/devanshu/Desktop/cp/ds_algos/algo/search/input.txt", "r", stdin);  
    freopen("/home/devanshu/Desktop/cp/ds_algos/algo/search/output.txt", "w", stdout); 

    #endif
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    
    test();
}