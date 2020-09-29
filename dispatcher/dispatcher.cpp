/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 29, 2020
 *      Author: Tim Siltz
 */

#include "../includes/dispatcher.h"
#include "../includes/CPU.h"
#include "../includes/PCB.h"

using namespace std;

	//pull current process (if any) off CPU and return it
	//if nothing on CPU returns an uninitialized PCB
	PCB Dispatcher::get_from_CPU(){
		return PCB();
	}

	//place the current process on the CPU for execution
	void Dispatcher::put_on_CPU(PCB &process){
		//current_Process = &process;
	}

	//is CPU idle or working
	bool Dispatcher::isValidJobOnCPU(){
		//return is_valid_job_on_cpu;
		return false;
	}
