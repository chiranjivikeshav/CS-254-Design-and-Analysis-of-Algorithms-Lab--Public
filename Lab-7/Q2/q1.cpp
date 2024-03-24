// TIME COMPLEXITY :  O(N) 
// SPACE COMPLEXITY : O(N)
// where N is number of job

#include<bits/stdc++.h>
using namespace std;
int maxProfit(int n,int D[],int P[],int mx){
    map<int,priority_queue<int>>m;
    for(int i=0;i<n;i++){
      m[D[i]].push(P[i]);
    }
    int ans =0;
    for(int i=1;i<=mx;i++){
        while(m.size()>0){
            int deadline = m.begin()->first;
            if(deadline<i){
                m.erase(m.begin());
            }
            else{
                break;
            }
        }
        if(m.size()>0){
               
               int deadline = m.begin()->first;
                ans+=(m[deadline].top());
                m[deadline].pop();
                if(m[deadline].size()==0){
                    m.erase(m.begin());
                }
        }
    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    int D[n];
    int mx =0;
    for(int i=0;i<n;i++){
        cin>>D[i];
        mx = max(mx,D[i]);
    }
    int P[n];
    for(int i=0;i<n;i++){
        cin>>P[i];
    }
    cout<<maxProfit(n,D,P,mx)<<endl;
    return 0;
}