//
// Created by Gavin Taylor Mcroy on 10/27/21.
//

#ifndef PROJECT_3_ALLOCATOR_H
#define PROJECT_3_ALLOCATOR_H

#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>
#include <stdio.h>

#define _GNU_SOURCE
#define PAGESIZE 4096

void __attribute__((constructor)) lib_init();

void __attribute__((destructor)) lib_destroy();


#endif //PROJECT_3_ALLOCATOR_H
