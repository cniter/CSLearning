/**
 * 
 * 题目描述
给一个01矩阵，1代表是陆地，0代表海洋， 如果两个1相邻，那么这两个1属于同一个岛。我们只考虑上下左右为相邻。
岛屿: 相邻陆地可以组成一个岛屿（相邻:上下左右） 判断岛屿个数。
示例1
输入
复制

[[1,1,0,0,0],[0,1,0,1,1],[0,0,0,1,1],[0,0,0,0,0],[0,0,1,1,1]]

返回值
复制

3


 */


import java.util.*;


public class Solution {
    /**
     * 判断岛屿数量
     * @param grid char字符型二维数组 
     * @return int整型
     */
    public int solve (char[][] grid) {
        // write code here
        int rows = grid.length;
        int cols = grid[0].length;
        int[][] labels = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                labels[i][j] = 0;
            }
        }
        
        int marker = 0;
        int[][] pos = new int[][]{{0,-1},{0,1},{-1,0},{1,0}};
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                LinkedList<int[]> queue = new LinkedList<int[]>();
                if (grid[i][j] > '0' && labels[i][j] < 1) {
                    marker++;
                    queue.offer(new int[]{j,i});
                    labels[i][j] = marker;
                }
                while (!queue.isEmpty()) {
                    int[] top = queue.poll();
                    for(int p = 0; p < pos.length; p++) {
                        int[] xy = pos[p];
                        int x = top[0] + xy[0];
                        int y = top[1] + xy[1];
                        if (
                            x > -1 && x < cols
                            && y > -1 && y < rows
                            && labels[y][x] < 1
                            && grid[y][x] > '0'
                        ) {
                            queue.offer(new int[]{x,y});
                            labels[y][x] = marker;
                        }
                    }
                }
            }
        }
        
        return marker;
    }
}