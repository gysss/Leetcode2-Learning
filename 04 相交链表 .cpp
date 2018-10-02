// 编写一个程序，找到两个单链表相交的起始节点。

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
    int getlength(ListNode *head){
        int count = 0;
        while(head!=NULL){
            head = head->next;
            count++;
        }
        return count;
    }
    ListNode *movediff(ListNode *head,int diff){
        for(int i = 0;i<diff;i++){
            head = head->next;
        }
        return head;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        int len_A = getlength(headA);
        int len_B = getlength(headB);
        int diff = 0;
        if(len_A > len_B){
            diff = len_A - len_B;
            headA = movediff(headA, diff);
        }
        else{
            diff = len_B - len_A;
            headB = movediff(headB, diff);
        }
        ListNode *p,*q;
        p = headA;
        q = headB;
        while(p!=q && p!=NULL &q!=NULL){
            p = p->next;
            q = q->next;
        }
        return p;
    }
};