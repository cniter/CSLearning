/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 * 
 *  对于一个字符串，请设计一个高效算法，计算其中最长回文子串的长度。

给定字符串A以及它的长度n，请返回最长回文子串的长度。
示例1
输入
复制

"abc1234321ab",12

返回值
复制

7


 * @param A string字符串 
 * @param n int整型 
 * @return int整型
 */
export function getLongestPalindrome(A: string, n: number): number {
    // write code here
    let length = 0;
    let tmpLength = 0;
    for (let i = 0; i < A.length; i++) {
        if (A.length - i < length)    break;
        tmpLength = 1;
        let count = Math.min(i - 0, A.length - i);
        for (let j = 1; j <= count; j++) {
            if (A[i+j] === A[i-j]) {
                tmpLength += 2;
            }
            else {
                break;
            }
        }
        if (tmpLength > length) {
            length = tmpLength;
        }
    }
    for (let i = 0; i < A.length; i++) {
        if (A.length - i < length)    break;
        tmpLength = 0;
        let count = Math.min(i - 0, A.length - i)-1;
        for (let j = 0; j <= count; j++) {
            if (A[i+j] === A[i-j-1]) {
                tmpLength += 2;
            }
            else {
                break;
            }
        }
        if (tmpLength > length) {
            length = tmpLength;
        }
    }
    return length;
}