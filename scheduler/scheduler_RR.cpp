/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 29, 2020
 *      Author: Tim Siltz
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */

#include "../includes/scheduler_RR.h"

	//override base class behaviour if necessary, otherwise call it
	bool Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p){
		if (tick_count == 0){
			return true;
		}

		return false;
	}

	//RR - preemptive - no sorting of ready_q needed.
	void Scheduler_RR::sort(){

	}
