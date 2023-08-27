#include"StateMachine.h"
#include"stdio.h"
#include"stdlib.h"

ACTION_MAP_t actionMap[] =
{
	{ STATE1,	state1_entry,	state1_do,	state1_exit },
	{ STATE2,	state2_entry,	state2_do,	state2_exit },
	{ STATE3,	state3_entry,	state3_do,	state3_exit },
	{ STATE4,	state4_entry,	state4_do,	state4_exit },
};

EVENT_MAP_t eventMap[] =
{
	{ EVENT1,	STATE1,	STATE2 },
	{ EVENT2,	STATE2,	STATE3 },
	{ EVENT3,	STATE3,	STATE4 },
	{ EVENT4,	STATE4,	STATE1 },
	{ EVENT5,	STATE1,	STATE4 },

	{ EVENT_MAP_END,	0,	0 },
};

void fsm_init(FSM_t* pFsm, EVENT_MAP_t* pEventMap, ACTION_MAP_t *pActionMap)
{
	pFsm->stCurState = 0;
	pFsm->stNextState = EVENT_MAP_END;
	pFsm->pEventMap = pEventMap;
	pFsm->pActionMap = pActionMap;
}

void fsm_state_transfer(FSM_t* pFsm, EVENT_t stEventID)
{
	int i = 0;

	for (i = 0; pFsm->pEventMap[i].stEventID<EVENT_MAP_END; i++)
	{
		if ((stEventID == pFsm->pEventMap[i].stEventID)
			&& (pFsm->stCurState == pFsm->pEventMap[i].stCurState))
		{
			pFsm->stNextState = pFsm->pEventMap[i].stNextState;

			return;
		}
	}
}

void action_perfrom(FSM_t* pFsm)
{
	if (EVENT_MAP_END != pFsm->stNextState)
	{
		pFsm->pActionMap[pFsm->stCurState].ExitAct();
		pFsm->pActionMap[pFsm->stNextState].EnterAct();

		pFsm->stCurState = pFsm->stNextState;
		pFsm->stNextState = EVENT_MAP_END;
	}
	else
	{
		pFsm->pActionMap[pFsm->stCurState].RunningAct();
	}
}

void state1_entry(void)
{
	printf("state1_entry\n");
}
void state1_do(void)
{
	printf("state1_do\n");
}
void state1_exit(void)
{
	printf("state1_exit\n");
}

void state2_entry(void)
{
	printf("state2_entry\n");
}
void state2_do(void)
{
	printf("state2_do\n");
}
void state2_exit(void)
{
	printf("state1_exit\n");
}

void state3_entry(void)
{
	printf("state3_entry\n");
}
void state3_do(void)
{
	printf("state3_do\n");
}
void state3_exit(void)
{
	printf("state3_exit\n");
}

void state4_entry(void)
{
	printf("state4_entry\n");
}
void state4_do(void)
{
	printf("state4_do\n");
}
void state4_exit(void)
{
	printf("state4_exit\n");
}
