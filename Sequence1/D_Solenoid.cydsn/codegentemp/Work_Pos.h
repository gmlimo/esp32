/*******************************************************************************
* File Name: Work_Pos.h  
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

#if !defined(CY_PINS_Work_Pos_H) /* Pins Work_Pos_H */
#define CY_PINS_Work_Pos_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Work_Pos_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Work_Pos__PORT == 15 && ((Work_Pos__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Work_Pos_Write(uint8 value);
void    Work_Pos_SetDriveMode(uint8 mode);
uint8   Work_Pos_ReadDataReg(void);
uint8   Work_Pos_Read(void);
void    Work_Pos_SetInterruptMode(uint16 position, uint16 mode);
uint8   Work_Pos_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Work_Pos_SetDriveMode() function.
     *  @{
     */
        #define Work_Pos_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Work_Pos_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Work_Pos_DM_RES_UP          PIN_DM_RES_UP
        #define Work_Pos_DM_RES_DWN         PIN_DM_RES_DWN
        #define Work_Pos_DM_OD_LO           PIN_DM_OD_LO
        #define Work_Pos_DM_OD_HI           PIN_DM_OD_HI
        #define Work_Pos_DM_STRONG          PIN_DM_STRONG
        #define Work_Pos_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Work_Pos_MASK               Work_Pos__MASK
#define Work_Pos_SHIFT              Work_Pos__SHIFT
#define Work_Pos_WIDTH              1u

/* Interrupt constants */
#if defined(Work_Pos__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Work_Pos_SetInterruptMode() function.
     *  @{
     */
        #define Work_Pos_INTR_NONE      (uint16)(0x0000u)
        #define Work_Pos_INTR_RISING    (uint16)(0x0001u)
        #define Work_Pos_INTR_FALLING   (uint16)(0x0002u)
        #define Work_Pos_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Work_Pos_INTR_MASK      (0x01u) 
#endif /* (Work_Pos__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Work_Pos_PS                     (* (reg8 *) Work_Pos__PS)
/* Data Register */
#define Work_Pos_DR                     (* (reg8 *) Work_Pos__DR)
/* Port Number */
#define Work_Pos_PRT_NUM                (* (reg8 *) Work_Pos__PRT) 
/* Connect to Analog Globals */                                                  
#define Work_Pos_AG                     (* (reg8 *) Work_Pos__AG)                       
/* Analog MUX bux enable */
#define Work_Pos_AMUX                   (* (reg8 *) Work_Pos__AMUX) 
/* Bidirectional Enable */                                                        
#define Work_Pos_BIE                    (* (reg8 *) Work_Pos__BIE)
/* Bit-mask for Aliased Register Access */
#define Work_Pos_BIT_MASK               (* (reg8 *) Work_Pos__BIT_MASK)
/* Bypass Enable */
#define Work_Pos_BYP                    (* (reg8 *) Work_Pos__BYP)
/* Port wide control signals */                                                   
#define Work_Pos_CTL                    (* (reg8 *) Work_Pos__CTL)
/* Drive Modes */
#define Work_Pos_DM0                    (* (reg8 *) Work_Pos__DM0) 
#define Work_Pos_DM1                    (* (reg8 *) Work_Pos__DM1)
#define Work_Pos_DM2                    (* (reg8 *) Work_Pos__DM2) 
/* Input Buffer Disable Override */
#define Work_Pos_INP_DIS                (* (reg8 *) Work_Pos__INP_DIS)
/* LCD Common or Segment Drive */
#define Work_Pos_LCD_COM_SEG            (* (reg8 *) Work_Pos__LCD_COM_SEG)
/* Enable Segment LCD */
#define Work_Pos_LCD_EN                 (* (reg8 *) Work_Pos__LCD_EN)
/* Slew Rate Control */
#define Work_Pos_SLW                    (* (reg8 *) Work_Pos__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Work_Pos_PRTDSI__CAPS_SEL       (* (reg8 *) Work_Pos__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Work_Pos_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Work_Pos__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Work_Pos_PRTDSI__OE_SEL0        (* (reg8 *) Work_Pos__PRTDSI__OE_SEL0) 
#define Work_Pos_PRTDSI__OE_SEL1        (* (reg8 *) Work_Pos__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Work_Pos_PRTDSI__OUT_SEL0       (* (reg8 *) Work_Pos__PRTDSI__OUT_SEL0) 
#define Work_Pos_PRTDSI__OUT_SEL1       (* (reg8 *) Work_Pos__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Work_Pos_PRTDSI__SYNC_OUT       (* (reg8 *) Work_Pos__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Work_Pos__SIO_CFG)
    #define Work_Pos_SIO_HYST_EN        (* (reg8 *) Work_Pos__SIO_HYST_EN)
    #define Work_Pos_SIO_REG_HIFREQ     (* (reg8 *) Work_Pos__SIO_REG_HIFREQ)
    #define Work_Pos_SIO_CFG            (* (reg8 *) Work_Pos__SIO_CFG)
    #define Work_Pos_SIO_DIFF           (* (reg8 *) Work_Pos__SIO_DIFF)
#endif /* (Work_Pos__SIO_CFG) */

/* Interrupt Registers */
#if defined(Work_Pos__INTSTAT)
    #define Work_Pos_INTSTAT            (* (reg8 *) Work_Pos__INTSTAT)
    #define Work_Pos_SNAP               (* (reg8 *) Work_Pos__SNAP)
    
	#define Work_Pos_0_INTTYPE_REG 		(* (reg8 *) Work_Pos__0__INTTYPE)
#endif /* (Work_Pos__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Work_Pos_H */


/* [] END OF FILE */
