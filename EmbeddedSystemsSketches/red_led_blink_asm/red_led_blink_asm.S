;-----------------------
; ASSEMBLY CODE
;-----------------------
#define __SFR_OFFSET 0x20
#include "avr/io.h"
;-----------------------
.global start
.global led
;-----------------------
start:
  SBI DDRB,4   ;set PB5(D12) as o/p
  RET          ;return to setup() function
;---------------------------------------------------
led:
  CPI R24, 0  ;value passed by caller in R24 compared with 0
  BREQ ledOFF    ;jump (branch) if equal to subroutine ledOFF
  SBI PORTB, 4   ;set D12 high
  RCALL myDelay
  RET            ;return to loop() function
;---------------------------------------------------
ledOFF:
  CBI PORTB, 4   ;set D12 to low
  RCALL myDelay
  RET
;---------------------------------------------------
.equ delayVal, 10000
;---------------------------------------------------
myDelay:
  LDI R20, 100
outerLoop:
  LDI R30, lo8(delayVal) ;low byte of delayVal in R30
  LDI R31, hi8(delayVal) ;high byte of delayVal in R31
innerLoop:
  SBIW R30, 1            ;subtract 1 from 16-bit value in R31
