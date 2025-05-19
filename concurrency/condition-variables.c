#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

struct thread_arg_t {
	int* rand_int;
	pthread_mutex_t* my_mutex;
	pthread_cond_t* my_cv;
};

void* start_routine(void* arg) {
	struct thread_arg_t* casted_arg = arg;
	
	// Wait until *(casted_arg->rand_int) > 7
	pthread_mutex_lock(casted_arg->my_mutex);
	while (*(casted_arg->rand_int) <= 7) {
		pthread_cond_wait(casted_arg->my_cv, casted_arg->my_mutex);
	}
	printf("x has been modified to: %d\n", *(casted_arg->rand_int));
	pthread_mutex_unlock(casted_arg->my_mutex);

}

int main() {
	srand(time(NULL));

	pthread_mutex_t my_mutex;
	pthread_mutex_init(&my_mutex, NULL);
	pthread_cond_t my_cv;
	pthread_cond_init(&my_cv, NULL);
	int x = 0;


	pthread_t new_thread;
	struct thread_arg_t thread_arg;
	thread_arg.rand_int = &x;
	thread_arg.my_mutex = &my_mutex;
	thread_arg.my_cv = &my_cv;
	pthread_create(&(new_thread), NULL, start_routine, &(thread_arg));

	// At this point, there are two threads running concurrently.
	while (1) {
		int random_variable = rand() % 10 + 1;
		pthread_mutex_lock(&my_mutex);
		x = random_variable;
		pthread_mutex_unlock(&my_mutex);
		pthread_cond_signal(&my_cv);
	}
}
