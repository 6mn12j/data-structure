#ifndef _CircularList_
# define _CircularList_

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNodeType
{
	int data;
	struct ListNodeType *pLink;
} ListNode;

typedef struct CircularListType
{
	int currentElementCount;	// 현재 저장된 원소의 개수
	ListNode headerNode;		// 헤더 노드(Header Node)
} CircularList;

CircularList 	*createCircularList();
//int			addCLElement(CircularList *pList, int position, ListNode element);
int			addCLElement(CircularList *pList, int position, int element);

int			removeCLElement(CircularList *pList, int position);
//ListNode	*getCLElement(CircularList *pList, int position);
int	getCLElement(CircularList *pList, int position);

void		clearCircularList(CircularList *pList);
int			getCircularListLength(CircularList *pList);
void		deleteCircularList(CircularList *pList);
#endif

#ifndef _COMMON_LIST_DEF_
# define _COMMON_LIST_DEF_

# define TRUE		1
# define FALSE		0

#endif
