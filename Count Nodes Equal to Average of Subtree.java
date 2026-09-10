//https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/?envType=daily-question&envId=2026-09-10


/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int count=0;
    public int[] helper(TreeNode parent){
        if(parent!=null){
            int[] left=helper(parent.left);
            int[] right=helper(parent.right);

            if(((left[0]+right[0]+parent.val)/(left[1]+right[1]+1))==parent.val){
                count++;
            }

            return new int[]{left[0]+right[0]+parent.val,left[1]+right[1]+1};
        }
        return new int[]{0,0};
    }
    public int averageOfSubtree(TreeNode root) {
        helper(root);
        return count;
    }
}
