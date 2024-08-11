#ifndef _FILE_HANDLER_
#define _FILE_HANDLER_

#include "../shared/STD_TYPES.h"

void FILE_writeU32(String key, u32 num);
u32 FILE_readU32(String key);

void FILE_writeU32Arr(String key, u32 arr[], u32 size);
void FILE_readU32Arr(String key, u32 buffer[]);

void FILE_writeU8Arr(String key, u8 arr[], u32 size);
void FILE_readU8Arr(String key, u8 buffer[]);

void FILE_writeStringArr(String key, String arr[], u32 size);
void FILE_readStringArr(String key, String buffer[]);


#endif