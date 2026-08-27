##https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/description/?envType=daily-question&envId=2026-08-27



class Helper:
    def joiner(self,hashmap):
        r=""
        for i,j in hashmap.items():
            if j!=0:
                r+=(i*j)
        r="".join(sorted(r))
        return r
    
    def fun(self,hashmap,idx, target, result):
        if(idx==len(target)):
            if(result>target):
                return result
            return ""
        start=target[idx]
        for e in range(ord(start),ord('z')+1):
            element=chr(e)
            if element in hashmap and hashmap[element]!=0:
                result+=element
                hashmap[element]-=1
                if(element!=start):
                    ans=result+self.joiner(hashmap)
                else:
                    ans=self.fun(hashmap,idx+1,target,result)
                if len(ans)==len(target) and ans>target:
                    return ans
                hashmap[element]+=1
                result=result[:-1]
        return ""
class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        hashmap=dict()
        for i in s:
            if i not in hashmap:
                hashmap[i]=0
            hashmap[i]+=1
        result=""
        obj=Helper()
        return obj.fun(hashmap,0,target,result)
