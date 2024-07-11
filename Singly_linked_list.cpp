#include"Singly_linked_list.h"

Linked_list::Linked_list()
{
    m_pHead = nullptr;
}
Linked_list::~Linked_list()
{

}

void Linked_list::InsertFirst(int _inputData)
{
    struct Node *pNewNode = nullptr;
    pNewNode = new struct Node;

    pNewNode->iData = _inputData;
    if(nullptr == m_pHead)
    {
        pNewNode->pNext = nullptr;
        m_pHead = pNewNode;
        return;
    }
    pNewNode->pNext = m_pHead;
    m_pHead = pNewNode;

    if(pNewNode)
    {
        pNewNode = nullptr;
    }
    return;
}
void Linked_list::InsertLast(int _inputData)
{
    struct Node *pNewNode = nullptr;
    struct Node *pTemp    = nullptr;
    pNewNode = new struct Node;
    
    pNewNode->iData = _inputData;
    if(nullptr == m_pHead)
    {
        pNewNode->pNext = nullptr;
        m_pHead  = pNewNode;
        pNewNode = nullptr;
        return;
    }

    pTemp = m_pHead;
    while(pTemp->pNext)
        pTemp = pTemp->pNext;
    
    pTemp->pNext = pNewNode;
    pNewNode->pNext = nullptr;

    pNewNode = nullptr;
    pTemp = nullptr;
    return;
}
short Linked_list::ListNodeCount()
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
void Linked_list::InsertAtPosition(int _inputData, int _inputPosition)
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
        std::cout<<"\n Memoey Allocation Failed in InsertAtPosition"<<std::endl;
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

    }while((icounter) < _inputPosition -1);

    pNewNode->iData = _inputData;
    pNewNode->pNext = pTemp->pNext->pNext;
    pTemp->pNext = pNewNode;

    return;

}
void Linked_list::DisplayList()
{
    struct Node *pTemp =nullptr;
    pTemp = m_pHead;
    std::cout<<"\n";
    while(pTemp)
    {
        std::cout<<"|"<<pTemp->iData<<"|->";
        std::cout<<"|"<<pTemp->pNext<<"|->";
        pTemp = pTemp->pNext;
    }
    
    return;
}

short Linked_list::DeleteFirst()
{
    short iDeletedData = 0;
    (void)iDeletedData;
    struct Node *pTemp = nullptr;

    pTemp = m_pHead;
    m_pHead = pTemp->pNext;
    iDeletedData = pTemp->iData;

    delete pTemp;
    
    return iDeletedData;
    
}

short Linked_list::DeleteLast()
{
    short iDeletedData = 0;
    struct Node* pTemp = m_pHead;
    
    if (ListNodeCount() == 1)
    {
        iDeletedData = pTemp->iData;
        delete pTemp;
        return iDeletedData;
    }
    while (pTemp->pNext->pNext)
        pTemp = pTemp->pNext;

    iDeletedData = pTemp->pNext->iData;
    delete pTemp->pNext;
    pTemp->pNext = nullptr;

    return iDeletedData;

}

void Linked_list::PhysicalReverse()
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

int Linked_list::SerachFirstOccurance(int _inputData)
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

int Linked_list::SerachLastOccurance(int _inputData)
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

int Linked_list::SerachAllOccurance(int _inputData)
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

 void Linked_list::MemoryFree()
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