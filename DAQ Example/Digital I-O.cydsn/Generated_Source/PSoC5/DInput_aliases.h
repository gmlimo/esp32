/*******************************************************************************
* File Name: DInput.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_DInput_ALIASES_H) /* Pins DInput_ALIASES_H */
#define CY_PINS_DInput_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define DInput_0			(DInput__0__PC)
#define DInput_0_INTR	((uint16)((uint16)0x0001u << DInput__0__SHIFT))

#define DInput_1			(DInput__1__PC)
#define DInput_1_INTR	((uint16)((uint16)0x0001u << DInput__1__SHIFT))

#define DInput_2			(DInput__2__PC)
#define DInput_2_INTR	((uint16)((uint16)0x0001u << DInput__2__SHIFT))

#define DInput_3			(DInput__3__PC)
#define DInput_3_INTR	((uint16)((uint16)0x0001u << DInput__3__SHIFT))

#define DInput_INTR_ALL	 ((uint16)(DInput_0_INTR| DInput_1_INTR| DInput_2_INTR| DInput_3_INTR))

#endif /* End Pins DInput_ALIASES_H */


/* [] END OF FILE */
