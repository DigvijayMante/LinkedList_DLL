#include"SinglyCircularLinkedList.h"

LinkedList::LinkedList()
{
    m_pHead = nullptr;
    m_pTail = nullptr;
}

LinkedList::~LinkedList()
{
    // MemoryFree();
}

void LinkedList::InsertFirst(int _inputData)
{
    struct Node *pNewNode = nullptr;
    pNewNode = new struct Node;

    if(nullptr == pNewNode )
    {
        std::cout<<"\n Memory Allocation Failed in InsertFirst";
        return;
    }
    
    pNewNode->iData = _inputData;
    if(nullptr == m_pHead)
    {
        m_pHead = pNewNode;
        m_pTail = pNewNode;
        pNewNode->pNext = m_pHead;
        pNewNode = nullptr;
        return;
    }
    else
    {
        pNewNode->pNext = m_pHead;
        m_pHead = pNewNode;
        m_pTail->pNext = pNewNode;
    }

    return ;
}

void LinkedList::InsertLast(int _inputData)
{
    struct Node *pNewNode = nullptr;
    pNewNode = new struct Node;

    if(nullptr == pNewNode )
    {
        std::cout<<"\n Memory Allocation Failed in InsertFirst";
        return;
    }
    
    pNewNode->iData = _inputData;
    if(nullptr == m_pHead)
    {
        m_pHead = pNewNode;
        m_pTail = pNewNode;
        pNewNode->pNext = m_pHead;
        pNewNode = nullptr;
        return;
    }
    else
    {
        m_pTail->pNext = pNewNode;
        pNewNode->pNext = m_pHead;
        m_pTail = pNewNode;
    }

    return ;
}

void LinkedList:: InsertAtPosition(int _inputData, int _inputPosition)
{
    struct Node *pNewNode = nullptr;
    struct Node *pTemp = nullptr;
    short iNodeCount = 0, iCounter = 1;
    
    iNodeCount = GetCountNode();
    if(_inputPosition > (iNodeCount+2) || _inputPosition < 0)
    {
        std::cout<<"\n OOops..!! INVALID positions...(InsertAtPosition)";
        return;
    }

    if(_inputPosition == 1 || _inputPosition == 0)
    {
        InsertFirst(_inputData);
        return ;
    }

    if(_inputPosition == (iNodeCount + 1) || _inputPosition == iNodeCount)
    {
        InsertLast(_inputData);
        return;
    }
    
    pNewNode = new struct Node;
    if(nullptr == pNewNode )
    {
        std::cout<<"\n Memory Allocation Failed in InsertFirst";
        return;
    }
    
    pNewNode->iData = _inputData;
    pTemp = m_pHead;

    while(iCounter < _inputPosition - 1)
    {
        ++iCounter;
        pTemp =pTemp->pNext;
    }
    pNewNode->pNext = pTemp->pNext;
    pTemp->pNext = pNewNode;

    return ;
}

short LinkedList::GetCountNode()
{
    short iCounter = 0;
    struct Node *pTemp = nullptr;
    pTemp = m_pHead;

    if(nullptr == m_pHead)
    {
        std::cout<<"\nLinked List is EMPTY(GetCount)";
        return -1;
    }

    do
    {
        ++iCounter;
        pTemp = pTemp->pNext;
    }while(pTemp != m_pTail->pNext);

    return iCounter;
}

void LinkedList::DisplayList()
{
    struct Node *pTemp = nullptr;
    pTemp = m_pHead;

    if(nullptr == m_pHead)
    {
        std::cout<<"\nOOops..! Linked List is EMPTY(DisplayList)";
        return;
    }

    do
    {
        std::cout<<"|"<<pTemp->iData<<"|->";
        std::cout<<"|"<<pTemp->pNext<<"|->";
        pTemp = pTemp->pNext;
    }while(pTemp != m_pTail->pNext);

    return;
}

short LinkedList::DeleteFirst()
{
    if(nullptr == m_pHead)
    {
        std::cout<<"\n OOops...!! Linked List is EMPTY(DeleteFirst)";
        return -1;
    }

    struct Node *pTemp = nullptr;
    short iData = 0;

    pTemp = m_pHead;
    iData = pTemp ->iData;
    m_pHead = m_pHead->pNext;
    m_pTail->pNext = m_pHead;

    delete pTemp;
    return iData;
}

