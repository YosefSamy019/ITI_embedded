#include "../shared/STD_TYPES.h"
#include "../models/models.h"
#include "../file_handler/file_handler.h"

#include "data_api.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_PAT_NO "patient_no.txt"

#define KEY_FIRST_NAME "1st_name.txt"
#define KEY_LAST_NAME "lst_name.txt"
#define KEY_AGE "age.txt"
#define KEY_GENDER "gender.txt"
#define KEY_ID "id.txt"

#define KEY_SLOTS_IDS "slots_ids.txt"
#define KEY_SLOTS_FLAGS "slots_flags.txt"

#define SLOT_LEN 5

static u32 patientLength;
Patient_t *buffer = NULL;


static u32 slotsArrId[SLOT_LEN] = {0};
static u32 slotsArrBoolean[SLOT_LEN] = {0};


static const String time[] = {
    "02:00 to 02:30",
    "02:30 to 03:00",
    "03:00 to 03:30",
    "04:00 to 04:30",
    "04:30 to 05:00"};

static u32 _getMaxID(void) {
    u32 max = 0, i;

    if (buffer != NULL) {
        for (i = 0; i < patientLength; i++) {
            if (buffer[i].id > max) {
                max = buffer[i].id;
            }
        }
    }

    return max;
};

static void _copyPatient(Patient_t *to, Patient_t *from) {
    to->age = from->age;
    to->gender = from->gender;
    to->id = from->id;
    strcpy(to->firstName, from->firstName);
    strcpy(to->lastName, from->lastName);
}

static void _loadFromFiles(void) {
    u32 i;
    String firstName[patientLength];
    String lastName[patientLength];
    u32 age[patientLength];
    Gender_t gender[patientLength];
    u32 id[patientLength];

    FILE_readStringArr(KEY_FIRST_NAME, firstName);
    FILE_readStringArr(KEY_LAST_NAME, lastName);
    FILE_readU32Arr(KEY_AGE, age);
    FILE_readU32Arr(KEY_GENDER, gender);
    FILE_readU32Arr(KEY_ID, id);

    for (i = 0; i < patientLength; i++) {
        strcpy(buffer[i].firstName, firstName[i]);
        strcpy(buffer[i].lastName, lastName[i]);
        buffer[i].age = age[i];
        buffer[i].gender = gender[i];
        buffer[i].id = id[i];
    }


    FILE_readU32Arr(KEY_SLOTS_IDS, slotsArrId);
    FILE_readU32Arr(KEY_SLOTS_FLAGS, slotsArrBoolean);
}

static void _saveToFiles(void) {
    u32 i;
    String firstName[patientLength];
    String lastName[patientLength];
    u32 age[patientLength];
    Gender_t gender[patientLength];
    u32 id[patientLength];

    for (i = 0; i < patientLength; i++) {
        strcpy(firstName[i], buffer[i].firstName);
        strcpy(lastName[i], buffer[i].lastName);
        age[i] = buffer[i].age;
        gender[i] = buffer[i].gender;
        id[i] = buffer[i].id;
    }

    FILE_writeStringArr(KEY_FIRST_NAME, firstName, patientLength);
    FILE_writeStringArr(KEY_LAST_NAME, lastName, patientLength);
    FILE_writeU32Arr(KEY_AGE, age, patientLength);
    FILE_writeU32Arr(KEY_GENDER, gender, patientLength);
    FILE_writeU32Arr(KEY_ID, id, patientLength);

    FILE_writeU32(KEY_PAT_NO, patientLength);


    FILE_writeU32Arr(KEY_SLOTS_IDS, slotsArrId, SLOT_LEN);
    FILE_writeU32Arr(KEY_SLOTS_FLAGS, slotsArrBoolean, SLOT_LEN);
}


void DATA_init(void) {
    //get student number
    patientLength = FILE_readU32(KEY_PAT_NO);

    //allocate buffer
    buffer = (Patient_t *)malloc(sizeof(Patient_t) * patientLength);

    if (patientLength > 0 && buffer != NULL) {
        _loadFromFiles();
    }

    _saveToFiles();
}

DataApiStatus DATA_searchPatient(u32 id, Patient_t *patient) {
    u32 i;

    for (i = 0; i < patientLength; i++) {
        if (buffer[i].id == id) {
            _copyPatient(patient, buffer + i);
            return Status_ok;
        }
    }

    return Status_PatientNotFound;
}



DataApiStatus DATA_addPatient(Patient_t patient, u32 *newID) {
    patient.id = _getMaxID() + 1;

    *newID = patient.id;

    patientLength += 1;
    buffer = realloc(buffer, sizeof(Patient_t) * patientLength);
    buffer[patientLength - 1] = patient;

    _saveToFiles();

    return Status_ok;
}

DataApiStatus DATA_editPatient(Patient_t oldPatient, Patient_t newPatient) {
    u32 i;

    for (i = 0; i < patientLength; i++) {
        if (buffer[i].id == oldPatient.id) {
            buffer[i] = newPatient;
            buffer[i].id = oldPatient.id;

            _saveToFiles();

            return Status_ok;
        }
    }

    return Status_PatientNotFound;
}

Slots_t DATA_getReservations(void) {
    Slots_t slot;
    u32 i;

    for (i = 0; i < SLOT_LEN; i++) {
        strcpy(slot.time[i], time[i]);
        slot.slotisReserved[i] = (slotsArrBoolean[i] == 0) ? FALSE : TRUE;
        DATA_searchPatient(slotsArrId[i], slot.slot_reserveMan + i);
    }

    return slot;
}

DataApiStatus DATA_reserveSlot(Patient_t patient, u8 slotIndex) {
    if (slotIndex >= SLOT_LEN) {

        return Status_wrongSlotIndex;
    } else if (slotsArrBoolean[slotIndex] == 0) {
        slotsArrBoolean[slotIndex] = 1;
        slotsArrId[slotIndex] = patient.id;

        _saveToFiles();
        return Status_ok;
    } else {
        return Status_slotReserved;
    }
}

DataApiStatus DATA_cancelSlot( u8 slotIndex) {
    if (slotIndex < SLOT_LEN) {
        slotsArrBoolean[slotIndex] = 0;

        _saveToFiles();
        return Status_ok;
    } else {
        return Status_wrongSlotIndex;
    }
}