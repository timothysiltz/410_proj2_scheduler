/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 29, 2020
 *      Author: Tim Siltz
 *
 *      implements FIFO scheduling algorithm
 *      not pre-emptive
 */

#include "../includes/scheduler_FIFO.h"

	//override base class behaviour if necessary, otherwise call it
	bool Scheduler_FIFO::time_to_switch_processes(int tick_count, PCB &p){
		if (tick_count == 0){
			return true;
		}

		return false;
	}

	//FIFO - not preemptive - no sorting needed
	void Scheduler_FIFO::sort(){

	}
