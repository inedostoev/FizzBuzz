#include"fizzbuzz.h"


//Make error buffer for detecting errors
errorBuf* makeErrorBuf(int errNum, char *errStr) {
    errorBuf *buf = NULL;
    
    buf = (errorBuf*)calloc(1, sizeof(errorBuf));
    if(buf == NULL) {
        printf("Can not create errorBuf\n");
        exit(ERROR_BUF_NULL_PRT_ERROR);
    }

    buf->errorNum = errNum;
    buf->errorStr = errStr;

    return buf;
}

//Validate number and checking division by 3 and 5 
errorBuf* checkDiv3And5(FILE* stream, char *checkStr) {
    int numCounter = 0;
    skipPlusAndMinus(&numCounter, checkStr);
   
    int sumDigits = 0;
    for(numCounter; checkStr[numCounter] != '\0'; numCounter++) {
        if(!isdigit(checkStr[numCounter])) {
            return makeErrorBuf(NOT_NUMBER_ERROR, checkStr);
        }
        
        //overflow protection
        if(numCounter == getMaxNumberLength()) {  
            return makeErrorBuf(LONG_NUMBER_ERROR, checkStr);
        }
        
        //calculation sum of digit to check division by 3
        sumDigits += checkStr[numCounter] - '0'; 
    }

    if(atoi(checkStr) == 0) {
        fprintf(stream, "0 ");
        return makeErrorBuf(OK, NULL);
    }
    
    int fizzFlag = isDiv3(sumDigits);
    int buzzFlag = isDiv5(checkStr, numCounter - 1);

    printResults(stream, checkStr, fizzFlag, buzzFlag);
 
    fizzFlag = 0;
    buzzFlag = 0;

    return makeErrorBuf(OK, NULL);
}

//Checking division by 5
//Used the sing of division by 3, last digit should be 0 or 5
int isDiv5(char *checkStr, int numCounter) {
    if(checkStr[numCounter] == '0' || checkStr[numCounter] == '5') return 1;
    else return 0;
}

//Checking division by 3
//Used the sing of division by 3, sum of digits should also be divided by 3
int isDiv3(int sumDigits) {
    while(sumDigits > 0) {
        sumDigits -= 3;
    }
    
    if(sumDigits == 0) return 1;
    else return 0;
}

//Print resuls in stream for the task
int printResults(FILE* stream, char *numStr, int fizzFlag, int buzzFlag) {
    if(fizzFlag == 1) fprintf(stream, "FIZZ");
    if(buzzFlag == 1) fprintf(stream, "BUZZ");
    if(buzzFlag == 0 && fizzFlag == 0) fprintf(stream, "%s", numStr);
    fprintf(stream, " ");
    
    return OK;
}

//Function, that unites validation of all numbers and checking div by 3 and 5
errorBuf* checkAllDataOnDivision(FILE* stream, int argc, char **argv) {
    
    if(argc <= 1)
        return makeErrorBuf(ARGC_ERROR, NULL);
    if(stream == NULL)
        return makeErrorBuf(OUTPUT_STREAM_ERROR, NULL);

    //Checking every number
    int i = 1;
    for(i = 1; i < argc; i++) {
        
        errorBuf *buf = checkDiv3And5(stream, argv[i]);
        
        //if not valid number, return errorBuf
        if(buf->errorNum != OK) {
            return buf;
        }
    }
    
    return makeErrorBuf(OK, NULL);
}

//Skip first plus or minus in string
int skipPlusAndMinus(int *numCounter, char *checkStr) {
    if(checkStr[0] == '-' || checkStr[0] == '+')
        *numCounter = 1;
    return OK;
}


//Return max number of digits
//Use in int overflow protection
//can be less than 240k
int getMaxNumberLength() {
    return 9;
}

//Printing input data in stream from console
int printInputData(FILE* stream, int argc, char **argv) {
    if(stream == NULL) {
        printf("printInputData(): Output stream is equal to NULL\n");
        return OUTPUT_STREAM_ERROR;
    }
    
    int i = 1;
    for(i = 1; i < argc; i++) {
        fprintf(stream, "%s ", argv[i]);
    }
    fprintf(stream, "\n");
    
    return OK;
}
