class Node{
  public:
    int data;
    int row;
    int col;
    
    Node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare{
    public:
        bool operator()(Node* a, Node* b)
        {
             return a->data > b->data;   
        }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        int mini = INT_MAX, maxi = INT_MIN, range = INT_MAX;
        int start = mini, end = maxi;
        priority_queue< Node*, vector<Node*>, compare > minHeap;
        for(int i = 0 ; i < nums.size(); i++)
        {
            int element = nums[i][0];
            mini = min(mini,element);
            maxi = max(maxi,element);
            minHeap.push(new Node(element,i,0));
        }
        
        while(!minHeap.empty())
        {
            Node* temp = minHeap.top();
            minHeap.pop();
            
            mini = temp->data;
            
            if(maxi - mini < range)
            {
                end = maxi;
                start = mini;
                range = end - start;
            }
            
            if((temp->col + 1) == nums[temp->row].size())
                break;
            maxi = max(maxi,nums[temp->row][temp->col+1]);
            minHeap.push(new Node(nums[temp->row][temp->col+1],temp->row,temp->col+1));
        }
        return {start,end};
    }
};