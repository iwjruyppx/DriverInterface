
/* Standard includes. */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#include "interpolationSearch.h"

//#define INTERPOLATION_DEBUG
#ifdef INTERPOLATION_DEBUG
extern void osLog(const char * sFormat, ...);
static int amount = 0;
static int count = 0;
#endif /*INTERPOLATION_DEBUG*/

typedef struct
{
    int index;
    void *info;
}searchInfo_t, *psearchInfo_t;

int interpolationSearch(void *mem, int maxSize, int find)
{
    psearchInfo_t a = (psearchInfo_t)mem;
    int low, mid, high, searchTime;
    low = 0;
    high = maxSize-1;
    searchTime = 0;
    while(low<=high)
    {
        mid = (high-low) * (find-a[low].index) / (a[high].index -a[low].index) + low;
        searchTime++;
        if((mid < low) || (mid > high))
            return -1;
        if(find < a[mid].index)
            high = mid - 1;
        else if(find > a[mid].index)
            low = mid +1;
        else
        {
#ifdef INTERPOLATION_DEBUG
            amount = amount+searchTime;
            count++;
            float avarge = (float)amount/count;
            osLog("[%d]%s:%s,%d,%f\n", __LINE__, __FUNCTION__, "searchTime", searchTime, avarge);
#endif /*INTERPOLATION_DEBUG*/
            return mid;
        }
    }
    return -1;    
}
