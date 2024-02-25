#ifndef GCPLAYER_LOG_H_
#define GCPLAYER_LOG_H_

#ifdef __cplusplus
#ifdef __GNUC__
extern "C" {
#include <tttl/tttl.h>
}

#define ltrace(...) \
  tttl_log_log(TTTL_LOG_TRACE, __FILE__, __LINE__, __VA_ARGS__)
#define ldebug(...) \
  tttl_log_log(TTTL_LOG_DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define linfo(...) tttl_log_log(TTTL_LOG_INFO, __FILE__, __LINE__, __VA_ARGS__)
#define lwarn(...) tttl_log_log(TTTL_LOG_WARN, __FILE__, __LINE__, __VA_ARGS__)
#define lerror(...) \
  tttl_log_log(TTTL_LOG_ERROR, __FILE__, __LINE__, __VA_ARGS__)
#define lfatal(...) \
  tttl_log_log(TTTL_LOG_FATAL, __FILE__, __LINE__, __VA_ARGS__)

class Logger {
 public:
  Logger() {
    tttl_log_set_level(TTTL_LOG_DEBUG);
    tttl_log_set_mode(TTTL_LOG_MODE_ASYNC);
  }
  ~Logger() {
    tttl_log_close();
  }
};
#endif // __GNUC__

#ifdef _MSC_VER
#define ltrace(...)
#define ldebug(...)
#define linfo(...)
#define lwarn(...)
#define lerror(...)
#define lfatal(...)

class Logger {};
#endif  // _MSC_VER
#endif // __cplusplus

#endif  // GCPLAYER_LOG_H_
