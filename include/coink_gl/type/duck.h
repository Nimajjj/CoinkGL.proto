//
// Created by Benjamin on 15/12/2022.
//

#pragma once

// Because every duck is unique

using DUCK = unsigned long int;

namespace Duck {
static DUCK last_id = 0;

inline DUCK New() { return ++last_id; }
};