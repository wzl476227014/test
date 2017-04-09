/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *tmpNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *p = tmpNode;
    tmpNode->val = 0;
    tmpNode->next = NULL;
    int carry = 0;
    if (l1 == NULL && l2 == NULL) {
        return tmpNode;
    }
    while(l1 != NULL || l2 != NULL) {
        int num1 = l1 == NULL?0:l1->val;
        int num2 = l2 == NULL?0:l2->val;
        int sum = num1 + num2 + carry;
        p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->next->val = sum % 10;
        carry = sum / 10;
        p = p->next;
        p->next = NULL;
        l1=l1 == NULL? NULL:l1->next;
        l2=l2 == NULL? NULL:l2->next;
    }
    if(carry == 1) {
        p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->next->val = carry;
        p = p->next;
        p->next = NULL;
    }
    return tmpNode->next;
}
