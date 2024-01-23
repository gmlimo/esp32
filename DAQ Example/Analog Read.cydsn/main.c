/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "stdio.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    UART_Start();
    ADC_Start();
    int tx_data = 0;
    int rx_data = 0;
    int result = 0;
    char string[8];
    

    while (1)
    {
 read:           
     ADC_StartConvert();
     ADC_IsEndConversion( ADC_WAIT_FOR_RESULT );
     tx_data=ADC_GetResult16();
     result=ADC_CountsTo_mVolts( tx_data );
     sprintf(string, "%d", result);
     UART_PutChar('a');
     UART_PutString( string );
     UART_PutCRLF( ' ' );
     CyDelay( 200 ); 

    UART_ClearRxBuffer();
    if(UART_ReadRxStatus() == 0u)
        {
           rx_data = UART_ReadRxData();
        }
        if(rx_data == 'e')
        {
            ack_Write( 1u );
            no_rx_Write( 1u );
            goto read;
        }
        if(rx_data == 'n')
        {
            ack_Write( 0u );
            no_rx_Write( 1u );
            goto read;
        }
        else
        {
            no_rx_Write( 0u );
        }
    
    }
    return 0;
}

/* [] END OF FILE */
