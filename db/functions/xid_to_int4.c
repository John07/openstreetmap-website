#ifndef USE_MYSQL
#ifndef USE_PGSQL
#error One of USE_MYSQL or USE_PGSQL must be defined
#endif
#endif

#ifdef USE_PGSQL
#ifdef USE_MYSQL
#error ONLY one of USE_MYSQL and USE_PGSQL should be defined
#endif

#include <postgres.h>
#include <fmgr.h>

int xid_to_int4(TransactionId xid)
{
   return xid;
}

/*
 * To bind this into PGSQL, try something like:
 *
 * CREATE FUNCTION xid_to_int4(xid) RETURNS int4
 *  AS '/path/to/rails-port/db/functions/libpgosm', 'xid_to_int4'
 *  LANGUAGE C IMMUTABLE STRICT;
 *
 * (without all the *s)
 */

#endif
