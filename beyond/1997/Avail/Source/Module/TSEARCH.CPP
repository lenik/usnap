#include <_Null.h>
#include "TopType.h"

#define SO_BackSort	1
#define SO_CaseSens	2

/*
char LinearSortBubble(
	void *(*GetData)(Word RecNo, Word *Len),
	int (*Sort2)(void **DataA, void **DataB)
) {
  Word RecNo;
  return 1;
}
*/

#include <string.h>
char StringSortBubble(char **StringArray, Word Num, Byte Option) {
  Word Limit=Num-1;
  Word Switch=0;
  do {
    Switch=0;
    Word Row=0;
    for (; Row<Limit; Row++) {
      if (((Option&SO_CaseSens)?strcmp(StringArray[Row], StringArray[Row+1]):stricmp(StringArray[Row], StringArray[Row+1]))>0) {
	char *Temp;
	Temp=StringArray[Row];
	StringArray[Row]=StringArray[Row+1];
	StringArray[Row+1]=Temp;
	Switch=Row;
      }
    }
    Limit=Switch;
  } while(Switch);
  return 1;
}

/*
#include <stdio.h>
void main() {
  char *sa[]={
    "Pear", "Apple", "orange", "Tree"
  };
  StringSortBubble(sa, 4, SO_BackSort|SO_CaseSens);
  for (int k=0; k<4; k++)
    printf("No.%d\t%s\n", k, sa[k]);
}
*/








