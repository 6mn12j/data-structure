#include "doublylist.h"

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
	DoublyListNode *pPreNode;
	pPreNode = &(pList->headerNode);
	for(int i =0 ; i<=position ;i ++)
		pPreNode = pPreNode->pRLink;
	return pPreNode;
}

int getDoublyListLength(DoublyList* pList)
{
	return pList->currentElementCount;
}

void deleteDoublyList(DoublyList* pList)
{
	clearDoublyList(pList);
	free(pList);
	pList = 0;
	return ;
}

void clearDoublyList(DoublyList* pList)
{
	if(!pList)
		return ;
	DoublyListNode *pDelNode;
	DoublyListNode *pPreNode;

	pPreNode = pList->headerNode.pLLink;
	for(int i = 0 ; i < pList->currentElementCount; i++)
	{
		pDelNode = pPreNode;
		pPreNode = pPreNode->pLLink;
		free(pDelNode);
		pDelNode=0;
	}
	pList->headerNode.pRLink = &pList->headerNode;
	pList->headerNode.pLLink = &pList->headerNode;
	pList->currentElementCount = 0;

	return ;
}

int removeDLElement(DoublyList* pList, int position)
{
	if(!pList || position < 0 || pList->currentElementCount < position)
		return (-1);
	DoublyListNode *pPreNode;
	DoublyListNode *pDelNode;

	pPreNode= &(pList->headerNode);

	for(int i = 0; i < position; i++)
		pPreNode = pPreNode->pRLink;
	pDelNode = pPreNode->pRLink;
	pPreNode->pRLink = pDelNode->pRLink;
	pPreNode->pRLink->pLLink = pPreNode;
	//pDelNode->pLLink = pPreNode;

	free(pDelNode);
	pDelNode = 0;
	pList -> currentElementCount--;
	return (1);
}

int addDLElement(DoublyList* pList, int position, int element)
{
	if(!pList || position < 0 || pList->currentElementCount < position)
		return (-1);

	DoublyListNode *pNewNode;
	DoublyListNode *pPreNode;

	if(!(pNewNode = (DoublyListNode*)malloc(sizeof(DoublyListNode))))
		return (-1);
	// if(!(pPreNode = (DoublyListNode*)malloc(sizeof(DoublyListNode))))
	// 	return (-1);

	pPreNode = &(pList->headerNode);
	pNewNode->data = element;


	for (int i = 0 ; i < position ; i ++)
		pPreNode = pPreNode->pRLink;
	pNewNode->pLLink = pPreNode;
	pNewNode->pRLink = pPreNode->pRLink;
	pPreNode->pRLink = pNewNode;
	pNewNode->pRLink->pLLink = pNewNode;


	pList->currentElementCount++;
	return (0);
}

DoublyList* createDoublyList()
{
	DoublyList *doublyList;
	if(!(doublyList = (DoublyList*)malloc(sizeof(DoublyList))))
		return (0);

	doublyList->headerNode.pRLink = &doublyList->headerNode;
	doublyList->headerNode.pLLink = &doublyList->headerNode;
	doublyList->currentElementCount = 0 ;

	return doublyList;

}
