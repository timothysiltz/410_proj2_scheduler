/*
 * Stats.cpp
 *
 *  Created on: Sep 29, 2020
 *      Author: Tim Siltz
 */

#include "../includes/stats.h"

Stats::Stats(std::vector<PCB> &finished_vector) {
	vec = &finished_vector;
	av_response_time = 0.00;
	av_turnaround_time = 0.00;
	av_wait_time = 0.00;
}

//loops thru vec, prints 1 line for each process using the following format
//Process 1 Required CPU time:2  arrived:0 started:0 finished:2
//if there are 10 processes in vector, should print 10 lines
void Stats::showAllProcessInfo() {
	//got a warning just using int
	for (long unsigned int i = 0; i < vec->size(); i++) {
		std::cout << "Process " << (i + 1) << " Required CPU time "
				<< vec->at(i).remaining_cpu_time << " arrived:"
				<< vec->at(i).arrival_time << " started:"
				<< vec->at(i).start_time << " finished:"
				<< vec->at(i).finish_time;
	}
}

//after a process is placed in the ready_q, how long does
//it take before its placed on the processor?
//response_time per process = start_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_response_time() {
	double temp = 0.00;

	//got a warning just using int
	for (long unsigned int i = 0; i < vec->size(); i++) {
		av_response_time = (vec->at(i).start_time - vec->at(i).arrival_time);
		temp += av_response_time;
	}

	temp /= vec->size();

	return temp;
}

//after a process is placed in the ready_q, how long does
//it take to complete?
//turnaround time per process = finish_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_turnaround_time() {
	double temp = 0.00;

	//got a warning just using int
	for (long unsigned int i = 0; i < vec->size(); i++) {
		av_turnaround_time = (vec->at(i).finish_time - vec->at(i).arrival_time);
		temp += av_turnaround_time;
	}

	temp /= vec->size();

	return temp;
}

//after a process is placed in the ready_q, how much time does it
//spend waiting for processor time?
//wait time per process = finish_time - arrival_time-required_CPU_time
//this funtion returns the average over all processes
float Stats::get_av_wait_time() {
	double temp = 0.00;

	//got a warning just using int
	for (long unsigned int i = 0; i < vec->size(); i++) {
		av_wait_time = (vec->at(i).finish_time - vec->at(i).arrival_time
				- vec->at(i).required_cpu_time);
		temp += av_wait_time;
	}

	temp /= vec->size();

	return temp;
}
