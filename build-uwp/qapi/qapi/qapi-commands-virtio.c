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

#include "qemu/osdep.h"
#include "qapi/compat-policy.h"
#include "qapi/visitor.h"
#include "qapi/qmp/qdict.h"
#include "qapi/dealloc-visitor.h"
#include "qapi/error.h"
#include "qapi-visit-virtio.h"
#include "qapi-commands-virtio.h"

#include "qapi/qmp/qjson.h"
#include "trace/trace-qapi_commands_virtio_trace_events.h"

static void qmp_marshal_output_VirtioInfoList(VirtioInfoList *ret_in,
                                QObject **ret_out, Error **errp)
{
    Visitor *v;

    v = qobject_output_visitor_new_qmp(ret_out);
    if (visit_type_VirtioInfoList(v, "unused", &ret_in, errp)) {
        visit_complete(v, ret_out);
    }
    visit_free(v);
    v = qapi_dealloc_visitor_new();
    visit_type_VirtioInfoList(v, "unused", &ret_in, NULL);
    visit_free(v);
}

void qmp_marshal_x_query_virtio(QDict *args, QObject **ret, Error **errp)
{
    Error *err = NULL;
    bool ok = false;
    Visitor *v;
    VirtioInfoList *retval;

    v = qobject_input_visitor_new_qmp(QOBJECT(args));
    if (!visit_start_struct(v, NULL, NULL, 0, errp)) {
        goto out;
    }
    ok = visit_check_struct(v, errp);
    visit_end_struct(v, NULL);
    if (!ok) {
        goto out;
    }

    if (trace_event_get_state_backends(TRACE_QMP_ENTER_X_QUERY_VIRTIO)) {
        g_autoptr(GString) req_json = qobject_to_json(QOBJECT(args));

        trace_qmp_enter_x_query_virtio(req_json->str);
    }
    
    retval = qmp_x_query_virtio(&err);
    if (err) {
        trace_qmp_exit_x_query_virtio(error_get_pretty(err), false);
        error_propagate(errp, err);
        goto out;
    }

    qmp_marshal_output_VirtioInfoList(retval, ret, errp);

    if (trace_event_get_state_backends(TRACE_QMP_EXIT_X_QUERY_VIRTIO)) {
        g_autoptr(GString) ret_json = qobject_to_json(*ret);

        trace_qmp_exit_x_query_virtio(ret_json->str, true);
    }
    
out:
    visit_free(v);
    v = qapi_dealloc_visitor_new();
    visit_start_struct(v, NULL, NULL, 0, NULL);
    visit_end_struct(v, NULL);
    visit_free(v);
}

static void qmp_marshal_output_VirtioStatus(VirtioStatus *ret_in,
                                QObject **ret_out, Error **errp)
{
    Visitor *v;

    v = qobject_output_visitor_new_qmp(ret_out);
    if (visit_type_VirtioStatus(v, "unused", &ret_in, errp)) {
        visit_complete(v, ret_out);
    }
    visit_free(v);
    v = qapi_dealloc_visitor_new();
    visit_type_VirtioStatus(v, "unused", &ret_in, NULL);
    visit_free(v);
}

void qmp_marshal_x_query_virtio_status(QDict *args, QObject **ret, Error **errp)
{
    Error *err = NULL;
    bool ok = false;
    Visitor *v;
    VirtioStatus *retval;
    q_obj_x_query_virtio_status_arg arg = {0};

    v = qobject_input_visitor_new_qmp(QOBJECT(args));
    if (!visit_start_struct(v, NULL, NULL, 0, errp)) {
        goto out;
    }
    if (visit_type_q_obj_x_query_virtio_status_arg_members(v, &arg, errp)) {
        ok = visit_check_struct(v, errp);
    }
    visit_end_struct(v, NULL);
    if (!ok) {
        goto out;
    }

    if (trace_event_get_state_backends(TRACE_QMP_ENTER_X_QUERY_VIRTIO_STATUS)) {
        g_autoptr(GString) req_json = qobject_to_json(QOBJECT(args));

        trace_qmp_enter_x_query_virtio_status(req_json->str);
    }
    
    retval = qmp_x_query_virtio_status(arg.path, &err);
    if (err) {
        trace_qmp_exit_x_query_virtio_status(error_get_pretty(err), false);
        error_propagate(errp, err);
        goto out;
    }

    qmp_marshal_output_VirtioStatus(retval, ret, errp);

    if (trace_event_get_state_backends(TRACE_QMP_EXIT_X_QUERY_VIRTIO_STATUS)) {
        g_autoptr(GString) ret_json = qobject_to_json(*ret);

        trace_qmp_exit_x_query_virtio_status(ret_json->str, true);
    }
    
out:
    visit_free(v);
    v = qapi_dealloc_visitor_new();
    visit_start_struct(v, NULL, NULL, 0, NULL);
    visit_type_q_obj_x_query_virtio_status_arg_members(v, &arg, NULL);
    visit_end_struct(v, NULL);
    visit_free(v);
}

