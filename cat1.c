#include <stdio.h>//used for standard input and output operations
//like printf and scanf needed for most c programs

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
    FILE *fptr;//we are having a file pointer, fptr is a pointer to a file
    //to read the data from the file, we need to open the file
    //to read the data to the file, we need to open the file
    fptr=fopen(argv[1],"r");
    //argv[1] is the name of the file,we are opening it in read mode
    if(!fptr||argc!=2)
    //if the file pointer is null or the number of arguments is not equal to 2
    {   
        //then print the error message
        printf("error");

    }
    char ch;
    //to read the data from the file, we need a variable to store the data
    //and print each character one by one
    while ((ch=fgetc(fptr))!=EOF)
    //fgetc is a function to read the data from the file,fptr,it will read the data
    //till the end of file.and stop after it arrives the end of file.
    {   
        printf("%c",ch);
    }

    fclose(fptr);
    //to close the file,to avoid memory leakage.
}