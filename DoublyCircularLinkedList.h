#pragma once
#include<iostream>

struct Node
{
    struct Node* pPrev;
    int iData;
    struct Node* pNext;

    Node()
    {
        iData = 0;
        pPrev = pNext = nullptr;
    }
};

class DoublyCircularLinkedList
{

public:
    struct Node* m_pHead;
    struct Node* m_pTail;

    DoublyCircularLinkedList();
    ~DoublyCircularLinkedList();

    void InsertFirst(int _inputData);
    void InsertLast(int _inputData);
    void InsertAtPosition(int _inputData, int _inputPosition);

    void  DisplayList();
    short ListNodeCount();

    short DeleteFirst();
    short DeleteLast();
    short DeleteAtPosition(int _inputPosition);

    void PhysicalReverse();
    void DisplayReverseList();

    int SerachFirstOccurance(int _inputData);
    int SerachLastOccurance(int _inputData);
    int SerachAllOccurance(int _inputData);

    void MemoryFree();
};
