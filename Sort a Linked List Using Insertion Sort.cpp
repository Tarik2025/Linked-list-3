#include <iostream>

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to sort the linked list using insertion sort
ListNode* insertionSortList(ListNode* head) {
    ListNode* dummy = new ListNode(0); // Create a new sorted list
    ListNode* current = head;

    while (current) {
        ListNode* prev = dummy;
        // Find the correct position to insert the current node
        while (prev->next && prev->next->val < current->val) {
            prev = prev->next;
        }

        ListNode* next = current->next;
        current->next = prev->next;
        prev->next = current;
        current = next;
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
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    std::cout << "Original list: ";
    printList(head);

    head = insertionSortList(head);

    std::cout << "After insertion sort: ";
    printList(head);

    return 0;
}

