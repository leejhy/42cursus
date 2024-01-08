#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
   pid_t a;

   if (argc != 5)
      return (0);
   a = fork();

   pipe();

}
