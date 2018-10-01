"""
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 双指针，快指针每次比慢指针多走1，当两指针第一次相遇时，则有环，快指针比慢指针多走了环的长度M
# 将快指针重新指向头，快慢指针每次走一步，第二次相遇时，则指的是入环的第一个节点
class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        fast = head
        slow = head
        while fast is not None and fast.next is not None:
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                fast = head
                while fast is not slow:
                    fast = fast.next
                    slow = slow.next
                return fast
        return None
