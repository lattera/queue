#if !defined(_REVBOT_QUEUE_H)
#define _REVBOT_QUEUE_H

#include <pthread.h>

typedef struct _queue_item
{
	char *action;
	void *data;
	size_t sz;
	
	struct _queue_item *next;
} QUEUE_ITEM;

typedef struct _queue
{
	size_t numitems;
	QUEUE_ITEM *items;
	
	pthread_mutex_t modify_mutex;
	pthread_mutex_t read_mutex;
} QUEUE;

QUEUE *Initialize_Queue(void);
void Add_Queue_Item(QUEUE *, char *, void *, size_t);
QUEUE_ITEM *Get_Queue_Item(QUEUE *);
void Free_Queue_Item(QUEUE_ITEM *);

#endif
