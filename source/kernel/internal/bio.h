/*
 * Copyright(c) 2012-2018 Intel Corporation
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */

#ifndef SOURCE_KERNEL_INTERNAL_BIO_H
#define SOURCE_KERNEL_INTERNAL_BIO_H

#include <linux/bio.h>
#include <linux/blkdev.h>
#include <linux/version.h>

#if LINUX_VERSION_CODE != KERNEL_VERSION(3, 10, 0)
#error Unsupported Linux Kernel Version
#endif

#define IOTRACE_BIO_OP_FLAGS(bio) (bio)->bi_rw

/* bio operation macros (read/write/discard) */
#define IOTRACE_BIO_IS_WRITE(bio) (bio_data_dir(bio) == WRITE)
#define IOTRACE_BIO_IS_DISCARD(bio) ((IOTRACE_BIO_OP_FLAGS(bio)) & REQ_DISCARD)

/* bio atributes macros (address, size ...) */
#define IOTRACE_BIO_BISIZE(bio) (bio)->bi_size
#define IOTRACE_BIO_BISECTOR(bio) (bio)->bi_sector

/* bio flags macros (flush, fua, ...) */
#define IOTRACE_BIO_IS_FLUSH(bio) ((IOTRACE_BIO_OP_FLAGS(bio)) & REQ_FLUSH)
#define IOTRACE_BIO_IS_FUA(bio) ((IOTRACE_BIO_OP_FLAGS(bio)) & REQ_FUA)

#endif  // SOURCE_KERNEL_INTERNAL_BIO_H