short LinkedList::DeleteLast()
{
    if(nullptr == m_pHead)
    {
        std::cout<<"\n OOops...!! Linked List is EMPTY (DeleteLast)";
        return -1;
    }
    struct Node *pTemp = nullptr;
    short iData = 0;
    pTemp = m_pHead;

    do
    {
        pTemp = pTemp->pNext;
    }while(pTemp->pNext != m_pTail);

    iData = m_pTail->iData;
    pTemp->pNext = m_pTail->pNext;
    if(m_pHead == m_pTail)
    {
        delete m_pTail;
        m_pHead = nullptr;
        m_pTail = nullptr;
    }
    else 
    {
        delete m_pTail;
        m_pTail = nullptr;
        m_pTail = pTemp;
    }
    
    
    return iData;
}
short LinkedList::DeleteAtPosition(int _inputPosition)
{
    if(nullptr == m_pHead)
    {
        std::cout<<"\n OOops...!! Linked List is EMPTY (DeleteAtPosition)";
        return -1;
    }
    struct Node *pTemp = nullptr;
    struct Node *pTemp2 = nullptr;
    short iData = 0;
    short iCounter = 1;
    short iNodeCount = 0;

    iNodeCount = GetCountNode();
    if(_inputPosition > (iNodeCount+1) || _inputPosition < 0)
    {
        std::cout<<"\nOOops...! INVALID Position(DeleteAtPosittion)";
        return -1;
    }

    if(_inputPosition == 1 || _inputPosition == 0)
    {
        return DeleteFirst();
    }
    if(_inputPosition == (iNodeCount+1) || _inputPosition == iNodeCount )
    {
        return DeleteLast();
    }
  
    pTemp = m_pHead;
    while(iCounter < iNodeCount-1)
    {
        ++iCounter;
        pTemp = pTemp->pNext;
    }
    pTemp2 = pTemp->pNext;

    iData = pTemp2->iData;
    pTemp->pNext = pTemp2->pNext;
    delete pTemp2;
    pTemp2 =nullptr;   
    
    return iData;
}

int LinkedList::SerachFirstOccurance(int _inputData)
{
    if(nullptr == m_pHead)
    {
        std::cout<<"\nOOops..!! Linked List is empty(SearchFirstOccurance)";
        return -1;
    }

    struct Node *pTemp = nullptr;
    int iCounter = 0;
    pTemp = m_pHead;

    do
    {
        ++iCounter;
        if(pTemp->iData == _inputData)
        {
            return iCounter;
        }
        pTemp = pTemp->pNext;
    }while(pTemp != m_pTail);
    return -1;
}

int LinkedList::SerachLastOccurance(int _inputData)
{
    if(nullptr == m_pHead)
    {
        std::cout<<"\nOOops..!! Linked List is empty(SearchLastOccurance)";
        return -1;
    }

    struct Node *pTemp = nullptr;
    int iCounter = 0;
    int iFoundCount = -1;
    pTemp = m_pHead;

    while(pTemp != m_pTail)
    {
        ++iCounter;
        if(pTemp->iData == _inputData)
        {
            iFoundCount = iCounter;
        }
        pTemp = pTemp->pNext;
    }

    return iFoundCount;
}

int LinkedList::SerachAllOccurance(int _inputData)
{
    if(nullptr == m_pHead)
    {
        std::cout<<"\nOOops..!! Linked List is empty(SearchAllOccurance)";
        return -1;
    }

    struct Node *pTemp = nullptr;
    int iCounter = 0;
    pTemp = m_pHead;

    while(pTemp != m_pTail)
    {
        if(pTemp->iData == _inputData)
        {
            ++iCounter;
        }
        pTemp = pTemp->pNext;
    }

    if(nullptr == pTemp && iCounter == 0)
        return -1;
    else
        return iCounter;
}

void LinkedList::PhysicalReverse()
{
    struct Node *pCurr = nullptr,*pPrev = nullptr,*pNext = nullptr;

    if(nullptr == m_pHead)
    {
        std::cout<<"\nLinked List is empty(PhysicalReverse)";
        return;
    }
    pCurr = m_pHead;

    do
    {
        pNext = pCurr->pNext;

        pCurr->pNext = pPrev;

        pPrev = pCurr;
        pCurr = pNext;
    }while(pCurr != m_pHead);
    m_pHead =pPrev;
    m_pTail= pNext;
    pNext->pNext = m_pHead;
}