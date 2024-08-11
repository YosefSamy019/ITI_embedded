#ifndef _DATA_API_
#define _DATA_API_

#include "../shared/STD_TYPES.h"
#include "../models/models.h"


typedef enum {
    Status_PatientNotFound,
    Status_ok,
    Status_PatientIDRepeated,
    Status_slotReserved,
    Status_wrongSlotIndex
} DataApiStatus;

void DATA_init(void);

DataApiStatus DATA_searchPatient(u32 id, Patient_t *patient);

DataApiStatus DATA_addPatient(Patient_t patient, u32 *newID);

DataApiStatus DATA_editPatient(Patient_t oldPatient, Patient_t newPatient);

Slots_t DATA_getReservations(void);

DataApiStatus DATA_reserveSlot(Patient_t patient, u8 slotIndex);

DataApiStatus DATA_cancelSlot( u8 slotIndex);

#endif