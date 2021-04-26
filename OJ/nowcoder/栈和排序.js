/**题目描述
给你一个1->n的排列和一个栈，入栈顺序给定
你要在不打乱入栈顺序的情况下，对数组进行从大到小排序
当无法完全排序时，请输出字典序最大的出栈序列
示例1
输入
复制

[2,1,5,3,4]

返回值
复制

[5,4,3,1,2]

说明

2入栈；1入栈；5入栈；5出栈；3入栈；4入栈；4出栈；3出栈；1出栈；2出栈

备注:

n<=1e6
 * 栈排序
 * @param a int整型一维数组 描述入栈顺序
 * @return int整型一维数组
 */
function solve( a ) {
    // write code here
    let max = [];
    let maxIndex = [];
    for (let i = a.length-1; i >= 0; i--) {
        if (i === a.length-1 || (i < a.length-1 && a[i] >= max[i+1])) {
            max[i] = a[i];
            maxIndex[i] = i;
            continue;
        }
        
        max[i] = max[i+1];
        maxIndex[i] = maxIndex[i+1];
    }
    
    
    const res = [];
    const stack = [];
    for (let i = 0; i < a.length; i++) {
        stack.push(a[i]);
        if (i === maxIndex[i]) {
            res.push(stack.pop());
            
            while (stack.length > 0 
                   && i < a.length-1 
                   && stack[stack.length-1] > max[i+1]
            ) {
                res.push(stack.pop());
            }
        }
    }
    while (stack.length > 0) {
        res.push(stack.pop());
    }
    
    return res;
}
module.exports = {
    solve : solve
};
