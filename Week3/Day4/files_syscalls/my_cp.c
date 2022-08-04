#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char**argp) {
    int fd_in = open(argp[1], O_RDONLY);
    int fd_out = open(argp[2], O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);

    if (fd_in == -1){
        perror("Could not open file!\n");
        return -1;
    }
    char curr_sym;
    int read_count = 1;
    int written_count;
    while ((read_count = read(fd_in, &curr_sym, 1)) != 0) {
        if (read_count == -1){
            perror("Could not read from in_file!\n");
            return -1;
        }

        written_count = write(fd_out, &curr_sym, 1);

        if (written_count == 0){
            perror("Could not write to file!\n");
            return -1;
        }
    }
    close(fd_in);
    close(fd_out);
}