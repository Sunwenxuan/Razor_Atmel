/**********************************************************************************************************************
File: user_app1.c                                                                

----------------------------------------------------------------------------------------------------------------------
To start a new task using this user_app1 as a template:
 1. Copy both user_app1.c and user_app1.h to the Application directory
 2. Rename the files yournewtaskname.c and yournewtaskname.h
 3. Add yournewtaskname.c and yournewtaskname.h to the Application Include and Source groups in the IAR project
 4. Use ctrl-h (make sure "Match Case" is checked) to find and replace all instances of "user_app1" with "yournewtaskname"
 5. Use ctrl-h to find and replace all instances of "UserApp1" with "YourNewTaskName"
 6. Use ctrl-h to find and replace all instances of "USER_APP1" with "YOUR_NEW_TASK_NAME"
 7. Add a call to YourNewTaskNameInitialize() in the init section of main
 8. Add a call to YourNewTaskNameRunActiveState() in the Super Loop section of main
 9. Update yournewtaskname.h per the instructions at the top of yournewtaskname.h
10. Delete this text (between the dashed lines) and update the Description below to describe your task
----------------------------------------------------------------------------------------------------------------------

Description:
This is a user_app1.c file template 

------------------------------------------------------------------------------------------------------------------------
API:

Public functions:


Protected System functions:
void UserApp1Initialize(void)
Runs required initialzation for the task.  Should only be called once in main init section.

void UserApp1RunActiveState(void)
Runs current task state.  Should only be called once in main loop.


**********************************************************************************************************************/

#include "configuration.h"

/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_UserApp1"
***********************************************************************************************************************/
/* New variables */
volatile u32 G_u32UserApp1Flags;                       /* Global state flags */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Existing variables (defined in other files -- should all contain the "extern" keyword) */
extern volatile u32 G_u32SystemFlags;                  /* From main.c */
extern volatile u32 G_u32ApplicationFlags;             /* From main.c */

extern volatile u32 G_u32SystemTime1ms;                /* From board-specific source file */
extern volatile u32 G_u32SystemTime1s;                 /* From board-specific source file */
extern u8 G_au8DebugScanfBuffer[];  /* From debug.c */
extern u8 G_u8DebugScanfCharCount;  /* From debug.c */

/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variable names shall start with "UserApp1_" and be declared as static.
***********************************************************************************************************************/
static fnCode_type UserApp1_StateMachine;            /* The state machine function pointer */
//static u32 UserApp1_u32Timeout;                      /* Timeout counter used across states */


/**********************************************************************************************************************
Function Definitions
**********************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Public functions                                                                                                   */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Protected functions                                                                                                */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Function: UserApp1Initialize

Description:
Initializes the State Machine and its variables.

Requires:
  -

Promises:
  - 
*/
void UserApp1Initialize(void)
{
  /*
  static u32 u32Number1 = 1111;
  static u32 u32Number2 = 0;
  static u8 au8OutputPattern[128];
  u8 u8Count1 = 0;
  u8 u8Count2 = 0;
  u8 u8Index;
  u8 u8Index1;
  u8 temp;

  u32Number2 = u32Number1;
  while(u32Number2)
  {
    u32Number2 = u32Number2/10;
    u8Count1++;
  }
  
 
  for(u8Index = 0;u8Index<(2+u8Count1);u8Index++)
  {
    au8OutputPattern[u8Index] = '*';  
  }
  au8OutputPattern[u8Index] = '\n';
  u8Index++;
  au8OutputPattern[u8Index] = '\r';
  u8Index++;
  au8OutputPattern[u8Index] = '*';
  u8Index++;
  
  while(u32Number1)
  {
     au8OutputPattern[u8Index] = ((u32Number1%10)+0x30);
     u32Number1 = u32Number1/10;
     u8Index++;
     u8Count2++;
  }
  
  
  
  for(u8 i = 0;i<u8Count2/2;i++)
  {
      temp = au8OutputPattern[i+u8Index-u8Count2];
      au8OutputPattern[i+u8Index-u8Count2] = au8OutputPattern[u8Index-i-1];
      au8OutputPattern[u8Index-i-1] = temp;
  }


  au8OutputPattern[u8Index] = '*';
  u8Index++;
  au8OutputPattern[u8Index] = '\n';
  u8Index++;
  au8OutputPattern[u8Index] = '\r';
  u8Index1 = u8Index+1;
  for(u8Index = u8Index1;u8Index<(u8Index1+2+u8Count1);u8Index++)
  {
     au8OutputPattern[u8Index] = '*';  
  }
  au8OutputPattern[u8Index] = '\n';
  u8Index++;
  au8OutputPattern[u8Index] = '\r';
  u8Index++;
  au8OutputPattern[u8Index] = '\0';
    
  DebugPrintf(au8OutputPattern);
  
 */
     
  /* If good initialization, set state to Idle */
  if( 1 )
  {
    UserApp1_StateMachine = UserApp1SM_Idle;
  }
  else
  {
    /* The task isn't properly initialized, so shut it down and don't run */
    UserApp1_StateMachine = UserApp1SM_FailedInit;
  }

} /* end UserApp1Initialize() */

  
/*----------------------------------------------------------------------------------------------------------------------
Function UserApp1RunActiveState()

Description:
Selects and runs one iteration of the current state in the state machine.
All state machines have a TOTAL of 1ms to execute, so on average n state machines
may take 1ms / n to execute.

Requires:
  - State machine function pointer points at current state

Promises:
  - Calls the function to pointed by the state machine function pointer
*/
void UserApp1RunActiveState(void)
{
  UserApp1_StateMachine();

} /* end UserApp1RunActiveState */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Private functions                                                                                                  */
/*--------------------------------------------------------------------------------------------------------------------*/


