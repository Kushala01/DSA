class Solution {
    public:

    int firstOcc(vector<int>&nums, int target){
        int n=nums.size(), low=0, high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>target) high=mid-1;
            else if(nums[mid]<target) low=mid+1;
            else{
                if(mid==0 || nums[mid]!=nums[mid-1]) return mid;
                else high=mid-1;
            }
        }return -1;
    }
    int lastOcc(vector<int>&nums, int target){
        int n=nums.size(), low=0, high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>target) high=mid-1;
            else if(nums[mid]<target) low=mid+1;
            else{
                if(mid==n-1 || nums[mid]!=nums[mid+1]) return mid;
                else low=mid+1;
            }
        }return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
            return {firstOcc(nums , target) , lastOcc(nums , target)};
        }
    };
//Time Complexity: O(2*logN)
//Space Complexity: O(1)

/*to count the number of occurances
int count(vector<int>& arr, int n, int x) {
    pair<int, int> ans = firstAndLastPosition(arr, n, x);
    if (ans.first == -1) return 0;
    return (ans.second - ans.first + 1);
}*/