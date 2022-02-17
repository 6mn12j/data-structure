#include "circularlist.h"

int			getCircularListLength(CircularList *pList)
{
	return (pList->currentElementCount);
}

void		deleteCircularList(CircularList *pList)
{
	clearCircularList(pList);
	free(pList);
	pList=0;
	return ;
}
void		clearCircularList(CircularList *pList)
{
	if(!pList)
		return ;

	ListNode *pPreNode;
	ListNode *pDelNode;

	pPreNode = pList->headerNode.pLink;
	pDelNode = 0;
	for(int i = 0 ; i <pList->currentElementCount ;i++)
	{
		pDelNode = pPreNode;
		pPreNode = pPreNode->pLink;
		free(pDelNode);
		pDelNode = 0;
	}
	pList->headerNode.pLink = 0;
	pList->currentElementCount=0;

}

ListNode	*getCLElement(CircularList *pList, int position)
{
	ListNode *pPreNode;
	pPreNode = pList->headerNode.pLink;
	if (!pList || position >= pList->currentElementCount)
		return (-1);

	for(int i = 0 ; i < position ; i ++){
		pPreNode = pPreNode->pLink;
	}
	return (pPreNode);
}

int	removeCLElement(CircularList *pList, int position)
{

	if (position < 0 || !pList || pList->currentElementCount<=position)
		return (-1);

	ListNode *pDelNode;
	ListNode *pLastNode;
	ListNode *pPreNode;

	pPreNode = pList->headerNode.pLink;
	pLastNode = pList->headerNode.pLink;


	if (position == 0){
		if(position == pList->currentElementCount - 1){
			pDelNode = pList->headerNode.pLink;
			free(pDelNode);
			pDelNode = 0 ;
			pList->headerNode.pLink = 0;
			pList->currentElementCount--;
		}
		else
		{
			for(int i = 0; i < pList->currentElementCount; i++) //lastNode 까지 이동
				pLastNode = pLastNode->pLink;

			pDelNode = pList->headerNode.pLink;
			pList->headerNode.pLink = pDelNode->pLink;
			free(pDelNode);
			pDelNode = 0;
			pLastNode->pLink = pList->headerNode.pLink;

			pList->currentElementCount--;

		}
	}
	else
	{
		pPreNode = &(pList->headerNode);

		for(int i = 0 ; i < position; i++)
			pPreNode = pPreNode->pLink;
		pDelNode = pPreNode->pLink;
		pPreNode->pLink = pDelNode->pLink;
		free(pDelNode);
		pDelNode = 0;

		pList->currentElementCount--;

	}
	return (1);

}

int	addCLElement(CircularList *pList, int position, int element)
{
	if (!pList || position < 0 || pList->currentElementCount < position)
		return (-1);

	ListNode *pNewNode = 0;
	ListNode *pPreNode = 0;
	ListNode *pLastNode = 0;

	if(!(pNewNode = (ListNode *)malloc(sizeof(ListNode))))
		return (-1);

	pNewNode -> data = element;
	pNewNode -> pLink = 0;
	//1. 첫번째 노드추가이고 공백 리스트일때
	//2. 첫번째 노드추가 이고 공백 리스트가 아닐때

	//3. 첫번째 노드추가가 아닐떄

	if(position == 0){
		if(pList->headerNode.pLink == 0)
		{
			pList->headerNode.pLink = pNewNode;
			pNewNode->pLink = pNewNode;
			pList->currentElementCount++;
			return (0);
		}
		else
		{
			pLastNode = pList->headerNode.pLink;
			for(int i = 0; i < pList->currentElementCount; i++) //lastNode 까지 이동
				pLastNode = pLastNode->pLink;

			pList->headerNode.pLink = pNewNode;
			pPreNode->pLink = pNewNode;
			pLastNode->pLink = pNewNode;

			pList->currentElementCount++;
			return (0);
		}
	}else{
		pPreNode = &(pList->headerNode);
		for (int i = 0 ; i < position; i ++) //position -1 까지 이동
			pPreNode = pPreNode->pLink;
		pNewNode->pLink = pPreNode->pLink;
		pPreNode->pLink = pNewNode;
		pList->currentElementCount ++;

		return (0);
	}


	return (0);
}

CircularList 	*createCircularList()
{
	CircularList *newCircularList = 0;
	if(!(newCircularList = (CircularList*)malloc(sizeof(CircularList))))
	{
		return (0);
	}
	newCircularList->currentElementCount = 0;
	newCircularList->headerNode.pLink = 0;

	return newCircularList;
}
