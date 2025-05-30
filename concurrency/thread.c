#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

struct thread_arg_t {
	double* volumes_of_spheres;
	size_t index;
};

void* start_routine(void* arg) {
	struct thread_arg_t* casted_arg = arg;

	// This is the ith thread, where i is
	// casted_arg->index
	double volume = 4.0 / 3.0 * 3.141592 * casted_arg->index * 
		casted_arg->index * casted_arg->index;
	casted_arg->volumes_of_spheres[casted_arg->index] = volume;

	return NULL;
}

int main() {
	double volumes_of_spheres[100];

	pthread_t new_threads[100];
	struct thread_arg_t thread_args[100];
	int i;
	for (i = 0; i < 100; i++) {
		thread_args[i].volumes_of_spheres = volumes_of_spheres;
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
	printf("The volume of a sphere with radius 54 is: %lf\n",
		volumes_of_spheres[54]);
}
