// TIME COMPLEXITY :- O(N);
// SPACE COMPLEXITY :- O(N);

#include<bits/stdc++.h>
using namespace std;

void Union_merge(int a[],int n,int b[],int m,int c[],int &k){
    int i =0;
    int j =0;
    while(i<n||j<m){
        if(i==n||b[j]<a[i]){
            c[k] = b[j];
            k++;
            j++;
        }
        else if(j==m||b[j]>a[i]){
            c[k] = a[i];
            i++;
            k++;
        }
        else{
            c[k] = a[i];
            i++;
            j++;
            k++;
        }
    }
}


int main(){
   int n;
   cout<<"Enter the size of first array"<<endl;
   cin>>n;
   int a[n];
   cout<<"Enter elements first array"<<endl;
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   int m;
   cout<<"Enter the size of second array"<<endl;
   cin>>m;
   int b[m];
   cout<<"Enter elements second array"<<endl;
   for(int i=0;i<m;i++){
    cin>>b[i];
   }

   int k = m+n; //maximum possible size of required array
   int c[k];
   k =0;
   Union_merge(a,n,b,m,c,k); // function call
   cout<<"Final array after union merging"<<endl;
   for(int i=0;i<k;i++){
    cout<<c[i]<<" ";
   }
   cout<<endl;
    return 0;
}