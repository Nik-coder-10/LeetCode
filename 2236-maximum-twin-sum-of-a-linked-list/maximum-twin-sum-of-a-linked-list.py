class Solution:
    def pairSum(self, head):
        slow = fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        prev = None
        curr = slow

        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt

        ans = 0
        first = head
        second = prev

        while second:
            ans = max(ans, first.val + second.val)
            first = first.next
            second = second.next

        return ans