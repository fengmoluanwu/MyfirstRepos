#pragma once
typedef enum {
	STATE1 = 0,
	STATE2,
	STATE3,
	STATE4,
}STATE_t;

typedef void(*STATE_ACTION)(void);

typedef struct ACTION_MAP
{
	STATE_t 		stStateID;
	STATE_ACTION 	EnterAct;
	STATE_ACTION 	RunningAct;
	STATE_ACTION 	ExitAct;
}ACTION_MAP_t;

typedef enum
{
	EVENT1 = 0,
	EVENT2,
	EVENT3,
	EVENT4,
	EVENT5,
	EVENT_MAP_END
}EVENT_t;

typedef struct EVENT_MAP
{
	EVENT_t	stEventID;
	STATE_t stCurState;
	STATE_t stNextState;
}EVENT_MAP_t;

typedef struct FSM
{
	STATE_t stCurState;
	STATE_t stNextState;
	ACTION_MAP_t *pActionMap;
	EVENT_MAP_t *pEventMap;
}FSM_t;

extern ACTION_MAP_t actionMap[];
extern EVENT_MAP_t eventMap[];

void fsm_init(FSM_t* pFsm, EVENT_MAP_t* pEventMap, ACTION_MAP_t *pActionMap);
void fsm_state_transfer(FSM_t* pFsm, EVENT_t stEventID);
void action_perfrom(FSM_t* pFsm);

void state1_entry(void);

void state1_do(void);

void state1_exit(void);


void state2_entry(void);

void state2_do(void);

void state2_exit(void) ;
					  
void state3_entry(void);
					   
void state3_do(void)   ;
					   
void state3_exit(void) ;
					   
void state4_entry(void);
					  
void state4_do(void)   ;
					  
void state4_exit(void) ;
