#https://leetcode.com/problems/count-servers-that-communicate/description/


class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        count=0
        r=len(grid)
        c=len(grid[0])
        for i in range(0,r):
            for j in range(0,c):
                if grid[i][j]==1:
                    #row
                    a=j-1
                    b=j+1
                    found=0
                    while a>-1:
                        if grid[i][a]==1:
                            found=1
                            count+=1
                            break
                        a-=1
                    if found==0:
                        while b<c:
                            if grid[i][b]==1:
                                found=1
                                count+=1
                                break
                            b+=1
                    #col
                    a=i-1
                    b=i+1
                    if found==0:
                        while a>-1:
                            if grid[a][j]==1:
                                found=1
                                count+=1
                                break
                            a-=1
                    if found==0:
                        while b<r:
                            if grid[b][j]==1:
                                found=1
                                count+=1
                                break
                            b+=1
        return count
