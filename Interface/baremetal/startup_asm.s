
.equ PTR_STACK_H, 0x003E  
.equ PTR_STACK_L, 0x003D

.equ _STACK_TOP, 0x085F 

.section .vectors
vectors:
    rjmp _reset
    rjmp INT0_vect
    rjmp INT1_vect
    rjmp Timer2_comp_vect
    rjmp Timer2_ovf_vect
    rjmp Timer1_capt_vect
    rjmp Timer1_compA_vect
    rjmp Timer1_compB_vect
    rjmp Timer1_ovf_vect
    rjmp Timer0_ovf_vect
    rjmp SPI_STC_vect
    rjmp USART_RXC_vect
    rjmp USART_UDRE_vect
    rjmp USART_TXC_vect
    rjmp ADC_vect
    rjmp EE_RDY_vect
    rjmp ANA_COMP_vect
    rjmp ANA_COMP_vect
    rjmp ANA_COMP_vect

.section .text
.global _reset
_reset:

    ldi r16, ((_STACK_TOP>>8) & 0x00ff)
    out PTR_STACK_H, r16
    
    ldi r16, (_STACK_TOP & 0x00ff)
    out PTR_STACK_L, r16

    rjmp _startup_c


INT0_vect:
    reti
INT1_vect:
    reti
Timer2_comp_vect:
    reti
Timer2_ovf_vect:
    reti
Timer1_capt_vect:
    reti
Timer1_compA_vect:
    reti
Timer1_compB_vect:
    reti
Timer1_ovf_vect:
    reti
Timer0_ovf_vect:
    reti
SPI_STC_vect:
    reti
USART_RXC_vect:
    reti
USART_UDRE_vect:
    reti
USART_TXC_vect:
    reti
ADC_vect:
    reti
EE_RDY_vect:
    reti
ANA_COMP_vect:
    reti
TWI_vect:
    reti
SPM_RDY_vect:
    reti