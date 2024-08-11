
#include "navigator.h"
#include "../shared/delay_ms.h"
#include "../shared/STD_TYPES.h"
#include "../shared/input_output.h"
#include "../data_api/data_api.h"

SCREEN_DEFINE(SCREEN_admin_cancel_reservation) {
    u32 id, i;
    DataApiStatus status;
    Slots_t slots;



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


    printString("Enter slot index to cancel (0 -> 4): ", TextStyle_question);
    u32 slotIndex = readInt();

    status = DATA_cancelSlot(slotIndex);

    if (status == Status_ok) {
        printStringLn("The slot is canceled successfully", TextStyle_body);
    } else {
        printStringLn("The slot is not canceled successfully", TextStyle_error);
    }

    printStringLn("Enter 1 refresh screen, otherwise to return", TextStyle_label);
    printString("Select: ", TextStyle_question);
    if (readInt() == 1) {
        navigatorPushReplacement(SCREEN_admin_cancel_reservation);
    } else {
        navigatorPop();
    }
}