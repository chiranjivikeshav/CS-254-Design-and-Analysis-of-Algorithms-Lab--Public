#include<bits/stdc++.h>
using namespace std;
long getmaxsum( long int a[],int n){
    int l,r;
    if(a[0]>a[1]){
         l = 1;
         r = 0;
    }
    else{
         l = 0;
         r = 1;
    }
    for(int i=2;i<n;i++){
        if(a[i]>=a[r]){
            l = r;
            r = i;
        }
    }
    return  a[l]+a[r];
}


int main()
{
     cout<<"ENTER SIZE OF ARRAY"<<endl;
    int  n;
    cin>>n;
    long int a[n];
    cout<<"ENTER ELEMENTS OF ARRAY"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // output 
    cout<<getmaxsum(a,n)<<endl;
    return 0;
}