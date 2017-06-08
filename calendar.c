#include <stdio.h>
//#include <stdlib.h>

struct calendar_t
{
        int events_count[52];
};

struct events_month{
        int events[13];
};

struct events_month events_per_month(struct calendar_t);

int main()
{
        struct calendar_t mycal;
        for(int i=0; i<52; i++)mycal.events_count[i]=i%5;
        for(int i=0; i<13; i++)printf("%d\n", events_per_month(mycal).events[i]);
        return 0;
}

struct events_month events_per_month(struct calendar_t cal)
{
        struct events_month count_month;
        int count;
        //for(int i=0;i<13;i++)count_month.events[i]=i%5;
        for(int i=0, j=0; i<13; i++, j+=4)
        {
                count_month.events[i]=cal.events_count[j]+cal.events_count[j+1]+cal.events_count[j+2]+cal.events_count[j+3] ;
        }
        return count_month;
}

