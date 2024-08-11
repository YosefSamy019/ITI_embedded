#include "navigator.h"
#include "../shared/delay_ms.h"
#include "../shared/STD_TYPES.h"
#include "../shared/input_output.h"


SCREEN_DEFINE(SCREEN_userMode_menu) {
    u32 select;

    printStringLn("Please your choice: ", TextStyle_label);
    printStringLn("1 to view patient data", TextStyle_body);
    printStringLn("2 to view reservation", TextStyle_body);
    printStringLn("0 to return screen", TextStyle_body);

    printString("Your select: ", TextStyle_question);

    select = readInt();

    switch (select) {
    case 0: {
        navigatorPop();
        break;
    }
    case 1: {
        navigatorPush(SCREEN_user_view_patient_id);
        break;
    }
    case 2: {
        navigatorPush(SCREEN_user_view_basic_reservation);
        break;
    }
    default: {
        printStringLn("Wrong input", TextStyle_error);
        waitKey();
        navigatorPushReplacement(SCREEN_userMode_menu);
    }
    }
}