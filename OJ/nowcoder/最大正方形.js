/**
 * 题目描述
给定一个由0和1组成的2维矩阵，返回该矩阵中最大的由1组成的正方形的面积
示例1
输入
复制

[[1,0,1,0,0],[1,0,1,1,1],[1,1,1,1,1],[1,0,0,1,0]]

返回值
复制

4


 * 
 * 
 * 最大正方形
 * @param matrix char字符型二维数组 
 * @return int整型
 */
function solve( matrix ) {
    // write code here
    
    let sum = [];
    for (let i = 0; i <= matrix.length; i++) {
        sum[i] = [0];
    }
    for (let i = 0; i <= matrix[0].length; i++) {
        sum[0][i] = 0;
    }
    for (let i = 1; i <= matrix.length; i++) {
        for (let j = 1; j <= matrix[i-1].length; j++) {
            let top = Number(sum[i-1][j]);
            let left = Number(sum[i][j-1]);
            let leftTop = Number(sum[i-1][j-1]); 
            sum[i][j] = left + top - leftTop + Number(matrix[i-1][j-1]);
        }
    }
    
    let maxD = 0;
    let maxLength = Math.min(matrix.length, matrix[0].length);
    for (let d = 0; d <= maxLength; d++) {
        if (!hasD(sum, d)) {
            return maxD * maxD;
        }
        maxD = d;
    }
    return maxD * maxD;
    
    function hasD(sumMatrix, d) {
        for (let i = 0; i < sumMatrix.length-d; i++) {
            for (let j = 0; j < sumMatrix[i].length-d; j++) {
                let leftSum = sumMatrix[i+d][j];
                let topSum = sumMatrix[i][j+d];
                let leftTopSum = sumMatrix[i][j];
                if (sumMatrix[i+d][j+d] - leftSum - topSum + leftTopSum === d * d) {
                    return true;
                }
            }
        }
        
        return false;
    }
}
module.exports = {
    solve : solve
};