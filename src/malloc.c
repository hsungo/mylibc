#include "../include/stdlib.h" 
#include "../include/unistd.h"  

#define HEADER_SIZE sizeof(struct block_header)

struct block_header {
    size_t size;       
    int is_free;        
    struct block_header *next; 
};

static struct block_header *head = NULL;

void *malloc(size_t size){
    if(size == 0){
        return NULL;
    }
    size = (size + 7) & ~7; // align to 8x bytes

    struct block_header *curr = head;
    struct block_header *last = NULL;
    while(curr){ // have a header with enough space
        if(curr->size >= size && curr->is_free){
            curr->is_free = 0;
            return (void*)(curr + 1);
        }
        last = curr;
        curr = curr->next;
    }

    struct block_header *block = sbrk(size + HEADER_SIZE); // get space from system
    if(block == (void*)-1){
        return NULL;
    }

    block->size = size; //initialize block info
    block->is_free = 0;
    block->next = NULL;
    
    if(last){
        last->next = block;
    }
    else{
        head = block;
    }

    return (void*)(block + 1);
}

void free(void* ptr){
    if(!ptr){
        return ;
    }
    struct block_header *block = (struct block_header*)ptr - 1;
    block->is_free = 1;
}