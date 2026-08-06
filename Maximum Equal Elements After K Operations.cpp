//https://www.naukri.com/code360/problems/maximum-equal-elements-after-k-operations_992848?leftPanelTabValue=PROBLEM



#include <bits/stdc++.h> 
int maxEqualElements(vector<int> arr, int n, int k) {
	// Write your code here.
	sort(arr.begin(),arr.end());
	int i=0,j=0, pSum=0;
	int result=0;
	while(j<n){
		pSum+=arr[j];
		int kUsed=(j-i+1)*arr[j]-pSum;
		while(i<j && kUsed>k){
			pSum-=arr[i];
			i++;
			kUsed=(j-i+1)*arr[j]-pSum;
		}
		result=max(result,j-i+1);
		j++;
	}
	return result;
}
