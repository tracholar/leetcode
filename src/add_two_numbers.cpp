/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head = NULL, *p = head;

        int val = 0, lead = 0;
        int a,b;
        while(l1 != NULL || l2 != NULL || lead != 0){
            if(l1 != NULL) {
                a = l1->val;
                l1 = l1->next;
            }else{
                a = 0;
            }
            if(l2 != NULL){
                b = l2->val;
                l2 = l2->next;
            }else{
                b = 0;
            }
            val = a + b + lead;
            lead = val / 10;
            ListNode * q = new ListNode(val % 10);
            if(head == NULL) {
                head = q;
                p = head;
            }
            else{
                p -> next = q;
                p = p->next;
            }

        }
        return head;
    }
};


int main(){
    ListNode * l1 = new ListNode(3);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(2);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution s;
    ListNode *l3 = s.addTwoNumbers(l1, l2), *p = l3;
    assert(l3 != NULL);
    while(p != NULL){
        printf("%d", p->val);
        p = p->next;
    }
    printf("\n**** end program ****\n");
}