/*
' ============================= ExchangeSort =================================
'   The ExchangeSort compares each element in SortArray - starting with
'   the first element - with every following element.  If any of the
'   following elements is smaller than the current element, it is exchanged
'   with the current element and the process is repeated for the next
'   element in SortArray.
' ============================================================================
'
SUB ExchangeSort STATIC
   FOR Row = 1 TO MaxRow
      SmallestRow = Row
      FOR J = Row + 1 TO MaxRow
	 IF SortArray(J).Length < SortArray(SmallestRow).Length THEN
            SmallestRow = J
            ElapsedTime J
         END IF
      NEXT J

      ' Found a row shorter than the current row, so swap those
      ' two array elements:
      IF SmallestRow > Row THEN
         SWAP SortArray(Row), SortArray(SmallestRow)
         SwapBars Row, SmallestRow
      END IF
   NEXT Row
END SUB

' =============================== HeapSort ===================================
'  The HeapSort procedure works by calling two other procedures - PercolateUp
'  and PercolateDown.  PercolateUp turns SortArray into a "heap," which has
'  the properties outlined in the diagram below:
'
'                               SortArray(1)
'                               /          \
'                    SortArray(2)           SortArray(3)
'                   /          \            /          \
'         SortArray(4)   SortArray(5)   SortArray(6)  SortArray(7)
'          /      \       /       \       /      \      /      \
'        ...      ...   ...       ...   ...      ...  ...      ...
'
'
'  where each "parent node" is greater than each of its "child nodes"; for
'  example, SortArray(1) is greater than SortArray(2) or SortArray(3),
'  SortArray(3) is greater than SortArray(6) or SortArray(7), and so forth.
'
'  Therefore, once the first FOR...NEXT loop in HeapSort is finished, the
'  largest element is in SortArray(1).
'
'  The second FOR...NEXT loop in HeapSort swaps the element in SortArray(1)
'  with the element in MaxRow, rebuilds the heap (with PercolateDown) for
'  MaxRow - 1, then swaps the element in SortArray(1) with the element in
'  MaxRow - 1, rebuilds the heap for MaxRow - 2, and continues in this way
'  until the array is sorted.
' ============================================================================
'
SUB HeapSort STATIC
   FOR I = 2 TO MaxRow
      PercolateUp I
   NEXT I

   FOR I = MaxRow TO 2 STEP -1
      SWAP SortArray(1), SortArray(I)
      SwapBars 1, I
      PercolateDown I - 1
   NEXT I
END SUB

' ============================= InsertionSort ================================
'   The InsertionSort procedure compares the length of each successive
'   element in SortArray with the lengths of all the preceding elements.
'   When the procedure finds the appropriate place for the new element, it
'   inserts the element in its new place, and moves all the other elements
'   down one place.
' ============================================================================
'
void InsertionSort() {
  SortType TempVal;
  DWord Row;
  for (Row=2; Row<=MaxRow) {
    TempVal=SortArray[Row];
    TempLength=TempVal.Length;
    for (J=Row; J<=2; J--) {
      if (SortArray[J-1].Length>TempLength) {
	SortArray[J]=SortArray[J-1];
	PrintOneBar J;
	ElapsedTime J;
      }else break;
    }
    SortArray[J]=TempVal;
    PrintOneBar J;
    ElapsedTime J;
  }
}

' ============================ PercolateDown =================================
'   The PercolateDown procedure restores the elements of SortArray from 1 to
'   MaxLevel to a "heap" (see the diagram with the HeapSort procedure).
' ============================================================================
'

void PercolateDown(DWord MaxLevel) {
  DWord I=1;
  do {
    DWord Child=2*I;
    if (Child>MaxLevel) break;
    if (Child+1<=MaxLevel)
      if (SortArray[Child+1]>SortArray[Child]) Child++;
    if (SortArray[I]<SortArray[Child]) {
      Swap SortArray[I], SortArray[Child];
      I=Child;
    } else break;
  }

' ============================== PercolateUp =================================
'   The PercolateUp procedure converts the elements from 1 to MaxLevel in
'   SortArray into a "heap" (see the diagram with the HeapSort procedure).
' ============================================================================
'
void PercolateUp(MaxLevel) {
  DWord I=MaxLevel;
  while (I!=1) {
    DWord Parent=I/2;
    if (SortArray[I]>SortArray[Parent]) {
      Swap (SortArray[Parent], SortArray[I]);
      I=Parent;
    }else break;
  }
}

' ============================== QuickSort ===================================
'   QuickSort works by picking a random "pivot" element in SortArray, then
'   moving every element that is bigger to one side of the pivot, and every
'   element that is smaller to the other side.  QuickSort is then called
'   recursively with the two subdivisions created by the pivot.  Once the
'   number of elements in a subdivision reaches two, the recursive calls end
'   and the array is sorted.
' ============================================================================
'
void QuickSort(DWord Low, DWord High) {
  if (Low<High) {
    if ((High-Low)==1) {
      if (SortArray[Low]>SortArray[High]) Swap(SortArray[Low), SortArray[High]);
    } // Only 2
    else {
      DWord RandIndex=RandBetween(Low, High);
      Swap (SortArray[High], SortArray[RandIndex]);
      Partition=SortArray[High]; //Original SortArray[RandIndex]
      do {
	DWord I=Low, J=High;
	while (I<J)&&(SortArray[I]<=Partition) I++;
	while (J>I)&&(SortArray[J]>=Partition) J--;
	if (I<J) Swap (SortArray[I], SortArray[J]);
      } while (I<J);
      Swap (SortArray[I], SortArray[High]);
      if ((I-Low)<(High-I)) {
	this(Low, I-1);
	this(I+1, High);
      } else {
	this(I+1, High);
	this(Low, I-1);
      }
    } // >2
  }
}

SUB ShellSort STATIC

   ' Set comparison offset to half the number of records in SortArray:
   Offset = MaxRow \ 2

   DO WHILE Offset > 0          ' Loop until offset gets to zero.
      Limit = MaxRow - Offset
      DO
	 Switch = FALSE         ' Assume no switches at this offset.

	 ' Compare elements and switch ones out of order:
	 FOR Row = 1 TO Limit
	    IF SortArray(Row).Length > SortArray(Row + Offset).Length THEN
	       SWAP SortArray(Row), SortArray(Row + Offset)
	       SwapBars Row, Row + Offset
	       Switch = Row
	    END IF
	 NEXT Row

	 ' Sort on next pass only to where last switch was made:
	 Limit = Switch - Offset
      LOOP WHILE Switch

      ' No switches at last offset, try one half as big:
      Offset = Offset \ 2
   LOOP
END SUB
*/