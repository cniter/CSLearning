/**
 * 给定数组arr，设长度为n，输出arr的最长递增子序列。（如果有多个答案，请输出其中字典序最小的）
示例1
输入
复制

[2,1,5,3,6,4,8,9,7]

返回值
复制

[1,3,4,8,9]

示例2
输入
复制

[1,2,8,6,4]

返回值
复制

[1,2,4]

说明

其最长递增子序列有3个，（1，2，8）、（1，2，6）、（1，2，4）其中第三个字典序最小，故答案为（1，2，4）

备注:

n≤105n \leq 10^5n≤105
1≤arri≤1091 \leq arr_i \leq 10^91≤arri​≤109
 * retrun the longest increasing subsequence
 * @param arr int整型一维数组 the array
 * @return int整型一维数组
 */
function LIS( arr ) {
    // write code here
    let is = [];
    is[0] = [Number.MIN_SAFE_INTEGER];
    is[1] = [arr[0]];
    for (let i = 1; i < arr.length; i++) {
        if (is[is.length-1][is[is.length-1].length-1] < arr[i]) {
            is.push(is[is.length-1].concat(arr[i]));
            continue;
        }
        let left = 0;
        let right = is.length-2;
        let index = 0;
        while (left <= right) {
            index = Math.trunc((left + right) / 2);
            if (is[index][is[index].length-1] === arr[i]) break;
            else if (is[index][is[index].length-1] > arr[i]) {
                right = index - 1;
            }
            else {
                left = index + 1;
            }
        }
        if (is[index][is[index].length-1] === arr[i]) continue;
        if (is[index][is[index].length-1] > arr[i]) {
            index -= 1;
        }
        let next = index + 1;
        if (index === 0) is[next] = [arr[i]];
        else {
            is[next] = is[index].slice();
            is[next].push(arr[i]);
            
//             is[next] = is[index].concat(arr[i]);
            
//             is[next].length = 0;
//             Object.assign(is[next], is[index]);
//             is[next].push(arr[i]);
        }
        
    }
    
    return is[is.length-1];
}
module.exports = {
    LIS : LIS
};