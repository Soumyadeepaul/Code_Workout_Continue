#https://leetcode.com/problems/count-days-spent-together/description/?envType=daily-question&envId=2026-10-24


class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        arriveAlice+='-A'
        leaveAlice+='-A'
        arriveBob+='-B'
        leaveBob+='-B'

        aArrive = arriveAlice.split("-")
        aLeave = leaveAlice.split("-")

        bArrive = arriveBob.split("-")
        bLeave = leaveBob.split("-")

        interval = []
        interval.append(aArrive)
        interval.append(aLeave)
        interval.append(bArrive)
        interval.append(bLeave)
        interval.sort()


        if(interval[0][2]==interval[1][2]):
            if(interval[1][0]==interval[2][0] and interval[1][1]==interval[2][1]):
                return 1
            return 0

        days = [0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        monthStart=int(interval[1][0])
        monthEnd=int(interval[2][0])
        if(monthStart==monthEnd):
            return  int(interval[2][1])-int(interval[1][1])+1
        count = ( int(interval[2][1]) + days[monthStart] -(int(interval[1][1])-1) ) + (sum(days[monthStart+1:monthEnd]))

        return count
        
