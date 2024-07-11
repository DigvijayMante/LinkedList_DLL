// #include"Singly_linked_list.h"
//#include"SinglyCircularLinkedList.h"
 #include"DoublyLinkedList.h"

int main(void)
{
    int iPositon = 0;
    short iDelData = 0;
    // Linked_list objLinked_list;
//    LinkedList objDoublyLinkedList;
    DoublyLinkedList objDoublyLinkedList;

    for(int iCounter = 10 ; iCounter <= 70 ; iCounter += 10)
    {
        objDoublyLinkedList.InsertFirst(iCounter);
    }
    
    objDoublyLinkedList.DisplayList();
    objDoublyLinkedList.InsertAtPosition(55,0);
    std::cout<<"\n\n"; 
    objDoublyLinkedList.DisplayList();


    objDoublyLinkedList.DeleteFirst();
    std::cout << "\n\n";
    objDoublyLinkedList.DisplayList();

    iDelData = objDoublyLinkedList.DeleteAtPosition(3);
    std::cout<<"\n Deleted Data is "<<iDelData;
    std::cout<<"\n\n";
    objDoublyLinkedList.DisplayList();

    iPositon = objDoublyLinkedList.SerachFirstOccurance(20);
    std::cout<<"\n Positon is "<<iPositon;

    objDoublyLinkedList.PhysicalReverse();
    std::cout<<"\n\n";
    objDoublyLinkedList.DisplayList();
    iPositon = objDoublyLinkedList.SerachLastOccurance(0);
    std::cout<<"\n Positon is "<<iPositon;

    iPositon = objDoublyLinkedList.SerachAllOccurance(50);
    std::cout<<"\n Total Found Count is  "<<iPositon;
    
    std::cout<<"\n Total Linked list Count is "<< objDoublyLinkedList.ListNodeCount();

    return 0;
}