static void qmp_marshal_output_VirtQueueStatus(VirtQueueStatus *ret_in,
                                QObject **ret_out, Error **errp)
{
    Visitor *v;

    v = qobject_output_visitor_new_qmp(ret_out);
    if (visit_type_VirtQueueStatus(v, "unused", &ret_in, errp)) {
        visit_complete(v, ret_out);
    }
    visit_free(v);
    v = qapi_dealloc_visitor_new();
    visit_type_VirtQueueStatus(v, "unused", &ret_in, NULL);
    visit_free(v);
}

void qmp_marshal_x_query_virtio_queue_status(QDict *args, QObject **ret, Error **errp)
{
    Error *err = NULL;
    bool ok = false;
    Visitor *v;
    VirtQueueStatus *retval;
    q_obj_x_query_virtio_queue_status_arg arg = {0};

    v = qobject_input_visitor_new_qmp(QOBJECT(args));
    if (!visit_start_struct(v, NULL, NULL, 0, errp)) {
        goto out;
    }
    if (visit_type_q_obj_x_query_virtio_queue_status_arg_members(v, &arg, errp)) {
        ok = visit_check_struct(v, errp);
    }
    visit_end_struct(v, NULL);
    if (!ok) {
        goto out;
    }

    if (trace_event_get_state_backends(TRACE_QMP_ENTER_X_QUERY_VIRTIO_QUEUE_STATUS)) {
        g_autoptr(GString) req_json = qobject_to_json(QOBJECT(args));

        trace_qmp_enter_x_query_virtio_queue_status(req_json->str);
    }
    
    retval = qmp_x_query_virtio_queue_status(arg.path, arg.queue, &err);
    if (err) {
        trace_qmp_exit_x_query_virtio_queue_status(error_get_pretty(err), false);
        error_propagate(errp, err);
        goto out;
    }

    qmp_marshal_output_VirtQueueStatus(retval, ret, errp);

    if (trace_event_get_state_backends(TRACE_QMP_EXIT_X_QUERY_VIRTIO_QUEUE_STATUS)) {
        g_autoptr(GString) ret_json = qobject_to_json(*ret);

        trace_qmp_exit_x_query_virtio_queue_status(ret_json->str, true);
    }
    
out:
    visit_free(v);
    v = qapi_dealloc_visitor_new();
    visit_start_struct(v, NULL, NULL, 0, NULL);
    visit_type_q_obj_x_query_virtio_queue_status_arg_members(v, &arg, NULL);
    visit_end_struct(v, NULL);
    visit_free(v);
}

static void qmp_marshal_output_VirtVhostQueueStatus(VirtVhostQueueStatus *ret_in,
                                QObject **ret_out, Error **errp)
{
    Visitor *v;

    v = qobject_output_visitor_new_qmp(ret_out);
    if (visit_type_VirtVhostQueueStatus(v, "unused", &ret_in, errp)) {
        visit_complete(v, ret_out);
    }
    visit_free(v);
    v = qapi_dealloc_visitor_new();
    visit_type_VirtVhostQueueStatus(v, "unused", &ret_in, NULL);
    visit_free(v);
}

