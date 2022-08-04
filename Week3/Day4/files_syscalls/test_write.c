#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>


int main() {

    int fd = open("test_binary", O_WRONLY | O_TRUNC);
    printf("%d\n", fd);

    if (fd == -1){
        perror("Could not open file!\n");
    }
    //char *str = "Hello syscalls";
    int written_count;
    //int sym_count = strlen(str);
    int nums[] = {1, 2, 3, 4};
    written_count = write(fd, nums, sizeof(int) * 4);

    if (written_count != sizeof(int) * 4){
        write(2, "Could not write to file!\n", 26);
    }
    close(fd);

    return 0;
}