#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "rpn.h"
#include "errors.h"
#include "rpn-convert.h"
//#define list_buffer 10
#define list_buffer 128
int main(int argc, char *argv[]) {


    //问题出在conversion associative还是不对

    //getting the first line, last bit in that line casuing trouble

    /*
    int status = SUCCESS;
    double result;
    char array_in[100] = {"4 3 8 * +"};
    char array_out[100];
    //conversion(array_in, array_out, &status);
    result = evaluate(array_in, &status);
    printf("%f", result);
    printf("\n");
    //strcpy(array_in," 6 *（ 4 + 3 ）- 2");
    //char array_out[100] = "";
   // conversion(array_in, array_out, &status);
    //printf("%s", array_out);
    */



    int status;
    double result;
    char error_report_array[list_buffer];
    char result_array[1024];
    char dataLine_input[list_buffer];//to store input strings
    char dataLine_output[list_buffer];
    FILE* input = fopen(argv[1], "r"); //must exist
    FILE* output = fopen(argv[2], "w+");
    if (!input || !output) {
        perror("I/O error: ");
        return -1;
    }
    //fprintf(output, "this is a test\n");
    while (fgets(dataLine_input, list_buffer, input)) {
        printf("%s", dataLine_input); //why no /n?
        fprintf(output, "infix: ");
        fprintf(output, dataLine_input);
        fprintf(output, "postfix: ");
        conversion(dataLine_input, dataLine_output, &status);
        fprintf(output, dataLine_output);
        fprintf(output, "\n");
        fprintf(output, "result: ");
        result = evaluate(dataLine_output, &status);
        if (status != SUCCESS){
            error_function(&status, error_report_array);
            fprintf(output, error_report_array);
            fprintf(output, "\n");
        }else{
            snprintf(result_array, 1024, "%f", result);
            fprintf(output, result_array);
            fprintf(output, "\n");
        }
        dataLine_output[0] = 0;
        status = SUCCESS;

    }

    fclose(input);
    fclose(output);
    return 0;





    /*
    char array[list_buffer][col_buffer];
    int input_count = 0;
    int total = 0;
    FILE* input = fopen(argv[1], "r");
    if(!input){
        perror("I/O error:");
        return -1;
    }
    while(fgets(array[input_count], col_buffer, input)){
        array[input_count][strlen(array[input_count]-1)] = '\0';
        input_count++;
    }
    total = input_count;
    for(int i = 0; i < total; ++i)
    {
        printf(" %s\n", array[i]);
    }
    */



    /*
    int status;
    double result;

    printf("result for test 1\n");
    char expression_1[] = {"1 1 +"};
    result = evaluate(expression_1, &status);
    if (status != SUCCESS){
        error_function(&status);
    }else{
        printf("%f", result);
    }
    printf("\n");

    /*
    printf("result for test 2\n");
    char expression_2[] = {"+"};
    result = evaluate(expression_2, &status);
    if (status != SUCCESS){
        error_function(&status);
    }else{
        printf("%f", result);
    }
    printf("\n");

    printf("result for test 3\n");
    char expression_3[] = {"17 22 / 4 * 16 -"};
    result = evaluate(expression_3, &status);
    if (status != SUCCESS){
        error_function(&status);
    }else{
        printf("%f", result);
    }
    printf("\n");

    printf("result for test 4\n");
    char expression_4[] = {"2 8 ^ 3 /"};
    result = evaluate(expression_4, &status);
    if (status != SUCCESS){
        error_function(&status);
    }else{
        printf("%f", result);
    }
    printf("\n");


    printf("result for test 5\n");
    char expression_5[] = {"17 22 33 / 4 + 2"};
    result = evaluate(expression_5, &status);
    if (status != SUCCESS){
        error_function(&status);
    }else{
        printf("%f", result);
    }
    printf("\n");



    printf("result for test 6\n");
    char expression_6[] = {""};
    result = evaluate(expression_6, &status);
    if (status != SUCCESS){
        error_function(&status);
    }else{
        printf("%f", result);
    }
    printf("\n");


    printf("result for test 7\n");
    char expression_7[] = {"8 7 + 6 - 5 / 4 * 3 ^"};
    status = SUCCESS;
    result = evaluate(expression_7, &status);
    if (status != SUCCESS){
        error_function(&status);
    }else{
        printf("%f", result);
    }
    printf("\n");

*/

}
