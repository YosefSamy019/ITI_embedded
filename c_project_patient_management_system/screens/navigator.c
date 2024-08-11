//
// Created by asus on 2024-07-02.
//

#include <stdlib.h>
#include "navigator.h"
#include "../shared/input_output.h"
#include "../shared/debug.h"
#include "../shared/input_output.h"


void (*(screenPtrStack[10]))();

enum Screens screensStack[10];

static char count = 0;

static void printScreen(enum Screens screen, TextStyle textStyle) {
    switch (screen) {
    case SCREEN_splash: {
        printString("Splash", textStyle);
        break;
    }
    case SCREEN_login: {
        printString("Login", textStyle);

        break;
    }
    case SCREEN_userMode_menu: {
        printString("User mode menu", textStyle);


        break;
    }
    case SCREEN_adminMode_menu: {
        printString("Admin mode menu", textStyle);

        break;
    }
    case SCREEN_user_view_patient_id: {
        printString("View patient data", textStyle);

        break;
    }
    case SCREEN_user_view_basic_reservation: {
        printString("View reservation", textStyle);

        break;
    }
    case SCREEN_admin_add_patient: {
        printString("Add patient", textStyle);

        break;
    }
    case SCREEN_admin_edit_patient: {
        printString("Edit patient", textStyle);

        break;
    }
    case SCREEN_admin_reserve_slot: {
        printString("Reserve Slot", textStyle);

        break;
    }
    case SCREEN_admin_cancel_reservation: {
        printString("Cancel reservation", textStyle);

        break;
    }
    default:
        return;
    }
}

static void printHeader() {
    if (count == 0)
        return;
    int i;

    printStringLn("\n---------------------------------------------------", TextStyle_header);

    printString("|\tPATH: ", TextStyle_header);
    for (i = 0; i < count; ++i) {
        printString(" > ", TextStyle_header);
        printScreen(screensStack[i], TextStyle_header);
    }

    printStringLn("\n---------------------------------------------------\n", TextStyle_header);
}

void navigatorPush(enum Screens screen) {


    if (count >= 5) {
        PRINT_DEBUG("Screen Stack is full", 0);
    } else {
        screensStack[count] = screen;

        switch (screen) {
        case SCREEN_splash: {
            screenPtrStack[count] = SCREEN(SCREEN_splash);
            break;
        }
        case SCREEN_login: {
            screenPtrStack[count] = SCREEN(SCREEN_login);
            break;
        }
        case SCREEN_userMode_menu: {
            screenPtrStack[count] = SCREEN(SCREEN_userMode_menu);

            break;
        }
        case SCREEN_adminMode_menu: {
            screenPtrStack[count] = SCREEN(SCREEN_adminMode_menu);
            break;
        }
        case SCREEN_user_view_patient_id: {
            screenPtrStack[count] = SCREEN(SCREEN_user_view_patient_id);
            break;
        }
        case SCREEN_user_view_basic_reservation: {
            screenPtrStack[count] = SCREEN(SCREEN_user_view_basic_reservation);
            break;
        }
        case SCREEN_admin_add_patient: {
            screenPtrStack[count] = SCREEN(SCREEN_admin_add_patient);
            break;
        }
        case SCREEN_admin_edit_patient: {
            screenPtrStack[count] = SCREEN(SCREEN_admin_edit_patient);
            break;
        }
        case SCREEN_admin_reserve_slot: {
            screenPtrStack[count] = SCREEN(SCREEN_admin_reserve_slot);
            break;
        }
        case SCREEN_admin_cancel_reservation: {
            screenPtrStack[count] = SCREEN(SCREEN_admin_cancel_reservation);
            break;
        }
        default:
            return;
        }
        //clear old console

        system("cls");
        count++;

        //call screen
        printHeader();

        PRINT_DEBUG("call screen: %d", screen);

        screenPtrStack[count - 1]();
    }
}

void navigatorPushReplacement(enum Screens screen) {
    if (count == 0) {
        PRINT_DEBUG("Screen Stack is empty", 0);
    } else {
        screensStack[count - 1] = screen;

        switch (screen) {
        case SCREEN_splash: {
            screenPtrStack[count - 1] = SCREEN(SCREEN_splash);
            break;
        }
        case SCREEN_login: {
            screenPtrStack[count - 1] = SCREEN(SCREEN_login);
            break;
        }
        case SCREEN_userMode_menu: {
            screenPtrStack[count - 1] = SCREEN(SCREEN_userMode_menu);

            break;
        }
        case SCREEN_adminMode_menu: {
            screenPtrStack[count - 1] = SCREEN(SCREEN_adminMode_menu);
            break;
        }
        case SCREEN_user_view_patient_id: {
            screenPtrStack[count - 1] = SCREEN(SCREEN_user_view_patient_id);
            break;
        }
        case SCREEN_user_view_basic_reservation: {
            screenPtrStack[count - 1] = SCREEN(SCREEN_user_view_basic_reservation);
            break;
        }
        case SCREEN_admin_add_patient: {
            screenPtrStack[count - 1] = SCREEN(SCREEN_admin_add_patient);
            break;
        }
        case SCREEN_admin_edit_patient: {
            screenPtrStack[count - 1] = SCREEN(SCREEN_admin_edit_patient);
            break;
        }
        case SCREEN_admin_reserve_slot: {
            screenPtrStack[count] = SCREEN(SCREEN_admin_reserve_slot);
            break;
        }
        case SCREEN_admin_cancel_reservation: {
            screenPtrStack[count] = SCREEN(SCREEN_admin_cancel_reservation);
            break;
        }
        default:
            return;
        }
        //clear old console

        system("cls");

        //call screen
        printHeader();

        PRINT_DEBUG("call screen: %d", screen);

        screenPtrStack[count - 1]();
    }
}


void navigatorPop() {
    if (count == 0) {
        PRINT_DEBUG("Screen Stack is empty", 0);
    } else {
        //clear old console
        system("cls");

        count--;


        //call screen
        printHeader();
        PRINT_DEBUG("pop from previous screen: %d", 0);

        screenPtrStack[count - 1]();
    }
}
