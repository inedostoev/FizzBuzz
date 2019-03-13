#ifndef FIZZBUZZ_H_INCLUDED
#define FIZZBUZZ_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


//Errors numbers, first number OK means that all is good
enum Errors {
    OK,
    OUTPUT_STREAM_ERROR,
    ARGC_ERROR,
    ARGV_NULL_PTR_ERROR,
    STR_NULL_PTR_ERROR,
    NOT_NUMBER_ERROR,
    LONG_NUMBER_ERROR,
    ERROR_BUF_NULL_PRT_ERROR,
    
};

//struct for detecting errors
typedef struct errorBuf {

    char *errorStr;
    int errorNum;

}errorBuf;


int printInputData(FILE* stream, int argc, char **argv);
errorBuf* checkAllDataOnDivision(FILE* stream, int argc, char **argv);
errorBuf* checkDiv3And5(FILE* stream, char *checkStr);
int skipPlusAndMinus(int *numCounter, char *checkStr);
int getMaxNumberLength();
int isDiv3(int sumDigits);
int isDiv5(char *checkStr, int numCounter);
errorBuf* makeErrorBuf(int errNum, char *errStr);
int printResults(FILE* stream, char *numStr, int fizzFlag, int buzzFlag);

#endif
