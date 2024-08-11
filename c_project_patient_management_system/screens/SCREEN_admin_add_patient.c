

#include "navigator.h"
#include "../shared/delay_ms.h"
#include "../shared/STD_TYPES.h"
#include "../shared/input_output.h"
#include "../data_api/data_api.h"

SCREEN_DEFINE(SCREEN_admin_add_patient) {
    Patient_t newP;
    u32 temp;

    printString("Enter First Name: ", TextStyle_label);
    readString(newP.firstName);

    printString("Enter Last Name: ", TextStyle_label);
    readString(newP.lastName);

    printString("Enter Age: ", TextStyle_label);
    newP.age = readInt();

    printString("Select Male (0: male, otherwise: female): ", TextStyle_label);
    temp = readInt();
    if (temp == 0) {
        newP.gender = male;
    } else {
        newP.gender = female;
    }

    u32 newID;
    DataApiStatus status = DATA_addPatient(newP,&newID);

    if (status == Status_ok) {
        printStringLn("\nThe patient is added successfully", TextStyle_body);
        printString("Registered with ID: ",TextStyle_body);
        printIntLn(newID,TextStyle_number);
    } else {
        printStringLn("\nThe patient is not added successfully", TextStyle_error);
    }
    
    printStringLn("\nEnter 1 refresh screen, otherwise to return", TextStyle_label);
    printString("Select: ", TextStyle_question);
    if (readInt() == 1) {
        navigatorPushReplacement(SCREEN_admin_add_patient);
    } else {
        navigatorPop();
    }
}