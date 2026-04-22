#include <string.h>
#include "fir_filter.h"

static const float INTERNAL_COEFFS[] = { 0.2f, 0.2f, 0.2f, 0.2f, 0.2f };
static const int TAPS_COUNT = 5;

typedef struct {
    float buffer[5];
    int head;
} FIRFilter;

static FIRFilter my_filter; // Private global instance

void fir_process_block(const float *input_buf, float *output_buf, int len) {
    for (int i = 0; i < len; i++) {
        my_filter.buffer[my_filter.head] = input_buf[i];
        float sum = 0.0f;
        int idx = my_filter.head;

        for (int j = 0; j < TAPS_COUNT; j++) {
            sum += INTERNAL_COEFFS[j] * my_filter.buffer[idx];
            if (--idx < 0) idx = TAPS_COUNT - 1;
        }
        output_buf[i] = sum;

        if (++my_filter.head >= TAPS_COUNT) my_filter.head = 0;
    }
}