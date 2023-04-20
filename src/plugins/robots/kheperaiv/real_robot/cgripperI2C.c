/*!
 * \file   cgripperI2C.c The Collective Khepera4 Gripper Module
 *
 * \brief
 *         This module is layer for communication with the collective's khepera 4 Gripper module.
 *
 * \author   Chandler Garcia
 *
 * \note     We are using the i2ccom.h code for reference
 * \bug      none discovered.
 * \todo     Save all the information that we send to the gripper turret in here on variables maybes?
 */
#include "cgripperI2C.h"
#include <khepera/khepera.h>
#include <khepera/i2ccom.h>
#include <stdlib.h>
#include <stdio.h>

int i2c_read16( i2c_t * i2c ,
		i2c_dev_t dev ,
		unsigned char reg ,
		unsigned short *val )
{
  return i2c_lltransfer( i2c , dev , &reg , 1 , 
			 (unsigned char *)val , 2 );
}

int i2c_write16( i2c_t * i2c ,
		 i2c_dev_t dev ,
		 unsigned char reg ,
		 unsigned short val )
{
  unsigned char buf[3];

  buf[0] = reg;
  buf[1] = val;
  buf[2] = (val>>8);

  return i2c_llwrite( i2c , dev , buf , 3 );
}

i2c_t i2c;
// TODO : Check if this devpath even works (seems to worlk - Yasmine)
char *devpath = NULL;// might default to correct devpath, but unsure
int status;

/* Address of our gripper module */
int addr = 0x24;
// float m_PI = 3.14159265359;

int cgripper_init( void ){
	/* 
	 * Initializes the connection to the gripper, expects a response
	 * TODO : Wait for a response for a specific amount of time maybe?
	 */

	fprintf(stderr, "Opening i2c device %s\n", devpath);

	  if (i2c_open(&i2c, devpath) < 0) {
	    perror("open");
	    exit(1);
	    return -1;
	  }
	  return 0;
}

void cgripper_Modularity_Test(){
	i2c_write16(&i2c, addr, CONTINUITY_TEST, 0x01);
}



/**********************************************/
/***************Turret Functions***************/
/**********************************************/

/* Position Information */
unsigned short cgripper_Turret_Get_Position(){
	/*
	 * Turret Position in Encoder Counts
	*/
	unsigned short Position;
	status = i2c_read16(&i2c,addr,TURRET_GET_POSITION,&Position);
	return Position;
}
unsigned short cgripper_Turret_Get_Raw_Position(){
	/*
	 * Turret Position RAW in PWM Pulse width waveform
	*/
	unsigned short Position;
	status = i2c_read16(&i2c,addr,RAW_TURRET_POSITION,&Position);
	return Position;
}

void cgripper_Turret_Set_Position(unsigned short pos){
	/*
	 * Takes in an encoder position count between 0 and 44690 where 0 is 0 radians, and 44690 is 2 pi radians
	*/
	// unsigned short posToEncoder = (unsigned short) pos / (m_PI * 2) * 44690;
	i2c_write16(&i2c, addr, TURRET_SET_POSITION, pos);
}

unsigned short cgripper_Turret_Get_Speed(){
	/*
	 * Returns speed of turret in frequency units
	*/
	unsigned short Speed;
	status = i2c_read16(&i2c,addr,TURRET_SPEED,&Speed);
	return Speed;
}

void cgripper_Turret_Set_Speed(short speed){
	/*
	 * Sets speed in frequency units
	*/
	i2c_write16(&i2c, addr, TURRET_SPEED, speed);
}

unsigned short cgripper_Turret_Get_Max_Speed(){
	unsigned short Max_Speed;
//	knet_read8( dev , TURRET_MAX_SPEED , &Max_Speed );
	status = i2c_read16(&i2c,addr,TURRET_MAX_SPEED,&Max_Speed);
	return Max_Speed;
}

