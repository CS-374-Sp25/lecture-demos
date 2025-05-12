#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

struct thread_arg_t {
	double* volumes_of_spheres;
	size_t index;
};

void* start_routine(void* arg) {
	// TODO Rewrite this
	int* arg_as_int = arg;
	(*arg_as_int)++;
	
	float* my_float_array = (float*) malloc(sizeof(float) * 10);
	my_float_array[0] = 3.14;
	return my_float_array;
}

int main() {
	double volumes_of_spheres[100];

	pthread_t new_threads[100];
	thread_arg_t thread_args[100];
	int i;
	for (i = 0; i < 100; i++) {
		thread_args[i].volumes_of_spheres = volumes_of_spheres;
		thread_args[i].index = i;
		pthread_create(&(new_threads[i]), NULL, start_routine, &(thread_args[i]));
	}

	// TODO Rewrite this
	void* my_variable;
	pthread_join(new_thread, &my_variable);
	float* my_variable_as_float = my_variable;
	printf("First variable in float array: %f\n", my_variable_as_float[0]);

	printf("%d\n", x);
}
