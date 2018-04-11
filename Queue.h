#ifndef _EVENT_Q_H_
#define _EVENT_Q_H_

struct Queue
{
        int capacity;
        int front;
        int rear;
        struct evtRecord *elements;
};

struct evtRecord
{
	uint32_t evtType;
	void *evtData;
	uint32_t Tid;
};
	
struct Queue * createQueue(int maxElements);

struct evtRecord* Dequeue(struct Queue *Q);
struct evtRecord* DequeueFromIsr(struct Queue *Q);

int Enqueue(struct Queue *Q, uint32_t evtType, void* evtData, uint32_t taskID);
int EnqueueFromIsr(struct Queue *Q, uint32_t evtType, void* evtData, uint32_t taskID);

#endif
