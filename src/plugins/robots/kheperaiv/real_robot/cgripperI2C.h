/*--------------------------------------------------------------------
 * cgripperi2c.h - Khepera4 Rotational Gripper functions
 *--------------------------------------------------------------------
 * $Author: Chandler Garcia (crgarcia@wpi.edu) $
 * $Date: 2023/04/15
 * $Revision: 1.2.1 $
 * Using kb_gripper for reference
 *-------------------------------------------------------------------*/

#ifndef __cgripperI2C__
#define __cgripperI2C__

/*--------------------------------------------------------------------
 *!  Continuity Tester Register For Setup
 *   Set to 1 if you want to check if the module and all its pieces 
 *   are properly set up 
 */
#define CONTINUITY_TEST         0x20

/*--------------------------------------------------------------------
 *	Turret Register Definitions
 */
#define TURRET_SET_POSITION 	        0x00
#define TURRET_GET_POSITION             0x1E // In counts, 0 to 44690 (0 to 2pi)
#define TURRET_SPEED 			        0x02
#define TURRET_MAX_SPEED		        0x03
#define TURRET_MAX_TOLERANCE	        0x04 // + or - in degrees of turret angle
#define TURRET_PROPORTIONAL_CONSTANT    0x05
#define TURRET_INTEGRAL_CONSTANT        0x06
#define TURRET_DERIVATIVE_CONSTANT      0x07
#define TURRET_STATE                    0x08
#define TURRET_TRIM                     0x1C
#define TURRET_AUTOTRIM                 0x1D
#define RAW_TURRET_POSITION             0x01
#define TURRET_FORCE_PROPORTIONAL       0x00

/*--------------------------------------------------------------------
 *	Gripper Register Definition, only send 0 or 1
 */
#define CGRIPPER_POSITION		        0x09

/*
 *  EEPROM Register
*/
#define EEPROM_REGISTER                 0x1B

/*--------------------------------------------------------------------
 *	Force Sensor Register Definitions
 */
#define FORCE_SENSOR_PARALLEL		0xB
#define FORCE_SENSOR_PERPENDICULAR	0xC

/*--------------------------------------------------------------------
 *	LED Register Definitions
 *	Unsure if we would ever want to know what we are showing on LED,
 *	or just send orders
 */
#define LED_CONFIG				0x16


/*--------------------------------------------------------------------
 *	Function Definitions
 *	Every return is a short since we will probably have to do
 *	conversions ourselves.
 */

extern int cgripper_init(void);
/* Turret Functions */
extern unsigned short cgripper_Turret_Get_Position();
extern unsigned short cgripper_Turret_Get_Raw_Position();
extern void cgripper_Turret_Set_Position(unsigned short pos);

extern unsigned short cgripper_Turret_Get_Speed();
extern void cgripper_Turret_Set_Speed(unsigned short speed);

extern unsigned short cgripper_Turret_Get_Max_Speed();
extern void cgripper_Turret_Set_Max_Speed( unsigned short Max_Speed);
extern unsigned short cgripper_Turret_Get_Max_Tolerance();
extern void cgripper_Turret_Set_Max_Tolerance( unsigned short Max_Tolerance);

extern void cgripper_Turret_Total_Reset();
extern void cgripper_Turret_Set_Autotrim(unsigned short Autotrim);
extern void cgripper_Turret_Set_Trim(unsigned short Trim);

extern void cgripper_Turret_Disable();
extern void cgripper_Turret_Position_Mode();
extern void cgripper_Turret_Speed_Mode();
extern void cgripper_Turret_Locked();

extern void cgripper_Modularity_Test();

extern void cgripper_Set_EEPROM(unsigned short val);

/* Gripper Functions */
extern unsigned short cgripper_Gripper_Get_Position();
extern void cgripper_Gripper_Set_Position( unsigned short Position );
extern void cgripper_Close_Gripper();
extern void cgripper_Open_Gripper();

/* Force Sensor Functions */
extern unsigned short cgripper_ForceSensor_Get_Parallel_Force();
extern unsigned short cgripper_ForceSensor_Get_Perpendicular_Force();

/* LED Functions */
extern unsigned short cgripper_LEDRing_Get_Config();
extern void cgripper_LEDRing_Set_Status( unsigned short Config );
extern void testLED();

/* Sets ALL lights to these specific presets or off */
extern void setAllPreset1();
extern void setAllPreset2();
extern void setAllPreset3();
extern void setAllOff();
#endif /*	cgripperI2C	*/
