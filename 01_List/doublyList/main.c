#include "doublylist.h"

void display(DoublyList *pList)
{

	if(pList->currentElementCount == 0 )
	{
			printf("빈배열\n");
			return;
	}
		DoublyListNode *pPreNode = 0;

		pPreNode = &(pList->headerNode);
		for (int i = 0 ; i <pList->currentElementCount;i++){
			pPreNode = pPreNode->pRLink ;
			printf("%d ",pPreNode->data);

		}
		printf("\n");
		//printf("headnode data: %d\n",pList->headerNode.data);
}

int main()
{
	DoublyList * doublylist;
	doublylist = createDoublyList();
	printf("doublylist count1 %d\n",doublylist->currentElementCount);

	addDLElement(doublylist,0,1);
	addDLElement(doublylist,1,2);
	addDLElement(doublylist,2,3);
	addDLElement(doublylist,3,4);
	addDLElement(doublylist,4,5);
	addDLElement(doublylist,5,6);

	display(doublylist);

	addDLElement(doublylist,3,10);
	display(doublylist);


	removeDLElement(doublylist,1);
	display(doublylist);
	removeDLElement(doublylist,4);
	display(doublylist);

	printf("get doublylist[1]: %d\n",getDLElement(doublylist,1)->data);
	printf("get doublylist[3]: %d\n",getDLElement(doublylist,3)->data);

	clearDoublyList(doublylist);
	printf("clear ");
	printf("doublylist count %d\n",doublylist->currentElementCount);
	display(doublylist);

	addDLElement(doublylist,1,11);
	display(doublylist);

	addDLElement(doublylist,0,11);
	addDLElement(doublylist,1,2);
	display(doublylist);

	deleteDoublyList(doublylist);
	printf("delete");
	display(doublylist);







}
