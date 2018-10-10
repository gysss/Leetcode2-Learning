# 合并两个有序链表
## 要求
* 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

## 示例
* 输入：1->2->4, 1->3->4
* 输出：1->1->2->3->4->4

## Python 代码

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        dummy = ListNode(-1)
        cur = dummy
        while l1 and l2:
            if l1.val < l2.val:
                cur.next = l1
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
            cur = cur.next
        if l1:
            cur.next = l1
        else:
            cur.next = l2
        return dummy.next
```

## C++ 代码

```c
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p, *q;
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        if(l1->val < l2->val){
            p = l1;
            q = l1;
            l1 = l1->next;
        }
        else{
            p = l2;
            q = l2;
            l2 = l2->next;
        }
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                q->next = l1;
                q = q->next;
                l1 = l1->next;
            }
            else{
                q->next = l2;
                q = q->next;
                l2 = l2->next;
            }
        }
        if(l1!=NULL){
            q->next = l1;
            l1 = l1->next;
            q = q->next;
        }
        else if(l2 != NULL){
            q->next = l2;
            l2 = l2->next;
            q = q->next;
        }
        return p;
    }
};
```