#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// 1、从数组中创建链表
struct ListNode* createList(int* array, int size) {
    struct ListNode* dummy = (struct ListNode*) malloc(sizeof(struct ListNode));
    dummy->val = array[0];
    struct ListNode* p = dummy;

    for (int i = 1; i < size; i++) {
        struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
        node->val = array[i];
        p->next = node;
        p = node;
    }

    // 添加尾结点
    p->next = NULL;

    return dummy;
}

// 2、反转整个链表
void reverseLinkedList(struct ListNode* head) {
    struct ListNode* pre = NULL;
    struct ListNode* cur = head;

    while (cur != NULL)
    {
        /* code */
        struct ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    
}


//3、反转[Left, right]之间的链表
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    // 添加虚拟的头结点
    struct ListNode* dummyNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    dummyNode->val = -1;
    dummyNode->next = head;

    // 先找到left前面的一个节点
    struct ListNode* pre = dummyNode;
    for (int i = 0; i < left - 1; i++) {
        pre = pre->next;
    }

    // 再找到right节点
    struct ListNode* rightNode = pre;
    for (int i = 0; i < right - left + 1; i++) {
        rightNode = rightNode->next;
    }

    // 将要反转的链表给切割出来
    struct ListNode* leftNode = pre->next;
    struct ListNode* curr = rightNode->next;
    pre->next = NULL;
    rightNode->next = NULL;
  
   // 进行反转
    reverseLinkedList(leftNode);

   // 接回原来的链表
    pre->next = rightNode;
    leftNode->next = curr;
   
    struct ListNode* res = dummyNode->next;

    // 一定要释放，否则就是内存泄漏了
    free(dummyNode);

    return res;

}



// 4、反转[Left, right]之间的链表，只需要进行1次反转
struct ListNode *reverseBetween1(struct ListNode *head, int left, int right) {
    // 因为头节点有可能发生变化，使用虚拟头节点可以避免复杂的分类讨论
    struct ListNode *dummyNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    dummyNode->val = -1;
    dummyNode->next = head;

    struct ListNode *pre = dummyNode;
    for (int i = 0; i < left - 1; i++) {
        pre = pre->next;
    }
    struct ListNode *cur = pre->next;
    struct ListNode *next;
    for (int i = 0; i < right - left; i++) {
        next = cur->next;
        cur->next = next->next;
        next->next = pre->next;
        pre->next = next;
    }
    return dummyNode->next;
}


int main() {
    int array[] = {1,2,3,4,5};
    struct ListNode* head = createList(array, 5);
    struct ListNode* head1 = reverseBetween(head, 2, 4);
    struct ListNode* p = head1;
    while (p != NULL)
    {
        /* code */

        // 有caller进行动态内存的释放
        printf("%d ", p->val);
        struct ListNode* temp = p->next;
        free(p);
        p = temp;
    }
    
    return 0;
}