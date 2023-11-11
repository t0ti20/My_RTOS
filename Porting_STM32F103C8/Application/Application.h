/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Application.h
 *  Module:  Application
 *  Description:  Application Interface File
*******************************************************************/
#ifndef _APPLICATION_H_
#define _APPLICATION_H_
/********************************************************************/
/*****************************************
----------   Include Files    ------------
*****************************************/
#include "RTOS.h"
#include "GPIO_Interface.h"
/*****************************************
---  Application Programming Interface  --
*****************************************/
void Task_1_Function(void);
void Task_2_Function(void);
void Task_3_Function(void);
void Idle_Task_Function(void);
void Context_Switch_Function(void);
void System_Initialization(void);
/********************************************************************
 *  END OF FILE:  Application.h
********************************************************************/
#endif
