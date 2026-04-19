#include <stdio.h>

/*
 * Simple Moving Average Filter
 * This function takes a new input value and a pointer to an array of 
 * previous values to calculate the average.
 */
float moving_average(float next_value, float *buffer, int length) {
    static int index = 0;
    static float sum = 0;

    // Subtract the oldest value from the sum and add the new value
    sum -= buffer[index];
    buffer[index] = next_value;
    sum += next_value;

    // Advance the index
    index = (index + 1) % length;

    return sum / length;
}