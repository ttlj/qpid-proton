#ifndef PROTON_CODEC_H
#define PROTON_CODEC_H 1

/*
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 */

#include <proton/types.h>

#ifdef _WINDOWS						// mdh -- header changes for windows
	#include <stdint.h>
	#include <stdarg.h>
#else
	#include <stdbool.h>
	#include <stdint.h>
	#include <unistd.h>
	#include <stdarg.h>
#endif

/* ttlj: src_util.h was copied from the src folder;
   instead of the protonWinSnap branch including stuff from the src/ folder;
   QPID_PROTON.h was also copied from proton-c/ folder */
#include "src_util.h"
#include "QPID_PROTON.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  PN_NULL,
  PN_BOOL,
  PN_UBYTE,
  PN_BYTE,
  PN_USHORT,
  PN_SHORT,
  PN_UINT,
  PN_INT,
  PN_CHAR,
  PN_ULONG,
  PN_LONG,
  PN_TIMESTAMP,
  PN_FLOAT,
  PN_DOUBLE,
  PN_DECIMAL32,
  PN_DECIMAL64,
  PN_DECIMAL128,
  PN_UUID,
  PN_BINARY,
  PN_STRING,
  PN_SYMBOL,
  PN_DESCRIBED,
  PN_ARRAY,
  PN_LIST,
  PN_MAP
} pn_type_t;

typedef struct {
  pn_type_t type;
  union {
    bool as_bool;
    uint8_t as_ubyte;
    int8_t as_byte;
    uint16_t as_ushort;
    int16_t as_short;
    uint32_t as_uint;
    int32_t as_int;
    pn_char_t as_char;
    uint64_t as_ulong;
    int64_t as_long;
    pn_timestamp_t as_timestamp;
    float as_float;
    double as_double;
    pn_decimal32_t as_decimal32;
    pn_decimal64_t as_decimal64;
    pn_decimal128_t as_decimal128;
    pn_uuid_t as_uuid;
    pn_bytes_t as_bytes;
    size_t as_count;
  } u;
} pn_atom_t;

// data

typedef struct pn_data_t pn_data_t;

QPID_PROTON_API pn_data_t *pn_data(size_t capacity);
QPID_PROTON_API void pn_data_free(pn_data_t *data);
QPID_PROTON_PY	int pn_data_errno(pn_data_t *data);
QPID_PROTON_PY	const char *pn_data_error(pn_data_t *data);
QPID_PROTON_API int pn_data_vfill(pn_data_t *data, const char *fmt, va_list ap);
QPID_PROTON_API int pn_data_fill(pn_data_t *data, const char *fmt, ...);
QPID_PROTON_PY	int pn_data_vscan(pn_data_t *data, const char *fmt, va_list ap);
QPID_PROTON_API int pn_data_scan(pn_data_t *data, const char *fmt, ...);

QPID_PROTON_API int pn_data_clear(pn_data_t *data);
QPID_PROTON_PY	size_t pn_data_size(pn_data_t *data);
QPID_PROTON_PY	void pn_data_rewind(pn_data_t *data);
QPID_PROTON_PY	bool pn_data_next(pn_data_t *data);
QPID_PROTON_PY	bool pn_data_prev(pn_data_t *data);
QPID_PROTON_PY	bool pn_data_enter(pn_data_t *data);
QPID_PROTON_PY	bool pn_data_exit(pn_data_t *data);

QPID_PROTON_PY  pn_type_t pn_data_type(pn_data_t *data);

QPID_PROTON_API int pn_data_print(pn_data_t *data);
QPID_PROTON_API int pn_data_format(pn_data_t *data, char *bytes, size_t *size);
QPID_PROTON_PY	ssize_t pn_data_encode(pn_data_t *data, char *bytes, size_t size);
QPID_PROTON_PY	ssize_t pn_data_decode(pn_data_t *data, char *bytes, size_t size);

