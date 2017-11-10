#ifndef ArduLogger_h
#define ArduLogger_h

#include <Arduino.h>
#include <map>

namespace ardulogger {
/**
 * Arduino console logger
 */
class Log
{
public:
  /**
   * Log level
   */
  enum Level
  {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    NONE
  };

  /**
   * Enables serial at provided boud
   * @param a_boud serial boud
   */
  static void enable(uint32 a_boud)
  {
    Serial.begin(a_boud);
  }

  /**
   * Returns debug logger
   * @param a_tag log tag
   * @return debug logger
   */
  static const Log& d(const String& a_tag)
  {
    return get_log(a_tag, DEBUG, "D");
  }

  /**
   * Returns info logger
   * @param a_tag log tag
   * @return info logger
   */
  static const Log& i(const String& a_tag)
  {
    return get_log(a_tag, INFO, "I");
  }

  /**
   * Returns warning logger
   * @param a_tag log tag
   * @return warning logger
   */
  static const Log& w(const String& a_tag)
  {
    return get_log(a_tag, WARNING, "W");
  }

  /**
   * Returns error logger
   * @param a_tag log tag
   * @return error logger
   */
  static const Log& e(const String& a_tag)
  {
    return get_log(a_tag, ERROR, "E");
  }

  /**
   * Sets log level for provided tag
   * @param a_tag log tag for which level should be set
   * @param a_level log level for provided tag
   */
  static void set_tag_level(const String& a_tag, Level a_level);

  template<class T>
  void print(T arg) const
  {
    if (Log::level != NONE) {
      Serial.print(arg);
    }
  }

private:
  static const Log& get_log(const String& tag,
                            Level log_level,
                            const String& level_tag);

  Log(Level a_level)
    : level(a_level)
  {}
  typedef std::map<String, Log*> TagMap;

  static Log LOG_D;
  static Log LOG_I;
  static Log LOG_W;
  static Log LOG_E;
  static Log LOG_N;
  static TagMap tags;
  Level level;
};

// Generic template
template<class T>
inline const Log&
operator<<(const Log& stream, T arg)
{
  stream.print(arg);
  return stream;
}
}
#endif

