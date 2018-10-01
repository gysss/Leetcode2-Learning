"""
给定一个链表，判断链表中是否有环。
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        fast = head
        slow = head
        count = 0
        while fast is not None and fast.next is not None:
            count +=1
            if count%2==1:
                fast = fast.next
            else:
                fast = fast.next
                slow = slow.next
            if fast is slow:
                return True
        return False