void cgripper_Turret_Set_Max_Speed( unsigned short Max_Speed){
//	knet_write16( dev , TURRET_MAX_SPEED , Max_Speed );
	i2c_write16(&i2c, addr, TURRET_MAX_SPEED, Max_Speed);
}

/* Degree Error Information */
unsigned short cgripper_Turret_Get_Max_Tolerance(){
	unsigned short Max_Tolerance;
//	knet_read8( dev , TURRET_MAX_TOLERANCE , &Max_Tolerance );
	status = i2c_read16(&i2c,addr,TURRET_MAX_TOLERANCE,&Max_Tolerance);
	return Max_Tolerance;
}

void cgripper_Turret_Set_Max_Tolerance( unsigned short Max_Tolerance){
	i2c_write16(&i2c, addr, TURRET_MAX_TOLERANCE, Max_Tolerance);
}

void cgripper_Turret_Total_Reset(){
	/*
	 * Do NOT call this unless you wish to RESET the turret's position and default the gripper
	 * To be open
	*/
	cgripper_Turret_Set_Autotrim(0x01);
    cgripper_Set_EEPROM(0x01);
}

/* Reset Turret Encoder's Relative 0 Information */
void cgripper_Turret_Set_Autotrim(unsigned short Autotrim){
	/*
	 * By setting this to 1, we will update the encoder's recognized 0 degree for the turret
	*/
	i2c_write16(&i2c, addr, TURRET_AUTOTRIM, Autotrim);
}

void cgripper_Turret_Set_Trim(unsigned short Trim){
	i2c_write16(&i2c, addr, TURRET_TRIM, Trim);
}

void cgripper_Set_EEPROM(unsigned short val){
	i2c_write16(&i2c, addr, EEPROM_REGISTER, val);
}

/* Set the Turret's mode, you will most likely always be using Position Mode */
void cgripper_Turret_Disable(){
	i2c_write16(&i2c, addr, 0x8, 0x0);
}

void cgripper_Turret_Position_Mode(){
	i2c_write16(&i2c, addr, 0x8, 0x1);
}

void cgripper_Turret_Speed_Mode(){
	i2c_write16(&i2c, addr, 0x8, 0x2);
}

void cgripper_Turret_Locked(){
	i2c_write16(&i2c, addr, 0x8, 0x3);
}

void cgripper_Turret_Push(){
	i2c_write16(&i2c, addr, 0x8, 0x4);
}

void cgripper_Turret_Set_Proportional(unsigned short Proportional){
	i2c_write16(&i2c, addr, TURRET_PROPORTIONAL_CONSTANT, Proportional);
}

void cgripper_Turret_Set_Integral(unsigned short Integral){
	i2c_write16(&i2c, addr, TURRET_INTEGRAL_CONSTANT, Integral);
}

void cgripper_Turret_Set_Derivative(unsigned short Derivative){
	i2c_write16(&i2c, addr, TURRET_DERIVATIVE_CONSTANT, Derivative);
}

void cgripper_Turret_Force_Tolerance(unsigned short Proportional){
	i2c_write16(&i2c,addr, TURRET_FORCE_PROPORTIONAL, Proportional);
}


/**********************************************/
/**************Gripper Functions***************/
/**********************************************/

unsigned short cgripper_Gripper_Get_Position(){
	/*
	 * Unsure if this will ever be used, like why the hell do you want to know
	 * where the gripper is? Did you NOT keep track of it yourself? 
	 * Welp this returns 1 if open, 0 if closed
	*/
	unsigned short Position;
	i2c_read16(&i2c,addr,CGRIPPER_POSITION,&Position);
	return Position;
}

void cgripper_Open_Gripper(){
	i2c_write16(&i2c, addr, CGRIPPER_POSITION, 0x01);
}

void cgripper_Close_Gripper(){
	i2c_write16(&i2c, addr, CGRIPPER_POSITION, 0x00);
}

