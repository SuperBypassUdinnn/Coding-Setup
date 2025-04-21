#pragma once

#ifndef TIMER_H
#define TIMER_H

#include <time.h>

// Mulai hitung waktu
clock_t startTimer();

// Mengakhiri hitung waktu
clock_t stopTimer();

// Menghitung waktu antara start dan end
double timerResult(int start, int end);

#endif