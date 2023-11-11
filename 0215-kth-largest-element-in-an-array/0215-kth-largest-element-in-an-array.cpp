class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // using heap we will solve 
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>> minHeap;
        
        //step 1 : build a min heap for k elements of the array
        for(int i = 0; i < k; i++)
            minHeap.push(nums[i]);
        
        //step 2: now we will process remaining elemnts of array 
        for(int i = k ; i < n; i++)
            if(nums[i] > minHeap.top())
            {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        
        //step 3: top of minHeap is kth largest element return it
        int ans = minHeap.top();
        return ans;
    }
};