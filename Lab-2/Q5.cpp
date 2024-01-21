// TIME COMPLEXITY :- O(N); 
// SPACE COMPLEXITY :- O(1);

#include<bits/stdc++.h>
using namespace std;

vector<int> Minima_elements(int n,int a[]){
	vector<int>ans;
    int min1 = a[0];
    int min2 = a[0];
    for(int i=1;i<n;i++){
        if(min1>=a[i]){
            min2=min1;
            min1 =a[i];
        }
    }
    ans.push_back(min1);
    ans.push_back(min2);
    return ans;
}

int main(){
   int n;
   cout<<"Enter the size of array"<<endl;
   cin>>n;
   int a[n];
   cout<<"Enter elements array"<<endl;
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   vector<int>ans = Minima_elements(n,a); // function call
   cout<<"First minima of the array is : "<<ans[0]<<endl;
   cout<<"Second minima of the array is : "<<ans[1]<<endl;
   cout<<endl;
    return 0;
}