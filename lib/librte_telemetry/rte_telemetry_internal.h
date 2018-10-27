/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2018 Intel Corporation
 */

#include <rte_log.h>
#include <rte_tailq.h>

#ifndef _RTE_TELEMETRY_INTERNAL_H_
#define _RTE_TELEMETRY_INTERNAL_H_

/* Logging Macros */
extern int telemetry_log_level;

#define TELEMETRY_LOG(level, fmt, args...) \
	rte_log(RTE_LOG_ ##level, telemetry_log_level, "%s(): "fmt "\n", \
		__func__, ##args)

#define TELEMETRY_LOG_ERR(fmt, args...) \
	TELEMETRY_LOG(ERR, fmt, ## args)

#define TELEMETRY_LOG_WARN(fmt, args...) \
	TELEMETRY_LOG(WARNING, fmt, ## args)

#define TELEMETRY_LOG_INFO(fmt, args...) \
	TELEMETRY_LOG(INFO, fmt, ## args)

typedef struct telemetry_client {
	char *file_path;
	int fd;
	TAILQ_ENTRY(telemetry_client) client_list;
} telemetry_client;

typedef struct telemetry_impl {
	int accept_fd;
	int server_fd;
	pthread_t thread_id;
	int thread_status;
	uint32_t socket_id;
	int reg_index;
	int metrics_register_done;
	TAILQ_HEAD(, telemetry_client) client_list_head;
	struct telemetry_client *request_client;
	int register_fail_count;
} telemetry_impl;

int32_t
rte_telemetry_parse_client_message(struct telemetry_impl *telemetry, char *buf);

int32_t
rte_telemetry_send_error_response(struct telemetry_impl *telemetry,
	int error_type);

int32_t
rte_telemetry_register_client(struct telemetry_impl *telemetry,
	const char *client_path);

int32_t
rte_telemetry_unregister_client(struct telemetry_impl *telemetry,
	const char *client_path);

#endif