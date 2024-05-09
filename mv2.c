#include <stdio.h>//used for standard input and output operations
//like printf and scanf needed for most c programs
#include <unistd.h>

#include <fcntl.h>//allows the program to use certain functions and
//constants for handling file operations, such as open, close, read, and write
int main(int argc, char *argv[])
//it tells the computer what to do
//argc is the number of arguments
//argv is the array of arguments
//argv[0] is the name of the program
//argv[1] is the first argument
//argv[2] is the second argument
//argv[argc-1] is the last argument
//argv[argc] is the NULL pointer
{
    int i, fd1, fd2;
    //i is an integer variable, fd1 and fd2 are file descriptors
    //used to store the file descriptors of the files.
    char *file1,*file2;
    //file1 and file2 are pointers, to char variables,to read the file names
    //from the command line,as well as write into the file.
    char buf[1024];
    //buf is a character array to store the data read from the file,
    //and as well as write into the file.
    file1 = argv[1];
    //storing name of the 1st file in file1,from address file 1
    file2 = argv[2];
    //storing name of the 2nd file in file2
    //the destination file will be created if it doesn't exist
    printf("file1=%s file2=%s", file1, file2);
    //printing the file names in the command line
    fd1 = open(file1, O_RDONLY, 0777);
    //open() is used to open a file.in read-only mode,0777 is the permissions
    //assigned to the file, and we are opening file1
    fd2 = creat(file2, 0777);
    //creat() is used to create a file in write-only mode
    //0777 is the permissions assigned to the file
    //and we are creating file2,if already exists, it will be overwritten
    //these functions will return the file descriptor of the file
    /*fd1 and fd2 are file descriptors returned by these functions.
    A file descriptor is a unique identifier for a file opened by a process. 
    If the open() or creat() function fails for any reason (like the file doesn't 
    exist, or there's no permission to create a file), it returns -1, indicating 
    an error.*/
    while (i = read(fd1, buf, 1) > 0)
    //read() is used to read the data from the file,fd1(signifies the file name)
    //and store the data in buf,1 is the number of bytes to be read 
    //so it will read one at a time.and store it into the buf
        write(fd2, buf, 1);
    //write() is used to write the data to the file,fd2(signifies the file name)
    //the buf which was read above will be written to the file, 1 byte at a time
    //and so it will write one at a time

    //i becomes 0 when it reaches the end of the file
    //so the while loop breaks.
    remove(file1);
    //after the file is copied, it will be removed,
    //the from address will be removed.
    close(fd1);
    //close() is used to close the file,over here it's the file 1
    //which is being closed.
    close(fd2);
    //close() is used to close the file,over here it's the file 2
    return 0;
}