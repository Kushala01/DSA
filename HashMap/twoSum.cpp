#include<bits/stdc++.h>
using namespace std;

vector <int> twoSum(vector <int> &nums, int target){
	unordered_map<int , int> mpp;
	vector <int> answer;
	int value;
	for(int i=0; i<nums.size(); i++){
		value=target-nums[i];
		if(mpp.find(value) != mpp.end()){
			answer.push_back(i);
			answer.push_back(mpp[value]);
			return answer;
		}mpp[nums[i]]=i;
	}
	return {-1, -1};
}

int main(){
	int n;
	cin>>n;
	vector <int> sum(n);
	for(int i=0;i<n;i++){
		cin>>sum[i];
	}
	int target;
	cin>>target;
	vector <int> ans=twoSum(sum, target);
	for (auto i: ans){
		cout<< i<< endl;
	}
	return 0;
}
