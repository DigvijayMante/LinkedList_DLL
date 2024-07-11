#include<iostream>
#pragma once

struct Node
{
    int iData;
    struct Node *pNext;

    Node()
    {
        iData = 0;
        pNext = nullptr;
    }
    ~Node()
    {
         
    }
};

class LinkedList
{

public:
    struct Node *m_pHead;
    struct Node *m_pTail;
    
    LinkedList();
    ~LinkedList();

    void InsertFirst(int _inputData);
    void InsertLast(int _inputData);
    void InsertAtPosition(int _inputData, int _inputPosition);
    
    void  DisplayList();
    short GetCountNode();

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
