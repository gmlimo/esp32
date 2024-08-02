/*******************************************************************************
* File Name: Work_Sensor.h  
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

#if !defined(CY_PINS_Work_Sensor_H) /* Pins Work_Sensor_H */
#define CY_PINS_Work_Sensor_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Work_Sensor_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Work_Sensor__PORT == 15 && ((Work_Sensor__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Work_Sensor_Write(uint8 value);
void    Work_Sensor_SetDriveMode(uint8 mode);
uint8   Work_Sensor_ReadDataReg(void);
uint8   Work_Sensor_Read(void);
void    Work_Sensor_SetInterruptMode(uint16 position, uint16 mode);
uint8   Work_Sensor_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Work_Sensor_SetDriveMode() function.
     *  @{
     */
        #define Work_Sensor_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Work_Sensor_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Work_Sensor_DM_RES_UP          PIN_DM_RES_UP
        #define Work_Sensor_DM_RES_DWN         PIN_DM_RES_DWN
        #define Work_Sensor_DM_OD_LO           PIN_DM_OD_LO
        #define Work_Sensor_DM_OD_HI           PIN_DM_OD_HI
        #define Work_Sensor_DM_STRONG          PIN_DM_STRONG
        #define Work_Sensor_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Work_Sensor_MASK               Work_Sensor__MASK
#define Work_Sensor_SHIFT              Work_Sensor__SHIFT
#define Work_Sensor_WIDTH              1u

/* Interrupt constants */
#if defined(Work_Sensor__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Work_Sensor_SetInterruptMode() function.
     *  @{
     */
        #define Work_Sensor_INTR_NONE      (uint16)(0x0000u)
        #define Work_Sensor_INTR_RISING    (uint16)(0x0001u)
        #define Work_Sensor_INTR_FALLING   (uint16)(0x0002u)
        #define Work_Sensor_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Work_Sensor_INTR_MASK      (0x01u) 
#endif /* (Work_Sensor__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Work_Sensor_PS                     (* (reg8 *) Work_Sensor__PS)
/* Data Register */
#define Work_Sensor_DR                     (* (reg8 *) Work_Sensor__DR)
/* Port Number */
#define Work_Sensor_PRT_NUM                (* (reg8 *) Work_Sensor__PRT) 
/* Connect to Analog Globals */                                                  
#define Work_Sensor_AG                     (* (reg8 *) Work_Sensor__AG)                       
/* Analog MUX bux enable */
#define Work_Sensor_AMUX                   (* (reg8 *) Work_Sensor__AMUX) 
/* Bidirectional Enable */                                                        
#define Work_Sensor_BIE                    (* (reg8 *) Work_Sensor__BIE)
/* Bit-mask for Aliased Register Access */
#define Work_Sensor_BIT_MASK               (* (reg8 *) Work_Sensor__BIT_MASK)
/* Bypass Enable */
#define Work_Sensor_BYP                    (* (reg8 *) Work_Sensor__BYP)
/* Port wide control signals */                                                   
#define Work_Sensor_CTL                    (* (reg8 *) Work_Sensor__CTL)
/* Drive Modes */
#define Work_Sensor_DM0                    (* (reg8 *) Work_Sensor__DM0) 
#define Work_Sensor_DM1                    (* (reg8 *) Work_Sensor__DM1)
#define Work_Sensor_DM2                    (* (reg8 *) Work_Sensor__DM2) 
/* Input Buffer Disable Override */
#define Work_Sensor_INP_DIS                (* (reg8 *) Work_Sensor__INP_DIS)
/* LCD Common or Segment Drive */
#define Work_Sensor_LCD_COM_SEG            (* (reg8 *) Work_Sensor__LCD_COM_SEG)
/* Enable Segment LCD */
#define Work_Sensor_LCD_EN                 (* (reg8 *) Work_Sensor__LCD_EN)
/* Slew Rate Control */
#define Work_Sensor_SLW                    (* (reg8 *) Work_Sensor__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Work_Sensor_PRTDSI__CAPS_SEL       (* (reg8 *) Work_Sensor__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Work_Sensor_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Work_Sensor__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Work_Sensor_PRTDSI__OE_SEL0        (* (reg8 *) Work_Sensor__PRTDSI__OE_SEL0) 
#define Work_Sensor_PRTDSI__OE_SEL1        (* (reg8 *) Work_Sensor__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Work_Sensor_PRTDSI__OUT_SEL0       (* (reg8 *) Work_Sensor__PRTDSI__OUT_SEL0) 
#define Work_Sensor_PRTDSI__OUT_SEL1       (* (reg8 *) Work_Sensor__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Work_Sensor_PRTDSI__SYNC_OUT       (* (reg8 *) Work_Sensor__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Work_Sensor__SIO_CFG)
    #define Work_Sensor_SIO_HYST_EN        (* (reg8 *) Work_Sensor__SIO_HYST_EN)
    #define Work_Sensor_SIO_REG_HIFREQ     (* (reg8 *) Work_Sensor__SIO_REG_HIFREQ)
    #define Work_Sensor_SIO_CFG            (* (reg8 *) Work_Sensor__SIO_CFG)
    #define Work_Sensor_SIO_DIFF           (* (reg8 *) Work_Sensor__SIO_DIFF)
#endif /* (Work_Sensor__SIO_CFG) */

/* Interrupt Registers */
#if defined(Work_Sensor__INTSTAT)
    #define Work_Sensor_INTSTAT            (* (reg8 *) Work_Sensor__INTSTAT)
    #define Work_Sensor_SNAP               (* (reg8 *) Work_Sensor__SNAP)
    
	#define Work_Sensor_0_INTTYPE_REG 		(* (reg8 *) Work_Sensor__0__INTTYPE)
#endif /* (Work_Sensor__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Work_Sensor_H */


/* [] END OF FILE */
