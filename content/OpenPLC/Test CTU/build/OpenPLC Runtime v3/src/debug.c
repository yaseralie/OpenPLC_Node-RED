/*
 * This file is part of OpenPLC Runtime
 *
 * Copyright (C) 2023 Autonomy, GP Orcullo
 * Based on the work by GP Orcullo on Beremiz for uC
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <stdbool.h>

#include "iec_types_all.h"
#include "POUS.h"

#define SAME_ENDIANNESS      0
#define REVERSE_ENDIANNESS   1

char plc_program_md5[] = "b6a32ad104ff154ab81b16da3cf8eb01";

uint8_t endianness;


extern MAIN RES0__INSTANCE0;

static const struct {
    void *ptr;
    __IEC_types_enum type;
} debug_vars[] = {
    {&(RES0__INSTANCE0.R_TRIG0.EN), BOOL_ENUM},
    {&(RES0__INSTANCE0.R_TRIG0.ENO), BOOL_ENUM},
    {&(RES0__INSTANCE0.R_TRIG0.CLK), BOOL_ENUM},
    {&(RES0__INSTANCE0.R_TRIG0.Q), BOOL_ENUM},
    {&(RES0__INSTANCE0.R_TRIG0.M), BOOL_ENUM},
    {&(RES0__INSTANCE0.PULSE_COUNTER), BOOL_ENUM},
    {&(RES0__INSTANCE0.CTU0.EN), BOOL_ENUM},
    {&(RES0__INSTANCE0.CTU0.ENO), BOOL_ENUM},
    {&(RES0__INSTANCE0.CTU0.CU), BOOL_ENUM},
    {&(RES0__INSTANCE0.CTU0.R), BOOL_ENUM},
    {&(RES0__INSTANCE0.CTU0.PV), INT_ENUM},
    {&(RES0__INSTANCE0.CTU0.Q), BOOL_ENUM},
    {&(RES0__INSTANCE0.CTU0.CV), INT_ENUM},
    {&(RES0__INSTANCE0.CTU0.CU_T.EN), BOOL_ENUM},
    {&(RES0__INSTANCE0.CTU0.CU_T.ENO), BOOL_ENUM},
    {&(RES0__INSTANCE0.CTU0.CU_T.CLK), BOOL_ENUM},
    {&(RES0__INSTANCE0.CTU0.CU_T.Q), BOOL_ENUM},
    {&(RES0__INSTANCE0.CTU0.CU_T.M), BOOL_ENUM},
    {&(RES0__INSTANCE0.R_TRIG1.EN), BOOL_ENUM},
    {&(RES0__INSTANCE0.R_TRIG1.ENO), BOOL_ENUM},
    {&(RES0__INSTANCE0.R_TRIG1.CLK), BOOL_ENUM},
    {&(RES0__INSTANCE0.R_TRIG1.Q), BOOL_ENUM},
    {&(RES0__INSTANCE0.R_TRIG1.M), BOOL_ENUM},
    {&(RES0__INSTANCE0.PULSE_RESET), BOOL_ENUM},
    {&(RES0__INSTANCE0.RELAY_START), BOOL_O_ENUM},
    {&(RES0__INSTANCE0.START_STATE), BOOL_O_ENUM},
    {&(RES0__INSTANCE0.RELAY_DOWNTIME), BOOL_O_ENUM},
    {&(RES0__INSTANCE0.DOWNTIME_STATE), BOOL_O_ENUM},
    {&(RES0__INSTANCE0.COUNTER_TRIGGER), BOOL_O_ENUM},
    {&(RES0__INSTANCE0.RESET_COUNTER), BOOL_O_ENUM},
    {&(RES0__INSTANCE0.COUNTER_REGISTER), INT_O_ENUM},
};

#define VAR_COUNT               31

uint16_t get_var_count(void)
{
    return VAR_COUNT;
}

size_t get_var_size(size_t idx)
{
    if (idx >= VAR_COUNT)
    {
        return 0;
    }
    switch (debug_vars[idx].type) {
    case INT_ENUM:
    case INT_O_ENUM:
        return sizeof(INT);
    case BOOL_ENUM:
    case BOOL_O_ENUM:
        return sizeof(BOOL);
    default:
        return 0;
    }
}

void *get_var_addr(size_t idx)
{
    void *ptr = debug_vars[idx].ptr;

    switch (debug_vars[idx].type) {
    case INT_ENUM:
        return (void *)&((__IEC_INT_t *) ptr)->value;
    case INT_O_ENUM:
        return (void *)((((__IEC_INT_p *) ptr)->flags & __IEC_FORCE_FLAG)
                        ? &(((__IEC_INT_p *) ptr)->fvalue)
                        : ((__IEC_INT_p *) ptr)->value);
    case BOOL_ENUM:
        return (void *)&((__IEC_BOOL_t *) ptr)->value;
    case BOOL_O_ENUM:
        return (void *)((((__IEC_BOOL_p *) ptr)->flags & __IEC_FORCE_FLAG)
                        ? &(((__IEC_BOOL_p *) ptr)->fvalue)
                        : ((__IEC_BOOL_p *) ptr)->value);
    default:
        return 0;
    }
}

void force_var(size_t idx, bool forced, void *val)
{
    void *ptr = debug_vars[idx].ptr;

    if (forced) {
        size_t var_size = get_var_size(idx);
        switch (debug_vars[idx].type) {
        case INT_ENUM: {
            memcpy(&((__IEC_INT_t *) ptr)->value, val, var_size);
            ((__IEC_INT_t *) ptr)->flags |= __IEC_FORCE_FLAG;
            break;
        }
    
        case INT_O_ENUM: {
            memcpy((((__IEC_INT_p *) ptr)->value), val, var_size);
            memcpy(&((__IEC_INT_p *) ptr)->fvalue, val, var_size);
            ((__IEC_INT_p *) ptr)->flags |= __IEC_FORCE_FLAG;
            break;
        }
        case BOOL_ENUM: {
            memcpy(&((__IEC_BOOL_t *) ptr)->value, val, var_size);
            ((__IEC_BOOL_t *) ptr)->flags |= __IEC_FORCE_FLAG;
            break;
        }
    
        case BOOL_O_ENUM: {
            memcpy((((__IEC_BOOL_p *) ptr)->value), val, var_size);
            memcpy(&((__IEC_BOOL_p *) ptr)->fvalue, val, var_size);
            ((__IEC_BOOL_p *) ptr)->flags |= __IEC_FORCE_FLAG;
            break;
        }
        default:
            break;
        }
    } else {
        switch (debug_vars[idx].type) {
        case INT_ENUM:
            ((__IEC_INT_t *) ptr)->flags &= ~__IEC_FORCE_FLAG;
            break;
        case INT_O_ENUM:
            ((__IEC_INT_p *) ptr)->flags &= ~__IEC_FORCE_FLAG;
            break;
        case BOOL_ENUM:
            ((__IEC_BOOL_t *) ptr)->flags &= ~__IEC_FORCE_FLAG;
            break;
        case BOOL_O_ENUM:
            ((__IEC_BOOL_p *) ptr)->flags &= ~__IEC_FORCE_FLAG;
            break;
        default:
            break;
        }
    }
}

void swap_bytes(void *ptr, size_t size)
{
    uint8_t *bytePtr = (uint8_t *)ptr;
    size_t i;
    for (i = 0; i < size / 2; ++i)
    {
        uint8_t temp = bytePtr[i];
        bytePtr[i] = bytePtr[size - 1 - i];
        bytePtr[size - 1 - i] = temp;
    }
}

void trace_reset(void)
{
    for (size_t i=0; i < VAR_COUNT; i++)
    {
        force_var(i, false, 0);
    }
}

void set_trace(size_t idx, bool forced, void *val)
{
    if (idx >= 0 && idx < VAR_COUNT)
    {
        if (endianness == REVERSE_ENDIANNESS)
        {
            // Prevent swapping for STRING type
            if (debug_vars[idx].type == STRING_ENUM)
            {
                // Do nothing
                ;
            }
            else
            {
                swap_bytes(val, get_var_size(idx));
            }
        }

        force_var(idx, forced, val);
    }
}

void set_endianness(uint8_t value)
{
    if (value == SAME_ENDIANNESS || value == REVERSE_ENDIANNESS)
    {
        endianness = value;
    }
}
