/*
 * =====================================================================================
 *
 *       Filename:  binary.c
 *
 *    Description:  Library body for bit manipulation
 *
 *        Version:  1.0
 *        Created:  18/10/2015 08:34:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guillerme Duvillié (mfreeze), gduvillie@openmailbox.org
 *   Organization:  
 *
 * =====================================================================================
 */

#include "binary.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  isbigendian
 *  Description:  Determines if architecture is big endian
 * =====================================================================================
 */
    int
isbigendian()
{
    unsigned int i = 1;
    char *c = (char *)&i;
    return c ? 0 : 1;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  binaryconversion1
 *  Description:  Compute binary representation of data
 * =====================================================================================
 */
    char * 
binaryconversion1(const void *data, int s) 
{
    int i;
    char *src = (char *) data;
    char *res = (char *) calloc(s * (CHAR_BIT + 1), sizeof(char));
    if (!res) {
        perror("Malloc failed in binaryconversion1.\n");
        return NULL;
    }
    DEB_PRINT("Allocated pointer : %p.\n", (void *)res);

    char *dest = res;

    if (isbigendian()) 
        switch (1) 
        {
            for(; s; s--, src++) 
            {
                default:
                    *src++ = ' ';
                case 1:
                    for (i = 1 << (CHAR_BIT - 1); i; i >>= 1, dest++) 
                        *dest = *src & i ? '1' : '0';
            }
        }
    else
    {
        src += s-1;
        switch (1) 
        {
            for(; s; s--, src--)
            {
                default:
                    *src++ = ' ';
                case 1:
                    for (i = 1 << (CHAR_BIT - 1); i; i >>= 1, dest++) 
                        *dest = *src & i ? '1' : '0';
            }
        }
    }

    *dest = '\0';

    return res;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  memoryrepresentation
 *  Description:  Compute memory representation of data
 * =====================================================================================
 */
    char * 
memoryrepresentation(const void *data, int s) 
{
    int i;
    char *src = (char *) data;
    char *res = (char *) calloc(s * (CHAR_BIT + 1), sizeof(char));
    if (!res) {
        perror("Malloc failed in binaryconversion1.\n");
        return NULL;
    }

    DEB_PRINT("Allocated pointer : %p.\n", (void *)res);

    char *dest = res;

    switch(1)
    {
        for(; s; s--, src++) {
            default:
                *dest++ = ' ';
            case 1:
                for (i = 1 << (CHAR_BIT - 1); i; i >>= 1) 
                    *dest++ = *src & i ? '1' : '0';
        }
    }

    *dest = '\0';

    return res;
}
