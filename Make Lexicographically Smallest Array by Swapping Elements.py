#https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/?envType=daily-question&envId=2026-08-29


class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        pairNum=[]
        for i in range(0,len(nums)):
            pairNum.append([nums[i],i])
        
        pairNum=sorted(pairNum)

        j=1
        store=[]
        temp=[]
        while j<len(pairNum):
            if abs(pairNum[j][0]-pairNum[j-1][0])<=limit :
                temp.append(pairNum[j-1])
            else:
                temp.append(pairNum[j-1])
                store.append(temp)
                temp=[]
            j+=1
        temp.append(pairNum[j-1])
        store.append(temp)
        
        for v in store:
            pos=[]
            for i,j in v:
                pos.append(j)
            pos=sorted(pos)
            for i in range(0,len(v)):
                nums[pos[i]]=v[i][0]


        return nums
