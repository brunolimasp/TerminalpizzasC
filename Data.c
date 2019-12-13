#include <stdio.h>
#include <time.h>
 
int DataAgora() {
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    printf("\t\t\t    %d/%d/%d ", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

}
