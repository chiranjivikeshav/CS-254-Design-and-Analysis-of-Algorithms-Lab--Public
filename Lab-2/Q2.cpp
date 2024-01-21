// TIME COMPLEXITY :- O(N*(N-M));
// SPACE COMPLEXITY :- O(1) auxiliary space


#include<bits/stdc++.h>
using namespace std;
void In_place_merge(int a[],int k, int n){
    int i =0;
    int j = k;
    while(i<k&&j<n){
        if(a[i]<=a[j]){
            i++;
        }
        else{
            for(int l= j-1;l>=i;l--){
                swap(a[l],a[l+1]);
            }
            i++;
            j++;
            k++;
        }
    }
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
   int k;
   cout<<"Enter size of first sorted part"<<endl;
   cin>>k;

   In_place_merge(a,k,n); // function call
   
   cout<<"Final array after merging in-Place"<<endl;
   for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
   }
   cout<<endl;
    return 0;
}