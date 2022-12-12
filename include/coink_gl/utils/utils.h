//
// Created by Benjamin on 11/12/2022.
//
#pragma once
#include <string>
#include <iostream>

namespace Utils {
enum LOG_LEVEL {
  FATAL,
  ERROR,
  WARN,
  INFO,
  DEBUG
};

// https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
const std::string GetCurrentDateTime();
void Log(const Utils::LOG_LEVEL& p_log_level, const std::string& p_message);

void EnableLog();
void EnableInfoLog();
void EnableDebugLog();

void DisableLog();
void DisableInfoLog();
void DisableDebugLog();

}