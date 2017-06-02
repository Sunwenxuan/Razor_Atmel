/**********************************************************************************************************************
File: user_app1.c                                                                

Description:
Provides a Tera-Term driven system to display, read and write an LED command list.

------------------------------------------------------------------------------------------------------------------------
API:

Public functions:
None.

Protected System functions:
void UserApp1Initialize(void)
Runs required initialzation for the task.  Should only be called once in main init section.

void UserApp1RunActiveState(void)
Runs current task state.  Should only be called once in main loop.


**********************************************************************************************************************/

#include "configuration.h"

/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_"
***********************************************************************************************************************/
/* New variables */
volatile u32 G_u32UserApp1Flags;                       /* Global state flags */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Existing variables (defined in other files -- should all contain the "extern" keyword) */
extern volatile u32 G_u32SystemFlags;                  /* From main.c */
extern volatile u32 G_u32ApplicationFlags;             /* From main.c */

extern volatile u32 G_u32SystemTime1ms;                /* From board-specific source file */
extern volatile u32 G_u32SystemTime1s;                 /* From board-specific source file */

extern u8 G_au8DebugScanfBuffer[DEBUG_SCANF_BUFFER_SIZE]; /* From debug.c */
extern u8 G_u8DebugScanfCharCount;                        /* From debug.c */


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
  u8 au8UserApp1Start1[] = "LED program task started\n\r";
  
  /* Turn off the Debug task command processor and announce the task is ready */
  DebugSetPassthrough();
  DebugPrintf(au8UserApp1Start1);
  
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
static u8 DebugPrintfWord1(void)
{
  static u8 au8HeadWord1[]="******************************************************";
  static u8 au8HeadWord2[]="LED Programming Interface"; 
  static u8 au8HeadWord3[]="Press 1 to program LED command sequence"; 
  static u8 au8HeadWord4[]="Press 2 to show current USER program";
  static u8 au8HeadWord5[]="******************************************************";
  
  DebugLineFeed();
  DebugPrintf(au8HeadWord1);
  DebugLineFeed();
  DebugPrintf(au8HeadWord2);
  DebugLineFeed();
  DebugPrintf(au8HeadWord3);
  DebugLineFeed();
  DebugPrintf(au8HeadWord4);
  DebugLineFeed();
  DebugPrintf(au8HeadWord5); 
  DebugLineFeed();  
}

static u8 DebugPrintfWord2(void)
{
  static u8 au8HeadWord6[]="Enter commands as LED-ONTIME-OFFTIME and press Enter";
  static u8 au8HeadWord7[]="Time is in milliseconds,max 100 commands";
  static u8 au8HeadWord8[]="LED colors: R,O,Y,G,C,B,P,W";
  static u8 au8HeadWord9[]="Example: R-100-200(Red on at 100ms and off at 200ms)";  
  static u8 au8HeadWord10[]="Press Enter on blank line to end";   
  
  DebugLineFeed();
  DebugLineFeed();
  DebugPrintf(au8HeadWord6);
  DebugLineFeed();
  DebugPrintf(au8HeadWord7);
  DebugLineFeed();
  DebugPrintf(au8HeadWord8);
  DebugLineFeed();
  DebugPrintf(au8HeadWord9);
  DebugLineFeed();
  DebugPrintf(au8HeadWord10);
  DebugLineFeed();
}


static u8 u8ColorTransform(u8 *u8a)
{
  s8 s8Color;
  if(*u8a == 'W')
  {
    s8Color = WHITE;
  }
  if(*u8a == 'P')
  {
    s8Color = PURPLE;
  }
  if(*u8a == 'B')
  {
    s8Color = BLUE;
  }  
  if(*u8a == 'C')
  {
    s8Color = CYAN;
  }
  if(*u8a == 'G')
  {
    s8Color = GREEN;
  }
  if(*u8a == 'Y')
  {
    s8Color = YELLOW;
  }
  if(*u8a == 'O')
  {
    s8Color = ORANGE;
  }
  if(*u8a == 'R')
  {
    s8Color = RED;
  }
  return s8Color;
}

static u8 u8PowersOfTen(u8 u8Counter)
{
  u8 u8PowersOfTenResult = 1;
  static u8 u8i1;
  for(u8i1 = 0;u8i1 < u8Counter-1;u8i1++)
  {
    u8PowersOfTenResult *= 10;
  }
  return u8PowersOfTenResult;
}
/**********************************************************************************************************************
State Machine Function Definitions
**********************************************************************************************************************/

/*-------------------------------------------------------------------------------------------------------------------*/
/* Wait for input */
static void UserApp1SM_Idle(void)
{
  static u8 *u8p = G_au8DebugScanfBuffer;
  static bool bswitch1 = TRUE;
  static bool bswitch2 = TRUE;
  static bool bswitch3 = FALSE;  
  static LedCommandType LED;  
  static u8 u8Index = 2;
  static u8 u8i;
  static u8 u8Counter1 = 0;
  static u8 u8Counter2 = 0;  
  static u8 u8StartTime = 0;
  static u8 u8EndTime = 0;  
  
  if(bswitch2)
  {
    DebugPrintfWord1(); 
    bswitch2 = FALSE;
  }
  
  if(bswitch1)
  {
    if(G_u8DebugScanfCharCount == 1)
    {
      if(*u8p == '1')
      {
        DebugPrintfWord2();
        DebugScanf(G_au8DebugScanfBuffer);
        bswitch1 = FALSE;
        bswitch3 = TRUE;      
      }
    }
  }
  
  if(bswitch3)
  {
    LED.eLED = u8ColorTransform(u8p);
    while(G_au8DebugScanfBuffer[u8Index]!='-')
    {
      u8Index++;
      u8Counter1++;
    }
    while(G_au8DebugScanfBuffer[u8Index+u8Counter1+1]!='\r')
    {
      u8Index++;
      u8Counter2++;
    }
    for(u8i = 0;u8i < u8Counter1;u8i++)
    {
     u8StartTime += (G_au8DebugScanfBuffer[u8i+2]-0x30)*u8PowersOfTen(u8Counter1-u8i);  
    }
    LED.u32Time = u8StartTime;
    LED.bOn = TRUE;
    LedDisplayAddCommand(USER_LIST,&LED);
    
    for(u8i = 0;u8i < u8Counter2;u8i++)
    {
      u8EndTime += (G_au8DebugScanfBuffer[u8i+u8Index+u8Counter1+1]-0x30)*u8PowersOfTen(u8Counter2-u8i);
    }
    LED.u32Time = u8EndTime;
    LED.bOn = FALSE;
    LedDisplayAddCommand(USER_LIST,&LED);
    
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
