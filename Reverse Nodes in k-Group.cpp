#include <iostream>

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Helper function to reverse a section of the list
ListNode* reverseSection(ListNode* head, ListNode* tail) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (prev != tail) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to reverse nodes in k-group
ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1) return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* curr = head;

    while (true) {
        ListNode* tail = curr;
        int count = 0;
        while (tail && count < k) {
            tail = tail->next;
            count++;
        }
        if (count < k) break; // Less than k nodes left

        ListNode* nextSection = tail;
        ListNode* newHead = reverseSection(curr, tail);

        prev->next = newHead;
        curr->next = nextSection;
        prev = curr;
        curr = nextSection;
    }

    return dummy->next;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Main function to test the solution
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    std::cout << "Original list: ";
    printList(head);

    head = reverseKGroup(head, k);

    std::cout << "List after reversing in k-groups: ";
    printList(head);

    return 0;
}

