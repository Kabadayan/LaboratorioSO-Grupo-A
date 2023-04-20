#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

long long n = 1000000000; /* número de termos da fórmula */
int thread_count = NUM_THREADS;
double sum = 0.0; /* soma total dos termos */
pthread_mutex_t mutex;

/* implementação da função Thread_sum */
void * Thread_sum(void* rank)
{
    long my_rank = (long) rank;
    double factor;
    long long i;
    long long my_n = n / thread_count;
    long long my_first_i = my_n * my_rank;
    long long my_last_i = my_first_i + my_n;

    if (my_first_i % 2 == 0) /* my_first_i é par */
        factor = 1.0;
    else /* my_first_i é ímpar */
        factor = -1.0;
    for (i = my_first_i; i < my_last_i; i++, factor = -factor) {
        double my_sum = factor / (2 * i + 1);
        pthread_mutex_lock(&mutex);
        sum += my_sum;
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
} /* Thread_sum */

int main()
{
    pthread_t* thread_handles;
    long thread;

    thread_handles = malloc(thread_count*sizeof(pthread_t));

    pthread_mutex_init(&mutex, NULL);

    printf("Quantidade de threads: %d\n", thread_count);

    for (thread = 0; thread < thread_count; thread++)
        pthread_create(&thread_handles[thread], NULL, Thread_sum, (void*) thread);

    for (thread = 0; thread < thread_count; thread++)
        pthread_join(thread_handles[thread], NULL);

    free(thread_handles);

    pthread_mutex_destroy(&mutex);

    /* calcula aproximação de pi */
    double pi = 4.0 * sum;

    printf("Aproximacao de pi = %lf\n", pi);

    return 0;
} /* main */
