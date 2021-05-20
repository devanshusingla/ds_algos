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

// Output: kth smallest element
// Worst time complexity: O(n^2)
// Average time complexity: O(n)
template<class RandomAccessIterator, class T>
RandomAccessIterator quick_select(RandomAccessIterator first, RandomAccessIterator last, T k){
    T n = distance(first, last);
    T index[n] = {};
    for(T i=0; i<n; i++) index[i] = i;
    T f=0, l=n;
    while(f<=l){
        auto pivot = first[index[l-1]];
        auto j = f;
        for(auto i=f; i<l-1; i++){
            if(first[index[i]]<pivot){
                auto temp = index[i];
                index[i] = index[j];
                index[j++] = temp;
            }
        }
        auto temp = index[l-1];
        index[l-1] = index[j];
        index[j] = temp;
        if(j == k-1) return first+index[j];
        else if(j < k-1) f = j+1;
        else l = j;
    }
    return last;
}

void test(){
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    cout<<*quick_select(a, a+n, k);
}

int main(){
    #ifndef ONLINE_JUDGE 
 
    freopen("/home/devanshu/Desktop/cp/ds_algos/ds/array/order_statistics/k-th_element/input.txt", "r", stdin);  
    freopen("/home/devanshu/Desktop/cp/ds_algos/ds/array/order_statistics/k-th_element/output.txt", "w", stdout); 

    #endif
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    
    test();
}