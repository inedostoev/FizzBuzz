#include<stdio.h>
#include<stdlib.h>
#include"fizzbuzz.h"


int main(int argc, char **argv) {
   
    FILE* outputStream = stdout;
    
    fprintf(outputStream, "Input: ");
    printInputData(outputStream, argc, argv);

    fprintf(outputStream, "Output: ");


    errorBuf *buf;
    buf = checkAllDataOnDivision(outputStream, argc, argv);

    

    //Cheking errors
    int errorNum = buf->errorNum;
    if(errorNum == OUTPUT_STREAM_ERROR)
        fprintf(stdout, "NULL output pointer");
    if(errorNum == ARGC_ERROR)
        fprintf(outputStream, "Please, enter num");
    if(errorNum == NOT_NUMBER_ERROR)
        fprintf(outputStream, "Not a number: %s", buf->errorStr);
    if(errorNum == LONG_NUMBER_ERROR)
        fprintf(outputStream, "Long number: %s", buf->errorStr);

    fprintf(outputStream, "\n\n");

    return 0;
}

