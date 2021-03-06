#include "mod_mruby.h"
#include "ap_mrb_server.h"
//#include "json.h"

//static struct mrb_data_type server_rec_type = {
//    "server_rec", 0,
//};

// char write
/*
mrb_value ap_mrb_set_server_error_fname(mrb_state *mrb, mrb_value str)
{
    mrb_value val;
    request_rec *r = ap_mrb_get_request();
    mrb_get_args(mrb, "o", &val);
    r->server->error_fname = apr_pstrdup(r->pool, RSTRING_PTR(val));
    return val;
}
*/

// char read
mrb_value ap_mrb_get_conn_remote_ip(mrb_state *mrb, mrb_value str)
{
    request_rec *r = ap_mrb_get_request();
#ifdef __APACHE24__
    char *val = apr_pstrdup(r->pool, ap_mrb_string_check(r->pool, r->connection->client_ip));
#else
    char *val = apr_pstrdup(r->pool, ap_mrb_string_check(r->pool, r->connection->remote_ip));
#endif
    return mrb_str_new(mrb, val, strlen(val));
}

mrb_value ap_mrb_get_conn_remote_host(mrb_state *mrb, mrb_value str)
{
    request_rec *r = ap_mrb_get_request();
    char *val = apr_pstrdup(r->pool, ap_mrb_string_check(r->pool, r->connection->remote_host));
    return mrb_str_new(mrb, val, strlen(val));
}

mrb_value ap_mrb_get_conn_remote_logname(mrb_state *mrb, mrb_value str)
{
    request_rec *r = ap_mrb_get_request();
    char *val = apr_pstrdup(r->pool, ap_mrb_string_check(r->pool, r->connection->remote_logname));
    return mrb_str_new(mrb, val, strlen(val));
}

mrb_value ap_mrb_get_conn_local_ip(mrb_state *mrb, mrb_value str)
{
    request_rec *r = ap_mrb_get_request();
    char *val = apr_pstrdup(r->pool, ap_mrb_string_check(r->pool, r->connection->local_ip));
    return mrb_str_new(mrb, val, strlen(val));
}

mrb_value ap_mrb_get_conn_local_host(mrb_state *mrb, mrb_value str)
{
    request_rec *r = ap_mrb_get_request();
    char *val = apr_pstrdup(r->pool, ap_mrb_string_check(r->pool, r->connection->local_host));
    return mrb_str_new(mrb, val, strlen(val));
}

// int write
/*
mrb_value ap_mrb_set_server_loglevel(mrb_state *mrb, mrb_value str)
{
    mrb_int val;
    request_rec *r = ap_mrb_get_request();
    mrb_get_args(mrb, "i", &val);
#ifdef __APACHE24__
    r->server->log.level = (int)val;
#else
    r->server->loglevel = (int)val;
#endif
    return str;
}

// int read
mrb_value ap_mrb_get_server_loglevel(mrb_state *mrb, mrb_value str)
{
    request_rec *r = ap_mrb_get_request();
#ifdef __APACHE24__
    return mrb_fixnum_value(r->server->log.level);
#else
    return mrb_fixnum_value(r->server->loglevel);
#endif
}
*/

mrb_value ap_mrb_get_conn_keepalives(mrb_state *mrb, mrb_value str)
{
    request_rec *r = ap_mrb_get_request();
    return mrb_fixnum_value(r->connection->keepalives);
}

mrb_value ap_mrb_get_conn_data_in_input_filters(mrb_state *mrb, mrb_value str)
{
    request_rec *r = ap_mrb_get_request();
    return mrb_fixnum_value(r->connection->data_in_input_filters);
}

