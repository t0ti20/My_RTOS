#define TEST_CASE_NUMBER                (3)
#if TEST_CASE_NUMBER == 1
/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Application.c
 *  Module:  Application
 *  Description:  Main Application Logic File
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "Application.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/*Create Tasks Data*/
static RTOS_Task_t Task_1={255,"Task_1",512,Task_1_Function};
static RTOS_Task_t Task_2={255,"Task_2",512,Task_2_Function};
static RTOS_Task_t Task_3={255,"Task_3",512,Task_3_Function};
/****************************************/
int main(void) 
{
	/*Configure Required Hardware*/
	System_Initialization();
	/*Create Tasks In System*/
	RTOS_Create_Task(Task_1);
	RTOS_Create_Task(Task_2);
	RTOS_Create_Task(Task_3);
	/*Activate Tasks In System*/
    	RTOS_Activate_Task(Task_1);
    	RTOS_Activate_Task(Task_2);
    	RTOS_Activate_Task(Task_3);
	/*Configure Idle Task Function*/
	RTOS_Idle_Task(Idle_Task_Function);
	/*Configure Hook Function For Context Switch*/
	RTOS_Context_Switch_Hook_Function(Context_Switch_Function);
	/*Turn On Operating System By Running Activated Tasks*/
	RTOS_Run_Tasks();
	while (1){}
}
/****************************************/
void Context_Switch_Function(void)
{
	MCAL_GPIO_Write_Port(GPIO_A,0);
}
/****************************************/
void Idle_Task_Function(void)
{
	MCAL_GPIO_Write_Pin(GPIO_A,Pin_0,HI);
}
/****************************************/
void  __attribute__((noreturn)) Task_1_Function(void)
{
	while (1)
	{
		for(u32 Counter=0;Counter<9000;Counter++){MCAL_GPIO_Write_Pin(GPIO_A,Pin_1,HI);}
	}
}
/****************************************/
void __attribute__((noreturn)) Task_2_Function(void)
{
    while (1)
	{
		for(u32 Counter=0;Counter<9000;Counter++){MCAL_GPIO_Write_Pin(GPIO_A,Pin_2,HI);}
	}
}
/****************************************/
void __attribute__((noreturn)) Task_3_Function(void)
{
	while (1)
	{
		for(u32 Counter=0;Counter<9000;Counter++){MCAL_GPIO_Write_Pin(GPIO_A,Pin_3,HI);}
	}
}
/****************************************/
void System_Initialization(void)
{
	/*Configure Pins For Testing RTOS*/
	GPIO_Pin_Config_t Pin={Pin_0,Output_Push_Pull,Output_10};
	MCAL_GPIO_Initialize(GPIO_A,Pin);
    	Pin.Pin_Number=Pin_1;
	MCAL_GPIO_Initialize(GPIO_A,Pin);
	Pin.Pin_Number=Pin_2;
	MCAL_GPIO_Initialize(GPIO_A,Pin);
	Pin.Pin_Number=Pin_3;
	MCAL_GPIO_Initialize(GPIO_A,Pin);
	/*Run RTOS Initialization Function To Configure RTOS HW*/
	RTOS_Initialize();
}
/********************************************************************
 *  END OF FILE:  Application.c
********************************************************************/
#elif TEST_CASE_NUMBER == 2
/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Application.c
 *  Module:  Application
 *  Description:  Main Application Logic File
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "Application.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/*Create Tasks Data*/
static RTOS_Task_t Task_1={1,"Task_1",512,Task_1_Function};
static RTOS_Task_t Task_2={2,"Task_2",512,Task_2_Function};
static RTOS_Task_t Task_3={3,"Task_3",512,&Task_3_Function};
/****************************************/
int main(void) 
{
	/*Configure Required Hardware*/
	System_Initialization();
	/*Create Tasks In System*/
	RTOS_Create_Task(Task_1);
	RTOS_Create_Task(Task_2);
	RTOS_Create_Task(Task_3);
	/*Activate Tasks In System*/
    	RTOS_Activate_Task(Task_1);
    	RTOS_Activate_Task(Task_2);
    	RTOS_Activate_Task(Task_3);
	/*Configure Idle Task Function*/
	RTOS_Idle_Task(Idle_Task_Function);
	/*Configure Hook Function For Context Switch*/
	RTOS_Context_Switch_Hook_Function(Context_Switch_Function);
	/*Turn On Operating System By Running Activated Tasks*/
	RTOS_Run_Tasks();
	while (1){}
}
/****************************************/
void Context_Switch_Function(void)
{
	MCAL_GPIO_Write_Port(GPIO_A,0);
}
/****************************************/
void Idle_Task_Function(void)
{
	MCAL_GPIO_Write_Pin(GPIO_A,Pin_0,HI);
}
/****************************************/
void  __attribute__((noreturn)) Task_1_Function(void)
{
	while (1)
	{
		for(u32 Counter=0;Counter<500;Counter++){MCAL_GPIO_Write_Pin(GPIO_A,Pin_1,HI);}
		RTOS_Delay(100);
	}
}
/****************************************/
void __attribute__((noreturn)) Task_2_Function(void)
{
    while (1)
	{
        for(u32 Counter=0;Counter<1000;Counter++){MCAL_GPIO_Write_Pin(GPIO_A,Pin_2,HI);}
        RTOS_Delay(400);
	}
}
/****************************************/
void __attribute__((noreturn)) Task_3_Function(void)
{
	while (1)
	{
        for(u32 Counter=0;Counter<1500;Counter++){MCAL_GPIO_Write_Pin(GPIO_A,Pin_3,HI);}
        RTOS_Delay(800);
	}
}
/****************************************/
void System_Initialization(void)
{
	/*Configure Pins For Testing RTOS*/
	GPIO_Pin_Config_t Pin={Pin_0,Output_Push_Pull,Output_10};
	MCAL_GPIO_Initialize(GPIO_A,Pin);
    	Pin.Pin_Number=Pin_1;
	MCAL_GPIO_Initialize(GPIO_A,Pin);
	Pin.Pin_Number=Pin_2;
	MCAL_GPIO_Initialize(GPIO_A,Pin);
	Pin.Pin_Number=Pin_3;
	MCAL_GPIO_Initialize(GPIO_A,Pin);
	/*Run RTOS Initialization Function To Configure RTOS HW*/
	RTOS_Initialize();
}
/********************************************************************
 *  END OF FILE:  Application.c
********************************************************************/
#elif TEST_CASE_NUMBER == 3
/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Application.c
 *  Module:  Application
 *  Description:  Main Application Logic File
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "Application.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
static RTOS_Mutex_t Mutex_1={.Name="Task_1"};
/*Create Tasks Data*/
static RTOS_Task_t Task_1={1,"Task_1",512,Task_1_Function};
static RTOS_Task_t Task_2={2,"Task_2",512,Task_2_Function};
static RTOS_Task_t Task_3={3,"Task_3",512,&Task_3_Function};
/****************************************/
int main(void) 
{
	/*Configure Required Hardware*/
	System_Initialization();
	/*Create Tasks In System*/
	RTOS_Create_Task(Task_1);
	RTOS_Create_Task(Task_2);
	RTOS_Create_Task(Task_3);
	/*Activate Tasks In System*/
    	//RTOS_Activate_Task(Task_1);
    	RTOS_Activate_Task(Task_2);
    	RTOS_Activate_Task(Task_3);
	/*Configure Idle Task Function*/
	RTOS_Idle_Task(Idle_Task_Function);
	/*Configure Hook Function For Context Switch*/
	RTOS_Context_Switch_Hook_Function(Context_Switch_Function);
	/*Turn On Operating System By Running Activated Tasks*/
	RTOS_Run_Tasks();
	while (1){}
}
/****************************************/
void Context_Switch_Function(void)
{
	MCAL_GPIO_Write_Port(GPIO_A,0);
}
/****************************************/
void Idle_Task_Function(void)
{
	MCAL_GPIO_Write_Pin(GPIO_A,Pin_0,HI);
}
/****************************************/
void  __attribute__((noreturn)) Task_1_Function(void)
{
	MCAL_GPIO_Write_Pin(GPIO_A,Pin_1,HI);
	RTOS_Mutex_Aquire(&Mutex_1);
	while (1)
	{
		for(u32 Counter=0;Counter<5000;Counter++){MCAL_GPIO_Write_Pin(GPIO_A,Pin_1,HI);}
	}
}
/****************************************/
void __attribute__((noreturn)) Task_2_Function(void)
{
    while (1)
	{
		for(u32 Counter=0;Counter<10000;Counter++){MCAL_GPIO_Write_Pin(GPIO_A,Pin_2,HI);}
		RTOS_Delay(50);
	}
}
/****************************************/
void __attribute__((noreturn)) Task_3_Function(void)
{
	RTOS_Mutex_Aquire(&Mutex_1);
    for(u32 Counter=0;Counter<9000;Counter++){MCAL_GPIO_Write_Pin(GPIO_A,Pin_3,HI);}
	RTOS_Activate_Task(Task_1);
    for(u32 Counter=0;Counter<9000;Counter++){MCAL_GPIO_Write_Pin(GPIO_A,Pin_3,HI);}
	RTOS_Mutex_Release(&Mutex_1);
	while (1)
	{
        for(u32 Counter=0;Counter<4000;Counter++){MCAL_GPIO_Write_Pin(GPIO_A,Pin_3,HI);}
	}
}
/****************************************/
void System_Initialization(void)
{
	/*Configure Pins For Testing RTOS*/
	GPIO_Pin_Config_t Pin={Pin_0,Output_Push_Pull,Output_10};
	MCAL_GPIO_Initialize(GPIO_A,Pin);
    	Pin.Pin_Number=Pin_1;
	MCAL_GPIO_Initialize(GPIO_A,Pin);
	Pin.Pin_Number=Pin_2;
	MCAL_GPIO_Initialize(GPIO_A,Pin);
	Pin.Pin_Number=Pin_3;
	MCAL_GPIO_Initialize(GPIO_A,Pin);
	/*Run RTOS Initialization Function To Configure RTOS HW*/
	RTOS_Initialize();
}
/********************************************************************
 *  END OF FILE:  Application.c
********************************************************************/
#endif
