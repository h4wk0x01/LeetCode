// --> (github.com/h4wk0x01)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode asw, *ptr = &asw, *head = ptr;
    ptr = ptr->next = malloc(sizeof(struct ListNode));
    int n1 = 0, n2 = 0, carry = 0, sum = 0, num = 0;
    int flag = 1, finish_l1 = 0, finish_l2 = 0;
    while( flag ){
        n1 = l1->val; // Get values from dynamic nodes
        n2 = l2->val;
        if(finish_l1)
            n1 = 0; // If finish_l1, for now on, n1 = 0
        if(finish_l2)
            n2 = 0; // If finish_l2, for now on, n2 = 0
        if(l1->next == NULL) // If last number to sum from l1
            finish_l1 = 1; 
        if(l2->next == NULL) // If last number to sum from l2
            finish_l2 = 1; 
        sum = n1 + n2;
        
        if(carry == 1)
            sum += 1;
        if(sum > 9){
            carry = 1;
            num = sum%10;
        }else{
            carry = 0;
            num = sum;
        }
        ptr->val = num;
        if(l1->next == NULL && l2->next == NULL){ // Last Sum
            if(carry == 1){ // If carry, add one more node
                ptr = ptr->next = malloc(sizeof(struct ListNode));
                ptr-> val = carry;
            }
            ptr->next = NULL;
            flag = 0;
        }else{
            ptr = ptr->next = malloc(sizeof(struct ListNode));
            if(l1->next != NULL){ // If next pointer isn't null
                l1 = l1->next; // Advance
            }
            if(l2->next != NULL){
                l2 = l2->next;
            }
        }
    }

    return head->next;
}