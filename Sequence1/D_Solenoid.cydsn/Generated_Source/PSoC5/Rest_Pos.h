/*******************************************************************************
* File Name: Rest_Pos.h  
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

#if !defined(CY_PINS_Rest_Pos_H) /* Pins Rest_Pos_H */
#define CY_PINS_Rest_Pos_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Rest_Pos_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Rest_Pos__PORT == 15 && ((Rest_Pos__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Rest_Pos_Write(uint8 value);
void    Rest_Pos_SetDriveMode(uint8 mode);
uint8   Rest_Pos_ReadDataReg(void);
uint8   Rest_Pos_Read(void);
void    Rest_Pos_SetInterruptMode(uint16 position, uint16 mode);
uint8   Rest_Pos_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Rest_Pos_SetDriveMode() function.
     *  @{
     */
        #define Rest_Pos_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Rest_Pos_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Rest_Pos_DM_RES_UP          PIN_DM_RES_UP
        #define Rest_Pos_DM_RES_DWN         PIN_DM_RES_DWN
        #define Rest_Pos_DM_OD_LO           PIN_DM_OD_LO
        #define Rest_Pos_DM_OD_HI           PIN_DM_OD_HI
        #define Rest_Pos_DM_STRONG          PIN_DM_STRONG
        #define Rest_Pos_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Rest_Pos_MASK               Rest_Pos__MASK
#define Rest_Pos_SHIFT              Rest_Pos__SHIFT
#define Rest_Pos_WIDTH              1u

/* Interrupt constants */
#if defined(Rest_Pos__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Rest_Pos_SetInterruptMode() function.
     *  @{
     */
        #define Rest_Pos_INTR_NONE      (uint16)(0x0000u)
        #define Rest_Pos_INTR_RISING    (uint16)(0x0001u)
        #define Rest_Pos_INTR_FALLING   (uint16)(0x0002u)
        #define Rest_Pos_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Rest_Pos_INTR_MASK      (0x01u) 
#endif /* (Rest_Pos__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Rest_Pos_PS                     (* (reg8 *) Rest_Pos__PS)
/* Data Register */
#define Rest_Pos_DR                     (* (reg8 *) Rest_Pos__DR)
/* Port Number */
#define Rest_Pos_PRT_NUM                (* (reg8 *) Rest_Pos__PRT) 
/* Connect to Analog Globals */                                                  
#define Rest_Pos_AG                     (* (reg8 *) Rest_Pos__AG)                       
/* Analog MUX bux enable */
#define Rest_Pos_AMUX                   (* (reg8 *) Rest_Pos__AMUX) 
/* Bidirectional Enable */                                                        
#define Rest_Pos_BIE                    (* (reg8 *) Rest_Pos__BIE)
/* Bit-mask for Aliased Register Access */
#define Rest_Pos_BIT_MASK               (* (reg8 *) Rest_Pos__BIT_MASK)
/* Bypass Enable */
#define Rest_Pos_BYP                    (* (reg8 *) Rest_Pos__BYP)
/* Port wide control signals */                                                   
#define Rest_Pos_CTL                    (* (reg8 *) Rest_Pos__CTL)
/* Drive Modes */
#define Rest_Pos_DM0                    (* (reg8 *) Rest_Pos__DM0) 
#define Rest_Pos_DM1                    (* (reg8 *) Rest_Pos__DM1)
#define Rest_Pos_DM2                    (* (reg8 *) Rest_Pos__DM2) 
/* Input Buffer Disable Override */
#define Rest_Pos_INP_DIS                (* (reg8 *) Rest_Pos__INP_DIS)
/* LCD Common or Segment Drive */
#define Rest_Pos_LCD_COM_SEG            (* (reg8 *) Rest_Pos__LCD_COM_SEG)
/* Enable Segment LCD */
#define Rest_Pos_LCD_EN                 (* (reg8 *) Rest_Pos__LCD_EN)
/* Slew Rate Control */
#define Rest_Pos_SLW                    (* (reg8 *) Rest_Pos__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Rest_Pos_PRTDSI__CAPS_SEL       (* (reg8 *) Rest_Pos__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Rest_Pos_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Rest_Pos__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Rest_Pos_PRTDSI__OE_SEL0        (* (reg8 *) Rest_Pos__PRTDSI__OE_SEL0) 
#define Rest_Pos_PRTDSI__OE_SEL1        (* (reg8 *) Rest_Pos__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Rest_Pos_PRTDSI__OUT_SEL0       (* (reg8 *) Rest_Pos__PRTDSI__OUT_SEL0) 
#define Rest_Pos_PRTDSI__OUT_SEL1       (* (reg8 *) Rest_Pos__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Rest_Pos_PRTDSI__SYNC_OUT       (* (reg8 *) Rest_Pos__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Rest_Pos__SIO_CFG)
    #define Rest_Pos_SIO_HYST_EN        (* (reg8 *) Rest_Pos__SIO_HYST_EN)
    #define Rest_Pos_SIO_REG_HIFREQ     (* (reg8 *) Rest_Pos__SIO_REG_HIFREQ)
    #define Rest_Pos_SIO_CFG            (* (reg8 *) Rest_Pos__SIO_CFG)
    #define Rest_Pos_SIO_DIFF           (* (reg8 *) Rest_Pos__SIO_DIFF)
#endif /* (Rest_Pos__SIO_CFG) */

/* Interrupt Registers */
#if defined(Rest_Pos__INTSTAT)
    #define Rest_Pos_INTSTAT            (* (reg8 *) Rest_Pos__INTSTAT)
    #define Rest_Pos_SNAP               (* (reg8 *) Rest_Pos__SNAP)
    
	#define Rest_Pos_0_INTTYPE_REG 		(* (reg8 *) Rest_Pos__0__INTTYPE)
#endif /* (Rest_Pos__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Rest_Pos_H */


/* [] END OF FILE */
