#define _XOPEN_SOURCE 600

#include <ucontext.h>

#define STACK_SIZE (16*1024)
#define NUM_LOCKS 10
#define CONDITIONS_PER_LOCK 10


#define _XOPEN_SOURCE 600
#define STANDBY 0
#define DONE 3
#define RUNNING 1
#define INVALID -1
#define LOCKED 1
#define WAITING 2
#define UNLOCKED 0
#define EXITED 4
#define MAIN_THREAD 0

typedef struct Node {
    int id;
    int status;
    ucontext_t context;
    void *result;

    int queuePosition;
    int lockNumber;
    int conditionalNumber;


    struct Node *next;
} Node;

//the type of function used to run your threads
typedef void *(*thFuncPtr)(void *);

extern void threadInit();

extern int threadCreate(thFuncPtr funcPtr, void *argPtr);

extern void threadYield();

extern void threadJoin(int thread_id, void **result);

//exits the current thread -- closing the main thread, will terminate the program
extern void threadExit(void *result);

extern void threadLock(int lockNum);

extern void threadUnlock(int lockNum);

extern void threadWait(int lockNum, int conditionNum);

extern void threadSignal(int lockNum, int conditionNum);

//this must be initialized
extern int interruptsAreDisabled;

static void interruptDisable();

static void interruptEnable();

/* Helper */
void *wrapper(thFuncPtr funcPtr, void *argPtr);

void rotate();

void switchThread(int fromID, int toID);

Node *pickNextThread();

Node *createNode(ucontext_t context);

void closeNode(int id);

Node *getNode(int id);

int addNode(ucontext_t context);

int deleteNode(int id);
