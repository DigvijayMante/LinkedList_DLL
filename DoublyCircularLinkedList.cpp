#include"DoublyCircularLinkedList.h"

DoublyCircularLinkedList::DoublyCircularLinkedList()
{
    m_pHead = nullptr;
}
DoublyCircularLinkedList::~DoublyCircularLinkedList()
{
    MemoryFree();
}

void DoublyCircularLinkedList::InsertFirst(int _inputData)
{
    struct Node* pNewNode = new struct Node;
    if (pNewNode == nullptr)
    {
        std::cout << "\n Memory Allocation Failed";
        return;
    }

    pNewNode->iData = _inputData;
    if (nullptr == m_pHead)
    {
        pNewNode->pNext = pNewNode;
        pNewNode->pPrev = pNewNode;
        m_pHead = m_pTail = pNewNode;
        return;
    }
    m_pHead->pPrev = pNewNode;
    pNewNode->pNext = m_pHead;
    pNewNode->pPrev = m_pTail;
    m_pHead = pNewNode;
    m_pTail->pNext = pNewNode;

    return;
}
void DoublyCircularLinkedList::InsertLast(int _inputData)
{
    struct Node* pNewNode = new struct Node;
    if (pNewNode == nullptr)
    {
        std::cout << "\n Memory Allocation Failed (DbCiLL InsertLast)";
        return; 
    }
    pNewNode->iData = _inputData;
    if (nullptr == m_pHead)
    {
        pNewNode->pNext = pNewNode;
        pNewNode->pPrev = pNewNode;
        m_pHead = m_pTail = pNewNode;

        return;
    }

    pNewNode->pNext = m_pHead;
    pNewNode->pPrev = m_pTail;
    m_pTail->pNext = pNewNode;
    m_pTail = pNewNode;
    m_pHead->pPrev = pNewNode;

    return;
}
short DoublyCircularLinkedList::ListNodeCount()
{
    short iCounter = 0;
    struct Node* pTemp = nullptr;
    pTemp = m_pHead;

    do
    {
        pTemp = pTemp->pNext;
        ++iCounter;
    } while (pTemp != m_pHead);

    return iCounter;
}
void DoublyCircularLinkedList::InsertAtPosition(int _inputData, int _inputPosition)
{
    short iTotalCount = 0;
    short icounter = 1;
    struct Node* pNewNode = nullptr;
    struct Node* pTemp = nullptr;

    iTotalCount = ListNodeCount();
    if (_inputPosition > (iTotalCount + 2) || _inputPosition < 0)
    {
        std::cout << "\n OOops..!! INVALID positions...";
        return;
    }

    pNewNode = new struct Node;
    if (nullptr == pNewNode)
    {
        std::cout << "\n Memory Allocation Failed in InsertAtPosition" << std::endl;
        return;
    }
    pNewNode->iData = _inputData;

    if (1 == _inputPosition || 0 == _inputPosition)
    {
        InsertFirst(_inputData);
        return;
    }

    if (iTotalCount == _inputPosition || (iTotalCount + 1) == _inputPosition)
    {
        InsertLast(_inputData);
        return;
    }

    pTemp = m_pHead;
    do
    {
        ++icounter;
        pTemp = pTemp->pNext;

    } while ((icounter) < (_inputPosition - 1));

    pNewNode->iData = _inputData;
    pNewNode->pNext = pTemp->pNext->pNext;
    pNewNode->pPrev = pTemp;
    pTemp->pNext->pPrev = pNewNode;
    pTemp->pNext = pNewNode;

    return;

}
void DoublyCircularLinkedList::DisplayList()
{
    struct Node* pTemp = nullptr;
    pTemp = m_pHead;
    std::cout << "\n";
    do
    {
        std::cout << "<-|" << pTemp->pPrev << "|";
        std::cout << pTemp->iData;
        std::cout << "|" << pTemp->pNext << "|->";
        pTemp = pTemp->pNext;
    } while (pTemp != m_pHead);

    return;
}

short DoublyCircularLinkedList::DeleteFirst()
{
    short iDeletedData = 0;
    struct Node* pTemp = m_pHead;
    
    if (m_pHead == m_pTail)
    {
        iDeletedData = m_pTail->iData;
        delete m_pTail;
        m_pHead = m_pTail = nullptr;
        return iDeletedData;
    }

    m_pHead = pTemp->pNext;
    iDeletedData = pTemp->iData;
    m_pHead->pPrev = m_pTail;
    m_pTail->pNext = m_pHead;
    delete pTemp;

    return iDeletedData;
}

