#include <iostream>
#include <string>
using namespace std;

template <class ItemType>
int linearSearch(ItemType anArray[], long long int first, long long int last, ItemType key)
{
	bool found=false;
	int index=0;
	for (int i=first; i<last&&!found; i++)
	{
		if(key==anArray[i])
		{
			index=i;
			found=true;
		}
		if (!found)
		{
			index=-1;
		}
	}
	return index;
}//end of linear search
