import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 将给定数组排序
     * @param arr int整型一维数组 待排序的数组
     * @return int整型一维数组
     */
    
    void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
    
    int partition(int[] arr, int start, int end) {
        int seedIdx = start;
        while(start < end) {
            while(arr[end] >= arr[seedIdx] && end > start) end--;
            while(arr[start] <= arr[seedIdx] && end > start) start++;
            swap(arr, start, end);
        }
        swap(arr, seedIdx, end);
        
        return end;
    }
    
    void qsort(int[] arr, int start, int end) {
        if (start >= end) return;
        int seed = partition(arr, start, end);
        qsort(arr, start, seed-1);
        qsort(arr, seed+1, end);
    }
    
    void merge(int[] arr, int start, int mid, int end) {
        if (mid >= arr.length) mid = arr.length-1;
        if (end >= arr.length) end = arr.length-1;
        
        int[] helper = new int[end-start+1];
        int p = start;
        int q = mid+1;
        int i = 0;
        while (p <= mid && q <= end) {
            if (arr[p] <= arr[q]) {
                helper[i++] = arr[p++];
            } else helper[i++] = arr[q++];
        }
        while(p <= mid) helper[i++] = arr[p++];
        while(q <= end) helper[i++] = arr[q++];
        
        i = 0;
        while(start <= end) arr[start++] = helper[i++];
    }
    
    void msort(int[] arr, int start, int end) {
        if (start >= end) return;
        int mid = start + ((end-start) >> 1);
        msort(arr, start, mid);
        msort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
    
    void msortIter(int[] arr) {
        for (int seg = 1; seg < arr.length; seg += seg) {
            for (int start = 0; start < arr.length; start += seg * 2) {
                merge(arr, start, start + seg-1, start + seg * 2-1);
            }
        }
    }
    
    public int[] MySort (int[] arr) {
        // write code here
//         msort(arr, 0, arr.length-1);
        msortIter(arr);
        return arr;
    }
}