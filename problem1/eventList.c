#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


EventList *CreateEventList(void)
{
    EventList *eventList = malloc(sizeof(EventList)) ;
    eventList->head = NULL;
    eventList->isEmpty = 0;
    eventList->last = NULL;
    return eventList;
}

void DestroyEventList(EventList *this)
{


    free(this);
}

Event *SearchEvent(EventList *this, char *name)
{
    if (this->isEmpty != 0)
    {
        Event* a = this->head;
        do{
        if (*name == *a->eventName && *(a->eventName+2) == *(name+2) && *(a->eventName+3) == *(name+3))
        {
            return a;
        }
        else
        {
            a = a->next;
        }
        
    
    }
    while (a!= NULL);
    }
    
    
    return NULL;
}

void AddEvent(EventList *this, Event *event)
{
    
    Event* a = this->head;
    char* nom = event->eventName;
    
    while (a != NULL)
    {
        if (*a->eventName == *nom && *(a->eventName+2) == *(nom+2) && *(a->eventName+3) == *(nom+3))
        {
            return;
        }
        
        a = a->next;
    }
    
    
    
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

    if (this->isEmpty == 0)
    {
        return;
    }

    Event* a = this->head;
    Event* x = SearchEvent(this, name);

    if (x == NULL)
    {
        return;
    }
    
    
    


        if (*this->head->eventName == *name && *(this->head->eventName+2) == *(name+2))
        {
            this->head = this->head->next;
            if (this->head == NULL)
            {
                this->isEmpty = 0;
            }
        
        free(a);
        }
    
    
        else
        {
            do
            {
                if (*a->next->eventName == *name && 
                *(a->next->eventName+2) == *(name+2)&& 
                *(a->next->eventName+3) == *(name+3))
                {
                    Event* b = malloc(sizeof(Event));
                    b = a->next;
                    a->next = b->next;
                    b = NULL;
                    DestroyEvent(b);
                    break;
                }
                
                a = a->next;
                
            }
            while (a != NULL);

        }
    
    
    
   
       
    
}

void ListEvents(EventList *this)
{
    Event* a = this->head;
    if (this->isEmpty == 0)
    {
        printf("empty\n");
    }
    else
    {
        do
        {
            printf("%s\n",a->eventName);

            if (a->next != NULL)
            {
                a = a->next;
            }
            else
            {
                break;
            }
            
        }
        while (1);
    }
    
    
    
    
}
