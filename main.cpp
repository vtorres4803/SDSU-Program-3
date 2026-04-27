#include <iostream>
#include "LinkedList.h"

using namespace std;
using namespace LinkedListNS;

int main() {
    Node<int>* head = nullptr;

    cout << "Testing LinkedList...\n";

    // Insert
    headInsert(head, 1);
    headInsert(head, 2);
    headInsert(head, 3); // 3 -> 2 -> 1

    // Search test
    if (search(head, 2) != nullptr)
        cout << "Search works\n";
    else
        cout << "Search failed\n";

    // Delete first
    deleteFirstNode(head);

    if (search(head, 3) == nullptr)
        cout << "Delete first works\n";
    else
        cout << "Delete first failed\n";

    // Delete next node
    deleteNode(head);

    if (search(head, 1) == nullptr)
        cout << "Delete node works\n";
    else
        cout << "Delete node failed\n";

    return 0;
}
