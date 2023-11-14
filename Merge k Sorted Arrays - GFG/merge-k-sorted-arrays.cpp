//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++

class Node
{
    public:
        int i;
        int j;
        int data;
    
      Node(int data, int row, int col)
      {
          this->data = data;
          i = row;
          j = col;
      }
};
class compare
{
    public:
        bool operator()(Node* a, Node* b)
        {
             return a->data > b->data;   
        }
};
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        //step 1: declare a minHeap
        priority_queue<Node*,vector<Node*>,compare> minHeap;
        
        //step 2: populate 1st element of each array in minHeap
        for(int i = 0; i < K; i++)
        {
            Node* temp = new Node(arr[i][0],i,0);
            minHeap.push(temp);
        }
        
        //step 3: use this minHeap to store ans
        vector<int> ans;
        while(!minHeap.empty())
        {
            //push minimum element into answer array 
            Node* temp = minHeap.top();
            ans.push_back(temp->data);
            //remove that pushed element
            minHeap.pop();
            
            int i = temp->i;
            int j = temp->j;
            //now check the next element of same array if exist or not 
            //if next element is present push that element in minHeap
            if(j+1 < arr[i].size())
            {
                Node* newNode = new Node(arr[i][j+1],i,j+1);
                minHeap.push(newNode);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends