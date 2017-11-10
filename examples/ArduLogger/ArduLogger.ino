#include <ArduLogger.h>

using namespace ardulogger;
static const String TAG1 = "TEST1";
static const String TAG2 = "TEST2";
static const String TAG3 = "TEST3";

void setup() {
  Log::enable(115200);
  Log::set_tag_level(TAG1, Log::DEBUG);
  Log::set_tag_level(TAG2, Log::ERROR);

  // Should log all levels
  Log::d(TAG1) << "Debug for tag1\n";
  Log::i(TAG1) << "Info for tag1\n";
  Log::w(TAG1) << "Warning for tag1\n";
  Log::e(TAG1) << "Error for tag1\n";

  // Should log only ERROR
  Log::d(TAG2) << "Debug for tag2\n";
  Log::i(TAG2) << "Info for tag2\n";
  Log::w(TAG2) << "Warning for tag2\n";
  Log::e(TAG2) << "Error for tag2\n";

  // Shouldn't log anything
  Log::d(TAG3) << "Debug for tag3\n";
  Log::i(TAG3) << "Info for tag3\n";
  Log::w(TAG3) << "Warning for tag3\n";
  Log::e(TAG3) << "Error for tag3\n";
}

void loop() {
  // put your main code here, to run repeatedly:

}


