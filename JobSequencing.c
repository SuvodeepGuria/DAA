#include <stdio.h>

// Function to find the maximum number of jobs that can be scheduled
int findMaxJobs(int jobs[][3], int n) {
    // Sort jobs based on deadline
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (jobs[i][1] > jobs[j][1]) {
                // Swap jobs[i] and jobs[j]
                int temp[3] = {jobs[i][0], jobs[i][1], jobs[i][2]};
                jobs[i][0] = jobs[j][0];
                jobs[i][1] = jobs[j][1];
                jobs[i][2] = jobs[j][2];
                jobs[j][0] = temp[0];
                jobs[j][1] = temp[1];
                jobs[j][2] = temp[2];
            }
        }
    }

    int count = 1; // Schedule the first job
    int lastJobDeadline = jobs[0][1];

    // Schedule remaining jobs
    for (int i = 1; i < n; i++) {
        if (jobs[i][1] > lastJobDeadline) {
            count++; // New day starts
            lastJobDeadline = jobs[i][1];
        }
    }

    return count;
}

int main() {
    int jobs[][3] = {{1, 2, 3}, {2, 3, 4}, {3, 4, 5}};
    int n = sizeof(jobs) / sizeof(jobs[0]);

    printf("Maximum number of jobs that can be scheduled = %d\n", findMaxJobs(jobs, n));

    return 0;
}
