#include "linkedlist.h"
 void iterateLinkedList(LinkedList* pList)
 {
	if(pList->headerNode.pLink == NULL)
	 	return ;
	ListNode* pNode = NULL;
	int count = 0;
	if (pList != NULL) {
		pNode = pList->headerNode.pLink;
		while(pNode != NULL) {
			printf("[%d],%d\n", count, pNode->data);
			count++;

			pNode = pNode->pLink;
			}
		printf("노드 개수: %d\n", count);
 	}
 	else
	{
 	printf("공백 리스트입니다");
 	}
 }

	int	main(void)
{

	LinkedList *myLinkedList;
	LinkedList *myLinkedList2;

	myLinkedList = createLinkedList();
	printf("create\n");
	addLLElement(myLinkedList,0,1);
	addLLElement(myLinkedList,1,2);
	addLLElement(myLinkedList,2,3);
	addLLElement(myLinkedList,3,4);
	iterateLinkedList(myLinkedList);

	addLLElement(myLinkedList,2,10);
	iterateLinkedList(myLinkedList);

	clearLinkedList(myLinkedList );
	printf("clear\n");
	printf("이거 %d\n",myLinkedList->currentElementCount);


	//deleteLinkedList(myLinkedList);
	//iterateLinkedList(myLinkedList);


	// myLinkedList2 = createLinkedList();
	// addLLElement(myLinkedList2 ,0,1);
	// addLLElement(myLinkedList2 ,1,2);

	// clearLinkedList(myLinkedList2 );
	// printf("clear 노드갯수 : %d\n",myLinkedList2 ->currentElementCount);

	// iterateLinkedList(myLinkedList2 );



	return (0);

}
