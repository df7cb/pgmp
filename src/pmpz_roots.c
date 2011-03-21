/* pmpz_roots -- root extraction functions
 *
 * Copyright (C) 2011 Daniele Varrazzo
 *
 * This file is part of the PostgreSQL GMP Module
 *
 * The PostgreSQL GMP Module is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the License,
 * or (at your option) any later version.
 *
 * The PostgreSQL GMP Module is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser
 * General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with the PostgreSQL GMP Module.  If not, see
 * http://www.gnu.org/licenses/.
 */

#include "pmpz.h"
#include "pgmp-impl.h"

#include "fmgr.h"
#include "funcapi.h"


/* Function with a more generic signature are defined in pmpz.arith.c */

PGMP_PG_FUNCTION(pmpz_perfect_power)
{
    const mpz_t     z1;

    mpz_from_pmpz(z1, PG_GETARG_PMPZ(0));

    PG_RETURN_BOOL(mpz_perfect_power_p(z1));
}

PGMP_PG_FUNCTION(pmpz_perfect_square)
{
    const mpz_t     z1;

    mpz_from_pmpz(z1, PG_GETARG_PMPZ(0));

    PG_RETURN_BOOL(mpz_perfect_square_p(z1));
}

PGMP_PG_FUNCTION(pmpz_rootrem)
{
    const mpz_t     z1;
    mpz_t           zroot;
    mpz_t           zrem;
    unsigned long   n;

    mpz_from_pmpz(z1, PG_GETARG_PMPZ(0));
    PMPZ_CHECK_NONEG(z1);

    PGMP_GETARG_ULONG(n, 1);
    PMPZ_CHECK_LONG_POS(n);

    mpz_init(zroot);
    mpz_init(zrem);
    mpz_rootrem (zroot, zrem, z1, n);

    PG_RETURN_MPZ_MPZ(zroot, zrem);
}

PGMP_PG_FUNCTION(pmpz_sqrtrem)
{
    const mpz_t     z1;
    mpz_t           zroot;
    mpz_t           zrem;

    mpz_from_pmpz(z1, PG_GETARG_PMPZ(0));

    mpz_init(zroot);
    mpz_init(zrem);
    mpz_sqrtrem(zroot, zrem, z1);

    PG_RETURN_MPZ_MPZ(zroot, zrem);
}


