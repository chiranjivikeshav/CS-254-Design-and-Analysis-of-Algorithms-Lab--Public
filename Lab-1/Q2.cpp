#include<bits/stdc++.h>
using namespace std;

long int maxvalue(int i,long int mW,long int w[],long int v[],int n,vector<vector<long>>&dp){
   if(i>=n){
    return 0;
   }
   if(dp[i][mW]!=-1){
    return dp[i][mW];
   }
  // not take the item
   long int ans = maxvalue(i+1,mW,w,v,n,dp);
  // take the item
  if(w[i]<=mW)   {
    ans = max(ans,v[i]+maxvalue(i+1,mW-w[i],w,v,n,dp));
  }
  return dp[i][mW] = ans;
}

int main(){   
    cout<<"ENTER NUMBER OF ITEMS"<<endl;
    int n;
    cin>>n;
    cout<<"ENTER WEIGHT OF EACH ITEMS"<<endl;
    long int w[n];
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    cout<<"ENTER VALUE OF EACH ITEMS"<<endl;
    long int v[n];
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<"ENTER MAX WEIGHT LIMIT"<<endl;
    long int mW;
    cin>>mW;
    // Apply Dynamic Programming
    vector<vector<long>>dp(n,vector<long>(mW+1,-1));
    // output
    cout<<maxvalue(0,mW,w,v,n,dp)<<endl;
    
    return 0;
}