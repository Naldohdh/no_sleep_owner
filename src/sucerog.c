/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** pipe
*/

#include "aim.h"
#include "foxx.h"
#include <unistd.h>
#include <stdlib.h>

int my_pipe(foxx_t *foxx, int i)
{
    int pipefd[2];
    pid_t pid;
    char buf[PIPE_BUF];
    int bytes_read;
    int bytes_written;
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return -1;
    }
    pid = fork();
    if (pid == -1) {
        perror("fork");
        return -1;
    }
    if (pid == 0) {
        close(pipefd[1]); // Close unused write end of the pipe
        dup2(pipefd[0], STDIN_FILENO); // Redirect stdin to read end of the pipe
        close(pipefd[0]); // Close read end of the pipe   
        my_exec_path(foxx); // Execute the command on the right side of the pipe
        exit(EXIT_SUCCESS);
    } else {
        close(pipefd[0]); // Close unused read end of the pipe
        dup2(pipefd[1], STDOUT_FILENO); // Redirect stdout to write end of the pipe
        close(pipefd[1]); // Close write end of the pipe
        // Read input from the command on the left side of the pipe and write it to the pipe
        while ((bytes_read = read(STDIN_FILENO, buf, PIPE_BUF)) > 0) {
            bytes_written = write(STDOUT_FILENO, buf, bytes_read);
            if (bytes_written != bytes_read) {
                perror("write");
                return -1;
            }
        }
        close(STDIN_FILENO); // Close stdin
        close(STDOUT_FILENO); // Close stdout        
        int status;
        waitpid(pid, &status, 0); // Wait for child process to finish
        return WEXITSTATUS(status);
    }
}

/*int suce(foxx_t *foxx, int fd[2], int save[2], int i)
{
    int j = 0;
    for (i += 1; foxx->cur_cmd[i]; i++) {
        foxx->cur_cmd[j] = foxx->cur_cmd[i];
        j++;
    } foxx->cur_cmd[j] = NULL;
    dup2(fd[0], STDIN_FILENO);
    check_commands(foxx);
    close(fd[0]);
    dup2(save[0], STDIN_FILENO);
    close(save[0]); return (1);
}

int my_pipe(foxx_t *foxx, int i)
{
    int save[2]; int fd[2];
    save[1] = dup(STDOUT_FILENO);
    save[0] = dup(STDIN_FILENO);
    if (foxx->cur_cmd[i + 1] == NULL) {
        pastor("Invalid null command.\n");
        return (84);
    } pipe(fd); dup2(fd[1], STDOUT_FILENO);
    foxx->cur_cmd[i] = NULL;
    check_commands(foxx);
    close(fd[1]);
    dup2(save[1], STDOUT_FILENO);
    close(save[1]);
    if (suce(foxx, fd, save, i) == -1) {
        return (84);
    } return (1);
    }*/
