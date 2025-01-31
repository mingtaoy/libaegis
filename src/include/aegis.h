#ifndef aegis_H
#define aegis_H

#include <stdint.h>

#if !defined(__clang__) && !defined(__GNUC__)
#    ifdef __attribute__
#        undef __attribute__
#    endif
#    define __attribute__(a)
#endif

#include "aegis128l.h"
#include "aegis128x2.h"
#include "aegis128x4.h"
#include "aegis256.h"
#include "aegis256x2.h"
#include "aegis256x4.h"

/* Initialize the AEGIS library.
 *
 * This function does runtime CPU capability detection, and must be called once
 * in your application before doing anything else with the library.
 *
 * If you don't, AEGIS will still work, but it may be much slower.
 *
 * The function can be called multiple times but is not thread-safe.
 */
int aegis_init(void);

/* Compare two 16-byte blocks for equality.
 *
 * This function is designed to be used in constant-time code.
 *
 * Returns 0 if the blocks are equal, -1 otherwise.
 */
int aegis_verify_16(const uint8_t *x, const uint8_t *y) __attribute__((warn_unused_result));

/* Compare two 32-byte blocks for equality.
 *
 * This function is designed to be used in constant-time code.
 *
 * Returns 0 if the blocks are equal, -1 otherwise.
 */
int aegis_verify_32(const uint8_t *x, const uint8_t *y) __attribute__((warn_unused_result));

#endif
