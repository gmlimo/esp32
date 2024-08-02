/*******************************************************************************
* File Name: Rest_Sensor.h  
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

#if !defined(CY_PINS_Rest_Sensor_H) /* Pins Rest_Sensor_H */
#define CY_PINS_Rest_Sensor_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Rest_Sensor_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Rest_Sensor__PORT == 15 && ((Rest_Sensor__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Rest_Sensor_Write(uint8 value);
void    Rest_Sensor_SetDriveMode(uint8 mode);
uint8   Rest_Sensor_ReadDataReg(void);
uint8   Rest_Sensor_Read(void);
void    Rest_Sensor_SetInterruptMode(uint16 position, uint16 mode);
uint8   Rest_Sensor_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Rest_Sensor_SetDriveMode() function.
     *  @{
     */
        #define Rest_Sensor_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Rest_Sensor_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Rest_Sensor_DM_RES_UP          PIN_DM_RES_UP
        #define Rest_Sensor_DM_RES_DWN         PIN_DM_RES_DWN
        #define Rest_Sensor_DM_OD_LO           PIN_DM_OD_LO
        #define Rest_Sensor_DM_OD_HI           PIN_DM_OD_HI
        #define Rest_Sensor_DM_STRONG          PIN_DM_STRONG
        #define Rest_Sensor_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Rest_Sensor_MASK               Rest_Sensor__MASK
#define Rest_Sensor_SHIFT              Rest_Sensor__SHIFT
#define Rest_Sensor_WIDTH              1u

/* Interrupt constants */
#if defined(Rest_Sensor__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Rest_Sensor_SetInterruptMode() function.
     *  @{
     */
        #define Rest_Sensor_INTR_NONE      (uint16)(0x0000u)
        #define Rest_Sensor_INTR_RISING    (uint16)(0x0001u)
        #define Rest_Sensor_INTR_FALLING   (uint16)(0x0002u)
        #define Rest_Sensor_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Rest_Sensor_INTR_MASK      (0x01u) 
#endif /* (Rest_Sensor__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Rest_Sensor_PS                     (* (reg8 *) Rest_Sensor__PS)
/* Data Register */
#define Rest_Sensor_DR                     (* (reg8 *) Rest_Sensor__DR)
/* Port Number */
#define Rest_Sensor_PRT_NUM                (* (reg8 *) Rest_Sensor__PRT) 
/* Connect to Analog Globals */                                                  
#define Rest_Sensor_AG                     (* (reg8 *) Rest_Sensor__AG)                       
/* Analog MUX bux enable */
#define Rest_Sensor_AMUX                   (* (reg8 *) Rest_Sensor__AMUX) 
/* Bidirectional Enable */                                                        
#define Rest_Sensor_BIE                    (* (reg8 *) Rest_Sensor__BIE)
/* Bit-mask for Aliased Register Access */
#define Rest_Sensor_BIT_MASK               (* (reg8 *) Rest_Sensor__BIT_MASK)
/* Bypass Enable */
#define Rest_Sensor_BYP                    (* (reg8 *) Rest_Sensor__BYP)
/* Port wide control signals */                                                   
#define Rest_Sensor_CTL                    (* (reg8 *) Rest_Sensor__CTL)
/* Drive Modes */
#define Rest_Sensor_DM0                    (* (reg8 *) Rest_Sensor__DM0) 
#define Rest_Sensor_DM1                    (* (reg8 *) Rest_Sensor__DM1)
#define Rest_Sensor_DM2                    (* (reg8 *) Rest_Sensor__DM2) 
/* Input Buffer Disable Override */
#define Rest_Sensor_INP_DIS                (* (reg8 *) Rest_Sensor__INP_DIS)
/* LCD Common or Segment Drive */
#define Rest_Sensor_LCD_COM_SEG            (* (reg8 *) Rest_Sensor__LCD_COM_SEG)
/* Enable Segment LCD */
#define Rest_Sensor_LCD_EN                 (* (reg8 *) Rest_Sensor__LCD_EN)
/* Slew Rate Control */
#define Rest_Sensor_SLW                    (* (reg8 *) Rest_Sensor__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Rest_Sensor_PRTDSI__CAPS_SEL       (* (reg8 *) Rest_Sensor__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Rest_Sensor_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Rest_Sensor__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Rest_Sensor_PRTDSI__OE_SEL0        (* (reg8 *) Rest_Sensor__PRTDSI__OE_SEL0) 
#define Rest_Sensor_PRTDSI__OE_SEL1        (* (reg8 *) Rest_Sensor__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Rest_Sensor_PRTDSI__OUT_SEL0       (* (reg8 *) Rest_Sensor__PRTDSI__OUT_SEL0) 
#define Rest_Sensor_PRTDSI__OUT_SEL1       (* (reg8 *) Rest_Sensor__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Rest_Sensor_PRTDSI__SYNC_OUT       (* (reg8 *) Rest_Sensor__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Rest_Sensor__SIO_CFG)
    #define Rest_Sensor_SIO_HYST_EN        (* (reg8 *) Rest_Sensor__SIO_HYST_EN)
    #define Rest_Sensor_SIO_REG_HIFREQ     (* (reg8 *) Rest_Sensor__SIO_REG_HIFREQ)
    #define Rest_Sensor_SIO_CFG            (* (reg8 *) Rest_Sensor__SIO_CFG)
    #define Rest_Sensor_SIO_DIFF           (* (reg8 *) Rest_Sensor__SIO_DIFF)
#endif /* (Rest_Sensor__SIO_CFG) */

/* Interrupt Registers */
#if defined(Rest_Sensor__INTSTAT)
    #define Rest_Sensor_INTSTAT            (* (reg8 *) Rest_Sensor__INTSTAT)
    #define Rest_Sensor_SNAP               (* (reg8 *) Rest_Sensor__SNAP)
    
	#define Rest_Sensor_0_INTTYPE_REG 		(* (reg8 *) Rest_Sensor__0__INTTYPE)
#endif /* (Rest_Sensor__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Rest_Sensor_H */


/* [] END OF FILE */
