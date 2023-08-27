#include"stdio.h"
#include"stdlib.h"
#include"StateMachine.h"

int main(void)
{
	int i = 0;
	FSM_t stFsmWeather;	//����״̬��

	fsm_init(&stFsmWeather, eventMap, actionMap);	//ע��״̬��

	while (1)
	{
		//usleep(10);
		printf("i = %d\n", i++);

		action_perfrom(&stFsmWeather);

		//����i����EVENT1~EVENT5
		if (0 == (i % 11))
		{
			fsm_state_transfer(&stFsmWeather, EVENT1);
		}

		if (0 == (i % 31))
		{
			fsm_state_transfer(&stFsmWeather, EVENT2);
		}

		if (0 == (i % 74))
		{
			fsm_state_transfer(&stFsmWeather, EVENT3);
		}

		if (0 == (i % 13))
		{
			fsm_state_transfer(&stFsmWeather, EVENT4);
		}

		if (0 == (i % 19))
		{
			fsm_state_transfer(&stFsmWeather, EVENT5);
		}
	}

	return 0;
}
