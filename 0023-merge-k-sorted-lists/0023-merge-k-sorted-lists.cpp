/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class compare{
    public:
        bool operator()(ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //declare a minHeap with ListNode as its node value
        priority_queue<ListNode* , vector<ListNode*>, compare > minHeap;
        
        //size of list
        int n = lists.size();
        
        if(n == 0)
            return NULL;
        
        //step 1: populate this minHap with values of LL
        for(int i = 0 ; i < n; i++)
        {
            if(lists[i] != NULL)
            {
                minHeap.push(lists[i]);   
            }
        }
        
        ListNode* head = NULL;
        ListNode* tail = NULL;
        
        while(!minHeap.empty())
        {
            ListNode* temp = minHeap.top();
            minHeap.pop();
            
            if(temp != NULL && temp->next != NULL)
                minHeap.push(temp->next);
            
            //when we enter first element in answer LL
            if(head == NULL)
                head = tail = temp;
            else
            {
                // we insert at last in answer LL
                tail->next = temp;
                tail = temp;
            }
        }
        return head;
    }
};