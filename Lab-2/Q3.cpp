// TIME COMPLEXITY :- O(N*NLog(N));
// SPACE COMPLEXITY :- O(1);

#include<bits/stdc++.h>
using namespace std;

void In_place_merge(int a[],int l,int k, int n){
    int i = l;
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

void mergeSort(int l,int r,int a[]){
    if(l==r){
        return;
    }
    int mid = l+(r-l)/2;
    mergeSort(l,mid,a);
    mergeSort(mid+1,r,a);
    In_place_merge(a,l,mid+1,r+1);
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
   
   mergeSort(0,n-1,a); // function call
   
   cout<<"Final array after sorting"<<endl;
   for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
   }
   cout<<endl;
    return 0;
}