//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//function Template for C++

//Function to reverse the queue.
class Solution
{
    private:
    void qRev(queue<int> &q)
    {
       if(q.empty())
        {
            return;
        }
        int num = q.front();
        q.pop();
        qRev(q);
        q.push(num); 
    }
    public:
    queue<int> rev(queue<int> q)
    {
        // add code here.
        qRev(q);
        return q;
    }
};


//{ Driver Code Starts.
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    Solution ob;
    queue<int> a=ob.rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends