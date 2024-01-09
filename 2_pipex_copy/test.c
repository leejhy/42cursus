#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
    char *cmd[5];
    
    cmd[0] = "/bin/sh";
    cmd[1] = "-c";
    cmd[2] = argv[1];
    cmd[3] = NULL;
    // cmd[4] = NULL;
	execve("/bin/sh", cmd, envp);
    return 0;
}