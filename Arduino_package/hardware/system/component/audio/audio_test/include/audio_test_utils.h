#ifndef AUDIO_TEST_AUDIO_TEST_UTILS
#define AUDIO_TEST_AUDIO_TEST_UTILS

#define TEST_WITH_CMD   1

#define  RTAUDIO_DEBUG_HEAP_BEGIN() \
    unsigned int heap_start;\
    unsigned int heap_end;\
    unsigned int heap_min_ever_free;\
    printf("=> I/AudioMem: mem debug info init \n");\
    heap_start = rtos_mem_get_free_heap_size()

#define  RTAUDIO_DEBUG_HEAP_END() \
    heap_end = rtos_mem_get_free_heap_size();\
    heap_min_ever_free = rtos_mem_get_minimum_ever_free_heap_size();\
    printf("=> I/AudioMem: start (0x%x), end (0x%x), \n", heap_start, heap_end);\
    printf("=> I/AudioMem: diff (%d), peak (%d) \n", heap_start - heap_end, heap_start - heap_min_ever_free)

void generate_sine(int8_t *buffer, uint32_t count, uint32_t rate, uint32_t channels, uint32_t bits, double *_phase);

#endif