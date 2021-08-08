/*
** EPITECH PROJECT, 2021
** memory
** File description:
** memory
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

typedef struct chunk_s {
    struct chunk_s *next;
    struct chunk_s *previous;
    size_t offset;
    bool freed;
} chunk_t;

typedef enum list {
    HEAD,
    CURRENT
} list_e;

typedef enum list_action {
    SET,
    GET
} action_e;

void *malloc(size_t size);
void *calloc(size_t nmemb, size_t size);
void free(void *ptr);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);
size_t convert_paging(size_t target);
chunk_t *memory_handle(list_e list, action_e action, chunk_t *value);
size_t pagesize_handler(action_e action, size_t value);
