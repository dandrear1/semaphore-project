# semaphore-project
This is an assignment I did in my Operating Systems course during college. It demonstrates using semaphores to synchronize two processes. The semaphores in this project prevent a producer from changing a buffer while a consumer is accessing the buffer and vice versa. 

## main.c
```main.c``` will create a user-defined amount of producer and consumer threads

## posix.c
Once a mutex lock is aquired, the producer will insert a ```buffer_item``` into a buffer and release the lock

Once a mutex lock is aquired, the consumer will remove a ```buffer_item``` from the buffer and release the lock. 

## buffer.c
The buffer is implemented as a circular queue. A ```buffer_item``` is inserted at the tail and removed at the head.
A ```buffer_item``` is created from ```typedef int buffer_item```

The project code is already compiled, but if you wish to recompile, run the following command:<br/>
```make```

To run the compiled code run the following command: <br/>
```./main <sleep time> <number of producers> <number of consumers>```

```<sleep time>``` - the amount of time that main will run<br/>
```<number of producers>``` - the amount of threads that will be adding to the buffer<br/>
```<number of consumers>``` - the amount of threads that will be taking from the buffer<br/>

