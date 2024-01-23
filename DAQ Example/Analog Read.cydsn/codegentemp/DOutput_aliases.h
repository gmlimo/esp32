/*******************************************************************************
* File Name: DOutput.h  
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

#if !defined(CY_PINS_DOutput_ALIASES_H) /* Pins DOutput_ALIASES_H */
#define CY_PINS_DOutput_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define DOutput_0			(DOutput__0__PC)
#define DOutput_0_INTR	((uint16)((uint16)0x0001u << DOutput__0__SHIFT))

#define DOutput_1			(DOutput__1__PC)
#define DOutput_1_INTR	((uint16)((uint16)0x0001u << DOutput__1__SHIFT))

#define DOutput_2			(DOutput__2__PC)
#define DOutput_2_INTR	((uint16)((uint16)0x0001u << DOutput__2__SHIFT))

#define DOutput_3			(DOutput__3__PC)
#define DOutput_3_INTR	((uint16)((uint16)0x0001u << DOutput__3__SHIFT))

#define DOutput_INTR_ALL	 ((uint16)(DOutput_0_INTR| DOutput_1_INTR| DOutput_2_INTR| DOutput_3_INTR))

#endif /* End Pins DOutput_ALIASES_H */


/* [] END OF FILE */
