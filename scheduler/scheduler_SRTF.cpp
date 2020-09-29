/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 29, 2020
 *      Author: Tim Siltz
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

#include "../includes/scheduler_SRTF.h"

	//override base class behaviour if necessary, otherwise call it
	bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p){
		if (tick_count == 0){
			return true;
		}

		return false;
	}

	//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
	void Scheduler_SRTF::sort(){

	}
