#ifndef RTK_WPAN_LOG_SAVE_H_
#define RTK_WPAN_LOG_SAVE_H_

#ifdef __cplusplus
extern "C" {
#endif

#define WPAN_LOG_SAVE     0
#define WPAN_LOG_SAVE_BUF 0
#define WPAN_LOG_SAVE_VFS 0

#if ((defined(WPAN_LOG_SAVE) && WPAN_LOG_SAVE) && (defined(WPAN_LOG_SAVE_BUF) && WPAN_LOG_SAVE_BUF) && (defined(WPAN_LOG_SAVE_VFS) && WPAN_LOG_SAVE_VFS))
#error "!!!WPAN_LOG_SAVE_BUF and WPAN_LOG_SAVE_BUF should not define 1 at the same time!!!"
#endif

int rtk_wpan_log_save_init(void);
int rtk_wpan_log_save_deinit(void);
int rtk_wpan_log_save(const char *aFormat, va_list aArguments);
int rtk_wpan_log_save_clear(void);
int rtk_wpan_log_save_print(void);
int rtk_wpan_cmd_save(const char *aFormat, ...);
int rtk_wpan_cmd_buf_save(const char *prefix, const char *buf);

#ifdef __cplusplus
}
#endif

#endif
