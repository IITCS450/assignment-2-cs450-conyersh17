#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_setpriority(void)
{
  int pid, prio;
  struct proc *p;

  // Argument parsing
  if(argint(0, &pid) < 0 || argint(1, &prio) < 0)
    return -1;

  // Validate priority range
  if(prio < 0 || prio > 2)
    return -1;

  acquire(&ptable.lock);
  for(p = ptable.proc; p < &ptable.proc[NPROC]; p++){
    if(p->pid == pid && p->state != UNUSED){
      p->priority = prio;
      release(&ptable.lock);
      return 0;
    }
  }
  release(&ptable.lock);

  return -1;  // PID not found
}
