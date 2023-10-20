class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //step1 : Sort the array
        sort(nums.begin(),nums.end());
        //step2 : 
        return nums[nums.size() - k];
    }
};