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

/**
 * 判断岛屿数量
 * @param grid char字符型二维数组 
 * @return int整型
 */
function solve( grid ) {
    // write code here
    let marker = [[]];
    for (let i = 0; i < grid.length; i++) {
        marker[i] = [];
        for (let j = 0; j < grid[i].length; j++) {
            marker[i][j] = 0;
        }
    }
    let indexer = [-1,1];
    let queue = [];
    let mark = 0;
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[i].length; j++) {
            if (grid[i][j] > 0 && marker[i][j] < 1) queue.push([i,j]);
            if (queue.length > 0) mark++;
            while (queue.length > 0) {
                let idx = queue[0];
                queue.splice(0,1);
                if (grid[idx[0]][idx[1]]>0 && marker[idx[0]][idx[1]] < 1) {
                    marker[idx[0]][idx[1]] = mark;
                }
                for (let k = 0; k < indexer.length; k++) {
                    let row = idx[0];
                    let col = idx[1] + indexer[k];
                    if (col < 0)    col = 0;
                    if (col >= grid[0].length) col = grid[0].length-1;
                    if (grid[row][col]>0 && marker[row][col] < 1) {
                        marker[row][col] = mark;
                        queue.push([row, col]);
                    }
                }
                for (let k = 0; k < indexer.length; k++) {
                    let row = idx[0] + indexer[k];
                    let col = idx[1];
                    if (row < 0)    row = 0;
                    if (row >= grid.length) row = grid.length-1;
                    if (grid[row][col]>0 && marker[row][col] < 1) {
                        marker[row][col] = mark;
                        queue.push([row, col]);
                    }
                }
            }
        }
    }
    
    
    return mark;
}
module.exports = {
    solve : solve
};