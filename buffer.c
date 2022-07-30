#include <stdio.h>
#include "buffer.h"


/*  the buffer 
    This is currently implemented as a queue. 
    Items are inserted at the tail and removed from the head.*/

int insert_item(buffer_item item) {
    
    buffer[tail] = item; // add an item to the tail 
    if ((tail + 1) >= BUFFER_SIZE){
        tail = 0; // reset the tail to 0 if it the end of the buffer
    } else
        tail++; // or else just increment the tail
    return 0;

}


int remove_item(buffer_item *item) {
    
    *item = buffer[head];
    if ((head + 1) >= BUFFER_SIZE){
        head = 0;
    } else {
        head++;
    }
        return 0;

}