void qmp_marshal_x_query_virtio_vhost_queue_status(QDict *args, QObject **ret, Error **errp)
{
    Error *err = NULL;
    bool ok = false;
    Visitor *v;
    VirtVhostQueueStatus *retval;
    q_obj_x_query_virtio_vhost_queue_status_arg arg = {0};

    v = qobject_input_visitor_new_qmp(QOBJECT(args));
    if (!visit_start_struct(v, NULL, NULL, 0, errp)) {
        goto out;
    }
    if (visit_type_q_obj_x_query_virtio_vhost_queue_status_arg_members(v, &arg, errp)) {
        ok = visit_check_struct(v, errp);
    }
    visit_end_struct(v, NULL);
    if (!ok) {
        goto out;
    }

    if (trace_event_get_state_backends(TRACE_QMP_ENTER_X_QUERY_VIRTIO_VHOST_QUEUE_STATUS)) {
        g_autoptr(GString) req_json = qobject_to_json(QOBJECT(args));

        trace_qmp_enter_x_query_virtio_vhost_queue_status(req_json->str);
    }
    
    retval = qmp_x_query_virtio_vhost_queue_status(arg.path, arg.queue, &err);
    if (err) {
        trace_qmp_exit_x_query_virtio_vhost_queue_status(error_get_pretty(err), false);
        error_propagate(errp, err);
        goto out;
    }

    qmp_marshal_output_VirtVhostQueueStatus(retval, ret, errp);

    if (trace_event_get_state_backends(TRACE_QMP_EXIT_X_QUERY_VIRTIO_VHOST_QUEUE_STATUS)) {
        g_autoptr(GString) ret_json = qobject_to_json(*ret);

        trace_qmp_exit_x_query_virtio_vhost_queue_status(ret_json->str, true);
    }
    
out:
    visit_free(v);
    v = qapi_dealloc_visitor_new();
    visit_start_struct(v, NULL, NULL, 0, NULL);
    visit_type_q_obj_x_query_virtio_vhost_queue_status_arg_members(v, &arg, NULL);
    visit_end_struct(v, NULL);
    visit_free(v);
}

static void qmp_marshal_output_VirtioQueueElement(VirtioQueueElement *ret_in,
                                QObject **ret_out, Error **errp)
{
    Visitor *v;

    v = qobject_output_visitor_new_qmp(ret_out);
    if (visit_type_VirtioQueueElement(v, "unused", &ret_in, errp)) {
        visit_complete(v, ret_out);
    }
    visit_free(v);
    v = qapi_dealloc_visitor_new();
    visit_type_VirtioQueueElement(v, "unused", &ret_in, NULL);
    visit_free(v);
}

void qmp_marshal_x_query_virtio_queue_element(QDict *args, QObject **ret, Error **errp)
{
    Error *err = NULL;
    bool ok = false;
    Visitor *v;
    VirtioQueueElement *retval;
    q_obj_x_query_virtio_queue_element_arg arg = {0};

    v = qobject_input_visitor_new_qmp(QOBJECT(args));
    if (!visit_start_struct(v, NULL, NULL, 0, errp)) {
        goto out;
    }
    if (visit_type_q_obj_x_query_virtio_queue_element_arg_members(v, &arg, errp)) {
        ok = visit_check_struct(v, errp);
    }
    visit_end_struct(v, NULL);
    if (!ok) {
        goto out;
    }

    if (trace_event_get_state_backends(TRACE_QMP_ENTER_X_QUERY_VIRTIO_QUEUE_ELEMENT)) {
        g_autoptr(GString) req_json = qobject_to_json(QOBJECT(args));

        trace_qmp_enter_x_query_virtio_queue_element(req_json->str);
    }
    
    retval = qmp_x_query_virtio_queue_element(arg.path, arg.queue, arg.has_index, arg.index, &err);
    if (err) {
        trace_qmp_exit_x_query_virtio_queue_element(error_get_pretty(err), false);
        error_propagate(errp, err);
        goto out;
    }

    qmp_marshal_output_VirtioQueueElement(retval, ret, errp);

    if (trace_event_get_state_backends(TRACE_QMP_EXIT_X_QUERY_VIRTIO_QUEUE_ELEMENT)) {
        g_autoptr(GString) ret_json = qobject_to_json(*ret);

        trace_qmp_exit_x_query_virtio_queue_element(ret_json->str, true);
    }
    
out:
    visit_free(v);
    v = qapi_dealloc_visitor_new();
    visit_start_struct(v, NULL, NULL, 0, NULL);
    visit_type_q_obj_x_query_virtio_queue_element_arg_members(v, &arg, NULL);
    visit_end_struct(v, NULL);
    visit_free(v);
}

/* Dummy declaration to prevent empty .o file */
char qapi_dummy_qapi_commands_virtio_c;
