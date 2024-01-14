#include<bits/stdc++.h>
using namespace std;

long int fun(int i, int mask,int n,vector<vector<int>>&memo,vector<vector<int>>&dist) {
	if (mask == ((1 << i) | 3)){
		return dist[1][i];
    }
	if (memo[i][mask] != 0){
		return memo[i][mask];
    }
	long int res = 1000000; 
	for (int j = 1; j <= n; j++){
		if ((mask & (1 << j)) && j != i && j != 1){
			res = min(res, fun(j, mask & (~(1 << i)),n,memo,dist)
									+ dist[j][i]);
        }
    }
	return memo[i][mask] = res;
}


int main()
{
    cout<<"ENTER NUMBER OF CITY (<= 20)"<<endl;
    int n;
    cin>>n;
    cout<<"ENTER DISTANCES BETWEEN CITIES"<<endl;
    vector<vector<int>>dist(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>dist[i][j];
        }
    }
    vector<vector<int>> memo(n+1,vector<int>(1 << (n + 1),0));
    long int ans = 1000000;
	for (int i = 1; i <= n; i++){
		ans = min(ans, fun(i, (1 << (n + 1)) - 1,n,memo,dist)
								+ dist[i][1]);
    }
    // output
	cout<<ans<<endl;
    
    return 0;
}