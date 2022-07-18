//
// Created by Aaron Gong on 3/30/21.
//

#include "errors.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

void error_function (int* status, char* error_report){
    switch (*status) {
        case SUCCESS:
            strcat(error_report, "Successful!");
            break;
        case nullpointer:
            strcat(error_report,"null pointer error");
            break;
        case wrongoperator:
            strcat(error_report,"invalid operator");
            break;
        case incorrect_amount:
            strcat(error_report,"entered math expression does not have a correct number of numerics values and operators");
            break;
        case dividebyzero:
            strcat(error_report,"cannot divide by 0");
            break;
        case unpairedP:
            strcat(error_report,"the expression has unpaired ()");
            break;
        default:
            strcat(error_report,"a unsuspected error occured");
    }
}
