class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //first find the number of unique elements in an sorted array
        int count = 1;
        for(int i = 1, j = 1 ; i < nums.size(); i++)
        {
            if(nums[i] != nums[i-1]) 
            {
                count++;
                nums[j] = nums[i];
                j++;
            }
        }  
        return count;
    }
};