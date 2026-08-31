#https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/?envType=daily-question&envId=2026-08-31

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        store=[]

        idx=0

        temp=head
        prev=None
        nextt=head.next
        while nextt:
            if prev!=None:
                if prev.val>temp.val and temp.val<nextt.val:
                    store.append(idx)
                if prev.val<temp.val and temp.val>nextt.val:
                    store.append(idx)
            idx+=1
            prev=temp
            temp=nextt
            nextt=nextt.next
        
        result=[-1,-1]
        mini=pow(10,9)
        for i in range(0,len(store)-1):
            mini=min(mini,store[i+1]-store[i])
        maxi=-1
        if len(store)>1:
            maxi=store[-1]-store[0]
        
        if mini!=pow(10,9):
            result[0]=mini
        result[1]=maxi
        return result
