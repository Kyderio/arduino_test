#ifndef AUDIO_TEST_DEBUG
#define AUDIO_TEST_DEBUG

#define AUDIO_DEBUG(fmt, args...)    printf("=> D/AudioTest:[%s]: " fmt "\n", __func__, ## args)
#define AUDIO_ERROR(fmt, args...)    printf("=> E/AudioTest:[%s]: " fmt "\n", __func__, ## args)

#endif