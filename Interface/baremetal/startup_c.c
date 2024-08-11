#include <avr/pgmspace.h>

#define U8 unsigned char

int main(void);
void _startup_c(void);

static void _init_bss(void);
static void _init_data(void);

void _startup_c(void){
    _init_data();
    _init_bss();

    main();
    
    while ((volatile U8)1);
}

static void _init_data(void){
    //copy data to ram
    extern  U8 _RODATA_END;
    extern  U8 _DATA_START;
    extern  U8 _DATA_END;
    
    U8 *ptrSource = &_RODATA_END;
    U8 *ptrDestination = &_DATA_START;
    
    unsigned int dataLength = (U8*)(&_DATA_END) - (U8*)(&_DATA_START);
    unsigned int i;
    
    for (i=0;i<dataLength;i++){
        *ptrDestination =(U8) pgm_read_byte(ptrSource);
        
        ptrSource++;
        ptrDestination++;
    }
    
}

static void _init_bss(void){
    //init bss
    extern  U8 _BSS_START;
    extern  U8 _BSS_END;
    
    U8 *ptrDestination = &_BSS_START;
    
    unsigned int bssLength = (U8*)(&_BSS_END) - (U8*)(&_BSS_START);
    
    unsigned int i;
    
    for (i=0;i<bssLength;i++){
        *ptrDestination = (U8)10;
        ptrDestination++;
    }
    
}