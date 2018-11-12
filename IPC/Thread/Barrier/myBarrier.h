#include <stddef.h>





typedef struct Barrier Barrier_t;
typedef  void (*_doSomeThing)(void*);


Barrier_t* Barrier_Create(size_t _numberOfThread);
int Barrier_Wait(Barrier_t* _barrier,_doSomeThing _toDo,void* _context);
void Barrier_Destroy(Barrier_t* _barrier);


