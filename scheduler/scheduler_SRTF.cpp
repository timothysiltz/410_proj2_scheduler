/*
 * Scheduler_SRTF.cpp
 *
 *  Created on: Sep 29, 2020
 *      Author: Tim Siltz
 *
 *     implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

#include <algorithm>
#include "../includes/scheduler_SRTF.h"

//declare srtf sort
bool SRTF_sort(PCB a, PCB b);

//sort processes
bool SRTF_sort(PCB a, PCB b) {
	if (a.remaining_cpu_time < b.remaining_cpu_time) {
		return true;
	}

	else {
		return false;
	}
}

//override base class behaviour if necessary, otherwise call it
bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	if (p.remaining_cpu_time <= 0) {
		return true;
	}

	if ((ready_q->empty() != true)
			&& (ready_q->front().remaining_cpu_time < p.remaining_cpu_time)) {
		return true;
	}

	else {
		return false;
	}
}

//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
void Scheduler_SRTF::sort() {
	std::vector<PCB> temp_q;

	while (ready_q->empty() != true) {
		temp_q.push_back(ready_q->front());
		ready_q->pop();
	}

	std::sort(temp_q.begin(), temp_q.end(), SRTF_sort);

	for (PCB process : temp_q) {
		ready_q->push(process);
	}
}
