#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{
    EventList *eventList = malloc(sizeof(EventList)) ;
    eventList->isEmpty = 0;
    return eventList;
}

void DestroyEventList(EventList *this)
{


    free(this);
}

Event *SearchEvent(EventList *this, char *name)
{
    Event* a = this->head;
    do{
        if (name == a->eventName)
        {
            return a;
        }
    a = a->next;
    }
    while (a->next != NULL);
    
    
    return NULL;
}

void AddEvent(EventList *this, Event *event)
{
    if (this->isEmpty == 0)
    {
        this->isEmpty = 1;
        this->head = event;
        this->last = event;
    }
    else
    {
        this->last->next = event;
        this->last = event;
    }
    
}

void RemoveEvent(EventList *this, char *name)
{
}

void ListEvents(EventList *this)
{
    // imprime esto si la lista está vacía
    printf("empty\n");
}
