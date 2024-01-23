/*******************************************************************************
* File Name: no_rx_write.h  
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

#if !defined(CY_PINS_no_rx_write_H) /* Pins no_rx_write_H */
#define CY_PINS_no_rx_write_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "no_rx_write_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 no_rx_write__PORT == 15 && ((no_rx_write__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    no_rx_write_Write(uint8 value);
void    no_rx_write_SetDriveMode(uint8 mode);
uint8   no_rx_write_ReadDataReg(void);
uint8   no_rx_write_Read(void);
void    no_rx_write_SetInterruptMode(uint16 position, uint16 mode);
uint8   no_rx_write_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the no_rx_write_SetDriveMode() function.
     *  @{
     */
        #define no_rx_write_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define no_rx_write_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define no_rx_write_DM_RES_UP          PIN_DM_RES_UP
        #define no_rx_write_DM_RES_DWN         PIN_DM_RES_DWN
        #define no_rx_write_DM_OD_LO           PIN_DM_OD_LO
        #define no_rx_write_DM_OD_HI           PIN_DM_OD_HI
        #define no_rx_write_DM_STRONG          PIN_DM_STRONG
        #define no_rx_write_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define no_rx_write_MASK               no_rx_write__MASK
#define no_rx_write_SHIFT              no_rx_write__SHIFT
#define no_rx_write_WIDTH              1u

/* Interrupt constants */
#if defined(no_rx_write__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in no_rx_write_SetInterruptMode() function.
     *  @{
     */
        #define no_rx_write_INTR_NONE      (uint16)(0x0000u)
        #define no_rx_write_INTR_RISING    (uint16)(0x0001u)
        #define no_rx_write_INTR_FALLING   (uint16)(0x0002u)
        #define no_rx_write_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define no_rx_write_INTR_MASK      (0x01u) 
#endif /* (no_rx_write__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define no_rx_write_PS                     (* (reg8 *) no_rx_write__PS)
/* Data Register */
#define no_rx_write_DR                     (* (reg8 *) no_rx_write__DR)
/* Port Number */
#define no_rx_write_PRT_NUM                (* (reg8 *) no_rx_write__PRT) 
/* Connect to Analog Globals */                                                  
#define no_rx_write_AG                     (* (reg8 *) no_rx_write__AG)                       
/* Analog MUX bux enable */
#define no_rx_write_AMUX                   (* (reg8 *) no_rx_write__AMUX) 
/* Bidirectional Enable */                                                        
#define no_rx_write_BIE                    (* (reg8 *) no_rx_write__BIE)
/* Bit-mask for Aliased Register Access */
#define no_rx_write_BIT_MASK               (* (reg8 *) no_rx_write__BIT_MASK)
/* Bypass Enable */
#define no_rx_write_BYP                    (* (reg8 *) no_rx_write__BYP)
/* Port wide control signals */                                                   
#define no_rx_write_CTL                    (* (reg8 *) no_rx_write__CTL)
/* Drive Modes */
#define no_rx_write_DM0                    (* (reg8 *) no_rx_write__DM0) 
#define no_rx_write_DM1                    (* (reg8 *) no_rx_write__DM1)
#define no_rx_write_DM2                    (* (reg8 *) no_rx_write__DM2) 
/* Input Buffer Disable Override */
#define no_rx_write_INP_DIS                (* (reg8 *) no_rx_write__INP_DIS)
/* LCD Common or Segment Drive */
#define no_rx_write_LCD_COM_SEG            (* (reg8 *) no_rx_write__LCD_COM_SEG)
/* Enable Segment LCD */
#define no_rx_write_LCD_EN                 (* (reg8 *) no_rx_write__LCD_EN)
/* Slew Rate Control */
#define no_rx_write_SLW                    (* (reg8 *) no_rx_write__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define no_rx_write_PRTDSI__CAPS_SEL       (* (reg8 *) no_rx_write__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define no_rx_write_PRTDSI__DBL_SYNC_IN    (* (reg8 *) no_rx_write__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define no_rx_write_PRTDSI__OE_SEL0        (* (reg8 *) no_rx_write__PRTDSI__OE_SEL0) 
#define no_rx_write_PRTDSI__OE_SEL1        (* (reg8 *) no_rx_write__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define no_rx_write_PRTDSI__OUT_SEL0       (* (reg8 *) no_rx_write__PRTDSI__OUT_SEL0) 
#define no_rx_write_PRTDSI__OUT_SEL1       (* (reg8 *) no_rx_write__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define no_rx_write_PRTDSI__SYNC_OUT       (* (reg8 *) no_rx_write__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(no_rx_write__SIO_CFG)
    #define no_rx_write_SIO_HYST_EN        (* (reg8 *) no_rx_write__SIO_HYST_EN)
    #define no_rx_write_SIO_REG_HIFREQ     (* (reg8 *) no_rx_write__SIO_REG_HIFREQ)
    #define no_rx_write_SIO_CFG            (* (reg8 *) no_rx_write__SIO_CFG)
    #define no_rx_write_SIO_DIFF           (* (reg8 *) no_rx_write__SIO_DIFF)
#endif /* (no_rx_write__SIO_CFG) */

/* Interrupt Registers */
#if defined(no_rx_write__INTSTAT)
    #define no_rx_write_INTSTAT            (* (reg8 *) no_rx_write__INTSTAT)
    #define no_rx_write_SNAP               (* (reg8 *) no_rx_write__SNAP)
    
	#define no_rx_write_0_INTTYPE_REG 		(* (reg8 *) no_rx_write__0__INTTYPE)
#endif /* (no_rx_write__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_no_rx_write_H */


/* [] END OF FILE */
