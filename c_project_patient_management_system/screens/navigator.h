//
// Created by asus on 2024-07-02.
//

#ifndef MAIN_C_NAVIGATOR_H
#define MAIN_C_NAVIGATOR_H

#define SCREEN_DEFINE(_screen_) void screen_##_screen_()
#define SCREEN(_screen_)  screen_##_screen_

enum Screens {
    SCREEN_splash,
    SCREEN_login,
    SCREEN_userMode_menu,
    SCREEN_adminMode_menu,
    SCREEN_user_view_patient_id,
    SCREEN_user_view_basic_reservation,
    SCREEN_admin_add_patient,
    SCREEN_admin_edit_patient,
    SCREEN_admin_reserve_slot,
    SCREEN_admin_cancel_reservation
};

//functions
void navigatorPush(enum Screens screen);

void navigatorPushReplacement(enum Screens screen);

void navigatorPop();

//screens

SCREEN_DEFINE(SCREEN_splash);

SCREEN_DEFINE(SCREEN_login);

SCREEN_DEFINE(SCREEN_userMode_menu);

SCREEN_DEFINE(SCREEN_adminMode_menu);

SCREEN_DEFINE(SCREEN_user_view_patient_id);

SCREEN_DEFINE(SCREEN_user_view_basic_reservation);

SCREEN_DEFINE(SCREEN_admin_add_patient);

SCREEN_DEFINE(SCREEN_admin_edit_patient);

SCREEN_DEFINE(SCREEN_admin_reserve_slot);

SCREEN_DEFINE(SCREEN_admin_cancel_reservation);

#endif //MAIN_C_NAVIGATOR_H
