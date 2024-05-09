#include <stdio.h>
// used for standard input and output operations
// like printf and scanf needed for most c programs

#include <unistd.h>
/*fork(): This function is used to create a new process by duplicating the
calling process. The new process is called a child process. fork() is defined in
unistd.h, and it returns a process ID. The return value is used to determine
whether the process running the code is the parent or the newly created child.*/
#include <stdlib.h>
/*
In the program you provided, the #include <stdlib.h> directive is used to include
the Standard Library in C, which provides functions for performing general
functions including memory allocation, process control, conversions, and others*/

int main()
{
    int pid;      // process id
    pid = fork(); // create another process
    if (pid < 0)
    { // if pid ==-1 then the fork call failed to implement
        printf("\nFork failed\n");
        exit(-1);
    }
    else if (pid == 0)
    { // if pid == 0 then the fork call was successful
        // child process is being executed if fork return value is 0
        execlp("/bin/ls", "ls", "-l", NULL); // execute ls command
        // this statement is used to serve the ls command
        /* This is a critical piece of functionality when you want the child
        process to carry out a specific task that is different from what the
        parent process continues to do.*/

        /* (in this case, the child process created by fork()) is replaced by a
        new program (/bin/ls).*/

        // lists the contents of directories.
        //"/bin/ls": This is the path to the executable that should be run.
        /*
        "ls": This argument is the name of the command, as it would appear if you 
        were to run it in a terminal.
        "-l": This argument tells the ls command to use a long listing format, 
        which provides detailed information about each file and directory 
        (e.g., permissions, owner, size, and modification date).
        NULL: This indicates the end of the arguments to the ls command.
        */
    }
    else
    {   //the child process is doing it's own work
        printf("\nChild process started.\n");
        // No wait() call here
        //and the parent will do it's own work independently.
        printf("\nParent process exiting.\n");
    }
    return 0;
}
