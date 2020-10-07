/*
 * Scheduler_RR.cpp
 *
 *  Created on: Sep 29, 2020
 *      Author: Tim Siltz
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */

#include "../includes/scheduler_RR.h"

//override base class behavior if necessary, otherwise call it
bool Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p) {
	if (p.remaining_cpu_time <= 0) {
		return true;
	}

	if (((p.remaining_cpu_time - p.required_cpu_time) % time_slice == 0)
			&& preemptive) {
		return true;
	}

	else {
		return false;
	}
}

//RR - preemptive - no sorting of ready_q needed.
void Scheduler_RR::sort() {

}
