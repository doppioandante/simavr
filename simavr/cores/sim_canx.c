/*
	sim_canx.c

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

#include "sim_canx.h"

void canx_init(struct avr_t * avr)
{
	struct mcu_t * mcu = (struct mcu_t*)avr;

	avr_flash_init(avr, &mcu->selfprog);
	// we try to initialize this one, in case it's declared
	avr_ioport_init(avr, &mcu->porta);
}

void canx_reset(struct avr_t * avr)
{
}


