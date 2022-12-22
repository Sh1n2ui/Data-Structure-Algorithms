#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int _val = 0, ListNode* _next = nullptr) : val(_val), next(_next) { }
};

// Merge two sorted lists
ListNode* mergeSortList(ListNode* a, ListNode* b)
{
    ListNode* head = new ListNode();
    ListNode* tail = head;
    while (a != nullptr && b != nullptr) {
        if (a->val < b->val) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    if (a != nullptr) {
        tail->next = a;
    } else {
        tail->next = b;
    }
    return head->next;
}

// Sort an unsorted list given its head pointer
ListNode* mergeSortList(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;
    while (fast != nullptr && fast->next != nullptr)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = nullptr;
    ListNode* left = mergeSortList(head);
    ListNode* right = mergeSortList(slow);
    ListNode* newHead = nullptr;
    ListNode* current = nullptr;
    while (left != nullptr && right != nullptr)
    {
        if (left->val < right->val)
        {
            if (newHead == nullptr)
            {
                newHead = left;
                current = left;
            }
            else
            {
                current->next = left;
                current = current->next;
            }
            left = left->next;
        }
        else
        {
            if (newHead == nullptr)
            {
                newHead = right;
                current = right;
            }
            else
            {
                current->next = right;
                current = current->next;
            }
            right = right->next;
        }
    }
    if (left != nullptr)
        current->next = left;
    if (right != nullptr)
        current->next = right;
    return newHead;
}