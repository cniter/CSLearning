/*
题目描述
给出一组区间，请合并所有重叠的区间。
示例1
输入
复制

[[10,30],[20,60],[80,100],[150,180]]

返回值
复制

[[10,60],[80,100],[150,180]]



 * function Interval(a, b){
 *   this.start = a || 0;
 *   this.end = b || 0;
 * }
 */

/**
 * 
 * @param intervals Interval类一维数组 
 * @return Interval类一维数组
 */
function merge( intervals ) {
    // write code here
    
    let res = [];
    intervals.sort((a, b) => a.start - b.start);
    for (let i = 0; i < intervals.length; i++) {
        let tmp = intervals[i];
        while (i < intervals.length-1 && tmp.end >= intervals[i+1].start) {
            tmp.end = Math.max(intervals[i+1].end, tmp.end);
            i++;
        }
        res.push(tmp);
    }
    
    return res;
}
module.exports = {
    merge : merge
};