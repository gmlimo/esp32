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

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    UART_Start();
    int inputs = 0;
    int data = 0;
    //int buffer[4];

    while (1)
    {    reread: UART_ClearRxBuffer();
    //UART_ClearTxBuffer();
    
        if(UART_ReadRxStatus() == 0)
    {
        data = UART_ReadRxData();
    }
    
       if(data == 'r')
       {
           ack_Write(0);
           goto read;
       }
      
       if(data == '0')
       {
          ack_Write(1);
          DOutput_Write(0x0);
          goto reread;
       }
       if(data == '1')
       {
          ack_Write(1);
          DOutput_Write(0x1);
          goto reread;
       }
       if(data == '2')
       {
          ack_Write(1);
          DOutput_Write(0x2);
          goto reread;
       }
       if(data == '3')
       {
          ack_Write(1);
          DOutput_Write(0x3);
          goto reread;
       }
       if(data == '4')
       {
          ack_Write(1);
          DOutput_Write(0x4);
          goto reread;
       }
       if(data == '5')
       {
          ack_Write(1);
          DOutput_Write(0x5);
          goto reread;
       }
       if(data == '6')
       {
          ack_Write(1);
          DOutput_Write(0x6);
          goto reread;
       }
       if(data == '7')
       {
          ack_Write(1);
          DOutput_Write(0x7);
          goto reread;
       }
       if(data == '8')
       {
          ack_Write(1);
          DOutput_Write(0x8);
          goto reread;
       }
       if(data == '9')
       {
          ack_Write(1);
          DOutput_Write(0x9);
          goto reread;
       }
       if(data == 'A')
       {
          ack_Write(1);
          DOutput_Write(0xA);
          goto reread;
       }
       if(data == 'B')
       {
          ack_Write(1);
          DOutput_Write(0xB);
          goto reread;
       }
       if(data == 'C')
       {
          ack_Write(1);
          DOutput_Write(0xC);
          goto reread;
       }
       if(data == 'D')
       {
          ack_Write(1);
          DOutput_Write(0xD);
          goto reread;
       }
       if(data == 'E')
       {
          ack_Write(1);
          DOutput_Write(0xE);
          goto reread;
       }
       if(data == 'F')
       {
          ack_Write(1);
          DOutput_Write(0xF);
          goto reread;
       }
    else
    {
        ack_Write(0);
        UART_PutString("nan1");
    }
     
    goto reread;
        CyDelay(200); 
    
   read:    inputs = DInput_Read();
       
       if(inputs == 0x0)
       {
          UART_PutChar('0');
          goto reread;
       }
       if(inputs == 0x1)
       {
          UART_PutChar('1');
          goto reread;
       }
       if(inputs == 0x2)
       {
          UART_PutChar('2');
          goto reread;
       }
       if(inputs == 0x3)
       {
          UART_PutChar('3');
          goto reread;
       }
       if(inputs == 0x4)
       {
          UART_PutChar('4');
          goto reread;
       }
       if(inputs == 0x5)
       {
          UART_PutChar('5');
          goto reread;
       }
       if(inputs == 0x6)
       {
          UART_PutChar('6');
          goto reread;
       }
       if(inputs == 0x7)
       {
          UART_PutChar('7');
          goto reread;
       }
       if(inputs == 0x8)
       {
          UART_PutChar('8');
          goto reread;
       }
       if(inputs == 0x9)
       {
          UART_PutChar('9');
          goto reread;
       }
       if(inputs == 0xA)
       {
          UART_PutChar('A');
          goto reread;
       }
       if(inputs == 0xB)
       {
          UART_PutChar('B');
          goto reread;
       }
       if(inputs == 0xC)
       {
          UART_PutChar('C');
          goto reread;
       }
       if(inputs == 0xD)
       {
          UART_PutChar('D');
          goto reread;
       }
       if(inputs == 0xE)
       {
          UART_PutChar('E');
          goto reread;
       }
       if(inputs == 0xF)
       {
          UART_PutChar('F');
          goto reread;
       }
      
    CyDelay(200);
    
    }
    return 0;
}

/* [] END OF FILE */
