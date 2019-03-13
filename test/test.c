#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"../src/fizzbuzz.h"


int main(int argc, char **argv) {
  
    FILE* outputStream = fopen("test/outputFile", "a");
    
    fprintf(outputStream, "Input: ");
    
    printInputData(outputStream, argc, argv);

    fprintf(outputStream, "Output: ");

    errorBuf *buf;
    buf = checkAllDataOnDivision(outputStream, argc, argv);

    //Cheking errors
    int errorNum = buf->errorNum;
    if(errorNum == OUTPUT_STREAM_ERROR) {
        fprintf(stdout, "NULL output pointer\n\n");
        exit(0);
    }
    if(errorNum == ARGC_ERROR) {
        fprintf(outputStream, "Please, enter num\n\n");
        exit(0);
    }
    if(errorNum == ARGV_NULL_PTR_ERROR) {
        fprintf(outputStream, "argv == NULL\n\n");
        exit(0);
    }
    if(errorNum == NOT_NUMBER_ERROR) {
        fprintf(outputStream, "Not a number: %s\n\n", buf->errorStr);
        exit(0);
    }
    if(errorNum == LONG_NUMBER_ERROR) {
        fprintf(outputStream, "Long number: %s\n\n", buf->errorStr);
        exit(0);
    }

    fprintf(outputStream, "\n\n");

    return 0;
}
