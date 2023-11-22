class Solution {
  public int singleNonDuplicate(int[] nums) {
     int l = 0;
     int r = nums.length - 1;
     int n = nums.length;

     while(l <= r){
         if(l+1 < n && nums[l] == nums[l+1]){
             l+=2;
         }else{
             return nums[l];
         }
         if(r-1 >= 0 && nums[r] == nums[r-1]){
             r-=2;
         }else{
             return nums[r];
         }
     }

     return -1;
 }
}
