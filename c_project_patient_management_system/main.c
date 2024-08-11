#include <stdio.h>
#include <string.h>

#include "shared/STD_TYPES.h"
#include "file_handler/file_handler.h"
#include "data_api/data_api.h"
#include <screens/navigator.h>


void main(void){
    DATA_init();
    navigatorPush(SCREEN_splash);

}