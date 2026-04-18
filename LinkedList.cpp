#include "LinkedList.h"
namespace LinkedListNS 
{
  template<class T>
  void headInsert(Node<T>*& head, const T& theData) 
  {
    head = new Node<T>(theData, head);
  }
  template<class T>
  void insert(Node<T>* afterMe, const T& theData) 
  {
    if (afterMe == nullptr) return;
    Node<T>* temp = new Node<T>(theData, afterMe->getLink());
    afterMe->setLink(temp);
  }
}
