#include "circularlist.h"

void display(CircularList *pList)
{
	if(pList->currentElementCount ==0)
		return ;

		ListNode *pPreNode = 0;
		pPreNode = &(pList->headerNode);
		for (int i = 0 ; i <pList->currentElementCount;i++){
						pPreNode = pPreNode->pLink ;

			printf("%d ",pPreNode->data);
		}
		printf("\n");
		//printf("headnode data: %d\n",pList->headerNode.data);
}

int main()
{
	CircularList *circularList;
	circularList = createCircularList();
	printf("create current count: %d\n",circularList->currentElementCount);
	addCLElement(circularList,0,10);

	addCLElement(circularList,1,20);
	addCLElement(circularList,2,30);
	addCLElement(circularList,3,40);
	addCLElement(circularList,4,50);
	display(circularList);
	addCLElement(circularList,2,100);
	display(circularList);

	removeCLElement(circularList, 1);
	display(circularList);

	removeCLElement(circularList, 0);
	display(circularList);

	removeCLElement(circularList, 3);
	display(circularList);

	printf("get 2 :%d\n",getCLElement(circularList,2));
	display(circularList);
	printf("lenght : %d\n",getCircularListLength(circularList));

	clearCircularList(circularList);
	printf("clear\n");
	addCLElement(circularList,1,1);
	display(circularList);
	addCLElement(circularList,0,1);
	addCLElement(circularList,1,2);

	display(circularList);

	deleteCircularList(circularList);
	printf("delete\n");



}
