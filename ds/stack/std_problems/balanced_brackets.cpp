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

bool balanced_brackets(string s){
    St(char) st;
    for(auto c:s){
        if(c == '(' || c == '{' || c == '['){
            st.push(c);
        } else if(c == ')'){
            if(!st.empty() && st.top() == '(') st.pop();
            else return false;
        } else if(c == '}'){
            if(!st.empty() && st.top() == '{') st.pop();
            else return false;
        } else if(c == ']'){
            if(!st.empty() && st.top() == '[') st.pop();
            else return false;
        } else return false;
    }
    return true;
}

void test(){
    string s;
    cin>>s;

    bool is_balanced = balanced_brackets(s);
    cout<<(is_balanced ? "Brackets balanced" : "Brackets not balanced");
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