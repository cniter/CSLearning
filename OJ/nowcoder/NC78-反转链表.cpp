/***
描述
输入一个链表，反转链表后，输出新链表的表头。
示例1
输入：

{1,2,3}

返回值：

{3,2,1}
 **/


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode *p = nullptr;
        ListNode *q = pHead;
        
        while (q != nullptr) {
            ListNode *tmp = q->next;
            q->next = p;
            p = q;
            q = tmp;
        }
        
        return p;
    }
};
