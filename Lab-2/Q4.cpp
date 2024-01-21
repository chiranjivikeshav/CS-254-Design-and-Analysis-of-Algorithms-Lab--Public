// USED THE CONCEPT OF QUICK SORT BUT NOT SORT THE ARRAY HERE
// TIME COMPLEXITY :- O(N); Avarage complexity ,O(N*N) Worst Case
// SPACE COMPLEXITY :- O(1);

#include<bits/stdc++.h>
using namespace std;

int partitions(int l,int r,int a[]){
    int x=a[r];
    int i= l;
	for(int j= l;j<r;j++)
	{
		if (a[j]<=x)
		{
			swap(a[i],a[j]);
			i++;
		}
	}
	swap(a[i],a[r]);
	return i;
}

int Median_element(int l,int r,int k,int a[]){
	int pivotIdx=partitions(l,r,a);
	if(pivotIdx-l==k-1)
		return pivotIdx;
	else if(pivotIdx-l>k-1)
		return Median_element(l,pivotIdx-1,k,a);
	return Median_element(pivotIdx+1,r,k-pivotIdx+l-1,a);
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
   int k = (n+1)/2;
   int median = Median_element(0,n-1,k,a); // function call

   cout<<a[median]<<endl;
   cout<<endl;
    return 0;
}