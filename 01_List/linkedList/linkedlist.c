#include "linkedlist.h"

void deleteLinkedList(LinkedList* pList)
{
	clearLinkedList(pList);
	free(pList);
	pList=0;
	pList->currentElementCount=0;
	return ;
}

void clearLinkedList(LinkedList* pList)
{
	if(pList == NULL)
		return ;

	ListNode *pDelNode;
	ListNode *pTempNode;

	pTempNode = pList->headerNode.pLink;
	pDelNode = 0;

	while (pTempNode)
	{
		pDelNode = pTempNode;
		pTempNode = pTempNode->pLink;
		free(pDelNode);
		// pDelNode->data = 0;
		// pDelNode->pLink = 0;
		pDelNode = 0;

	}
	pList->headerNode.pLink = NULL;
	pList->currentElementCount=0;
	return ;

}

int getLinkedListLength(LinkedList* pList)
{
	return pList->currentElementCount ;
}

int getLLElement(LinkedList* pList, int position)
{

	if (position < 0 || position >= pList->currentElementCount)
		return (-1);
	ListNode *pPreNode = 0;

	pPreNode = &(pList ->headerNode);
	for (int i = 0 ; i <= position; i++)
		pPreNode = pPreNode -> pLink;
	return (pPreNode->data);
}

int removeLLElement(LinkedList* pList, int position)
{
	if (position < 0 || position >= pList->currentElementCount)
		return (-1);

	ListNode *pDelNode = 0;
	ListNode *pPreNode = 0;

	pPreNode = &(pList->headerNode);
	for (int i = 0 ; i < position ; i ++)
		pPreNode = pPreNode->pLink;
	pDelNode = pPreNode->pLink;
	pPreNode-> pLink = pDelNode->pLink;
	free(pPreNode);
	pPreNode = 0;

	pList->currentElementCount--;
	return (1);
}

int addLLElement(LinkedList* pList, int position, int element)
{
	if (position < 0 || position > pList->currentElementCount)
		return (-1);

	ListNode *pNewNode = 0;
	ListNode *pPreNode = 0;

	//TODO: NULL가드
	pNewNode = (ListNode *)malloc(sizeof(ListNode));
	pNewNode->data = element;

	pPreNode = &(pList->headerNode); //탐색을 위한 더미노드 ?
	for (int i = 0 ; i < position ; i++) //position -1 	까지
		pPreNode = pPreNode->pLink;

	//1.새로운 노드의 링크가 가리키는 곳을 현재 이동시킨 커서, position-1가 가리키는 곳으로.
	//2.이동한 노드가 새로운 노드를 가리키게.

	pNewNode->pLink = pPreNode->pLink;
	pPreNode->pLink = pNewNode;
	pList->currentElementCount ++;

	return (1);
}

LinkedList* createLinkedList()
{
	LinkedList *newLinkedList = 0;
	if (!(newLinkedList = (LinkedList *)malloc(sizeof(LinkedList))))
		return (0);

	//LinkedList 만들면 headerNode가 이미 만들어져서 여기 x.
	//*(ListNode *)malloc(sizeof(ListNode)); * 값으로 받아오면 free 할때 xx 값만 저장함.
	//newLinkedList -> headerNode = *(ListNode *)malloc(sizeof(ListNode));

	newLinkedList -> currentElementCount = 0;
	newLinkedList -> headerNode.pLink = NULL;
	return newLinkedList;

}