/**********************************************************************************************************************
State Machine Function Definitions
**********************************************************************************************************************/

/*-------------------------------------------------------------------------------------------------------------------*/
/* Wait for ??? */
static void UserApp1SM_Idle(void)
{ 
  static u8 au8RealName[3] = {'s','w','x'};
  static u8 *u8p = au8RealName;
  static u32 auInputData[100];
  static u32 u32Number1 = 0;
  static u32 u32Number2 = 0;
  static u8 au8OutputPattern[128];
  static u8 u8i = 0;
  static u8 u8CharCount;
  u8 u8Count1 = 0;
  u8 u8Count2 = 0;
  u8 u8Index;
  u8 u8Index1;
  u8 temp;
  static bool bswitch1 = FALSE;
  static bool bswitch2 = FALSE;
  static bool bswitch3 = FALSE;  
  static bool bswitch = TRUE;
  extern u8 G_au8DebugScanfBuffer[]
  
  if(bswitch)
  {
    if(G_u8DebugScanfCharCount == 1)
    {
      if(G_au8DebugScanfBuffer[0] == *u8p)
      {
        u8p++;
        u8i++;
        bswitch1 = TRUE;
        u8CharCount = DebugScanf(UserApp_au8UserInputBuffer);
        UserApp_au8UserInputBuffer[u8CharCount] = '\0';
        DebugPrintf(u8BufferMessage);
        DebugScanf(G_au8DebugScanfBuffer);
        bswitch = FALSE;
      }
      else
      {
        u8p = au8RealName;
        DebugScanf(G_au8DebugScanfBuffer);
      }
    }
    
  }

  
  if(bswitch1)
  {
    if(G_u8DebugScanfCharCount == 1)
    {
      if(G_au8DebugScanfBuffer[0] == *u8p)
      {
        u8p++;
        u8i++;
        bswitch2 = TRUE;
        bswitch1 = FALSE;
        DebugScanf(G_au8DebugScanfBuffer);
      }
      else
      {
        u8p = au8RealName;
        u8i = 0;
        DebugScanf(G_au8DebugScanfBuffer);
        bswitch = TRUE;
      }   
    }
  }
  
  
  if(bswitch2)
  {
    if(G_u8DebugScanfCharCount == 1)
    {
      if(G_au8DebugScanfBuffer[0] == *u8p)
      {
        u8p = au8RealName;
        u8i++;
        bswitch2 = FALSE;
        DebugScanf(G_au8DebugScanfBuffer);
      }
      else
      {
        u8p = au8RealName;
        u8i = 0;
        DebugScanf(G_au8DebugScanfBuffer);
        bswitch = TRUE;      
      }
      if(u8i == 3)
      {
        u32Number1++;
        bswitch3 = TRUE;
      }
    }
  }
  
  
  if(bswitch3)
  {
    u32Number2 = u32Number1;
    while(u32Number2)
    {
      u32Number2 = u32Number2/10;
      u8Count1++;
    }
    
   
    for(u8Index = 0;u8Index<(2+u8Count1);u8Index++)
    {
      au8OutputPattern[u8Index] = '*';  
    }
    au8OutputPattern[u8Index] = '\n';
    u8Index++;
    au8OutputPattern[u8Index] = '\r';
    u8Index++;
    au8OutputPattern[u8Index] = '*';
    u8Index++;
    
    while(u32Number1)
    {
       au8OutputPattern[u8Index] = ((u32Number1%10)+0x30);
       u32Number1 = u32Number1/10;
       u8Index++;
       u8Count2++;
    }
    
    
    
    for(u8 i = 0;i<u8Count2/2;i++)
    {
        temp = au8OutputPattern[i+u8Index-u8Count2];
        au8OutputPattern[i+u8Index-u8Count2] = au8OutputPattern[u8Index-i-1];
        au8OutputPattern[u8Index-i-1] = temp;
    }


    au8OutputPattern[u8Index] = '*';
    u8Index++;
    au8OutputPattern[u8Index] = '\n';
    u8Index++;
    au8OutputPattern[u8Index] = '\r';
    u8Index1 = u8Index+1;
    for(u8Index = u8Index1;u8Index<(u8Index1+2+u8Count1);u8Index++)
    {
       au8OutputPattern[u8Index] = '*';  
    }
    au8OutputPattern[u8Index] = '\n';
    u8Index++;
    au8OutputPattern[u8Index] = '\r';
    u8Index++;
    au8OutputPattern[u8Index] = '\0';
      
    DebugPrintf(au8OutputPattern);
    bswitch3 = FALSE;
  }
  
  
} /* end UserApp1SM_Idle() */
    
#if 0
/*-------------------------------------------------------------------------------------------------------------------*/
/* Handle an error */
static void UserApp1SM_Error(void)          
{
  
  
} /* end UserApp1SM_Error() */
#endif


/*-------------------------------------------------------------------------------------------------------------------*/
/* State to sit in if init failed */
static void UserApp1SM_FailedInit(void)          
{
    
} /* end UserApp1SM_FailedInit() */


/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/
