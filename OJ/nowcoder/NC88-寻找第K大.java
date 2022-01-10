/**
描述

有一个整数数组，请你根据快速排序的思路，找出数组中第 大的数。
给定一个整数数组 ,同时给定它的大小n和要找的 ，请返回第 K 大的数(包括重复的元素，不用去重)，保证答案存在。
要求时间复杂度
示例1
输入：

[1,3,5,2,2],5,3

返回值：

2

示例2
输入：

[10,10,9,9,8,7,5,6,4,3,4,2],12,3

返回值：

9

说明：

去重后的第3大是8，但本题要求包含重复的元素，不用去重，所以输出9    

 */


import java.util.*;

public class Solution {
    public void swap(int[] a, int i, int j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    
    public int partition(int[] a, int start, int end) {
        int seedIdx = start;
        int seed = a[seedIdx];
        while(start < end) {
            while (a[end] <= seed && start < end) end--;
            while (a[start] >= seed && start < end) start++;
            
            swap(a, start, end);
        }
        swap(a, seedIdx, end);
        
        return end;
    }
    
    public int qSelectK(int[] a, int k, int start, int end) {
        int idx = partition(a, start, end);
        if (idx < k) return qSelectK(a, k, idx+1, end);
        else if (idx > k) return qSelectK(a, k, start, idx-1);
        else return a[idx];
    }
    public int findKth(int[] a, int n, int K) {
        // write code here
        
        return qSelectK(a, K-1, 0, n-1);
    }
}