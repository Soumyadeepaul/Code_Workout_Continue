//https://leetcode.com/problems/maximum-alternating-sum-of-squares/description/?envType=daily-question&envId=2026-10-13


class Solution {
    public long maxAlternatingSum(int[] nums) {
        int len=nums.length;
        PriorityQueue<Integer> pq= new PriorityQueue<>();
        for (int num : nums) pq.add(Math.abs(num)); 
        long result=0;
        for(int i=1;i<len;i+=2){
            result-=Math.pow(pq.poll(),2);
        }
        for(int i=0;i<len;i+=2){
            result+=Math.pow(pq.poll(),2);
        }
        return result;
    }
}
