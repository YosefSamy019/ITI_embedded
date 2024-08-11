
#include "navigator.h"
#include "../shared/delay_ms.h"
#include "../shared/STD_TYPES.h"
#include "../shared/input_output.h"
#include "../data_api/data_api.h"


SCREEN_DEFINE(SCREEN_admin_reserve_slot) {
    Patient_t patient;
    u32 id,i;
    DataApiStatus status;
    Slots_t slots;

    printStringLn("Enter ID to reserve slot about", TextStyle_label);
    printString("ID: ", TextStyle_question);
    id = readInt();

    status = DATA_searchPatient(id, &patient);

    if (status != Status_ok) {
        printStringLn("The patient is not found", TextStyle_error);
        
        
        printStringLn("Enter 1 refresh screen, otherwise to return", TextStyle_label);
        printString("Select: ", TextStyle_question);
        if (readInt() == 1) {
            navigatorPushReplacement(SCREEN_admin_reserve_slot);
        } else {
            navigatorPop();
        }
        
        return;
    } else {
        printStringLn("The patient is found", TextStyle_body);

        printString("ID: ", TextStyle_label);
        printIntLn(patient.id, TextStyle_number);

        printString("1st Name: ", TextStyle_label);
        printStringLn(patient.firstName, TextStyle_body);

        printString("2nd Name: ", TextStyle_label);
        printStringLn(patient.lastName, TextStyle_body);

        printString("Age: ", TextStyle_label);
        printIntLn(patient.age, TextStyle_number);

        printString("Gender: ", TextStyle_label);
        printStringLn((patient.gender == male ? "Male" : "Female"), TextStyle_body);
        
        
        slots = DATA_getReservations();

        printStringLn("\n\n-----------------------------------------------------------", TextStyle_label);
        printStringLn("Time\t\tID\t\tName\t\t", TextStyle_label);
        printStringLn("-----------------------------------------------------------", TextStyle_label);

        for (i = 0; i < 5; i++) {
            printString(slots.time[i], TextStyle_number);

            if (slots.slotisReserved[i] == TRUE) {
                printString("\t", TextStyle_body);
                printInt(slots.slot_reserveMan[i].id, TextStyle_body);
                printString("\t\t", TextStyle_body);
                printString(slots.slot_reserveMan[i].firstName, TextStyle_body);
                printString(" ", TextStyle_body);
                printString(slots.slot_reserveMan[i].lastName, TextStyle_body);
            } else {
                printString("\tFree to reserve", TextStyle_body);
            }

            printStringLn("", TextStyle_body);
        }
        printStringLn("-----------------------------------------------------------\n\n", TextStyle_label);

        printString("Enter slot index to reserve (0 -> 4): ", TextStyle_question);
        u32 slotIndex = readInt();
        
        status =  DATA_reserveSlot(patient,slotIndex);
        
        if(status == Status_ok){
            printStringLn("The slot is reserved successfully",TextStyle_body);
        }else{
            printStringLn("The slot is not reserved successfully",TextStyle_error);
        }
        
        printStringLn("Enter 1 refresh screen, otherwise to return", TextStyle_label);
        printString("Select: ", TextStyle_question);
        if (readInt() == 1) {
            navigatorPushReplacement(SCREEN_admin_reserve_slot);
        } else {
            navigatorPop();
        }
    }
}