
#define SET_BIT(num,bit) ((num)|= (1u<<(bit)))
#define TOG_BIT(num,bit) ((num)^= (1u<<(bit))) 
#define CLR_BIT(num,bit) ((num)&= ~(1u<<(bit))) 
#define GET_BIT(num,bit) (((num)>>(bit))&0x01) 

#define DDRA  *((volatile unsigned char*)0x3A)
#define PORTA *((volatile unsigned char*)0x3B)

int max;

int main(void){
    max = 10000;
    volatile unsigned int i;
    
    SET_BIT(DDRA,0);
    SET_BIT(PORTA,0);
    
    while (1){
        TOG_BIT(PORTA,0);
        for (i=0;i<max;i++);
    }
}