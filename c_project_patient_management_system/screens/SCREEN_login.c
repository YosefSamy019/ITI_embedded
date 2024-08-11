#include "navigator.h"
#include "../shared/delay_ms.h"
#include "../shared/STD_TYPES.h"
#include "../shared/input_output.h"

#include <stdio.h>
#include <stdlib.h>

SCREEN_DEFINE(SCREEN_login) {
    u32 select;

    printStringLn("Please select Mode: ", TextStyle_label);
    printStringLn("1 for admin", TextStyle_body);
    printStringLn("2 for user", TextStyle_body);
    printStringLn("0 to exit", TextStyle_body);
    printString("Your select: ", TextStyle_question);

    select = readInt();

    switch (select) {
    case 0: {
        exit(0);
        break;
    }
    case 1: {
        navigatorPush(SCREEN_adminMode_menu);
        break;
    }
    case 2: {
        navigatorPush(SCREEN_userMode_menu);
        break;
    }
    default: {
        printStringLn("Wrong input", TextStyle_error);
        waitKey();
        navigatorPushReplacement(SCREEN_login);
    }
    }
}