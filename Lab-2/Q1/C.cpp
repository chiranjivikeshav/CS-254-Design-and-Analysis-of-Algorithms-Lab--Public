// TIME COMPLEXITY :- O(N);
// SPACE COMPLEXITY :- O(N);

#include<bits/stdc++.h>
using namespace std;

void Intersection_merge(int a[],int n,int b[],int m,int c[],int &k){
    int i =0;
    int j =0;
    while(i<n&&j<m){
        if(b[j]<a[i]){
            j++;
        }
        else if(b[j]>a[i]){
            i++;
        }
        else{
            c[k] = a[i];
            k++;
            i++;
            j++;
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

   int k = max(n,m); // maximum possible size of required array
   int c[k];
   k =0;
   Intersection_merge(a,n,b,m,c,k); // function call
   cout<<"Final array after intersection"<<endl;
   for(int i=0;i<k;i++){
    cout<<c[i]<<" ";
   }
   cout<<endl;
    return 0;
}