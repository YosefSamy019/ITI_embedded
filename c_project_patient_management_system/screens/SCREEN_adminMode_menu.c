#include "navigator.h"
#include "../shared/delay_ms.h"
#include "../shared/STD_TYPES.h"
#include "../shared/input_output.h"

#define PASS 1234UL

SCREEN_DEFINE(SCREEN_adminMode_menu) {
    u32 select;
    u32 password;
    u8 trials = 0;

    do {
        printString("Please enter Passwaord: ", TextStyle_label);
        password = readInt();

        if (PASS != password) {
            printStringLn("Wrong password", TextStyle_error);
            trials++;
        }

    } while (password != PASS && trials < 3);

    if (trials >= 3) {
        navigatorPop();
    } else {
        printStringLn("Correct Password",TextStyle_number);
        
        printString(" 1 ",TextStyle_number);
        printStringLn("to add patient ", TextStyle_body);
        
        printString(" 2 ",TextStyle_number);
        printStringLn("to edit patient ", TextStyle_body);
        
        printString(" 3 ",TextStyle_number);
        printStringLn("to reserve slot ", TextStyle_body);
        
        printString(" 4 ",TextStyle_number);
        printStringLn("to cancel slot ", TextStyle_body);
        
        printString(" 0 ",TextStyle_number);
        printStringLn("to return screen ", TextStyle_body);
        
        printString("Your select: ", TextStyle_question);

        select = readInt();

        switch (select) {
        case 0: {
            navigatorPop();
            break;
        }
        case 1: {
            navigatorPush(SCREEN_admin_add_patient);
            break;
        }
        case 2: {
            navigatorPush(SCREEN_admin_edit_patient);
            break;
        }
        case 3: {
            navigatorPush(SCREEN_admin_reserve_slot);
            break;
        }
        case 4: {
            navigatorPush(SCREEN_admin_cancel_reservation);
            break;
        }
        default: {
            printStringLn("Wrong input", TextStyle_error);
            waitKey();
            navigatorPushReplacement(SCREEN_adminMode_menu);
        }
        }
    }
}