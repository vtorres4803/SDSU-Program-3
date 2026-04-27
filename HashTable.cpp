#include "HashTable.h"
#include "LinkedList.h"

using namespace LinkedListNS;

template<class T>
HashTable<T>::HashTable(int size)
{
    tableSize = size;

    tabla = new Node<T>*[tableSize];

    for (int i = 0; i < tableSize; i++)
    {
        tabla[i] = nullptr;
    }
}

template<class T>
HashTable<T>::~HashTable()
{
    for (int i = 0; i < tableSize; i++)
    {
        while (tabla[i] != nullptr)
        {
            deleteFirstNode(tabla[i]);
        }
    }

    delete[] tabla;
}

template<class T>
int HashTable<T>::hashFunction(const T& key) const
{
    return key % tableSize;
}

template<class T>
void HashTable<T>::insert(const T& key)
{
    int indice = hashFunction(key);

    headInsert(tabla[indice], key);
}

template<class T>
bool HashTable<T>::search(const T& key) const
{
    int indice = hashFunction(key);

    Node<T>* encontrado = LinkedListNS::search(tabla[indice], key);

    return encontrado != nullptr;
}

template<class T>
void HashTable<T>::remove(const T& key)
{
    int indice = hashFunction(key);

    Node<T>* actual = tabla[indice];

    if (actual == nullptr)
    {
        return;
    }

    if (actual->getData() == key)
    {
        deleteFirstNode(tabla[indice]);
        return;
    }

    while (actual->getLink() != nullptr)
    {
        if (actual->getLink()->getData() == key)
        {
            deleteNode(actual);
            return;
        }

        actual = actual->getLink();
    }
}
