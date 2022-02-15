#include "arraylist.h"


int getArrayListLength(ArrayList* pList)
{
	if(pList == NULL)
		return (-1); // 0 인가

	return pList->currentElementCount;
}

void clearArrayList(ArrayList* pList)
{
	if(pList == NULL)
		return ;

	memset(pList ->pElement, 0, sizeof(ArrayListNode) * pList->maxElementCount);
	pList->currentElementCount = 0;
	return ;

}

void displayArrayList(ArrayList* pList)
{
	if(pList == NULL)
		return ;
	for(int i = 0 ;i <pList->maxElementCount; i++)
	{
		printf("%d",pList->pElement[i].data);
	}
	printf("\n");
	return ;
}

int getALElement(ArrayList* pList, int position)
{
	return pList->pElement[position].data;
}

int isArrayListFull(ArrayList* pList)
{
	if(pList == NULL)
		return -1; //error

	if(pList->currentElementCount == pList->maxElementCount)
		return TRUE;
	else
		return FALSE;

}

int removeALElement(ArrayList* pList, int position)
{
	if(pList == NULL ||pList->currentElementCount < position)
		return (-1);
	while(position < pList->currentElementCount)
	{
		pList->pElement[position] = pList->pElement[position + 1];
		position ++;
	}
	pList->currentElementCount--;
	return (0);
}

int addALElement(ArrayList* pList, int position, int element)
{
	int currentIndex = pList->currentElementCount;


	//가장 오른쪽 원소 값에서 시작 해서 -1 하면서 추가하려는 위치까지 이동.

	//추가 못하는 경우
	//넣으려는 값이 (position) max 값보다 클때
	//이미 배열이 꽉 차 있을때

	if(	pList == NULL ||
		position > pList->maxElementCount - 1 ||
		pList->currentElementCount == pList->maxElementCount
		)
		return (-1);

	while( currentIndex != 0 && position != currentIndex )
	{
		pList->pElement[currentIndex].data = pList->pElement[currentIndex - 1].data;
		currentIndex--;
	}

	pList->pElement[currentIndex].data = element;
	pList->currentElementCount++;
	return(0);
}

ArrayList* createArrayList(int maxElementCount)
{

	//ArrayList.pElemnt에 ArrayListNode타입사이즈 * maxElementCount만큼의 메모리를 할당해라
 	ArrayList *newArray;
	  if (!(newArray = (ArrayList *)malloc(sizeof(ArrayList))))
		return NULL;
	newArray -> maxElementCount = maxElementCount;
	newArray -> currentElementCount = 0;
	newArray -> pElement=(ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
	return newArray;
}
