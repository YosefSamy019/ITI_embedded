#include "navigator.h"
#include "../shared/delay_ms.h"
#include "../shared/STD_TYPES.h"
#include "../shared/input_output.h"

SCREEN_DEFINE(SCREEN_splash){
    
    printString("Name:\t\t",TextStyle_label);
    printString("Youssef Samy Youssef \n",TextStyle_body);

    printString("Phone:\t\t",TextStyle_label);
    printString("+201030296141 \n",TextStyle_number);
  
    printString("Project:\t",TextStyle_label);
    printString("Patient Management system \n",TextStyle_body);
    
    printString("Supervisor:\t",TextStyle_label);
    printString("ITI Benha \n",TextStyle_body);
    
    printString("Instructors:\t",TextStyle_label);
    printString("Eng. Mohammed Ramadan",TextStyle_body);    
    printString(", Eng. Ahmed Samy\n",TextStyle_body);    

    waitKey();
    
    navigatorPush(SCREEN_login);
}