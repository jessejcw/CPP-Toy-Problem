//
// Created by jesse wang on 2/23/17.
//

#ifndef CODE1_SORTLIST_H
#define CODE1_SORTLIST_H

#include "inc_me.h"

class SortList {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next;
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* mid = slow->next;
        slow->next = NULL;

        ListNode* list1 = sortList(head);
        ListNode* list2 = sortList(mid);

        ListNode* sorted = merge(list1, list2);
        return sorted;
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }
        ListNode* head;
        ListNode* tmp;
        if (list1->val < list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }
        tmp = head;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tmp->next = list1;
                tmp = list1;
                list1 = list1->next;
            } else {
                tmp->next = list2;
                tmp = list2;
                list2 = list2->next;
            }
        }
        if (list1) {
            tmp->next = list1;
        }
        if (list2) {
            tmp->next = list2;
        }
        return head;
    }
};


#endif //CODE1_SORTLIST_H
