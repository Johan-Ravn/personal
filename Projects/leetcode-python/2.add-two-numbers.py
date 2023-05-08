#
# @lc app=leetcode id=2 lang=python3
#
# [2] Add Two Numbers
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        answer = ListNode(0)
        current_node = answer
        while l1 or l2 or carry:
            l1_val = l1.val if l1 else 0
            l2_val = l2.val if l2 else 0
            sum_val = l1_val + l2_val + carry
            carry = sum_val // 10
            current_node.next = ListNode(sum_val % 10)
            current_node = current_node.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        return answer.next

        
        

        
# @lc code=end

