//MERGE SORT

#include <bits/stdc++.h>
using namespace std;

void merge(int input_arr[], int  l, int r, int mid){
	int l_sz=mid-l+1;
	int r_sz=r-mid;
	int left_arr[l_sz+1];
	int right_arr[r_sz+1];
	for (int i=0; i<l_sz; ++i){
		left_arr[i]=input_arr[l+i];
	}
	for (int i=0; i<r_sz; ++i){
		right_arr[i]=input_arr[mid+1+i];
	}
	left_arr[l_sz]=right_arr[r_sz]=INT_MAX;

//ab left array and right array mil gaye hai (assuming that these are individually sorted)
//now we will keep checking the first elements in both these arrays
//put the smaller element at the position we are at, and then move forward

	int l_current=0;
	int r_current=0;
	//these track the present index that we are at in each array

	for(int i=l; i<=r; ++i){
		if(left_arr[l_current]<right_arr[r_current]){
			input_arr[i]=left_arr[l_current];
			++l_current;
		}
		else{
			input_arr[i]=right_arr[r_current];
			++r_current;
		}
	}
}

void mergesort(int input_arr[], int l, int r){
	if(l>=r) return;
	int mid=(l+r)/2;
	mergesort(input_arr, l, mid);
	mergesort(input_arr, mid+1, r);
	merge(input_arr, l, r, mid);
}

int main(){
	int n; cin >> n;
	int a[n];
	for(int i=0; i<n; ++i){
		cin >> a[i];
	}
	mergesort(a, 0, n-1);

	for(int i=0; i<n; ++i){
		cout << a[i] << " ";
	}
}