short DoublyCircularLinkedList::DeleteLast()
{
    short iDeletedData = 0;

    if (m_pHead == m_pTail)
    {
        iDeletedData = m_pTail->iData;
        delete m_pTail;
        m_pHead = m_pTail = nullptr;
        return iDeletedData;
    }

    iDeletedData = m_pTail->iData;
    m_pTail = m_pTail->pPrev;
    delete m_pTail->pNext;
    m_pTail->pNext = m_pHead;
    m_pHead->pPrev = m_pTail;

    return iDeletedData;

}

short DoublyCircularLinkedList::DeleteAtPosition(int _inputPosition)
{
    short iDeletedData = 0;
    short iCounter = 1;
    struct Node* pTemp = m_pHead;
    short iNodeCount = 0;
    if (nullptr == m_pHead)
    {
        std::cout << "\nOOoops.... Linked List Is Empty Cannnot Delete.....!!";
        return -1;
    }
    iNodeCount = ListNodeCount();

    if (_inputPosition < 0 || _inputPosition >(iNodeCount + 1))
    {
        std::cout << "\nOOoops....!!Invalid Position..";
        return -1;
    }

    if (_inputPosition == 1 || _inputPosition == 0)
    {
        return DeleteFirst();
    }

    if (_inputPosition == (iNodeCount) )
    {
        return DeleteLast();
    }
    
    while (iCounter < _inputPosition-1)
    {
        ++iCounter;
        pTemp = pTemp->pNext;
    }
    
    iDeletedData = pTemp->pNext->iData;
    pTemp->pNext = pTemp->pNext->pNext;
    delete pTemp->pNext->pPrev;
    pTemp->pNext->pPrev = pTemp;

    return iDeletedData;

}
void DoublyCircularLinkedList::PhysicalReverse()
{
    struct Node* pCurr = nullptr, * pPrev = nullptr, * pNext = nullptr;

    if (nullptr == m_pHead)
    {
        std::cout << "\nLinked List is empty";
        return;
    }

    if (m_pHead == m_pTail)
        return;

    pCurr = m_pHead;

    do
    {
        pNext = pCurr->pNext;

        pCurr->pNext = pPrev;

        pPrev = pCurr;
        pCurr = pNext;
        pPrev->pPrev = pCurr;
    } while (pCurr != m_pHead);
    m_pHead = pPrev;
    m_pTail = pCurr;
    m_pTail->pNext = m_pHead;
}

int DoublyCircularLinkedList::SerachFirstOccurance(int _inputData)
{
    if (nullptr == m_pHead)
    {
        std::cout << "\nOOops..!! Linked List is empty";
        return -1;
    }

    struct Node* pTemp = nullptr;
    int iCounter = 0;
    pTemp = m_pHead;

    do
    {
        ++iCounter;
        if (pTemp->iData == _inputData)
        {
            return iCounter;
        }
        pTemp = pTemp->pNext;
    } while (pTemp != m_pHead);
    return -1;
}

int DoublyCircularLinkedList::SerachLastOccurance(int _inputData)
{
    if (nullptr == m_pHead)
    {
        std::cout << "\nOOops..!! Linked List is empty";
        return -1;
    }

    struct Node* pTemp = nullptr;
    int iCounter = 0;
    int iFoundCount = -1;
    pTemp = m_pHead;

    do
    {
        ++iCounter;
        if (pTemp->iData == _inputData)
        {
            iFoundCount = iCounter;
        }
        pTemp = pTemp->pNext;
    } while (pTemp != m_pHead);

    return iFoundCount;
}

int DoublyCircularLinkedList::SerachAllOccurance(int _inputData)
{
    if (nullptr == m_pHead)
    {
        std::cout << "\nOOops..!! Linked List is empty";
        return -1;
    }

    struct Node* pTemp = nullptr;
    int iCounter = 0;
    pTemp = m_pHead;

    do
    {
        if (pTemp->iData == _inputData)
        {
            ++iCounter;
        }
        pTemp = pTemp->pNext;
    } while (pTemp != m_pHead);

    if (nullptr == pTemp && iCounter == 0)
        return -1;
    else
        return iCounter;
}

void DoublyCircularLinkedList::MemoryFree()
{
    if (nullptr == m_pHead)
    {
        std::cout << "\n Linked List Already Empty";
        return;
    }
    struct Node* pTemp = nullptr;

    do
    {
        pTemp = m_pHead;
        m_pHead = m_pHead->pNext;

        delete pTemp;
    } while (m_pHead != m_pTail);
    
    std::cout << "\n*************************************************************";
    std::cout << "\n \033[31m Deleted All Nodes as object going outofscope \033[0m";
    std::cout << "\n*************************************************************";
}