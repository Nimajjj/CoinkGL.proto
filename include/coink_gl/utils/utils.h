//
// Created by Benjamin on 11/12/2022.
//
#pragma once
#include <string>
#include <iostream>

#include "type/type.h"

namespace Utils {
// https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
const std::string GetCurrentDateTime();
void Log(const COINK_LOG_LEVEL& p_log_level, const std::string& p_message);

void EnableLog();
void EnableInfoLog();
void EnableDebugLog();

void DisableLog();
void DisableInfoLog();
void DisableDebugLog();

}