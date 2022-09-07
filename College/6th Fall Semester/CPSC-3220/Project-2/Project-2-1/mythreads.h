#define _XOPEN_SOURCE 600

#include <stdbool.h>
#include <ucontext.h>

#define STACK_SIZE (16*1024)
#define NUM_LOCKS 10

/* TODO temp debug value */
#define MAX_THREADS 10
/* TODO temp debug value */

#define CONDITIONS_PER_LOCK 10

typedef struct Thread {
    /* Could we assume that thread [0] is main thread */

    int threadID;
    bool isRunning;
    bool isWaiting;
    bool isReady;

    /* TODO isFinished maybe unnecessary*/
    bool isFinished;
    ucontext_t threadContext;
    struct Thread * nextThread;

} Thread;

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

//this needs to be defined in your library. Don't forget it or some of my tests won't compile.
extern int interruptsAreDisabled;

/* Initializes thread to default values, sets stack and so fourth */
Thread* threadSetup();

void printAllThreads();

/* Places new thread at the tail of the list */
void insertIntoList(Thread * thread);

/* Switches thread state from active, to no longer active */
void changeStateToRunning(Thread * runningThread, Thread * noLongerRunning);
