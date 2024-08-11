#include "navigator.h"
#include "../shared/delay_ms.h"
#include "../shared/STD_TYPES.h"
#include "../shared/input_output.h"
#include "../data_api/data_api.h"

SCREEN_DEFINE(SCREEN_user_view_patient_id) {
    u32 id;
    Patient_t patient;
    DataApiStatus status;

    printStringLn("Enter ID to search about", TextStyle_label);
    printString("ID: ", TextStyle_question);
    id = readInt();

    status = DATA_searchPatient(id, &patient);

    if (status == Status_ok) {
        printStringLn("The patient is found", TextStyle_body);
        
        printString("ID: ",TextStyle_label);
        printIntLn(patient.id,TextStyle_number);
        
        printString("1st Name: ", TextStyle_label);
        printStringLn(patient.firstName, TextStyle_body);

        printString("2nd Name: ", TextStyle_label);
        printStringLn(patient.lastName, TextStyle_body);

        printString("Age: ",TextStyle_label);
        printIntLn(patient.age,TextStyle_number);
        
        printString("Gender: ",TextStyle_label);
        printStringLn((patient.gender == male ? "Male" : "Female"),TextStyle_body);
        

    } else {
        printStringLn("The patient is not found", TextStyle_error);
      
    }
    
    printStringLn("Enter 1 refresh screen, otherwise to return", TextStyle_label);
    printString("Select: ", TextStyle_question);
    if(readInt() == 1){
        navigatorPushReplacement(SCREEN_user_view_patient_id);
    }else{
        navigatorPop();
    }

}