"""
编写一个程序，找到两个单链表相交的起始节点。
"""

# 自己的：求出两个链表的长度差值，长的那个减去差值后，两链表同时移动，相同的节点即起点

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getlenth(self, head):
        count = 0
        while head:
            head = head.next
            count += 1
        return count

    def move_diff(self, head, diff):
        for i in range(diff):
            head = head.next
        return head

    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        len_A = self.getlenth(headA)
        len_B = self.getlenth(headB)
        len_diff = 0
        if len_A > len_B:
            len_diff = len_A - len_B
            headA = self.move_diff(headA, len_diff)
        else:
            len_diff = len_B - len_A
            headB = self.move_diff(headB, len_diff)
        pa = headA
        pb = headB
        while pa is not pb:
            pa = pa.next
            pb = pb.next
        return pa

# 方法二：更巧妙的办法，运用数学方法
# class Solution(object):
#     def getIntersectionNode(self, headA, headB):
#         """
#         :type head1, head1: ListNode
#         :rtype: ListNode
#         """
#         pA, pB = headA, headB
#         while pA is not pB:
#             pA = pA.next if pA else headB
#             pB = pB.next if pB else headA
#         return pA
