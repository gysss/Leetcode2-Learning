//给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p,*q;
        p = head;
        q = head;
        for(int i = 0;i<n;i++){
            p = p->next;
        }
        if(p == NULL){
            head = head->next;
            return head;
        }
        while(p->next){
            p = p->next;
            q = q->next;
        }
        q->next = q->next->next;
        return head;
    }
};