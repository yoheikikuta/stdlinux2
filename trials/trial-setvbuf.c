#include <stdio.h>

int main(void)
{
        char buf[10];
        long l;
        
        setvbuf(stdout,buf,_IOLBF,sizeof(buf));
        printf("1234567890abcdefg");
        /* Empty loop to check the effect of setvbuf */
        for (l=0; l<1000000000; l++);
        printf("\n");
        
        return 0;
}