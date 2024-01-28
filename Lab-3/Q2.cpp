// Time Complexity: O(N*Log(N));
// Space complexity : O(Log(N)); Auxillary stack sapce

// we can solve this problem in O(N) using kadane's algorithm
#include <bits/stdc++.h>
using namespace std;
int mid_sum(int a[], int i, int j){
    int mid = i + (j - i) / 2;
    int val1 = 0,y1 =0;
    int val2 = 0,y2=0;
    for(int k = mid;k<=j;k++){
        y1+=a[k];
        val1=max(val1,y1);
    }
    for(int k = mid;k>=i;k--){
        y2+=a[k];
        val2=max(val2,y2);
    }
    return (val1+val2-a[mid]);
}
int max_subarry_sum(int a[], int i, int j){
    if (i > j)
    {
        return 0;
    }
    int mid = i + (j - i) / 2;
    int left_sum = max_subarry_sum(a, i, mid-1);
    int right_sum = max_subarry_sum(a, mid + 1, j);
    return max(mid_sum(a, i, j), max(right_sum, left_sum));
}
int main(){
    cout << "ENTER THE SIZE OF ARRYA" << endl;
    int n;
    cin >> n;
    int a[n];
    cout << "ENTER THE ELEMENTS OF ARRAY" << endl;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    // function call
    cout << max_subarry_sum(a, 0, n - 1) << endl;

    return 0;
}