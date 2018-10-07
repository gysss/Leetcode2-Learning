* 反转一个单链表。
* 示例：
  - 输入: 1-\>2-\>3-\>4-\>5-\>NULL
  - 输出: 5->4->3->2->1->NULL
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode *p = head;
        ListNode *q ;
        while(p->next!=NULL){
            q = p->next;
            p->next = q->next;
            q->next = head;
            head = q;
        }
        return head;
    }
};
```

* Python代码：

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        p = head
        if p is None:
            return []
        while p.next is not None:
            q = p.next
            p.next = q.next
            q.next = head
            head = q
        return head
```