

#include "navigator.h"
#include "../shared/delay_ms.h"
#include "../shared/STD_TYPES.h"
#include "../shared/input_output.h"
#include "../data_api/data_api.h"


SCREEN_DEFINE(SCREEN_admin_edit_patient) {
    Patient_t patient, tempPatient;
    u32 id;
    DataApiStatus status;

    printStringLn("Enter ID to searh about", TextStyle_label);
    printString("ID: ", TextStyle_question);
    id = readInt();



    status = DATA_searchPatient(id, &patient);
    tempPatient = patient;

    if (status == Status_ok) {
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


    } else {
        printStringLn("The patient is not found", TextStyle_error);
        waitKey();
        navigatorPop();
        return;
    }

    printStringLn("Please your choice: ", TextStyle_label);
    printString(" 1 ", TextStyle_number);
    printStringLn("to edit first name ", TextStyle_body);

    printString(" 2 ", TextStyle_number);
    printStringLn("to edit last name ", TextStyle_body);

    printString(" 3 ", TextStyle_number);
    printStringLn("to edit age ", TextStyle_body);

    printString(" 4 ", TextStyle_number);
    printStringLn("to edit gender ", TextStyle_body);

    printString(" 0 ", TextStyle_number);
    printStringLn("to return screen ", TextStyle_body);
    
    printString("Your select: ", TextStyle_question);

    u32 temp;
    u32 slct = readInt();

    switch (slct) {
    case 0: {
        navigatorPop();
        return;
        break;
    }
    case 1: {
        printString("Enter First Name: ", TextStyle_question);
        readString(tempPatient.firstName);

        break;
    }
    case 2: {
        printString("Enter Last Name: ", TextStyle_question);
        readString(tempPatient.lastName);
        break;
    }
    case 3: {
        printString("Enter Age: ", TextStyle_question);
        tempPatient.age = readInt();
        break;
    }
    case 4: {
        printString("Select Male (0: male, otherwise: female): ", TextStyle_question);
        temp = readInt();
        if (temp == 0) {
            tempPatient.gender = male;
        } else {
            tempPatient.gender = female;
        }
        break;
    }
    }

    status = DATA_editPatient(patient, tempPatient);
    if (Status_ok == status) {
        printStringLn("The patient is updated successfully", TextStyle_body);
    } else {
        printStringLn("The patient is not updated successfully", TextStyle_error);
    }

    printStringLn("Enter 1 refresh screen, otherwise to return", TextStyle_label);
    printString("Select: ", TextStyle_question);
    if (readInt() == 1) {
        navigatorPushReplacement(SCREEN_admin_edit_patient);
    } else {
        navigatorPop();
    }
}