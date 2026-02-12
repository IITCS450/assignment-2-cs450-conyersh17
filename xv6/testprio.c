#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
  int pid = getpid();

  printf(1, "Setting priority to 1 (valid)\n");
  if(setpriority(pid, 1) == 0)
    printf(1, "Success\n");
  else
    printf(1, "Failure\n");

  printf(1, "Setting priority to 5 (invalid)\n");
  if(setpriority(pid, 5) < 0)
    printf(1, "Correctly failed\n");

  printf(1, "Setting priority on invalid PID\n");
  if(setpriority(99999, 1) < 0)
    printf(1, "Correctly failed\n");

  exit();
}
