//SHELL SORT RELATED
/*-----------------------------------------------------------------*/
template<class ItemType>
void shellSort(ItemType theArray[], int n)//shell sort
{
   for (int h = n / 2; h > 0; h = h / 2)
   {
      for (int unsorted = h; unsorted < n; unsorted++)
      {
         ItemType nextItem = theArray[unsorted];
         int loc = unsorted;
         while ( (loc >= h) && (theArray[loc - h] > nextItem) )
         {
            theArray[loc] = theArray[loc - h];
            loc = loc - h;
         } // end while
         theArray[loc] = nextItem;
      }  // end for
   }  // end for
}  // end shellSort
