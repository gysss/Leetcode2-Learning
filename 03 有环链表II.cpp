/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(head==NULL||head->next==NULL)
            //注意分析临界情况 (1)成环单节点; (2)不成环单节点; (3)成环2节点; (4)不成环2节点
            return NULL;
        while(slow!=NULL&&fast!=NULL&&fast->next!=NULL){ //判断是否成环
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                break;
        }
        if(slow==fast){
            slow=head;
            while(slow!=fast&&fast!=NULL&&fast->next!=NULL){ //找到环的起点
                slow=slow->next;
                fast=fast->next;
                if(slow==fast)
                    break;
            }
            return slow;
        }else{
            return NULL;
        }
 
    }
};
