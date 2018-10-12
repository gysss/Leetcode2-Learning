# 两数相加
## 要求
* 给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。

## 示例
* 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
* 输出：7 -> 0 -> 8
* 原因：342 + 465 = 807

## Python代码

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(-1)
        cur = dummy;
        count = 0
        # l1 l2 is not None
        while l1 and l2:
            tmp = l1.val + l2.val + count
            count = 0
            if tmp <=9 :
                l1.val = tmp
            else:
                l1.val = tmp % 10
                count = 1
            cur.next = l1
            l1 = l1.next
            l2 = l2.next
            cur = cur.next
            
        # l1 l2 is None but count=1
        if(l1 is None and l2 is None and count == 1):
            res = ListNode(1)
            cur.next = res
        
        # l1 is nont None
        elif(l1 is not None):
            while(l1 is not None and count == 1):
                l1.val += count
                if(l1.val > 9):
                    l1.val = l1.val % 10
                    count = 1
                else:
                    count = 0
                cur.next = l1
                l1 = l1.next
                cur = cur.next
            if(count == 1):
                res = ListNode(1)
                cur.next = res
            else:
                cur.next = l1
        
        # l2 is not None
        elif(l2 is not None):
            while(l2 is not None and count == 1):
                l2.val += count
                if(l2.val > 9):
                    l2.val = l2.val % 10
                    count = 1
                else:
                    count = 0
                cur.next = l2
                l2 = l2.next
                cur = cur.next
            if(count == 1):
                res = ListNode(1)
                cur.next = res
            else:
                cur.next = l2  
        return dummy.next
                
```