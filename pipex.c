/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:57:10 by vfranco-          #+#    #+#             */
/*   Updated: 2022/06/25 09:38:47 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"
#include<sys/wait.h>

void test_fork()
{
    int id  = fork(); // child id is zero and parent id is bigger then zero
    int res = 0;
    if (id == 0) {
        printf("Child processes says:\n");
    } else {
        sleep(1); // sleep 1 s
        printf("Parent processes says:\n");
        res = wait(NULL);
    }
    printf("Child ID %d, parent ID %d\n", getpid(), getppid());
    if (id == 0) {
        printf("Child process received process id %d from wait\n", res);
    } else {
        printf("Parent process received process id %d from wait\n", res);
    }
}

int    test_pipe()
{
    int fd[2];
    // fd[0] read
    // fd[1] write
    if (pipe(fd) == -1)
    {
        printf("an error ocurred with opening pipe\n");
        return (1);
    }
    int id = fork();
    if (id == -1)
    {
        printf("An eror ocurred with fork\n");
        return (2);
    }
    if (id == 0)
    {
        close(fd[0]);
        int x;
        printf("Input number: ");
        scanf("%d", &x);
        if (write(fd[1], &x, sizeof(int)) == -1)
        {
            printf("An error ocurred with writing to the pipe\n");
            return (3);
        }
        close(fd[1]);
    } else {
        close(fd[1]);
        int y;
        if (read(fd[0], &y, sizeof(int)) == -1)
        {
            printf("An error ocurred with reading from pipe\n");
            return (4);
        }
        close(fd[0]);
        printf("Got from child process %d\n", y);
    }
    return (0);
}

int main(int argc, char **argv)
{
    printf("Program name: %s\n", argv[argc - 1] + 2);
    printf("\n");
    //test_fork();
    printf("\n");
    if (test_pipe() > 1)
    {
        printf("An error has ocurred in the pipe function\n");
        return (PIPEX_ERROR);
    }
    printf("\n");
    return (0);
}