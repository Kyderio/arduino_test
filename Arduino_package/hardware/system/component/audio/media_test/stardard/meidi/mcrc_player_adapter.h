#ifndef __MCRC_PLAYER_ADAPTER_H__
#define __MCRC_PLAYER_ADAPTER_H__

#ifdef __cplusplus
extern "C" {
#endif

#define MCRC_PLAYER_EXPORT __attribute ((visibility("default")))

typedef enum mcrc_player_type {
	MUSIC_PLAYER = 0,
	TTS_PLAYER,
} mcrc_player_type;

typedef enum mcrc_player_ev {
	// 必须，用于播放控制和管理
	MCRC_PLAYER_EV_START = 0,   // 开始处理播放请求
	MCRC_PLAYER_EV_END,     // 播放完成
	MCRC_PLAYER_EV_PAUSED,  // 暂停成功
	MCRC_PLAYER_EV_SEEKING, // 开始跳播
	MCRC_PLAYER_EV_PLAYING, // 开始播放
	MCRC_PLAYER_EV_STOPPED, // 停止成功

	// 必须，错误控制
	MCRC_PLAYER_EV_ERROR,   // 错误

	// 用于耗时切片分析,用于性能优化， 非必须，
	MCRC_PLAYER_INFO_NETWORK_RESOLVED,        // DNS 解析结束
	MCRC_PLAYER_INFO_NETWORK_TCP_CONNECTED,   // TCP Connect成功
	MCRC_PLAYER_INFO_NETWORK_TLS_HANDSHAKED,  // TLS Connect成功
	MCRC_PLAYER_INFO_PROBE_DATA_FILLED,       // 获取到需要的Probe Data
	MCRC_PLAYER_INFO_MEDIA_TYPE_PROBED,       // Probe到媒体类型
	MCRC_PLAYER_INFO_AUDIO_DECODER_START,     // Decode 第一笔音频数据
	MCRC_PLAYER_INFO_AUDIO_SINK_START,        // Sink 第一笔音频PCM到声卡

} mcrc_player_ev;


typedef enum mcrc_player_err {
	MCRC_PLAYER_SUCCESS            = 0,        /*!< 执行成功. */
	MCRC_PLAYER_ERR_UNKNOWN       = -1,       /*!< 未知错误. */
	MCRC_PLAYER_ERR_INVALID_PARAM = -2,       /*!< 参数错误. */
	MCRC_PLAYER_ERR_NO_MEM        = -3,       /*!< 没有可用内存. */
	MCRC_PLAYER_ERR_BUSY          = -4,       /*!< 系统繁忙. */
	MCRC_PLAYER_ERR_OPERATION     = -5,       /*!< 非法操作. */
} mcrc_player_err;

#define MCRC_PLAYER_LOG_QUIET          -1               /* Print no output                                            */
#define MCRC_PLAYER_LOG_PANIC           0               /* Something went really wrong and we will crash now          */
#define MCRC_PLAYER_LOG_FATAL           1               /* Something went wrong and recovery is not possible.         */
#define MCRC_PLAYER_LOG_ERROR           2               /* Something went wrong and cannot losslessly be recovered    */
#define MCRC_PLAYER_LOG_WARNING         3               /* Something somehow does not look correct                    */
#define MCRC_PLAYER_LOG_INFO            4               /* Standard information.                                      */
#define MCRC_PLAYER_LOG_VERBOSE         5               /* Detailed information                                       */
#define MCRC_PLAYER_LOG_DEBUG           6               /* Stuff which is only useful for libav* developers.          */
#define MCRC_PLAYER_LOG_TRACE           7               /* Extremely verbose debugging, useful for libav* development */

typedef void (*mcrc_player_callback)(void *userdata, mcrc_player_ev ev);
typedef void *mcrc_player_handle;

//MCRC_PLAYER_EXPORT mcrc_player_handle audio_player_trace(mcrc_player_handle player, int level);

/* 接口都是非阻塞接口，mcrc_player_callback里面也不会阻塞 */

/**
* @Function 创建一个播放器
* @Parameter    type: 类型，音乐播放器 或者 提示音播放器
*               cb: 事件回调句柄
*               userdata: 外部数据，保存，用于事件返回
* @return   NULL:   创建失败
**/
MCRC_PLAYER_EXPORT mcrc_player_handle mcrc_player_new(mcrc_player_type type, mcrc_player_callback cb, void *userdata);

/**
* @Function 销毁目标播放器
* @Parameter    player: 播放器句柄
* @return   MCRC_PLAYER_SUCCESS:    成功
*           MCRC_PLAYER_ERR_XXX:    失败
**/
MCRC_PLAYER_EXPORT mcrc_player_err mcrc_player_delete(mcrc_player_handle player);

/**
* @Function 播放URL，从0开始播放
* @Parameter    player: 播放器句柄
*               url: 网络url或者本地url
* @return   MCRC_PLAYER_SUCCESS:    成功
*           MCRC_PLAYER_ERR_XXX:    失败
**/
MCRC_PLAYER_EXPORT mcrc_player_err mcrc_player_play(mcrc_player_handle player, const char *url);

/**
* @Function 播放URL，从目标播放时间开始播放
* @Parameter    player: 播放器句柄
*               url: 网络url或者本地url
*               start_time_sec: 目标播放时间, 单位：秒
* @return   MCRC_PLAYER_SUCCESS:    成功
*           MCRC_PLAYER_ERR_XXX:    失败, 并通过callback通知
**/
MCRC_PLAYER_EXPORT mcrc_player_err mcrc_player_play_seek(mcrc_player_handle player, const char *url, int start_time_sec);

/**
* @Function 播放URL，快速播放播放
* @Parameter    player: 播放器句柄
*               url: 网络url或者本地url
*               factor: 倍速, 2, 3 ...
* @return   MCRC_PLAYER_SUCCESS:    成功
*           MCRC_PLAYER_ERR_INVALID_PARAM:  失败, 越界, 并通过callback通知
*           MCRC_PLAYER_ERR_XXX:    失败, 并通过callback通知
**/
MCRC_PLAYER_EXPORT mcrc_player_err mcrc_player_play_fast(mcrc_player_handle player, const char *url, int factor);

/**
* @Function 播放中控制，静音播放
* @Parameter    player: 播放器句柄
*               mute: 静音: 1, 非静音: 0
*               factor: 倍速, 2, 3 ...
* @return   MCRC_PLAYER_SUCCESS:    成功
*           MCRC_PLAYER_ERR_XXX:    失败, 不支持, 并通过callback通知
**/
MCRC_PLAYER_EXPORT mcrc_player_err mcrc_player_mute(mcrc_player_handle player, int mute);

/**
* @Function 播放中控制，seek
* @Parameter    player: 播放器句柄
*               increase_sec: 相对时间, 正负
* @return   MCRC_PLAYER_SUCCESS:    成功
*           MCRC_PLAYER_ERR_INVALID_PARAM:  失败, 越界, 并通过callback通知
*           MCRC_PLAYER_ERR_XXX:    失败, 不支持, 并通过callback通知
**/
MCRC_PLAYER_EXPORT mcrc_player_err mcrc_player_seek(mcrc_player_handle player, int increase_sec);


/**
* @Function 播放中控制，pause
* @Parameter    player: 播放器句柄
* @return   MCRC_PLAYER_SUCCESS:    成功
*           MCRC_PLAYER_ERR_XXX:    失败, 并通过callback通知
**/
MCRC_PLAYER_EXPORT mcrc_player_err mcrc_player_pause(mcrc_player_handle player);

/**
* @Function 播放中控制，resume
* @Parameter    player: 播放器句柄
* @return   MCRC_PLAYER_SUCCESS:    成功
*           MCRC_PLAYER_ERR_XXX:    失败, 并通过callback通知
**/
MCRC_PLAYER_EXPORT mcrc_player_err mcrc_player_resume(mcrc_player_handle player);

/**
* @Function 播放中控制，stop
* @Parameter    player: 播放器句柄
* @return   MCRC_PLAYER_SUCCESS:    成功
*           MCRC_PLAYER_ERR_XXX:    失败, 并通过callback通知
**/
MCRC_PLAYER_EXPORT mcrc_player_err mcrc_player_stop(mcrc_player_handle player);

/**
* @Function 播放中控制，设置软件音量
* @Parameter    player: 播放器句柄
* @return   MCRC_PLAYER_SUCCESS:    成功
*           MCRC_PLAYER_ERR_XXX:    失败, 并通过callback通知
* 不支持可以不动作，返回MCRC_PLAYER_ERR_OPERATION
**/
MCRC_PLAYER_EXPORT mcrc_player_err mcrc_player_set_volume(mcrc_player_handle player, float multiplier);

/**
* @Function 播放中控制，获取媒体总时长
* @Parameter    player: 播放器句柄, duration: 以毫秒为单位的时间, 直播媒体，没有总时长，赋值-1
* @return   MCRC_PLAYER_SUCCESS:    成功
*           MCRC_PLAYER_ERR_XXX:    失败, 并通过callback通知
* 不支持可以不动作，返回MCRC_PLAYER_ERR_OPERATION
**/
MCRC_PLAYER_EXPORT mcrc_player_err mcrc_player_get_duration(mcrc_player_handle player, int *duration);

#ifdef __cplusplus
}
#endif

#endif /* __MCRC_PLAYER_ADAPTER_H__ */
