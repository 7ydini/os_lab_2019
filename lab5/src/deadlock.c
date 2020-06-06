#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
 
#define M_SIZE 5

typedef struct Math_tag
{
    const char *name;
    unsigned left_fork;
    unsigned right_fork;
} Math_t;
typedef struct table_tag
{
    pthread_mutex_t forks[M_SIZE];
} table_t;
typedef struct Math_args_tag
{
    const Math_t *Math;
    const table_t *table;
} Math_args_t;
pthread_mutex_t entry_point = PTHREAD_MUTEX_INITIALIZER;
/* auxiliary initialization function */
void init_Math(Math_t *Math, const char *name,
unsigned left_fork, unsigned right_fork)
{
    Math->name = name;
    Math->left_fork = left_fork;
    Math->right_fork = right_fork;
}

/* auxiliary initialization function */
void init_table(table_t *table)
{
    size_t i;
    for (i = 0; i < M_SIZE; i++)
    {
        pthread_mutex_init(&table->forks[i], NULL);
    }
}

/* the main function, which simulates dinner */
void* eat(void *args)
{
    Math_args_t *arg = (Math_args_t*) args;
    const Mathr_t *Math = arg->Math;
    const table_t *table = arg->table;
    unsigned rand_time;  
    srand(NULL);
    do {
        printf("%s started dinner\n", Math->name); 
        pthread_mutex_lock(&entry_point);
        pthread_mutex_lock(&table->forks[Math->left_fork]);
        pthread_mutex_unlock(&entry_point);
        rand_time =rand()%10;
        sleep(rand_time);
        pthread_mutex_lock(&entry_point); 
        pthread_mutex_lock(&table->forks[Math->right_fork]);
        pthread_mutex_unlock(&entry_point);
        printf("%s is eating after %d s sleep\n", Math->name, rand_time);
        pthread_mutex_unlock(&table->forks[Math->right_fork]);
        pthread_mutex_unlock(&table->forks[Math->left_fork]);
        printf("%s finished dinner\n", Math->name);
    } while (1); /* repeat */
}
 
void main()
{
    pthread_t threads[M_SIZE];
    Math_t Mathx[M_SIZE];
    Math_args_t arguments[M_SIZE];
    table_t table;
    size_t i;
 
    init_table(&table);
 
    init_Math(&Math[0], "Piphagor", 0, 1);
    init_Math(&Math[1], "Evklid",   1, 2);
    init_Math(&Math[2], "Viet", 2, 3);
    init_Math(&Math[3], "Eyler", 3, 4);
    init_Math(&Math[4], "Galiley", 4, 0);
 
    for (i = 0; i < M_SIZE; i++)
    {
        arguments[i].Math = &Math[i];
        arguments[i].table = &table;
    }
 
    for (i = 0; i < M_SIZE; i++)
    {
        pthread_create(&threads[i], NULL, eat, &arguments[i]);
    }
 
    for (i = 0; i < M_SIZE; i++)
    {
        pthread_join(threads[i], NULL);
    }
}
