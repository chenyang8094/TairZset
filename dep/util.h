/*
 * Copyright (c) 2009-2012, Salvatore Sanfilippo <antirez at gmail dot com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of Redis nor the names of its contributors may be used
 *     to endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __UTIL_H_
#define __UTIL_H_

#include <stdint.h>
#include <sys/types.h>

/* The maximum number of characters needed to represent a long double
 * as a string (long double has a huge range).
 * This should be the size of the buffer given to ld2string */
#define MAX_LONG_DOUBLE_CHARS 5*1024

#if __GNUC__ >= 4
#define redis_unreachable __builtin_unreachable
#else
#define redis_unreachable abort
#endif

#define C_OK                    0
#define C_ERR                   -1

int m_stringmatchlen(const char *p, int plen, const char *s, int slen, int nocase);
int m_stringmatch(const char *p, const char *s, int nocase);
int m_stringmatchlen_fuzz_test(void);
long long m_memtoll(const char *p, int *err);
uint32_t m_digits10(uint64_t v);
uint32_t m_sdigits10(int64_t v);
int m_ll2string(char *s, size_t len, long long value);
int m_string2ll(const char *s, size_t slen, long long *value);
int m_string2l(const char *s, size_t slen, long *value);
int m_string2ld(const char *s, size_t slen, long double *dp);
int m_string2d(const char *s, size_t slen, double *dp);
int m_d2string(char *buf, size_t len, double value);
int m_ld2string(char *buf, size_t len, long double value, int humanfriendly);

#endif