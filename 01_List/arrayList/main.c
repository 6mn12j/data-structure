#include "arraylist.h"

	int	main(void)
{

	static ArrayList *myList;

	myList = createArrayList(6);
	printf("%d %d %d\n",myList->maxElementCount,myList->currentElementCount,myList->pElement[0].data);
	addALElement(myList, 0, 1);
	printf("%d %d %d %d %d %d\n",myList->pElement[0].data,myList->pElement[1].data,myList->pElement[2].data,myList->pElement[3].data,myList->pElement[4].data, myList->pElement[5].data);

	addALElement(myList, 1, 2);
	printf("%d %d %d %d %d %d\n",myList->pElement[0].data,myList->pElement[1].data,myList->pElement[2].data,myList->pElement[3].data,myList->pElement[4].data, myList->pElement[5].data);
	printf("getArrayListLength");
	printf("%d\n",getArrayListLength(myList));

	addALElement(myList, 2, 3);
	printf("%d %d %d %d %d %d\n",myList->pElement[0].data,myList->pElement[1].data,myList->pElement[2].data,myList->pElement[3].data,myList->pElement[4].data, myList->pElement[5].data);

	addALElement(myList, 3, 4);
	printf("%d %d %d %d %d %d\n",myList->pElement[0].data,myList->pElement[1].data,myList->pElement[2].data,myList->pElement[3].data,myList->pElement[4].data, myList->pElement[5].data);

	addALElement(myList, 4, 5);
	printf("%d %d %d %d %d %d\n",myList->pElement[0].data,myList->pElement[1].data,myList->pElement[2].data,myList->pElement[3].data,myList->pElement[4].data, myList->pElement[5].data);

	addALElement(myList, 5, 6);
	printf("%d %d %d %d %d %d\n",myList->pElement[0].data,myList->pElement[1].data,myList->pElement[2].data,myList->pElement[3].data,myList->pElement[4].data, myList->pElement[5].data);
	printf("true %d\n",isArrayListFull(myList));
	printf("getArrayListLength");
	printf("%d\n",getArrayListLength(myList));

	addALElement(myList, 1, 10);
	printf("%d %d %d %d %d %d\n",myList->pElement[0].data,myList->pElement[1].data,myList->pElement[2].data,myList->pElement[3].data,myList->pElement[4].data, myList->pElement[5].data);
	removeALElement(myList,2);
	printf("%d %d %d %d %d %d\n",myList->pElement[0].data,myList->pElement[1].data,myList->pElement[2].data,myList->pElement[3].data,myList->pElement[4].data, myList->pElement[5].data);
	printf("false %d\n",isArrayListFull(myList));

	printf("getElement ");
	printf("%d\n",getALElement(myList,2));

	printf("displayArrayList ");
	displayArrayList(myList);

	printf("clearArrayList ");
	clearArrayList(myList);
	displayArrayList(myList);

	printf("getArrayListLength");
	printf("%d\n",getArrayListLength(myList));



	return (0);

}
