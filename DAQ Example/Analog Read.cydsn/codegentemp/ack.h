/*******************************************************************************
* File Name: ack.h  
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

#if !defined(CY_PINS_ack_H) /* Pins ack_H */
#define CY_PINS_ack_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ack_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ack__PORT == 15 && ((ack__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ack_Write(uint8 value);
void    ack_SetDriveMode(uint8 mode);
uint8   ack_ReadDataReg(void);
uint8   ack_Read(void);
void    ack_SetInterruptMode(uint16 position, uint16 mode);
uint8   ack_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ack_SetDriveMode() function.
     *  @{
     */
        #define ack_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ack_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ack_DM_RES_UP          PIN_DM_RES_UP
        #define ack_DM_RES_DWN         PIN_DM_RES_DWN
        #define ack_DM_OD_LO           PIN_DM_OD_LO
        #define ack_DM_OD_HI           PIN_DM_OD_HI
        #define ack_DM_STRONG          PIN_DM_STRONG
        #define ack_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ack_MASK               ack__MASK
#define ack_SHIFT              ack__SHIFT
#define ack_WIDTH              1u

/* Interrupt constants */
#if defined(ack__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ack_SetInterruptMode() function.
     *  @{
     */
        #define ack_INTR_NONE      (uint16)(0x0000u)
        #define ack_INTR_RISING    (uint16)(0x0001u)
        #define ack_INTR_FALLING   (uint16)(0x0002u)
        #define ack_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ack_INTR_MASK      (0x01u) 
#endif /* (ack__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ack_PS                     (* (reg8 *) ack__PS)
/* Data Register */
#define ack_DR                     (* (reg8 *) ack__DR)
/* Port Number */
#define ack_PRT_NUM                (* (reg8 *) ack__PRT) 
/* Connect to Analog Globals */                                                  
#define ack_AG                     (* (reg8 *) ack__AG)                       
/* Analog MUX bux enable */
#define ack_AMUX                   (* (reg8 *) ack__AMUX) 
/* Bidirectional Enable */                                                        
#define ack_BIE                    (* (reg8 *) ack__BIE)
/* Bit-mask for Aliased Register Access */
#define ack_BIT_MASK               (* (reg8 *) ack__BIT_MASK)
/* Bypass Enable */
#define ack_BYP                    (* (reg8 *) ack__BYP)
/* Port wide control signals */                                                   
#define ack_CTL                    (* (reg8 *) ack__CTL)
/* Drive Modes */
#define ack_DM0                    (* (reg8 *) ack__DM0) 
#define ack_DM1                    (* (reg8 *) ack__DM1)
#define ack_DM2                    (* (reg8 *) ack__DM2) 
/* Input Buffer Disable Override */
#define ack_INP_DIS                (* (reg8 *) ack__INP_DIS)
/* LCD Common or Segment Drive */
#define ack_LCD_COM_SEG            (* (reg8 *) ack__LCD_COM_SEG)
/* Enable Segment LCD */
#define ack_LCD_EN                 (* (reg8 *) ack__LCD_EN)
/* Slew Rate Control */
#define ack_SLW                    (* (reg8 *) ack__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ack_PRTDSI__CAPS_SEL       (* (reg8 *) ack__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ack_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ack__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ack_PRTDSI__OE_SEL0        (* (reg8 *) ack__PRTDSI__OE_SEL0) 
#define ack_PRTDSI__OE_SEL1        (* (reg8 *) ack__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ack_PRTDSI__OUT_SEL0       (* (reg8 *) ack__PRTDSI__OUT_SEL0) 
#define ack_PRTDSI__OUT_SEL1       (* (reg8 *) ack__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ack_PRTDSI__SYNC_OUT       (* (reg8 *) ack__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ack__SIO_CFG)
    #define ack_SIO_HYST_EN        (* (reg8 *) ack__SIO_HYST_EN)
    #define ack_SIO_REG_HIFREQ     (* (reg8 *) ack__SIO_REG_HIFREQ)
    #define ack_SIO_CFG            (* (reg8 *) ack__SIO_CFG)
    #define ack_SIO_DIFF           (* (reg8 *) ack__SIO_DIFF)
#endif /* (ack__SIO_CFG) */

/* Interrupt Registers */
#if defined(ack__INTSTAT)
    #define ack_INTSTAT            (* (reg8 *) ack__INTSTAT)
    #define ack_SNAP               (* (reg8 *) ack__SNAP)
    
	#define ack_0_INTTYPE_REG 		(* (reg8 *) ack__0__INTTYPE)
#endif /* (ack__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ack_H */


/* [] END OF FILE */
