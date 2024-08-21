#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(void) {
  char msg[] = "Hello World xv6\n";
  write(1, msg, sizeof(msg));
  exit(0, "");
}
