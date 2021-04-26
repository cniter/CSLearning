/**
 * 题目描述
给定一个m x n大小的矩阵（m行，n列），按螺旋的顺序返回矩阵中的所有元素。
示例1
输入
复制

[[1,2,3],[4,5,6],[7,8,9]]

返回值
复制

[1,2,3,6,9,8,7,4,5]



 * @param matrix int整型二维数组 
 * @return int整型一维数组
 */
function spiralOrder( matrix ) {
    // write code here
    if (matrix.length < 1)    return [];
    let res = [];
    let count = matrix.length * matrix[0].length;
    for (let num = 0; num < (Math.min(matrix.length, matrix[0].length)+1)/2; num++) {
        for (let j = num; j < matrix[num].length - num; j++) {
            res.push(matrix[num][j]);
        }
        if (res.length >= count)    return res;
        for (let j = num+1; j < matrix.length - num; j++) {
            res.push(matrix[j][matrix[num].length-num-1]);
        }
        if (res.length >= count)    return res;
        for (let j = matrix[num].length-num-2; j >= num; j--) {
            res.push(matrix[matrix.length-num-1][j]);
        }
        if (res.length >= count)    return res;
        for (let j = matrix.length-num-2; j > num; j--) {
            res.push(matrix[j][num]);
        }
    }
    
    return res;
}
module.exports = {
    spiralOrder : spiralOrder
};