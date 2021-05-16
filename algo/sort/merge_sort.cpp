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
void merge_sort(RandomAccessIterator first, RandomAccessIterator last, RandomAccessIterator temp_arr){
    auto n = distance(first, last);
    if(n<=1) return;
    merge_sort(first, first + n/2, temp_arr);
    merge_sort(first + n/2, last, temp_arr);
    auto i = n*0;
    auto j = n/2;
    auto k = i;
    while(i<n/2 && j<n){
        if(first[i]<first[j]){
            temp_arr[k] = first[i++];
        } else {
            temp_arr[k] = first[j++];
        }
        k++;
    }
    while(i<n/2){
        temp_arr[k++] = first[i++];
    }
    while(j<n){
        temp_arr[k++] = first[j++];
    }
    for(k=n*0; k<n; k++){
        first[k] = temp_arr[k];
    }
}

void test(){
    int n;
    cin>>n;
    int arr[n], temp[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    merge_sort(arr, arr+n, temp);
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