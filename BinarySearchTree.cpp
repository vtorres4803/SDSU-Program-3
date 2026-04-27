#include "BinarySearchTree.h"

template<class T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = nullptr;
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
    makeEmpty();
}

template<class T>
void BinarySearchTree<T>::insert(const T& valor)
{
    root = insert(root, valor);
}

template<class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::insert(Node* nodo, const T& valor)
{
    if (nodo == nullptr)
    {
        return new Node(valor);
    }

    if (valor < nodo->data)
    {
        nodo->left = insert(nodo->left, valor);
    }
    else
    {
        nodo->right = insert(nodo->right, valor);
    }

    return nodo;
}

template<class T>
bool BinarySearchTree<T>::search(const T& valor) const
{
    return search(root, valor);
}

template<class T>
bool BinarySearchTree<T>::search(Node* nodo, const T& valor) const
{
    if (nodo == nullptr)
    {
        return false;
    }

    if (nodo->data == valor)
    {
        return true;
    }

    if (valor < nodo->data)
    {
        return search(nodo->left, valor);
    }

    return search(nodo->right, valor);
}

template<class T>
int BinarySearchTree<T>::size() const
{
    return size(root);
}

template<class T>
int BinarySearchTree<T>::size(Node* nodo) const
{
    if (nodo == nullptr)
    {
        return 0;
    }

    return 1 + size(nodo->left) + size(nodo->right);
}

template<class T>
int BinarySearchTree<T>::height() const
{
    return height(root);
}

template<class T>
int BinarySearchTree<T>::height(Node* nodo) const
{
    if (nodo == nullptr)
    {
        return -1;
    }

    int izq = height(nodo->left);
    int der = height(nodo->right);

    return 1 + (izq > der ? izq : der);
}

template<class T>
void BinarySearchTree<T>::remove(const T& valor)
{
    root = remove(root, valor);
}

template<class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::remove(Node* nodo, const T& valor)
{
    if (nodo == nullptr)
    {
        return nullptr;
    }

    if (valor < nodo->data)
    {
        nodo->left = remove(nodo->left, valor);
    }
    else if (valor > nodo->data)
    {
        nodo->right = remove(nodo->right, valor);
    }
    else
    {
        if (nodo->left == nullptr)
        {
            Node* aux = nodo->right;
            delete nodo;
            return aux;
        }
        else if (nodo->right == nullptr)
        {
            Node* aux = nodo->left;
            delete nodo;
            return aux;
        }

        Node* sucesor = findMin(nodo->right);

        nodo->data = sucesor->data;
        nodo->right = remove(nodo->right, sucesor->data);
    }

    return nodo;
}

template<class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::findMin(Node* nodo) const
{
    while (nodo->left != nullptr)
    {
        nodo = nodo->left;
    }

    return nodo;
}

template<class T>
void BinarySearchTree<T>::makeEmpty()
{
    makeEmpty(root);
    root = nullptr;
}

template<class T>
void BinarySearchTree<T>::makeEmpty(Node* nodo)
{
    if (nodo != nullptr)
    {
        makeEmpty(nodo->left);
        makeEmpty(nodo->right);
        delete nodo;
    }
}
