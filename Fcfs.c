#include <stdio.h>//used for standard input and output operations
//like printf and scanf needed for most c programs

int main() {
    int n = 5; // Number of processes
    int arrival_times[] = {0, 1, 2, 3, 4}; // Arrival times 
    // process execution order strictly follows their order of appearance in the queue.
    int burst_times[] = {80, 20, 10, 20, 50}; // Burst times of the processes
    // containing the execution time (or burst time) for each process. 
    // These are critical in FCFS, as the scheduler will allow each process to 
    // complete its burst time in the order they are called

    /*he amount of time a process requires to complete its execution without any 
    interruption once it has started running on the CPU. It's essentially the 
    time that a process needs to carry out its task from start to finish.
    */
    int wait_times[n], turnaround_times[n];
    int start_time = 0, total_wait_time = 0, total_turnaround_time = 0;

    printf("Gantt Chart:\n");
    for (int i = 0; i < n; i++) {
        //start time varies for each and every process
        //the first start time will be 0
        //whereas the next successive start time will be the end time of the 
        // previous processes.
        wait_times[i] = start_time; // Wait time is the start time of this process
        turnaround_times[i] = wait_times[i] + burst_times[i]; 
        // Turnaround time is wait time plus execution time(Burst Time)
        total_wait_time += wait_times[i];
        total_turnaround_time += turnaround_times[i];

        printf("P%d (%d -> %d)\n", i, start_time, start_time + burst_times[i]);
        //start time keeps on incrementing and adding to the 
        //end time of the previous process, which at the end will give
        //the start time of the next process
        //and the last time will be total time taken by all the processes
        // to complete all the processes.
        start_time += burst_times[i]; // Update start time for next process
        //end of existing process will be the start time of the next process.
    }

    printf("Average Wait Time: %.2f\n", (float)total_wait_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);

    return 0;
}
