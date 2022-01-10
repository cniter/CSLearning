/*
描述
输入一个长度为n的整型数组a，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为 O(n).

提示:
1 <= n <= 500
-100 <= a[i] <= 100

示例1
输入：

[1,-2,3,10,-4,7,2,-5]

返回值：

18

说明：

输入的数组为{1,-2,3,10,-4,7,2,-5}，和最大的子数组为{3,10,-4,7,2}，因此输出为该子数组的和 18。    
 */

public class Solution {
    public int solution1(int[] array) {
        int[] sums = new int[array.length];
        sums[0] = array[0];
        for (int i = 1; i < array.length; i++) {
            sums[i] = sums[i-1] + array[i];
        }
        
        int max = sums[0];
        for (int i = 0; i < array.length; i++) {
            for (int j = i; j < array.length; j++) {
                int tmp = sums[j] - sums[i] + array[i];
                if (tmp > max) max = tmp;
            }
        }
        
        return max;
    }
    
    public int solution2(int[] array) {
        int[] dp = new int[array.length];
        int max = array[0];
        dp[0] = array[0];
        for (int i = 1; i < array.length; i++) {
            int tmp = dp[i-1] + array[i];
            if (tmp > array[i]) dp[i] = tmp;
            else dp[i] = array[i];
            
            max = Math.max(dp[i], max);
        }
        
        return max;
    }
    
    public int FindGreatestSumOfSubArray(int[] array) {
        return solution2(array);
    }
}