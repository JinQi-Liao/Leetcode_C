#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    // 建立一个头结点
    struct ListNode* dummy = (struct ListNode*) malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* pre = dummy;
    struct ListNode* cur = head;

    while (cur != NULL)
    {
        // 用于记录重复结点的次数
        int curRepeatNum = 0;

        // 当前所要处理的节点
        struct ListNode* repeat = cur;
        while (repeat != NULL && repeat->val == cur->val) {
            curRepeatNum++;
            repeat = repeat->next;
        }
        if (curRepeatNum > 1) {
            pre->next = repeat;
        }
        else {
            pre = cur;
        }

        // 进行下一点的判断
        cur = repeat;
        
    }

   return dummy->next;
}