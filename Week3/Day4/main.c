#include "linked_list.h"

int main() {
    node_t *head1 = NULL;
    push_back(&head1, 45);
    push_back(&head1, 412);
    push_back(&head1, 12);
    push_back(&head1, 43);
    push_back(&head1, 98);
    printList(head1);
    reverse(&head1);
    printList(head1);
    destroy_ll(head1);

    return 0;
}