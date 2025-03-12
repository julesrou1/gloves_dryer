/**
 * Generated Driver File
 * 
 * @file pins.c
 * 
 * @ingroup  pinsdriver
 * 
 * @brief This is generated driver implementation for pins. 
 *        This file provides implementations for pin APIs for all pins selected in the GUI.
 *
 * @version Driver Version 3.0.0
*/

/*
� [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#include "../pins.h"

void (*IO_RC5_InterruptHandler)(void);

void PIN_MANAGER_Initialize(void)
{
   /**
    LATx registers
    */
    LATA = 0x0;
    LATC = 0x4;

    /**
    TRISx registers
    */
    TRISA = 0x37;
    TRISC = 0x30;

    /**
    ANSELx registers
    */
    ANSELA = 0x37;
    ANSELC = 0x10;

    /**
    WPUx registers
    */
    WPUA = 0x0;
    WPUC = 0x0;
  
    /**
    ODx registers
    */
   
    ODCONA = 0x0;
    ODCONC = 0x0;
    /**
    SLRCONx registers
    */
    SLRCONA = 0x37;
    SLRCONC = 0x3F;
    /**
    INLVLx registers
    */
    INLVLA = 0x3F;
    INLVLC = 0x3F;

    /**
    PPS registers
    */
    INTPPS = 0x15; //RC5->INTERRUPT MANAGER:INT;

    /**
    APFCON registers
    */

   /**
    IOCx registers 
    */
    IOCAP = 0x0;
    IOCAN = 0x0;
    IOCAF = 0x0;
    IOCCP = 0x20;
    IOCCN = 0x0;
    IOCCF = 0x0;

    IO_RC5_SetInterruptHandler(IO_RC5_DefaultInterruptHandler);

    // Enable PIE0bits.IOCIE interrupt 
    PIE0bits.IOCIE = 1; 
}
  
void PIN_MANAGER_IOC(void)
{
    // interrupt on change for pin IO_RC5}
    if(IOCCFbits.IOCCF5 == 1)
    {
        IO_RC5_ISR();  
    }
}
   
/**
   IO_RC5 Interrupt Service Routine
*/
void IO_RC5_ISR(void) {

    // Add custom IOCCF5 code

    // Call the interrupt handler for the callback registered at runtime
    if(IO_RC5_InterruptHandler)
    {
        IO_RC5_InterruptHandler();
    }
    IOCCFbits.IOCCF5 = 0;
}

/**
  Allows selecting an interrupt handler for IOCCF5 at application runtime
*/
void IO_RC5_SetInterruptHandler(void (* InterruptHandler)(void)){
    IO_RC5_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCCF5
*/
void IO_RC5_DefaultInterruptHandler(void){
    // add your IO_RC5 interrupt custom code
    // or set custom function using IO_RC5_SetInterruptHandler()
}
/**
 End of File
*/