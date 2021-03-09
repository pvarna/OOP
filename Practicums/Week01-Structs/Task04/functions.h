#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct Runner
{
    char name[100];
    double results[12];

    void readRunner();
    double averageSpeed();
    int beatNtime(Runner runnerB);
};

#endif