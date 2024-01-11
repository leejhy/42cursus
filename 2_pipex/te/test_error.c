#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

void	f(void)
{
	perror("pppppppppp");
	exit(1);
}

int main() {
	char	*err;
    int fd = open("nonexistent_file.txt", O_RDONLY);

    if (fd == -1) {
        // f();
		// while (1);
		err = strerror(errno);
		printf("errrrrrrrrr %s\n", err);
        printf("Error code: %d\n", errno);
    } else {
        printf("File opened successfully.\n");
        // 여기서 파일 처리를 계속할 수 있음
    }

    return 0;
}