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

// Juggling algorithm for array rotation

// Time complexity -> O(n)
// Space complexity -> O(1)

// first -> iterator of first element
// last -> iterator of element after last element
// d -> right rotation displacement
template <class RandomAccessIterator, typename T>
void juggler(RandomAccessIterator first, RandomAccessIterator last, T d){
    T n = distance(first, last);
    if(d<0){
        d = ((1+abs(d)/n)*n + d)%n;
    }
    T g = __gcd(n,d);
    for(T s=0; s<g; s++){
        auto prev = first[s];
        auto temp = first[0];
        T i=(s+d)%n;
        while(i != s){
            temp = first[i];
            first[i] = prev;
            prev = temp;
            i = (i+n+d)%n;
        }
        first[i] = prev;
    }
}

void test(){
    int arr[10];
    for(int i=0; i<10; i++) cin>>arr[i];
    for(int i=0; i<10; i++) cout<<arr[i]<<" ";
    cout<<endl;

    cout<<"\nRotating by 24"<<endl;
    juggler(arr, arr+10, 24);
    for(int i=0; i<10; i++) cout<<arr[i]<<" ";

    cout<<"\nRotating by -26"<<endl;
    juggler(arr, arr+10, -6);
    for(int i=0; i<10; i++) cout<<arr[i]<<" ";
}

int main(){
    #ifndef ONLINE_JUDGE 
 
    freopen("/home/devanshu/Desktop/cp/ds_algos/ds/array/rotations/input.txt", "r", stdin);  
    freopen("/home/devanshu/Desktop/cp/ds_algos/ds/array/rotations/output.txt", "w", stdout); 

    #endif
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    
    test();
}