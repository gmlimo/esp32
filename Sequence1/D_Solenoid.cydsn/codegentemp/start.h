/*******************************************************************************
* File Name: start.h  
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

#if !defined(CY_PINS_start_H) /* Pins start_H */
#define CY_PINS_start_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "start_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 start__PORT == 15 && ((start__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    start_Write(uint8 value);
void    start_SetDriveMode(uint8 mode);
uint8   start_ReadDataReg(void);
uint8   start_Read(void);
void    start_SetInterruptMode(uint16 position, uint16 mode);
uint8   start_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the start_SetDriveMode() function.
     *  @{
     */
        #define start_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define start_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define start_DM_RES_UP          PIN_DM_RES_UP
        #define start_DM_RES_DWN         PIN_DM_RES_DWN
        #define start_DM_OD_LO           PIN_DM_OD_LO
        #define start_DM_OD_HI           PIN_DM_OD_HI
        #define start_DM_STRONG          PIN_DM_STRONG
        #define start_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define start_MASK               start__MASK
#define start_SHIFT              start__SHIFT
#define start_WIDTH              1u

/* Interrupt constants */
#if defined(start__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in start_SetInterruptMode() function.
     *  @{
     */
        #define start_INTR_NONE      (uint16)(0x0000u)
        #define start_INTR_RISING    (uint16)(0x0001u)
        #define start_INTR_FALLING   (uint16)(0x0002u)
        #define start_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define start_INTR_MASK      (0x01u) 
#endif /* (start__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define start_PS                     (* (reg8 *) start__PS)
/* Data Register */
#define start_DR                     (* (reg8 *) start__DR)
/* Port Number */
#define start_PRT_NUM                (* (reg8 *) start__PRT) 
/* Connect to Analog Globals */                                                  
#define start_AG                     (* (reg8 *) start__AG)                       
/* Analog MUX bux enable */
#define start_AMUX                   (* (reg8 *) start__AMUX) 
/* Bidirectional Enable */                                                        
#define start_BIE                    (* (reg8 *) start__BIE)
/* Bit-mask for Aliased Register Access */
#define start_BIT_MASK               (* (reg8 *) start__BIT_MASK)
/* Bypass Enable */
#define start_BYP                    (* (reg8 *) start__BYP)
/* Port wide control signals */                                                   
#define start_CTL                    (* (reg8 *) start__CTL)
/* Drive Modes */
#define start_DM0                    (* (reg8 *) start__DM0) 
#define start_DM1                    (* (reg8 *) start__DM1)
#define start_DM2                    (* (reg8 *) start__DM2) 
/* Input Buffer Disable Override */
#define start_INP_DIS                (* (reg8 *) start__INP_DIS)
/* LCD Common or Segment Drive */
#define start_LCD_COM_SEG            (* (reg8 *) start__LCD_COM_SEG)
/* Enable Segment LCD */
#define start_LCD_EN                 (* (reg8 *) start__LCD_EN)
/* Slew Rate Control */
#define start_SLW                    (* (reg8 *) start__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define start_PRTDSI__CAPS_SEL       (* (reg8 *) start__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define start_PRTDSI__DBL_SYNC_IN    (* (reg8 *) start__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define start_PRTDSI__OE_SEL0        (* (reg8 *) start__PRTDSI__OE_SEL0) 
#define start_PRTDSI__OE_SEL1        (* (reg8 *) start__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define start_PRTDSI__OUT_SEL0       (* (reg8 *) start__PRTDSI__OUT_SEL0) 
#define start_PRTDSI__OUT_SEL1       (* (reg8 *) start__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define start_PRTDSI__SYNC_OUT       (* (reg8 *) start__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(start__SIO_CFG)
    #define start_SIO_HYST_EN        (* (reg8 *) start__SIO_HYST_EN)
    #define start_SIO_REG_HIFREQ     (* (reg8 *) start__SIO_REG_HIFREQ)
    #define start_SIO_CFG            (* (reg8 *) start__SIO_CFG)
    #define start_SIO_DIFF           (* (reg8 *) start__SIO_DIFF)
#endif /* (start__SIO_CFG) */

/* Interrupt Registers */
#if defined(start__INTSTAT)
    #define start_INTSTAT            (* (reg8 *) start__INTSTAT)
    #define start_SNAP               (* (reg8 *) start__SNAP)
    
	#define start_0_INTTYPE_REG 		(* (reg8 *) start__0__INTTYPE)
#endif /* (start__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_start_H */


/* [] END OF FILE */
