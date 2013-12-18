/*
** Get and display the number of processors
**
*/

/*
#include <config.h>
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
    short int     numprocs = -1;

#ifdef _SC_NPROCESSORS_ONLN
    numprocs = sysconf(_SC_NPROCESSORS_ONLN);
#endif
#ifdef _SC_NPROC_ONLN
    numprocs = sysconf(_SC_NPROC_ONLN);
#endif

    /* If the above failed, numprocs will be -1.  Just print it out */
    /* as such which should be enough of an indicator that it is    */
    /* unknown on this machine */
    printf("%d\n", numprocs);

    if (numprocs < 0) {
        exit(1);
    } else {
        exit(0);
    }
}
