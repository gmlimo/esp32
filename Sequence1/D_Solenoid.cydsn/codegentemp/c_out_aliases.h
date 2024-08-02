/*******************************************************************************
* File Name: c_out.h  
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

#if !defined(CY_PINS_c_out_ALIASES_H) /* Pins c_out_ALIASES_H */
#define CY_PINS_c_out_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define c_out_0			(c_out__0__PC)
#define c_out_0_INTR	((uint16)((uint16)0x0001u << c_out__0__SHIFT))

#define c_out_1			(c_out__1__PC)
#define c_out_1_INTR	((uint16)((uint16)0x0001u << c_out__1__SHIFT))

#define c_out_2			(c_out__2__PC)
#define c_out_2_INTR	((uint16)((uint16)0x0001u << c_out__2__SHIFT))

#define c_out_INTR_ALL	 ((uint16)(c_out_0_INTR| c_out_1_INTR| c_out_2_INTR))

#endif /* End Pins c_out_ALIASES_H */


/* [] END OF FILE */
