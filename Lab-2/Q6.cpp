// TIME COMPLEXITY :- O(N*Log(N)); Avarage complexity ,O(N*N*Log(N)) Worst Case
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

void quickSort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int k = (r-l+2)/2;
    int mid = Median_element(l,r,k,a);
    int piv = a[mid], i = l;
    for (int j = l; j <r; j++)
    {
        if (a[j] <= piv && j != mid)
        {
            swap(a[i], a[j]);
            i++;
        }
    }
    a[i] = piv;

    quickSort(a, l, mid);
    quickSort(a, mid + 1, r);
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
   quickSort(a,0,n-1); // function call
   cout<<"Array after sorting is :"<<endl;
   for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
   }
   cout<<endl;
    return 0;
}