void cgripper_Gripper_Set_Position( unsigned short Position){
	/* 
	 * The Position is 0 closed, 1 is open, anything else is just wrong, 
	 * why are you using this command, just use open or close gripper
	 * Hell, why do we even have this function
	*/
	i2c_write16(&i2c,addr,CGRIPPER_POSITION,Position); // for testing on pi pico
}


/**********************************************/
/*************Force Sensor Functions***********/
/**********************************************/

unsigned short cgripper_ForceSensor_Get_Parallel_Force(){
	unsigned short Force;
//	knet_read8( dev , FORCE_SENSOR_FORCE , &Force );
	i2c_read16(&i2c,addr,FORCE_SENSOR_PARALLEL,&Force);
	return Force;
}
unsigned short cgripper_ForceSensor_Get_Perpendicular_Force(){
	unsigned short Force;
//	knet_read8( dev , FORCE_SENSOR_FORCE , &Force );
	i2c_read16(&i2c,addr,FORCE_SENSOR_PERPENDICULAR,&Force);
	return Force;
}

/**********************************************/
/******************LED Functions***************/
/**********************************************/
unsigned short cgripper_LEDRing_Get_Config(){
	unsigned short Config;
	i2c_read16(&i2c,addr,LED_CONFIG,&Config);
	return Config;

}
void cgripper_LEDRing_Set_Status( unsigned short Config){
	i2c_write16(&i2c,addr,LED_CONFIG,Config);
}

void testLED() {
	i2c_write16(&i2c, addr, 0x16, 0x6DB6);
	i2c_write16(&i2c, addr, 0x17, 0xDB6D);
	i2c_write16(&i2c, addr, 0x18, 0xB6DB);
	i2c_write16(&i2c, addr, 0x19, 0x6DB6);
	i2c_write16(&i2c, addr, 0x1A, 0x0001);
	int i=0;
	i2c_write16(&i2c, addr, 0xD, i);
	for(i=0; i<32; i++){
		i2c_write16(&i2c, addr, 0xD, i);
		i2c_write16(&i2c, addr, 0x1A, 0x0001);
		/* TODO : Find a time based function to change
		 * The brightness of the LED's */
	}
}

void setAllPreset1() {
	i2c_write16(&i2c, addr, 0x16, 0x5555);
	i2c_write16(&i2c, addr, 0x17, 0x5555);
	i2c_write16(&i2c, addr, 0x18, 0x5555);
	i2c_write16(&i2c, addr, 0x19, 0x5555);
	i2c_write16(&i2c, addr, 0xD, 12);
	i2c_write16(&i2c, addr, 0x1A, 0x0001);
}

void setAllPreset2() {
	i2c_write16(&i2c, addr, 0x16, 0xAAAA);
	i2c_write16(&i2c, addr, 0x17, 0xAAAA);
	i2c_write16(&i2c, addr, 0x18, 0xAAAA);
	i2c_write16(&i2c, addr, 0x19, 0xAAAA);
	i2c_write16(&i2c, addr, 0xD, 2);
	i2c_write16(&i2c, addr, 0x1A, 0x0001);
}

void setAllPreset3() {
	i2c_write16(&i2c, addr, 0x16, 0xFFFF);
	i2c_write16(&i2c, addr, 0x17, 0xFFFF);
	i2c_write16(&i2c, addr, 0x18, 0xFFFF);
	i2c_write16(&i2c, addr, 0x19, 0xFFFF);
	i2c_write16(&i2c, addr, 0xD, 2);
	i2c_write16(&i2c, addr, 0x1A, 0x0001);
}

void setAllOff() {
	i2c_write16(&i2c, addr, 0x16, 0x0000);
	i2c_write16(&i2c, addr, 0x17, 0x0000);
	i2c_write16(&i2c, addr, 0x18, 0x0000);
	i2c_write16(&i2c, addr, 0x19, 0x0000);
	i2c_write16(&i2c, addr, 0xD, 0);
	i2c_write16(&i2c, addr, 0x1A, 0x0001);
}