QPID_PROTON_PY	int pn_data_put_list(pn_data_t *data);
QPID_PROTON_PY	int pn_data_put_map(pn_data_t *data);
QPID_PROTON_PY	int pn_data_put_array(pn_data_t *data, bool described, pn_type_t type);
QPID_PROTON_PY	int pn_data_put_described(pn_data_t *data);
QPID_PROTON_PY	int pn_data_put_null(pn_data_t *data);
QPID_PROTON_PY	int pn_data_put_bool(pn_data_t *data, bool b);
QPID_PROTON_PY	int pn_data_put_ubyte(pn_data_t *data, uint8_t ub);
QPID_PROTON_PY	int pn_data_put_byte(pn_data_t *data, int8_t b);
QPID_PROTON_PY	int pn_data_put_ushort(pn_data_t *data, uint16_t us);
QPID_PROTON_PY	int pn_data_put_short(pn_data_t *data, int16_t s);
QPID_PROTON_PY	int pn_data_put_uint(pn_data_t *data, uint32_t ui);
QPID_PROTON_PY	int pn_data_put_int(pn_data_t *data, int32_t i);
QPID_PROTON_PY	int pn_data_put_char(pn_data_t *data, pn_char_t c);
QPID_PROTON_PY	int pn_data_put_ulong(pn_data_t *data, uint64_t ul);
QPID_PROTON_PY	int pn_data_put_long(pn_data_t *data, int64_t l);
QPID_PROTON_PY	int pn_data_put_timestamp(pn_data_t *data, pn_timestamp_t t);
QPID_PROTON_PY	int pn_data_put_float(pn_data_t *data, float f);
QPID_PROTON_PY	int pn_data_put_double(pn_data_t *data, double d);
QPID_PROTON_PY	int pn_data_put_decimal32(pn_data_t *data, pn_decimal32_t d);
QPID_PROTON_PY	int pn_data_put_decimal64(pn_data_t *data, pn_decimal64_t d);
QPID_PROTON_PY	int pn_data_put_decimal128(pn_data_t *data, pn_decimal128_t d);
QPID_PROTON_PY	int pn_data_put_uuid(pn_data_t *data, pn_uuid_t u);
QPID_PROTON_PY	int pn_data_put_binary(pn_data_t *data, pn_bytes_t bytes);
QPID_PROTON_PY	int pn_data_put_string(pn_data_t *data, pn_bytes_t string);
QPID_PROTON_PY	int pn_data_put_symbol(pn_data_t *data, pn_bytes_t symbol);
QPID_PROTON_PY	int pn_data_put_atom(pn_data_t *data, pn_atom_t atom);

QPID_PROTON_PY	size_t pn_data_get_list(pn_data_t *data);
QPID_PROTON_PY	size_t pn_data_get_map(pn_data_t *data);
QPID_PROTON_PY	size_t pn_data_get_array(pn_data_t *data);
QPID_PROTON_PY	bool pn_data_is_array_described(pn_data_t *data);
QPID_PROTON_PY	pn_type_t pn_data_get_array_type(pn_data_t *data);
QPID_PROTON_PY	bool pn_data_is_described(pn_data_t *data);
QPID_PROTON_PY	bool pn_data_is_null(pn_data_t *data);
QPID_PROTON_PY	bool pn_data_get_bool(pn_data_t *data);
QPID_PROTON_PY	uint8_t pn_data_get_ubyte(pn_data_t *data);
QPID_PROTON_PY	int8_t pn_data_get_byte(pn_data_t *data);
QPID_PROTON_PY	uint16_t pn_data_get_ushort(pn_data_t *data);
QPID_PROTON_PY	int16_t pn_data_get_short(pn_data_t *data);
QPID_PROTON_PY	uint32_t pn_data_get_uint(pn_data_t *data);
QPID_PROTON_PY	int32_t pn_data_get_int(pn_data_t *data);
QPID_PROTON_PY	pn_char_t pn_data_get_char(pn_data_t *data);
QPID_PROTON_PY	uint64_t pn_data_get_ulong(pn_data_t *data);
QPID_PROTON_PY	int64_t pn_data_get_long(pn_data_t *data);
QPID_PROTON_PY	pn_timestamp_t pn_data_get_timestamp(pn_data_t *data);
QPID_PROTON_PY	float pn_data_get_float(pn_data_t *data);
QPID_PROTON_PY	double pn_data_get_double(pn_data_t *data);
QPID_PROTON_PY	pn_decimal32_t pn_data_get_decimal32(pn_data_t *data);
QPID_PROTON_PY	pn_decimal64_t pn_data_get_decimal64(pn_data_t *data);
QPID_PROTON_PY	pn_decimal128_t pn_data_get_decimal128(pn_data_t *data);
QPID_PROTON_PY	pn_uuid_t pn_data_get_uuid(pn_data_t *data);
QPID_PROTON_PY	pn_bytes_t pn_data_get_binary(pn_data_t *data);
QPID_PROTON_PY	pn_bytes_t pn_data_get_string(pn_data_t *data);
QPID_PROTON_PY	pn_bytes_t pn_data_get_symbol(pn_data_t *data);
QPID_PROTON_PY	pn_bytes_t pn_data_get_bytes(pn_data_t *data);
QPID_PROTON_PY	pn_atom_t pn_data_get_atom(pn_data_t *data);


QPID_PROTON_PY	int pn_data_copy(pn_data_t *data, pn_data_t *src);
QPID_PROTON_PY	int pn_data_append(pn_data_t *data, pn_data_t *src);
QPID_PROTON_PY	int pn_data_appendn(pn_data_t *data, pn_data_t *src, int limit);
QPID_PROTON_PY	void pn_data_narrow(pn_data_t *data);
QPID_PROTON_PY	void pn_data_widen(pn_data_t *data);

QPID_PROTON_PY	void pn_data_dump(pn_data_t *data);

#ifdef __cplusplus
}
#endif

#endif /* codec.h */
