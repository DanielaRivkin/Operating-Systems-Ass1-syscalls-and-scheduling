#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
int
main(int argc, char *argv[])
{

    if(argc == 2){
        int policy = (uint)atoi(argv[1]);
        if(policy >=0 && policy <=2){
            set_policy(policy);
            printf("policy changed to: %s", argv[1]);
            exit(0, "\n");
        }
    }
    exit(1, "Error \n");

}