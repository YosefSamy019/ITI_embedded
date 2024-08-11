#ifndef _MODELS_
#define _MODELS_

#include "../shared/STD_TYPES.h"

typedef enum {
    male = 0,
    female = 1
} Gender_t;



typedef struct {
    String firstName;
    String lastName;
    u32 age;
    Gender_t gender;
    u32 id;
} Patient_t;

typedef struct {
    boolean slotisReserved[5];
    Patient_t slot_reserveMan[5];
    String time[5];
} Slots_t;

#endif