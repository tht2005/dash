#ifndef __DALLOC_H
#define __DALLOC_H

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Wrapper for malloc
 *
 * @param size 
 */
void*
dalloc(size_t size);

/**
 * @brief Wrapper for realloc
 *
 * @param ptr 
 * @param size 
 */
void*
drealloc(void* ptr, size_t size);

#endif
