const int MAX_SIZE = 50;
const int MIN_SIZE = 10;
//MERGE SORT RELATED
/*-----------------------------------------------------------------*/
/** Merges two sorted array segments theArray[first..mid] and
    theArray[mid+1..last] into one sorted array.
 @pre  first <= mid <= last. The subarrays theArray[first..mid] and
    theArray[mid+1..last] are each sorted in increasing order.
 @post  theArray[first..last] is sorted.
 @param theArray  The given array.
 @param first  The index of the beginning of the first segment in theArray.
 @param mid  The index of the end of the first segment in theArray;
    mid + 1 marks the beginning of the second segment.
 @param last  The index of the last element in the second segment in theArray.
 @note  This function merges the two subarrays into a temporary
    array and copies the result into the original array theArray. */
template<class ItemType>
void merge(ItemType theArray[], int first, int mid, int last)//merge function
{
	// Initialize the local indices to indicate the subarrays
   /*int first1 = first;            // Beginning of first subarray
   int last1 = mid;               // End of first subarray
   int first2 = mid + 1;          // Beginning of second subarray
   int last2 = last;              // End of second subarray*/
   int leftIndex=0;
   int rightIndex=0;
   int mainIndex=first;
   
   int leftSize=mid-first+1;
   int rightSize= last-mid;
   
   ItemType *lArray=new ItemType[leftSize];  // left temp
   ItemType *rArray=new ItemType[rightSize];  // right temp
   //takes the elements of the left half af mainArray and adds it to lArray
   for (int i=0; i<leftSize; i++)
   {
   		lArray[i]=theArray[i+first];
   }
   //takes the elements of the right half af mainArray and adds it to rArray 
   for (int i=0; i<rightSize; i++)
   {
   		rArray[i]=theArray[mid+i+1];
   }
   //sorting goes on
   while (leftIndex<leftSize&&rightIndex<rightSize)
   {
   		if (lArray[leftIndex]<=rArray[rightIndex])
   		{
   			theArray[mainIndex]=lArray[leftIndex];//left array's item is being assigned to main array
			leftIndex++;	
		}
		else
		{
			theArray[mainIndex]=rArray[rightIndex];//right array's item is being assigned to main array
			rightIndex++;	
		}
		mainIndex++;
   }
   
   //copies the remaining elements inside lArray into mainArray
   while (leftIndex<leftSize)
   {
   		theArray[mainIndex]=lArray[leftIndex];
   		leftIndex++;
   		mainIndex++;
   }
   
    //copies the remaining elements inside lArray into mainArray
   while (rightIndex<rightSize)
   {
   		theArray[mainIndex]=rArray[rightIndex];
   		rightIndex++;
   		mainIndex++;
   }
   delete [] lArray;
   delete [] rArray;
   
   
   // While both subarrays are not empty, copy the
   // smaller item into the temporary array
   /*int index = first1;            // Next available location in tempArray
   while ((first1 <= last1) && (first2 <= last2))
   {
      // At this point, tempArray[first..index-1] is in order
      if (theArray[first1] <= theArray[first2])
      {
         tempArray[index] = theArray[first1];
         first1++;
      }
      else
      {
         tempArray[index] = theArray[first2];
         first2++;
      }  // end if
      index++;
   }  // end while
   
   // Finish off the first subarray, if necessary
   while (first1 <= last1)
   {
      // At this point, tempArray[first..index-1] is in order
      tempArray[index] = theArray[first1];
      first1++;
      index++;
   }  // end while
   
   // Finish off the second subarray, if necessary
   while (first2 <= last2)
   {
      // At this point, tempArray[first..index-1] is in order
      tempArray[index] = theArray[first2];
      first2++;
      index++;
   }  // end for
   
   // Copy the result back into the original array
   for (index = first; index <= last; index++)
   {
   		theArray[index] = tempArray[index];
   }
      */
}  // end merge
/** Sorts the items in an array into ascending order.
 @pre  theArray[first..last] is an array.
 @post  theArray[first..last] is sorted in ascending order.
 @param theArray  The given array.
 @param first  The index of the first element to consider in theArray.
 @param last  The index of the last element to consider in theArray. */
template<class ItemType>
void mergeSort(ItemType theArray[], int first, int last)//merge sort
{
   if (first < last)
   {
      // Sort each half
      int mid = first + (last - first) / 2; // Index of midpoint
      
      // Sort left half theArray[first..mid]
      mergeSort(theArray, first, mid);
      
      // Sort right half theArray[mid+1..last]
      mergeSort(theArray, mid + 1, last);
      
      // Merge the two halves
      merge(theArray, first, mid, last);
   }  // end if
}  // end mergeSort
