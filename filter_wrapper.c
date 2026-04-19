#include <string.h>
#include <stdbool.h>
#include "fir_filter.h"
#include "filter_wrapper.h"


void filter_wrapper(const float *input_buf, float *output_buf, int len, const char *filter_type) {
    
    if (filter_type != NULL && strcmp(filter_type, "fir") == 0) {

        fir_init();

        // Process the data
        fir_process_block(input_buf, output_buf, len);
        
    } else {
        // Bypass mode: Copy input to output
        memcpy(output_buf, input_buf, sizeof(float) * len);
    }
}