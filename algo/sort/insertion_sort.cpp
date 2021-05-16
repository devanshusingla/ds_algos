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
void insertion_sort(RandomAccessIterator first, RandomAccessIterator last){
    auto n = distance(first, last);
    for(auto i = n*0 + 1; i<n; i++){
        auto temp = first[i];
        auto j = i;
        while(j>0 && temp<first[j-1]){
            first[j] = first[j-1];
            j--;
        }
        first[j] = temp;
    }
}

template<class RandomAccessIterator, class Comp>
void insertion_sort(RandomAccessIterator first, RandomAccessIterator last, Comp compare){
    auto n = distance(first, last);
    for(auto i = n*0 + 1; i<n; i++){
        auto temp = first[i];
        auto j = i;
        while(j>0 && compare(temp,first[j-1])){
            first[j] = first[j-1];
            j--;
        }
        first[j] = temp;
    }
}

bool g(int a, int b){
    return a>b;
}

void test(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    insertion_sort(arr, arr+n);
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
    insertion_sort(arr, arr+n, g);
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