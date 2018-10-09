# 回文链表
## 要求
* 请判断一个链表是否为回文链表

## 示例
* 输入: 1->2
* 输出: false
* 输入: 1->2->2->1
* 输出: true

## 思路
1. 可以用链表存数据，然后翻转链表进行比较，空间复杂度大
2. 可以找到中间节点，分成两个链表，翻转链表二，然后比较，空间复杂度为O(1)

## Python 代码

```python
# 思路1

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        ans = []
        while head:
            ans.append(head.val)
            head = head.next
        return ans == ans[::-1]
        
# 思路2
class Solution:
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        fast = slow = head
        #找到中间节点
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        # 翻转后半部分
        prev = None
        while slow:
            tmp = slow.next
            slow.next = prev
            prev = slow
            slow = tmp
        # 比较前后两部分
        while prev:
            if prev.val != head.val:
                return False
            prev = prev.next
            head = head.next
        return True
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
    ListNode* func(ListNode* head){
        if(head->next != NULL){
            ListNode *tail = func(head->next);
            tail->next = head;
            head->next = NULL;
        }
        return head;
    }
    ListNode* reverseList(ListNode* head){
        if(head == NULL || head->next == NULL)
            return head;
        ListNOde *newhead = head;
        while(newhead->next != NULL){
            newhead = newhead->next;
        }
        func(head);
        return newhead;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next == NULL)
            return true;
        ListNode *p, *q;
        p = head;
        q = head;
        while(q!=NULL && q->next!=NULL){
            p = p->next;
            q = q->next->next;
        }
        p = reverseList(p);
        while(p != NULL) {
            if(head->val != p->val)
                return false;
            else {
                head = head->next;
                p = p->next;
            }
        }
        return true;
    }
};
```













