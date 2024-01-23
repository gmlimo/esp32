/*******************************************************************************
* File Name: DInput.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_DInput_H) /* Pins DInput_H */
#define CY_PINS_DInput_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DInput_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DInput__PORT == 15 && ((DInput__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DInput_Write(uint8 value);
void    DInput_SetDriveMode(uint8 mode);
uint8   DInput_ReadDataReg(void);
uint8   DInput_Read(void);
void    DInput_SetInterruptMode(uint16 position, uint16 mode);
uint8   DInput_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DInput_SetDriveMode() function.
     *  @{
     */
        #define DInput_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DInput_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DInput_DM_RES_UP          PIN_DM_RES_UP
        #define DInput_DM_RES_DWN         PIN_DM_RES_DWN
        #define DInput_DM_OD_LO           PIN_DM_OD_LO
        #define DInput_DM_OD_HI           PIN_DM_OD_HI
        #define DInput_DM_STRONG          PIN_DM_STRONG
        #define DInput_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DInput_MASK               DInput__MASK
#define DInput_SHIFT              DInput__SHIFT
#define DInput_WIDTH              4u

/* Interrupt constants */
#if defined(DInput__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DInput_SetInterruptMode() function.
     *  @{
     */
        #define DInput_INTR_NONE      (uint16)(0x0000u)
        #define DInput_INTR_RISING    (uint16)(0x0001u)
        #define DInput_INTR_FALLING   (uint16)(0x0002u)
        #define DInput_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DInput_INTR_MASK      (0x01u) 
#endif /* (DInput__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DInput_PS                     (* (reg8 *) DInput__PS)
/* Data Register */
#define DInput_DR                     (* (reg8 *) DInput__DR)
/* Port Number */
#define DInput_PRT_NUM                (* (reg8 *) DInput__PRT) 
/* Connect to Analog Globals */                                                  
#define DInput_AG                     (* (reg8 *) DInput__AG)                       
/* Analog MUX bux enable */
#define DInput_AMUX                   (* (reg8 *) DInput__AMUX) 
/* Bidirectional Enable */                                                        
#define DInput_BIE                    (* (reg8 *) DInput__BIE)
/* Bit-mask for Aliased Register Access */
#define DInput_BIT_MASK               (* (reg8 *) DInput__BIT_MASK)
/* Bypass Enable */
#define DInput_BYP                    (* (reg8 *) DInput__BYP)
/* Port wide control signals */                                                   
#define DInput_CTL                    (* (reg8 *) DInput__CTL)
/* Drive Modes */
#define DInput_DM0                    (* (reg8 *) DInput__DM0) 
#define DInput_DM1                    (* (reg8 *) DInput__DM1)
#define DInput_DM2                    (* (reg8 *) DInput__DM2) 
/* Input Buffer Disable Override */
#define DInput_INP_DIS                (* (reg8 *) DInput__INP_DIS)
/* LCD Common or Segment Drive */
#define DInput_LCD_COM_SEG            (* (reg8 *) DInput__LCD_COM_SEG)
/* Enable Segment LCD */
#define DInput_LCD_EN                 (* (reg8 *) DInput__LCD_EN)
/* Slew Rate Control */
#define DInput_SLW                    (* (reg8 *) DInput__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DInput_PRTDSI__CAPS_SEL       (* (reg8 *) DInput__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DInput_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DInput__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DInput_PRTDSI__OE_SEL0        (* (reg8 *) DInput__PRTDSI__OE_SEL0) 
#define DInput_PRTDSI__OE_SEL1        (* (reg8 *) DInput__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DInput_PRTDSI__OUT_SEL0       (* (reg8 *) DInput__PRTDSI__OUT_SEL0) 
#define DInput_PRTDSI__OUT_SEL1       (* (reg8 *) DInput__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DInput_PRTDSI__SYNC_OUT       (* (reg8 *) DInput__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DInput__SIO_CFG)
    #define DInput_SIO_HYST_EN        (* (reg8 *) DInput__SIO_HYST_EN)
    #define DInput_SIO_REG_HIFREQ     (* (reg8 *) DInput__SIO_REG_HIFREQ)
    #define DInput_SIO_CFG            (* (reg8 *) DInput__SIO_CFG)
    #define DInput_SIO_DIFF           (* (reg8 *) DInput__SIO_DIFF)
#endif /* (DInput__SIO_CFG) */

/* Interrupt Registers */
#if defined(DInput__INTSTAT)
    #define DInput_INTSTAT            (* (reg8 *) DInput__INTSTAT)
    #define DInput_SNAP               (* (reg8 *) DInput__SNAP)
    
	#define DInput_0_INTTYPE_REG 		(* (reg8 *) DInput__0__INTTYPE)
	#define DInput_1_INTTYPE_REG 		(* (reg8 *) DInput__1__INTTYPE)
	#define DInput_2_INTTYPE_REG 		(* (reg8 *) DInput__2__INTTYPE)
	#define DInput_3_INTTYPE_REG 		(* (reg8 *) DInput__3__INTTYPE)
#endif /* (DInput__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DInput_H */


/* [] END OF FILE */
