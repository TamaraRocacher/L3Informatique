/*
 * =====================================================================================
 *
 *       Filename:  binary.h
 *
 *    Description:  Library header for bit manipulation
 *
 *        Version:  1.0
 *        Created:  18/10/2015 08:18:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guillerme Duvillié (mfreeze), gduvillie@openmailbox.org
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef BINARY_H
#define BINARY_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <string.h>
#include <limits.h>

#include "debug.h"

#define iseven(x) (!(x & 1))
#define ispower2(x) (!(x & (x - 1)))

    int
isbigendian();

    char *
binaryconversion1(const void *, int);

    char *
memoryrepresentation(const void *, int);

#endif
