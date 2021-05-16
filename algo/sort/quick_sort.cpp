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

template<class RandomAccessIterator>
void quick_sort(RandomAccessIterator first, RandomAccessIterator last){
    auto n = distance(first, last);
    if(n<=1) return;
    auto pivot = first[n-1];
    auto j = 0*n;
    for(auto i=n*0; i<n-1; i++){
        if(first[i]<pivot){
            auto temp = first[i];
            first[i] = first[j];
            first[j++] = temp;
        }
    }
    auto temp = first[j];
    first[j] = first[n-1];
    first[n-1] = temp;
    quick_sort(first, first+j);
    quick_sort(first+j+1, last);
}

void test(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    quick_sort(arr, arr+n);
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
}

int main(){
    #ifndef ONLINE_JUDGE 
 
    freopen("/home/devanshu/Desktop/cp/ds_algos/algo/sort/input.txt", "r", stdin);  
    freopen("/home/devanshu/Desktop/cp/ds_algos/algo/sort/output.txt", "w", stdout); 

    #endif
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    
    test();
}