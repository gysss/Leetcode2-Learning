* 要求：删除链表中等于给定值 val 的所有节点
* 示例：
  - 输入: 1->2->6->3->4->5->6, val = 6
  - 输出: 1->2->3->4->5
* C++代码：

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p, *q;
        p = (ListNode *)malloc(sizeof(ListNode));
        p->next = head;
        q = p;
        while(q->next != NULL){
            if(q->next->val == val){
                q->next = q->next->next;
            }
            else{
                q = q->next;
            }
        }
        return(p->next);
    }
};
```

* Python 代码：

```python

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        p = ListNode(-1)
        p.next = head
        q = p

        while q.next:
            if q.next.val == val:
                q.next = q.next.next
            else:
                q = q.next
        return p.next
```