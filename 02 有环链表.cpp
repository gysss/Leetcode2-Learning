//给定一个链表，判断链表中是否有环。

// 策略：采用快慢指针的策略，快指针追上了慢指针，则是环
# include <iostream>
// struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };

class Solution {
public:
    bool hasCycle(ListNode *head) {
    	if (head == NULL)
    	{
    		return false;
    	}
    	ListNode *quick;
    	ListNode *slow;
    	quick = head;
    	slow = head;
    	int count=0;
    	while(quick->next != NULL){
    		count+=1;
    		if (count%2 == 1)
    		{
    			quick = quick->next;
    		}
    		if (count %2 == 0)
    		{
    			quick = quick->next;
    			slow = slow->next;
    		}
    		if (quick->next == slow)
    		{
    			return true;
    		}
    	}
    	return false;
    }
};