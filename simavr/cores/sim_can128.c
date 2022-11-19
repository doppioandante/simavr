/*
	sim_can128.c

	Copyright 2022 Enrico Lumetti

 	This file is part of simavr.

	simavr is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	simavr is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with simavr.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "sim_avr.h"

#define SIM_VECTOR_SIZE	2
#define SIM_MMCU		"atcan128"
#define SIM_CORENAME	mcu_can128

#define _AVR_IO_H_
#define __ASSEMBLER__
#include "avr/iocan128.h"
// instantiate the new core
#include "sim_canx.h"

static avr_t * make()
{
	return avr_core_allocate(&SIM_CORENAME.core, sizeof(struct mcu_t));
}

avr_kind_t can128 = {
	.names = { "at90can128" },
	.make = make
};