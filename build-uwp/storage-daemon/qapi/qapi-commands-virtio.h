/* AUTOMATICALLY GENERATED, DO NOT MODIFY */

/*
 * Schema-defined QAPI/QMP commands
 *
 * Copyright IBM, Corp. 2011
 * Copyright (C) 2014-2018 Red Hat, Inc.
 *
 * This work is licensed under the terms of the GNU LGPL, version 2.1 or later.
 * See the COPYING.LIB file in the top-level directory.
 */

#ifndef QAPI_COMMANDS_VIRTIO_H
#define QAPI_COMMANDS_VIRTIO_H

#include "qapi-types-virtio.h"

VirtioInfoList *qmp_x_query_virtio(Error **errp);
void qmp_marshal_x_query_virtio(QDict *args, QObject **ret, Error **errp);
VirtioStatus *qmp_x_query_virtio_status(const char *path, Error **errp);
void qmp_marshal_x_query_virtio_status(QDict *args, QObject **ret, Error **errp);
VirtQueueStatus *qmp_x_query_virtio_queue_status(const char *path, uint16_t queue, Error **errp);
void qmp_marshal_x_query_virtio_queue_status(QDict *args, QObject **ret, Error **errp);
VirtVhostQueueStatus *qmp_x_query_virtio_vhost_queue_status(const char *path, uint16_t queue, Error **errp);
void qmp_marshal_x_query_virtio_vhost_queue_status(QDict *args, QObject **ret, Error **errp);
VirtioQueueElement *qmp_x_query_virtio_queue_element(const char *path, uint16_t queue, bool has_index, uint16_t index, Error **errp);
void qmp_marshal_x_query_virtio_queue_element(QDict *args, QObject **ret, Error **errp);

#endif /* QAPI_COMMANDS_VIRTIO_H */
