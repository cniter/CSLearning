/**
 * 题目描述

请根据二叉树的前序遍历，中序遍历恢复二叉树，并打印出二叉树的右视图
示例1
输入
复制

[1,2,4,5,3],[4,2,5,1,3]

返回值
复制

[1,3,5]

备注:

二叉树每个节点的值在区间[1,10000]内，且保证每个节点的值互不相同。
 * 
 * 
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 * 求二叉树的右视图
 * @param xianxu int整型一维数组 先序遍历
 * @param zhongxu int整型一维数组 中序遍历
 * @return int整型一维数组
 */

function solve( xianxu ,  zhongxu ) {
    // write code here
    let root = buildTree(xianxu, zhongxu, 0, xianxu.length-1, 0, zhongxu.length-1);
    
    let res = [];
//     let queue = [root];
//     while (queue.length) {
//         let treeNode = queue.pop();
//         res.push(treeNode.data);
//         if (treeNode.left) queue.splice(0, 0, treeNode.left);
//         if (treeNode.right) queue.splice(0, 0, treeNode.right);
//     }
    let curLevelList = [root];
    while (curLevelList.length) {
        let nextLevelList = [];
        for (let i = 0; i < curLevelList.length; i++) {
            let treeNode = curLevelList[i];
            if (i === curLevelList.length-1) res.push(treeNode.data);
            if (treeNode.left) nextLevelList.push(treeNode.left);
            if (treeNode.right) nextLevelList.push(treeNode.right);
        }
        curLevelList = nextLevelList;
    }
    
    return res;
}

function buildTree(xianxu, zhongxu, preStartIndex, preEndIndex, midStartIndex, midEndIndex) {
    if (midEndIndex < midStartIndex) return null;
    
    let data = xianxu[preStartIndex];
    let midIndex = -1;
    for (let i = midStartIndex; i <= midEndIndex; i++) {
        if (zhongxu[i] === data) {
            midIndex = i;
            break;
        }
    }
    let leftMidStartIndex = midStartIndex;
    let leftMidEndIndex = midIndex - 1;
    let rightMidStartIndex = midIndex + 1;
    let rightMidEndIndex = midEndIndex;
    
    let leftPreStartIndex = preStartIndex + 1;
    let leftPreEndIndex = preStartIndex + midIndex - midStartIndex;
    let rightPreStartIndex = leftPreEndIndex + 1;
    let rightPreEndIndex = preEndIndex;
    
    let treeNode = {};
    treeNode.data = data;
    treeNode.left = buildTree(xianxu, zhongxu, leftPreStartIndex, leftPreEndIndex,
                             leftMidStartIndex, leftMidEndIndex);
    treeNode.right = buildTree(xianxu, zhongxu, rightPreStartIndex, rightPreEndIndex,
                             rightMidStartIndex, rightMidEndIndex);
    return treeNode;
}

module.exports = {
    solve : solve
};