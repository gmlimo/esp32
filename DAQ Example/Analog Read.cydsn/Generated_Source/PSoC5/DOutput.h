/*******************************************************************************
* File Name: DOutput.h  
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

#if !defined(CY_PINS_DOutput_H) /* Pins DOutput_H */
#define CY_PINS_DOutput_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DOutput_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DOutput__PORT == 15 && ((DOutput__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DOutput_Write(uint8 value);
void    DOutput_SetDriveMode(uint8 mode);
uint8   DOutput_ReadDataReg(void);
uint8   DOutput_Read(void);
void    DOutput_SetInterruptMode(uint16 position, uint16 mode);
uint8   DOutput_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DOutput_SetDriveMode() function.
     *  @{
     */
        #define DOutput_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DOutput_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DOutput_DM_RES_UP          PIN_DM_RES_UP
        #define DOutput_DM_RES_DWN         PIN_DM_RES_DWN
        #define DOutput_DM_OD_LO           PIN_DM_OD_LO
        #define DOutput_DM_OD_HI           PIN_DM_OD_HI
        #define DOutput_DM_STRONG          PIN_DM_STRONG
        #define DOutput_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DOutput_MASK               DOutput__MASK
#define DOutput_SHIFT              DOutput__SHIFT
#define DOutput_WIDTH              4u

/* Interrupt constants */
#if defined(DOutput__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DOutput_SetInterruptMode() function.
     *  @{
     */
        #define DOutput_INTR_NONE      (uint16)(0x0000u)
        #define DOutput_INTR_RISING    (uint16)(0x0001u)
        #define DOutput_INTR_FALLING   (uint16)(0x0002u)
        #define DOutput_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DOutput_INTR_MASK      (0x01u) 
#endif /* (DOutput__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DOutput_PS                     (* (reg8 *) DOutput__PS)
/* Data Register */
#define DOutput_DR                     (* (reg8 *) DOutput__DR)
/* Port Number */
#define DOutput_PRT_NUM                (* (reg8 *) DOutput__PRT) 
/* Connect to Analog Globals */                                                  
#define DOutput_AG                     (* (reg8 *) DOutput__AG)                       
/* Analog MUX bux enable */
#define DOutput_AMUX                   (* (reg8 *) DOutput__AMUX) 
/* Bidirectional Enable */                                                        
#define DOutput_BIE                    (* (reg8 *) DOutput__BIE)
/* Bit-mask for Aliased Register Access */
#define DOutput_BIT_MASK               (* (reg8 *) DOutput__BIT_MASK)
/* Bypass Enable */
#define DOutput_BYP                    (* (reg8 *) DOutput__BYP)
/* Port wide control signals */                                                   
#define DOutput_CTL                    (* (reg8 *) DOutput__CTL)
/* Drive Modes */
#define DOutput_DM0                    (* (reg8 *) DOutput__DM0) 
#define DOutput_DM1                    (* (reg8 *) DOutput__DM1)
#define DOutput_DM2                    (* (reg8 *) DOutput__DM2) 
/* Input Buffer Disable Override */
#define DOutput_INP_DIS                (* (reg8 *) DOutput__INP_DIS)
/* LCD Common or Segment Drive */
#define DOutput_LCD_COM_SEG            (* (reg8 *) DOutput__LCD_COM_SEG)
/* Enable Segment LCD */
#define DOutput_LCD_EN                 (* (reg8 *) DOutput__LCD_EN)
/* Slew Rate Control */
#define DOutput_SLW                    (* (reg8 *) DOutput__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DOutput_PRTDSI__CAPS_SEL       (* (reg8 *) DOutput__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DOutput_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DOutput__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DOutput_PRTDSI__OE_SEL0        (* (reg8 *) DOutput__PRTDSI__OE_SEL0) 
#define DOutput_PRTDSI__OE_SEL1        (* (reg8 *) DOutput__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DOutput_PRTDSI__OUT_SEL0       (* (reg8 *) DOutput__PRTDSI__OUT_SEL0) 
#define DOutput_PRTDSI__OUT_SEL1       (* (reg8 *) DOutput__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DOutput_PRTDSI__SYNC_OUT       (* (reg8 *) DOutput__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DOutput__SIO_CFG)
    #define DOutput_SIO_HYST_EN        (* (reg8 *) DOutput__SIO_HYST_EN)
    #define DOutput_SIO_REG_HIFREQ     (* (reg8 *) DOutput__SIO_REG_HIFREQ)
    #define DOutput_SIO_CFG            (* (reg8 *) DOutput__SIO_CFG)
    #define DOutput_SIO_DIFF           (* (reg8 *) DOutput__SIO_DIFF)
#endif /* (DOutput__SIO_CFG) */

/* Interrupt Registers */
#if defined(DOutput__INTSTAT)
    #define DOutput_INTSTAT            (* (reg8 *) DOutput__INTSTAT)
    #define DOutput_SNAP               (* (reg8 *) DOutput__SNAP)
    
	#define DOutput_0_INTTYPE_REG 		(* (reg8 *) DOutput__0__INTTYPE)
	#define DOutput_1_INTTYPE_REG 		(* (reg8 *) DOutput__1__INTTYPE)
	#define DOutput_2_INTTYPE_REG 		(* (reg8 *) DOutput__2__INTTYPE)
	#define DOutput_3_INTTYPE_REG 		(* (reg8 *) DOutput__3__INTTYPE)
#endif /* (DOutput__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DOutput_H */


/* [] END OF FILE */
