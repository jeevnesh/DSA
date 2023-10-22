class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i = 0 ; i < nums.size(); i++)
        {
            //remove out of window elements from front
            if(!dq.empty() && dq.front() == i-k)
            {
                dq.pop_front();
            }
            //insert element from back making monotonus dequeue
            while(!dq.empty() && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }
            //now we can add element from back
            dq.push_back(i);
            //now front element is maximum in queue for k size window element
            if(i>=k-1)   // we will add elements in the answer from k size window onward
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};