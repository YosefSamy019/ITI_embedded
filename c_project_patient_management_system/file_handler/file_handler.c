#include "file_handler.h"
#include "../shared/STD_TYPES.h"
#include "../shared/debug.h"

#include <stdio.h>
#include <string.h>

void FILE_writeU32(String key, u32 num) {
    FILE *file;
    file = fopen(key, "w");

    if (file == NULL) {
        PRINT_DEBUG("Can not open %s file", key);
    } else {
        fprintf(file, "%u", num);
        fclose(file);
    }
}
u32 FILE_readU32(String key) {
    FILE *file;
    u32 num = 0;

    file = fopen(key, "r");

    if (file == NULL) {
        PRINT_DEBUG("Can not open %s file", key);
    } else {
        fscanf(file, "%u", &num);
        fclose(file);
    }

    return num;
}

void FILE_writeU32Arr(String key, u32 arr[], u32 size) {
    FILE *file;
    u32 i;
    file = fopen(key, "w");

    if (file == NULL) {
        PRINT_DEBUG("Can not open %s file", key);
    } else {

        for (i = 0; i < size; i++) {
            fprintf(file, "%d\n", arr[i]);
        }

        fclose(file);
    }
}
void FILE_readU32Arr(String key, u32 buffer[]) {
    FILE *file;
    u32 flag = 0;
    u32 temp;
    u32 i = 0;
    file = fopen(key, "r");

    if (file == NULL) {
        PRINT_DEBUG("Can not open %s file", key);
    } else {

        while (1) {
            flag = fscanf(file, "%d", &temp);
            if (flag == 1) {
                buffer[i] = temp;
                i++;
            } else {
                break;
            }

            printf("Scan flag %d, temp %d\n", flag, temp);
        }

        fclose(file);
    }
}

void FILE_writeU8Arr(String key, u8 arr[], u32 size) {
    FILE *file;
    u32 i;
    file = fopen(key, "w");

    if (file == NULL) {
        PRINT_DEBUG("Can not open %s file", key);
    } else {

        for (i = 0; i < size; i++) {
            fprintf(file, "%c", arr[i]);
        }

        fclose(file);
    }
}
void FILE_readU8Arr(String key, u8 buffer[]) {
    FILE *file;
    u32 flag = 0;
    u8 temp;
    u32 i = 0;
    file = fopen(key, "r");

    if (file == NULL) {
        PRINT_DEBUG("Can not open %s file", key);
    } else {

        while (1) {
            flag = fscanf(file, "%c", &temp);
            if (flag == 1) {
                buffer[i] = temp;
                i++;
            } else {
                break;
            }
        }

        fclose(file);
    }
}

void FILE_writeStringArr(String key, String arr[], u32 size) {
    FILE *file;
    u32 i;
    file = fopen(key, "w");

    if (file == NULL) {
        PRINT_DEBUG("Can not open %s file", key);
    } else {

        for (i = 0; i < size; i++) {
            fprintf(file, "%s \0 \n", arr[i]);
        }

        fclose(file);
    }
}

void FILE_readStringArr(String key, String buffer[]) {
    FILE *file;
    u32 flag = 0;
    String temp;
    u32 i = 0;
    file = fopen(key, "r");

    if (file == NULL) {
        PRINT_DEBUG("Can not open %s file", key);
    } else {

        while (1) {
            flag = fscanf(file, "%s", temp);
            if (flag == 1) {
                strcpy((u8 *)(buffer + i), temp);
                i++;
            } else {
                break;
            }
        }

        fclose(file);
    }
}
