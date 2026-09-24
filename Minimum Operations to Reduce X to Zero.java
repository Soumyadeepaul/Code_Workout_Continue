//https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/?envType=daily-question&envId=2026-09-23


class Helper {
    public static int[] pref(int[] nums, int l) {
        int[] result = new int[l];
        result[0] = nums[0];
        for (int i = 1; i < l; i++) {
            result[i] = result[i - 1] + nums[i];
        }
        return result;

    }

    public static int[] suff(int[] nums, int l) {
        int[] result = new int[l];
        result[l - 1] = nums[l - 1];
        for (int i = l - 2; i >= 0; i--) {
            result[i] = result[i + 1] + nums[i];
        }
        return result;
    }
}

class BS {
    public int bs(int[] suff, int i, int j, int find) {
        int start = i;
        int end = j;
        int mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if (find == suff[mid]) {
                return mid;
            } else if (find < suff[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
}

class Condition {
    private int result = -1;
    BS bs;

    Condition(BS bs) {
        this.bs = bs;
    }

    private int len(int i, int get, int l) {
        if (get == -1)
            return -1;
        return i + (l - get);
    }

    public void helper(int[] pref, int[] suff, int x, int l) {
        int get = bs.bs(suff, 0, l - 1, x);
        if (get != -1) {
            result = l - get;
        }
        for (int i = 0; i < l; i++) {
            int find = x - pref[i];
            System.out.println(find);
            if(find == 0){
                if(result==-1){
                    result=i+1;
                }
                else result = Math.min(result, i+1);
            }
            else if (find < 0) {
                break;
            }
            else{
                int index = bs.bs(suff, i + 1, l - 1, find);
                if (index != -1) {
                    int current = len(i + 1, index, l);
                    if (result == -1) {
                        result = current;
                    } else {
                        result = Math.min(result, current);
                    }
                }
            }
        }
    }

    public int getter() {
        return result;
    }
}

class Solution {
    public int minOperations(int[] nums, int x) {
        int l = nums.length;
        int[] pref = new int[l];
        int[] suff = new int[l];
        pref = Helper.pref(nums, l);
        suff = Helper.suff(nums, l);
        BS bs = new BS();
        Condition obj = new Condition(bs);
        obj.helper(pref, suff, x, l);
        return obj.getter();
    }
}
