//
// Created by asus on 2024-07-02.
//

#include <stdarg.h>
#include <stdlib.h>
#include "input_output.h"

#include <stdio.h>
#include "delay_ms.h"

// ANSI escape codes for colors
#define RESET_COLOR "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

static char buffer[50];


static void setStyle(TextStyle textStyle) {
    switch (textStyle) {
    case TextStyle_header:
        printf(MAGENTA);
        break;
    case TextStyle_label:
        printf(BLUE);
        break;
    case TextStyle_body:
        printf(RESET_COLOR);
        break;
    case TextStyle_number:
        printf(YELLOW);
        break;
    case TextStyle_error:
        printf(RED);
        break;
    case TextStyle_question:
        printf(MAGENTA);
        break;

    case TextStyle_input:
        printf(GREEN);
        break;
    }
}

static void printAnimated(char *ptr, char *format, ...) {
    va_list args;
    va_start(args, format);
    int length, i = 0;

    length = sprintf(buffer, format, args);

    for (i = 0; i < length; ++i) {
        printf("%c", buffer[i]);
        delay_ms( 5);
    }
}

void printString(char *ptr, TextStyle textStyle) {
    setStyle(textStyle);
    printAnimated("%s", ptr);
    setStyle(TextStyle_body);
}

void printStringLn(char *ptr, TextStyle textStyle) {
    printString(ptr, textStyle);
    printf("\n");
    setStyle(TextStyle_body);
}

void printInt(int number, TextStyle textStyle) {
    setStyle(textStyle);
    printf("%d", number);
    setStyle(TextStyle_body);
}

void printIntLn(int number, TextStyle textStyle) {
    printInt(number, textStyle);
    printf("\n");
    setStyle(TextStyle_body);
}

void printFloat(float number, TextStyle textStyle) {
    setStyle(textStyle);
    printf("%f", number);
    setStyle(TextStyle_body);
}

void printFloatLn(float number, TextStyle textStyle) {
    printFloat(number, textStyle);
    setStyle(TextStyle_body);

    printf("\n");
}


int readInt() {
    int x;
    setStyle(TextStyle_input);
    scanf("%d", &x);
    return x;
}

void readString(char buffer[]) {
    setStyle(TextStyle_input);

    scanf("%s", buffer);
}

float readFloat() {
    float x;
    setStyle(TextStyle_input);

    scanf("%f", &x);
    return x;
}


void waitKey(void) {
    fflush(stdin);
    fflush(stdout);

    printString("\nHit Enter key to continue ...", TextStyle_header);
    getchar();
}