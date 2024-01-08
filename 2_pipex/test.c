#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv, char **envp)
{//argv[2]가 cmd1임
	
	//argv[2]를 쪼갬 "ls -l"면, {"ls", "-l"}이렇게
	char **command = {"ls", "-l"};

	execve(command[0], command, NULL);
	// if (execve(command[0], command, NULL) == -1) {
    //     perror("execve");
    //     return 1;
    // }

    // execve 함수가 성공하면 이 부분은 실행되지 않음

    return 0;
}