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

// 需要进一步修改，被这个标准flag变量给去掉
struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL) {
        return head;
    }
    struct ListNode* cur = head;
    struct ListNode* succ = head->next;
    while (cur != NULL && succ != NULL)
    {
        /* code */
        int flag = 0;
       while (cur && succ && cur->val == succ->val)
       {
           /* code */
           succ = succ->next;
           flag = 1;
       }
       if (flag) {
            cur->next = succ;
            cur = succ;
       }
       else {
           cur = cur->next;
           succ = succ->next;
       }
      
    }
    
    return head;
}