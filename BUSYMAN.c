#include<stdio.h>
typedef struct event
{
        int start_time;
        int end_time;
        int event_number;
}event;
int compare(const void *x, const void *y)
{
        event *e1 = (event *)x, *e2 = (event *)y;
        return (*e1).end_time - (*e2).end_time;
}
/* Given the list of events, our goal is to maximise the number of events we can attend. */
int main()
{
    int t;
    scanf("%d",&t);
while(t--)
{
        int number_of_events;
  //printf("enter num of events");
        scanf("%d",&number_of_events);
        event T[number_of_events];
        int iter;
        for(iter=0;iter<number_of_events;iter++)
        {
     //       printf("enter start time and end time resp. of %d item",iter+1);
                scanf("%d%d",&T[iter].start_time,&T[iter].end_time);
                T[iter].event_number = iter;
        }
        /* Sort the events according to their respective finish time. */
        qsort(T,number_of_events,sizeof(event),compare);


        int events[number_of_events]; // This is used to store the event numbers that can be attended.

        int possible_events = 0; // To store the number of possible events

        //Taking the first task
        events[possible_events++] = T[0].event_number;
        int previous_event = 0;

        /* Select the task if it is compatable with the previously selected task*/
        for(iter=1;iter<number_of_events;iter++)
        {
                if(T[iter].start_time >= T[previous_event].end_time)
                {
                        events[possible_events++] = T[iter].event_number;
                        previous_event = iter;
                }
        }
        printf("%d\n",possible_events);
        //printf("Maximum possible events that can be attended are %d. They are\n",possible_events);
    /*    for(iter=0;iter<possible_events;iter++)
        {
                printf("%d\n",events[iter]);
        }
    */
}
return 0;
}
