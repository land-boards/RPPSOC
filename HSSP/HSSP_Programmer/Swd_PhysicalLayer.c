/*******************************************************************************
* File Name: Swd_PhysicalLayer.c
* Version 3.0 Plus WiringPi modifications
*
* Description:
*  This file provides the source code for the physical layer functions of the
*  SWD protocol. These function definitions are the same as the corresponding
*  macro definitions in Swd_PhysicalLayer.h
*******************************************************************************/

/********************************************************************************
*   Header file Inclusion
********************************************************************************/
#include <stdio.h>
#include <wiringPi.h>
#include "Swd_PhysicalLayer.h"

/********************************************************************************
*   Function Definitions
********************************************************************************/

/************************ Debug Trigger functions ******************************
********************************************************************************/

/*******************************************************************************
* Function Name: setupTrig
*
* Summary:
*  Sets uup the Scope Trigger pin drive mode as CMOS drive mode at Low.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*
********************************************************************************/
void setupTrig()
{
	pinMode(TRIG_Pin,OUTPUT);
	digitalWrite(TRIG_Pin,0);
}

/*******************************************************************************
* Function Name: trigger
*
* Summary:
*  Toggles the trigger pin.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*
********************************************************************************/
void trigger()
{	
	digitalWrite(TRIG_Pin,1);
	digitalWrite(TRIG_Pin,0);
}

/****************** SWD Protocol Physical Layer functions ***********************
********************************************************************************/

/*******************************************************************************
* Function Name: SetSwdckCmosOutput
********************************************************************************
*
* Summary:
*  Sets the SWDCK pin drive mode as CMOS drive mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The function definition is the same as the macro definition SWDCK_DRIVEMODE_CMOSOUT in
*  Swd_PhysicalLayer.h.
*
*******************************************************************************/
inline void SetSwdckCmosOutput()
{
    SWDCK_DRIVEMODE_CMOSOUT;
}

/*******************************************************************************
* Function Name: SetSwdckHizInput
********************************************************************************
*
* Summary:
*  Sets the SWDCK pin drive mode as High impedance digital input.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The function definition is the same as the macro definition SWDCK_DRIVEMODE_HIGHZIN in
*  Swd_PhysicalLayer.h.
*
*******************************************************************************/
inline void SetSwdckHizInput()
{
    SWDCK_DRIVEMODE_HIGHZIN;
}

/*******************************************************************************
* Function Name: SetSwdioCmosOutput
********************************************************************************
*
* Summary:
*  Sets the SWDIO pin drive mode as CMOS drive mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The function definition is the same as the macro definition SWDIO_DRIVEMODE_CMOSOUT in
*  Swd_PhysicalLayer.h.
*
*******************************************************************************/
inline void SetSwdioCmosOutput()
{
    SWDIO_DRIVEMODE_CMOSOUT;
}

/*******************************************************************************
* Function Name: SetSwdioHizInput
********************************************************************************
*
* Summary:
*  Sets the SWDIO pin drive mode as High impedance digital input.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The function definition is the same as the macro definition SWDIO_DRIVEMODE_HIGHZIN in
*  Swd_PhysicalLayer.h.
*
*******************************************************************************/
inline void SetSwdioHizInput()
{
    SWDIO_DRIVEMODE_HIGHZIN;        
}

/*******************************************************************************
* Function Name: SetXresCmosOutput
********************************************************************************
*
* Summary:
*  Sets the XRES pin drive mode as CMOS drive mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The function definition is the same as the macro definition XRES_DRIVEMODE_CMOSOUT in
*  Swd_PhysicalLayer.h.
*
*******************************************************************************/
inline void SetXresCmosOutput()
{
    XRES_DRIVEMODE_CMOSOUT;
}

/*******************************************************************************
* Function Name: SetXresHizInput
********************************************************************************
*
* Summary:
*  Sets the XRES pin drive mode as High impedance digital input.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The function definition is the same as the macro definition XRES_DRIVEMODE_HIGHZIN in
*  Swd_PhysicalLayer.h.
*
*******************************************************************************/
inline void SetXresHizInput()
{
    XRES_DRIVEMODE_HIGHZIN;
}

/*******************************************************************************
* Function Name: SetSwdckHigh
********************************************************************************
*
* Summary:
*  Sets the SWDCK pin high
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The function definition is the same as the macro definition SWDCK_OUTPUT_HIGH in
*  Swd_PhysicalLayer.h.
*
*******************************************************************************/
inline void SetSwdckHigh()
{
    SWDCK_OUTPUT_HIGH;    
    SWDCK_OUTPUT_HIGH;    
}

/*******************************************************************************
* Function Name: SetSwdckLow
********************************************************************************
*
* Summary:
*  Sets the SWDCK pin low
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The function definition is the same as the macro definition SWDCK_OUTPUT_LOW in
*  Swd_PhysicalLayer.h.
*
*******************************************************************************/
inline void SetSwdckLow()
{
    SWDCK_OUTPUT_LOW;
    SWDCK_OUTPUT_LOW;
}

/*******************************************************************************
* Function Name: SetSwdioHigh
********************************************************************************
*
* Summary:
*  Sets the SWDIO pin high
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The function definition is the same as the macro definition SWDIO_OUTPUT_HIGH in
*  Swd_PhysicalLayer.h.
*
*******************************************************************************/
inline void SetSwdioHigh()
{
    SWDIO_OUTPUT_HIGH;
    SWDIO_OUTPUT_HIGH;
}

/*******************************************************************************
* Function Name: SetSwdioLow
********************************************************************************
*
* Summary:
*  Sets the SWDIO pin low
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The function definition is the same as the macro definition SWDIO_OUTPUT_LOW in
*  Swd_PhysicalLayer.h.
*
*******************************************************************************/
inline void SetSwdioLow()
{
    SWDIO_OUTPUT_LOW;
    SWDIO_OUTPUT_LOW;
}

/*******************************************************************************
* Function Name: SetXresHigh
********************************************************************************
*
* Summary:
*  Sets the XRES pin high
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The function definition is the same as the macro definition XRES_OUTPUT_HIGH in
*  Swd_PhysicalLayer.h.
*
*******************************************************************************/
inline void SetXresHigh()
{
    XRES_OUTPUT_HIGH;
    XRES_OUTPUT_HIGH;
}

/*******************************************************************************
* Function Name: SetXresLow
********************************************************************************
*
* Summary:
*  Sets the XRES pin low
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The function definition is the same as the macro definition XRES_OUTPUT_LOW in
*  Swd_PhysicalLayer.h.
*
*******************************************************************************/
inline void SetXresLow()
{
    XRES_OUTPUT_LOW;
    XRES_OUTPUT_LOW;
}

/*******************************************************************************
* Function Name: ReadSwdio
********************************************************************************
*
* Summary:
*  Returns the state of the SWDIO input pin
*
* Parameters:
*  None.
*
* Return:
*  unsigned char (only one of the two values as given below)
*   0x00 - If the SWDIO pin state is low
*   0x01 - If the SWDIO pin state is high
*
* Note:
*  The function definition is the same as the macro definition SWDIO_INPUT_READ in
*  Swd_PhysicalLayer.h.
*
*******************************************************************************/
inline unsigned char ReadSwdio()
{
    return (SWDIO_INPUT_READ);
}
