#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

struct thread_arg_t {
	pthread_mutex_t* volume_sum_mutex;
	double* volume_sum;
	size_t index;
};

void* start_routine(void* arg) {
	struct thread_arg_t* casted_arg = arg;

	// This is the ith thread, where i is
	// casted_arg->index
	double volume = 4.0 / 3.0 * 3.141592 * casted_arg->index * 
		casted_arg->index * casted_arg->index;

	// Acquire the lock
	pthread_mutex_lock(casted_arg->volume_sum_mutex);
	// Critical section starts here
	*(casted_arg->volume_sum) += volume;
	// Critical section ends here
	// Release the lock
	pthread_mutex_unlock(casted_arg->volume_sum_mutex);

	return NULL;
}

int main() {
	pthread_mutex_t volume_sum_mutex;
	pthread_mutex_init(&volume_sum_mutex, NULL);
	double volume_sum = 0;

	pthread_t new_threads[100];
	struct thread_arg_t thread_args[100];
	int i;
	for (i = 0; i < 100; i++) {
		thread_args[i].volume_sum_mutex = &volume_sum_mutex;
		thread_args[i].volume_sum = &volume_sum;
		thread_args[i].index = i;
		pthread_create(&(new_threads[i]), NULL, start_routine, &(thread_args[i]));
	}

	// Let's clean this up
	void* my_variable;
	for (i = 0; i < 100; i++) {
		pthread_join(new_threads[i], &my_variable);
	}
	
	// At this point, all threads are done (terminated).
	// It is now safe to access volumes_of_spheres
	printf("The sum of volumes is %lf\n", volume_sum);
}
