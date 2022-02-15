#ifndef _ARRAYLIST_
#define _ARRAYLIST_


#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
typedef struct ArrayListNodeType
{
	int data;
} ArrayListNode;

typedef struct ArrayListType
{
	int maxElementCount;		// 최대 원소 갯수
	int currentElementCount;	// 현재 원소 갯수
	ArrayListNode *pElement;	// 원소 저장을 위한 배열 포인터
} ArrayList;

ArrayList* createArrayList(int maxElementCount);
void deleteArrayList(ArrayList* pList);
int isArrayListFull(ArrayList* pList);
//int addALElement(ArrayList* pList, int position, ArrayListNode element);
int addALElement(ArrayList* pList, int position, int element);
int removeALElement(ArrayList* pList, int position);
int getALElement(ArrayList* pList, int position);
void displayArrayList(ArrayList* pList);
void clearArrayList(ArrayList* pList);
int getArrayListLength(ArrayList* pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
