#include "LinkedList.h"
namespace LinkedListNS 
{
// Add node at the head
  template<class T>
  void headInsert(Node<T>*& head, const T& theData) 
  {
    head = new Node<T>(theData, head);
  }
// Add node at the head

  template<class T>
  void insert(Node<T>* afterMe, const T& theData) 
  {
    if (afterMe == nullptr) return;
    Node<T>* temp = new Node<T>(theData, afterMe->getLink());
    afterMe->setLink(temp);
  }
// Delete node after 'before'
  template<class T>
  void deleteNode(Node<T>* before) 
  {
    if (before == nullptr || before->getLink() == nullptr) 
      return;
    
    Node<T>* temp = before->getLink();
    before->setLink(temp->getLink());
    delete temp;
  }
// Delete first head
  template<class T>
  void deleteFirstNode(Node<T>*& head) 
  {
    if (head == nullptr) 
      return;

    Node<T>* temp = head;
    head = head->getLink();
    delete temp;
  }
  // Search for a value
  template<class T>
  Node<T>* search(Node<T>* head, const T& target) 
  {
    Node<T>* current = head;

    while (current != nullptr) 
    {
        if (current->getData() == target)
            return current;

        current = current->getLink();
    }
    return nullptr;
}
