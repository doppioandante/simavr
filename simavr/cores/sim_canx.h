/*
	sim_canx.h

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

#ifndef __SIM_CAN_128_H
#define __SIM_CAN_128_H

#include "sim_core_declare.h"
#include "avr_flash.h"
#include "avr_ioport.h"

void canx_init(struct avr_t* avr);
void canx_reset(struct avr_t* avr);

/*
 * This is a template for can32, can64 and can128
 */
struct mcu_t {
	avr_t          core;
	avr_flash_t 	selfprog;
	avr_ioport_t	porta;
};

#ifdef SIM_CORENAME

#ifndef SIM_VECTOR_SIZE
#error SIM_VECTOR_SIZE is not declared
#endif
#ifndef SIM_MMCU
#error SIM_MMCU is not declared
#endif

#ifndef EFUSE_DEFAULT
#define EFUSE_DEFAULT 0xff
#endif

// this seems to be missing in the AVR libc headers
// but it is common to all at90can mcus
#define SPM_RDY_vect _VECTOR(37)

const struct mcu_t SIM_CORENAME = {
	.core = {
		.mmcu = SIM_MMCU,
		DEFAULT_CORE(SIM_VECTOR_SIZE),

		.init = canx_init,
		.reset = canx_reset,
	},
	AVR_SELFPROG_DECLARE(SPMCSR, SPMEN, SPM_RDY_vect),
	AVR_IOPORT_DECLARE(a, 'A', A),
};

#endif // SIM_CORENAME

#endif // __SIM_CAN_128_H
