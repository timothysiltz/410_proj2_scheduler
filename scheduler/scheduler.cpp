/*
 * scheduler.cpp
 *
 *  Created on: Sep 29, 2020
 *      Author: Tim Siltz
 */

#include "../includes/scheduler.h"

using namespace std;

//add a process, either a new one or one that
//had been running on the CPU and has been preempted
void Scheduler::add(PCB p) {
	ready_q->push(p);
}

//get next process
PCB Scheduler::getNext() {
	PCB next = ready_q->front();
	return next;
}

//returns true if there are no  jobs in the readyQ
//false otherwise
bool Scheduler::isEmpty() {
	if (ready_q->empty()) {
		return true;
	}

	return false;
}

//if process has completed (used all its remaining_cpu_time) or
//if we are using a preemptive scheduling algorithm and the
//timeslice is over then its time to switch processes
//returns:
//true - switch processes
//false - do not switch
bool Scheduler::time_to_switch_processes(int tick_count, PCB &p) {
	time_slice = tick_count;
	if (time_slice == 0 && preemptive) {
		return true;
	}

	return false;
}

//sort ready_q based on the scheduler algorithm used whenever add(PCB p) is called
//pure virtual function
void Scheduler::sort() {

}
