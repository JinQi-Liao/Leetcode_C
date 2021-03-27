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


struct ListNode* rotateRight(struct ListNode* head, int k){
    // 先求链表的长度
    if ( !head ) {
        return head;
    }
    int len = 0;
    struct ListNode* pre = head;
    while (pre)
    {
        len++;
        pre = pre->next;
    }

    // 开始移动
    k = k % len;
    if (k == 0) {
        return head;
    }
    // 先进行分割
    pre = head;
    for (int i = 1; i < len - k; i++) {
        pre = pre->next;
    }
    struct ListNode* succ = pre->next;
    pre->next = NULL;

    // 在开始遍历至最后一个节点
    struct ListNode* newHead = succ;
    for (int i = 1; i < k; i++) {
        succ = succ->next;
    }

    // 然后开始连接
    succ->next = head;
    return newHead;
}