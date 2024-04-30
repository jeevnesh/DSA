class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        int index = 0;
        for(int i = 0 ; i < nums.size(); i++)
        {
            st.insert(nums[i]);
        }
        for(auto it: st)
        {
            nums[index] = it;
            index++;
        }
        return st.size();
    }
};