#https://leetcode.com/problems/removing-minimum-and-maximum-from-array/description/?envType=daily-question&envId=2026-08-30

class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        #indexes
        mini=0
        maxi=0

        for i in range(len(nums)):
            if nums[i]<nums[mini]:
                mini=i
            
            if nums[i]>nums[maxi]:
                maxi=i


        l=len(nums)
        #if removed from end
        miniEnd=l-mini
        maxiEnd=l-maxi

        #if removed from start
        miniStart=mini+1
        maxiStart=maxi+1
        
        operations=[miniStart+maxiStart-min(miniStart,maxiStart), miniStart+maxiEnd, miniEnd+maxiStart, miniEnd+maxiEnd-min(miniEnd,maxiEnd)]
        return min(operations)
