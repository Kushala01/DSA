#include<bits/stdc++.h>
using namespace std;

int maxDist(int arr[], int n){
	unordered_map <int , int>mp;
	int max_dist = 0;

	for(int i=0;i<n;i++){
		if(mp.find(i)!=mp.end())
			mp[arr[i]]=i;
	else
	max_dist=max(max_dist, i - mp[arr[i]]);
}
	return max_dist;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"ans is"<<endl;
	cout<<maxDist(arr, n);
	return 0;
}
/*Hash maps allow efficient mapping of elements to their last seen positions.
They enable quick distance calculations between occurrences.
Using arrays would require more complex and less efficient code with additional iterations.*/
