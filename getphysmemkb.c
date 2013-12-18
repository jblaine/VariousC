/*
** Get and display the (rough) physical memory size on a POSIXy box.
**
** Pretty sure this sucks.
**
** BTW, Yippee:
** http://en.wikipedia.org/wiki/Kilobyte
** http://en.wikipedia.org/wiki/Megabyte
**
*/

/*
#include <config.h>
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
    unsigned long long int      physmem = -1;
    unsigned long int           pages = -1;
    unsigned long int           pagesizeKB = -1;

#ifdef _SC_PHYS_PAGES
    pages = sysconf(_SC_PHYS_PAGES);
#endif

#ifdef _SC_PAGESIZE
    pagesizeKB = sysconf(_SC_PAGESIZE) / 1024;
#endif

    if ((pages != -1) && (pagesizeKB != -1)) {
        physmem = pages * pagesizeKB;
        printf("%lld\n", physmem);
        exit(0);
    } else {
        printf("-1\n");
        exit(1);
    }
}

