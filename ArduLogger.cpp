#include "ArduLogger.h"

namespace ardulogger {
Log Log::LOG_D(DEBUG);
Log Log::LOG_I(INFO);
Log Log::LOG_W(WARNING);
Log Log::LOG_E(ERROR);
Log Log::LOG_N(NONE);
Log::TagMap Log::tags;

const Log&
Log::get_log(const String& tag, Level log_level, const String& level_tag)
{
  const Log& log =
    *(tags.insert(std::pair<String, Log*>(tag, &LOG_N)).first->second);
  if (log.level > log_level) {
    return LOG_N;
  }

  log << String(F("[")) << level_tag << String(F("][")) << tag
      << String(F("]: "));
  return log;
}

void
Log::set_tag_level(const String& a_tag, Level a_level)
{
  switch (a_level) {
    case DEBUG:
      tags[a_tag] = &LOG_D;
      break;
    case INFO:
      tags[a_tag] = &LOG_I;
      break;
    case WARNING:
      tags[a_tag] = &LOG_W;
      break;
    case ERROR:
      tags[a_tag] = &LOG_E;
      break;
    default:
      tags[a_tag] = &LOG_N;
  }
}
}

