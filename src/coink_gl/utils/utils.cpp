//
// Created by Benjamin on 11/12/2022.
//
#include "utils/utils.h"

namespace Utils {

namespace {
bool all_log = true;
bool info_log = true;
bool debug_log = false;

void NewLog(const std::string& prefix, const std::string& message) {
  if (!all_log) return;
  std::cout << "[" << GetCurrentDateTime() << "] ["
            << prefix << "] : "
            << message << "\n";
}

}

static std::string GetTextLogLevel(const COINK_LOG_LEVEL& p_log_level) {
  switch (p_log_level) {
    case FATAL:
      return "FATAL";
      break;
    case ERROR:
      return "ERROR";
      break;
    case WARN:
      return "WARN";
      break;
    case INFO:
      return "INFO";
      break;
    case DEBUG:
      return "DEBUG";
      break;
  }
  return "#####";
}

const std::string GetCurrentDateTime() {
  time_t     now = time(0);
  struct tm  tstruct;
  char       buf[80];
  tstruct = *localtime(&now);
  strftime(buf, sizeof(buf), "%Y/%m/%d %X", &tstruct);

  return buf;
}


void Log(const COINK_LOG_LEVEL& p_log_level, const std::string& p_message) {
  if (!all_log) return;
  if (p_log_level == COINK_LOG_LEVEL::INFO && !info_log) return;
  if (p_log_level == COINK_LOG_LEVEL::DEBUG && !debug_log) return;
  std::cout << "[" << GetCurrentDateTime() << "] [" <<
                GetTextLogLevel(p_log_level) << "] : "
                << p_message << "\n";
}



void FatalLog(const std::string& message) { NewLog("FATAL", message); }
void ErrorLog(const std::string& message) { NewLog("ERROR", message); }
void WarnLog(const std::string& message)  { NewLog("WARN", message); }

void InfoLog(const std::string& message)  { 
  if (info_log)
    NewLog("INFO", message); 
}

void DebugLog(const std::string& message) { 
  if (debug_log)
    NewLog("DEBUG", message); 
}





void EnableLog() {
  all_log = true;
}

void EnableInfoLog() {
  info_log = true;
}

void EnableDebugLog() {
  debug_log = true;
}


void DisableLog() {
  all_log = false;
}

void DisableInfoLog() {
  info_log = false;
}

void DisableDebugLog() {
  debug_log = false;
}

}
