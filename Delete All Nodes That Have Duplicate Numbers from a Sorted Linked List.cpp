
#include <iostream>

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to delete all nodes that have duplicate numbers
ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return nullptr;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* current = head;

    while (current) {
        bool duplicate = false;
        while (current->next && current->val == current->next->val) {
            duplicate = true;
            ListNode* temp = current;
            current = current->next;
            delete temp;
        }

        if (duplicate) {
            ListNode* temp = current;
            current = current->next;
            delete temp;
            continue;
        }

        prev->next = current;
        prev = current;
        current = current->next;
    }

    prev->next = nullptr; // Make sure the end of list is correctly set
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
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);

    std::cout << "Original list: ";
    printList(head);

    head = deleteDuplicates(head);

    std::cout << "After removing duplicates: ";
    printList(head);

    return 0;
}
