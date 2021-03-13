#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/**
 * \struct Runner
 * \brief Strucure for a runner
 * \author P. Kolev
*/
struct Runner
{
    char name[100]; //!< stores the name of the runner
    double results[12]; //!< stores the results for each 42km race

    //! Function to read information about the runner
    void readRunner();

    //! Function to calculate the average speed (km/h) of the runner across all races
    double averageSpeed();

    //! Function to get the number of times in which the runner has beaten runner B in a 
    int beatNtime(Runner runnerB);
};

#endif