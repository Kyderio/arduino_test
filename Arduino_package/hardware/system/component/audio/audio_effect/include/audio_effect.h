#ifndef AMEBA_COMPONENT_AUDIO_AUDIO_EFFECT_INCLUDE_AUDIO_EFFECT_H
#define AMEBA_COMPONENT_AUDIO_AUDIO_EFFECT_INCLUDE_AUDIO_EFFECT_H

#include <errno.h>
#include <stdint.h>
#include <strings.h>
#include <sys/cdefs.h>
#include <sys/types.h>

#include <cutils/bitops.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct effect_interface_s **effect_handle_t;

typedef struct audio_buffer_s audio_buffer_t;

struct effect_interface_s {
	int32_t (*process)(effect_handle_t self,
					   audio_buffer_t *inBuffer,
					   audio_buffer_t *outBuffer);
	int32_t (*command)(effect_handle_t self,
					   uint32_t cmdCode,
					   uint32_t cmdSize,
					   void *pCmdData,
					   uint32_t *replySize,
					   void *pReplyData);
	int32_t (*process_reverse)(effect_handle_t self,
							   audio_buffer_t *inBuffer,
							   audio_buffer_t *outBuffer);
};

enum effect_command_e {
	EFFECT_CMD_INIT,                 // initialize effect engine
	EFFECT_CMD_SET_CONFIG,           // configure effect engine (see effect_config_t)
	EFFECT_CMD_RESET,                // reset effect engine
	EFFECT_CMD_ENABLE,               // enable effect process
	EFFECT_CMD_DISABLE,              // disable effect process
	EFFECT_CMD_SET_PARAM,            // set parameter immediately (see effect_param_t)
	EFFECT_CMD_SET_PARAM_DEFERRED,   // set parameter deferred
	EFFECT_CMD_SET_PARAM_COMMIT,     // commit previous set parameter deferred
	EFFECT_CMD_GET_PARAM,            // get parameter
	EFFECT_CMD_SET_DEVICE,           // set audio device (see audio.h, audio_devices_t)
	EFFECT_CMD_SET_VOLUME,           // set volume
	EFFECT_CMD_SET_AUDIO_MODE,       // set the audio mode (normal, ring, ...)
	EFFECT_CMD_SET_CONFIG_REVERSE,   // configure effect engine reverse stream(see effect_config_t)
	EFFECT_CMD_SET_INPUT_DEVICE,     // set capture device (see audio.h, audio_devices_t)
	EFFECT_CMD_GET_CONFIG,           // read effect engine configuration
	EFFECT_CMD_GET_CONFIG_REVERSE,   // read configure effect engine reverse stream configuration
	EFFECT_CMD_GET_FEATURE_SUPPORTED_CONFIGS,// get all supported configurations for a feature.
	EFFECT_CMD_GET_FEATURE_CONFIG,   // get current feature configuration
	EFFECT_CMD_SET_FEATURE_CONFIG,   // set current feature configuration
	EFFECT_CMD_SET_AUDIO_SOURCE,     // set the audio source (see audio.h, audio_source_t)
	EFFECT_CMD_OFFLOAD,              // set if effect thread is an offload one,
	EFFECT_CMD_FIRST_PROPRIETARY = 0x10000 // first proprietary command code
};

struct audio_buffer_s {
	size_t   frameCount;        // number of frames in buffer
	union {
		void       *raw;        // raw pointer to start of buffer
		int32_t    *s32;        // pointer to signed 32 bit data at start of buffer
		int16_t    *s16;        // pointer to signed 16 bit data at start of buffer
		uint8_t    *u8;         // pointer to unsigned 8 bit data at start of buffer
	};
};

typedef int32_t (* buffer_function_t)(void *cookie, audio_buffer_t *buffer);

typedef struct buffer_provider_s {
	buffer_function_t getBuffer;       // retrieve next buffer
	buffer_function_t releaseBuffer;   // release used buffer
	void       *cookie;                // for use by client of buffer provider functions
} buffer_provider_t;

typedef struct buffer_config_s {
	audio_buffer_t  buffer;     // buffer for use by process() function if not passed explicitly
	uint32_t   samplingRate;    // sampling rate
	uint32_t   channels;        // channel mask (see uint32_t in audio.h)
	buffer_provider_t bufferProvider;   // buffer provider
	uint8_t    format;          // Audio format (see audio_format_t in audio.h)
	uint8_t    accessMode;      // read/write or accumulate in buffer (effect_buffer_access_e)
	uint16_t   mask;            // indicates which of the above fields is valid
} buffer_config_t;

enum effect_buffer_access_e {
	EFFECT_BUFFER_ACCESS_WRITE,
	EFFECT_BUFFER_ACCESS_READ,
	EFFECT_BUFFER_ACCESS_ACCUMULATE

};

enum effect_feature_e {
	EFFECT_FEATURE_AUX_CHANNELS, // supports auxiliary channels (e.g. dual mic noise suppressor)
	EFFECT_FEATURE_CNT
};

typedef struct channel_config_s {
	uint32_t main_channels; // channel mask for main channels
	uint32_t aux_channels;  // channel mask for auxiliary channels
} channel_config_t;

#define EFFECT_CONFIG_BUFFER    0x0001  // buffer field must be taken into account
#define EFFECT_CONFIG_SMP_RATE  0x0002  // samplingRate field must be taken into account
#define EFFECT_CONFIG_CHANNELS  0x0004  // channels field must be taken into account
#define EFFECT_CONFIG_FORMAT    0x0008  // format field must be taken into account
#define EFFECT_CONFIG_ACC_MODE  0x0010  // accessMode field must be taken into account
#define EFFECT_CONFIG_PROVIDER  0x0020  // bufferProvider field must be taken into account
#define EFFECT_CONFIG_ALL (EFFECT_CONFIG_BUFFER | EFFECT_CONFIG_SMP_RATE | \
                           EFFECT_CONFIG_CHANNELS | EFFECT_CONFIG_FORMAT | \
                           EFFECT_CONFIG_ACC_MODE | EFFECT_CONFIG_PROVIDER)

typedef struct effect_config_s {
	buffer_config_t   inputCfg;
	buffer_config_t   outputCfg;
} effect_config_t;

typedef struct effect_param_s {
	int32_t     status;
	uint32_t    psize;
	uint32_t    vsize;
	char        data[];
} effect_param_t;

#ifdef __cplusplus
}
#endif

#endif
