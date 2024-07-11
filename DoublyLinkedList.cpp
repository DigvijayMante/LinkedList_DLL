#include"DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
{
    m_pHead = nullptr;
}
DoublyLinkedList::~DoublyLinkedList()
{

}

void DoublyLinkedList::InsertFirst(int _inputData)
{
    struct Node *pNewNode = new struct Node;
    if (pNewNode == nullptr)
    {
        std::cout << "\n Memory Allocation Failed";
        return;
    }

    pNewNode->iData = _inputData;
    if(nullptr == m_pHead)
    {
        pNewNode->pNext = nullptr;
        pNewNode->pPrev = nullptr;
        m_pHead = pNewNode;
        return;
    }
    m_pHead->pPrev  = pNewNode;
    pNewNode->pNext = m_pHead;
    pNewNode->pPrev = nullptr;
    m_pHead = pNewNode;

    return;
}
void DoublyLinkedList::InsertLast(int _inputData)
{
    struct Node *pTemp    = nullptr;
    struct Node* pNewNode = new struct Node;
    
    pNewNode->iData = _inputData;
    if(nullptr == m_pHead)
    {
        pNewNode->pNext = nullptr;
        pNewNode->pPrev = nullptr;
        m_pHead  = pNewNode;
        return;
    }

    pTemp = m_pHead;
    while(pTemp->pNext)
        pTemp = pTemp->pNext;
    
    pTemp->pNext = pNewNode;
    pNewNode->pNext = nullptr;
    pNewNode->pPrev = pTemp;

    return;
}
short DoublyLinkedList::ListNodeCount()
{
    short iCounter = 0;
    struct Node *pTemp =nullptr;
    pTemp = m_pHead;

    while(pTemp)
    {
        pTemp = pTemp->pNext;
        ++iCounter;
    }

    return iCounter;
}
void DoublyLinkedList::InsertAtPosition(int _inputData, int _inputPosition)
{
    short iTotalCount = 0;
    short icounter = 1;
    struct Node *pNewNode = nullptr;
    struct Node *pTemp = nullptr;

    iTotalCount = ListNodeCount();
    if(_inputPosition > (iTotalCount+2) || _inputPosition < 0)
    {
        std::cout<<"\n OOops..!! INVALID positions...";
        return;
    }

    pNewNode = new struct Node;
    if(nullptr == pNewNode)
    {
        std::cout<<"\n Memory Allocation Failed in InsertAtPosition"<<std::endl;
        return;
    }
    pNewNode->iData = _inputData;

    if(1 ==_inputPosition || 0 == _inputPosition)
    {
        InsertFirst(_inputData);
        return;
    }
    
    if(iTotalCount == _inputPosition || (iTotalCount+1) == _inputPosition)
    {
        InsertLast(_inputData);
        return;
    }

    pTemp = m_pHead;
    do
    {
        ++icounter;
        pTemp = pTemp->pNext;

    }while((icounter) < (_inputPosition-1));

    pNewNode->iData = _inputData;
    pNewNode->pNext = pTemp->pNext->pNext;
    pNewNode->pPrev = pTemp;
    pTemp->pNext->pPrev = pNewNode;
    pTemp->pNext = pNewNode;

    return;

}
void DoublyLinkedList::DisplayList()
{
    struct Node *pTemp =nullptr;
    pTemp = m_pHead;
    std::cout<<"\n";
    while(pTemp)
    {
        std::cout << "<-|" << pTemp->pPrev << "|";
        std::cout<<pTemp->iData;
        std::cout<<"|"<<pTemp->pNext<<"|->";
        pTemp = pTemp->pNext;
    }
    
    return;
}

short DoublyLinkedList::DeleteFirst()
{
    short iDeletedData = 0;
    struct Node *pTemp = m_pHead;
    
    m_pHead = pTemp->pNext;
    iDeletedData = pTemp->iData;
    m_pHead->pPrev = nullptr;

    delete pTemp;
    
    return iDeletedData;
    
}

short DoublyLinkedList::DeleteLast()
{
    short iDeletedData = 0;
    struct Node* pTemp = m_pHead;

    while (pTemp->pNext)
        pTemp = pTemp->pNext;

    iDeletedData = pTemp->iData;
    pTemp->pPrev->pNext = nullptr;
    
    delete pTemp;

    return iDeletedData;

}

short DoublyLinkedList::DeleteAtPosition(int _inputPosition)
{
    short iDeletedData = 0;
    struct Node* pTemp = m_pHead;

    while (pTemp->pNext)
        pTemp = pTemp->pNext;

    iDeletedData = pTemp->iData;
    pTemp->pPrev->pNext = nullptr;

    delete pTemp;

    return iDeletedData;

}
void DoublyLinkedList::PhysicalReverse()
{
    struct Node *pCurr=nullptr,*pPrev = nullptr,*pNext =nullptr;

    if(nullptr == m_pHead)
    {
        std::cout<<"\nLinked List is empty";
        return; 
    }
    pCurr = m_pHead;

    while(pCurr != nullptr)
    {
        pNext = pCurr->pNext;

        pCurr->pNext = pPrev;

        pPrev = pCurr;
        pCurr = pNext;
    }
    m_pHead =pPrev;
}

int DoublyLinkedList::SerachFirstOccurance(int _inputData)
{
    if(nullptr == m_pHead)
    {
        std::cout<<"\nOOops..!! Linked List is empty";
        return -1;
    }

    struct Node *pTemp = nullptr;
    int iCounter = 0;
    pTemp = m_pHead;

    while(pTemp)
    {
        ++iCounter;
        if(pTemp->iData == _inputData)
        {
            return iCounter;
        }
        pTemp = pTemp->pNext;
    }
    return -1;
}

int DoublyLinkedList::SerachLastOccurance(int _inputData)
{
    if(nullptr == m_pHead)
    {
        std::cout<<"\nOOops..!! Linked List is empty";
        return -1;
    }

    struct Node *pTemp = nullptr;
    int iCounter = 0;
    int iFoundCount = -1;
    pTemp = m_pHead;

    while(pTemp)
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

int DoublyLinkedList::SerachAllOccurance(int _inputData)
{
    if(nullptr == m_pHead)
    {
        std::cout<<"\nOOops..!! Linked List is empty";
        return -1;
    }

    struct Node *pTemp = nullptr;
    int iCounter = 0;
    pTemp = m_pHead;

    while(pTemp)
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

 void DoublyLinkedList::MemoryFree()
 {
    if(nullptr == m_pHead)
    {
        std::cout<<"\n Linked List Already Empty";
        return ;
    }
    struct Node * pTemp = nullptr;

    while(m_pHead)
    {
        pTemp = m_pHead;
        m_pHead = m_pHead->pNext;

        delete pTemp;
    }
 }