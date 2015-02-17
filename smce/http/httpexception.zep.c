
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework 2
 * @github https://github.com/smceframework
 */
ZEPHIR_INIT_CLASS(Smce_Http_HttpException) {

	ZEPHIR_REGISTER_CLASS_EX(Smce\\Http, HttpException, smce, http_httpexception, zend_exception_get_default(TSRMLS_C), smce_http_httpexception_method_entry, 0);

	zend_declare_property_null(smce_http_httpexception_ce, SL("httpCode"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(smce_http_httpexception_ce, SL("msg"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Smce_Http_HttpException, __construct) {

	zval *msg = NULL;
	zval *httpCode_param = NULL, *msg_param = NULL, *_0;
	int httpCode, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &httpCode_param, &msg_param);

	httpCode = zephir_get_intval(httpCode_param);
	zephir_get_strval(msg, msg_param);


	zephir_update_property_this(this_ptr, SL("msg"), msg TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, httpCode);
	zephir_update_property_this(this_ptr, SL("httpCode"), _0 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("httpCode"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "http_response_code", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Http_HttpException, getMsg) {


	RETURN_MEMBER(this_ptr, "msg");

}

PHP_METHOD(Smce_Http_HttpException, getHttpCode) {


	RETURN_MEMBER(this_ptr, "httpCode");

}

PHP_METHOD(Smce_Http_HttpException, htppError) {

	zval *httpError, *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(httpError);
	array_init_size(httpError, 3);
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("httpCode"), PH_NOISY_CC);
	zephir_array_update_string(&httpError, SL("code"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("msg"), PH_NOISY_CC);
	zephir_array_update_string(&httpError, SL("msg"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(httpError);

}

PHP_METHOD(Smce_Http_HttpException, http_response_code) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL;
	zval *_1;
	zval *code_param = NULL, *text = NULL, *protocol = NULL, _0 = zval_used_for_init, _2, *_SERVER, *_4;
	int code, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &code_param);

	if (!code_param) {
		code = 0;
	} else {
		code = zephir_get_intval(code_param);
	}


	do {
		if (code == 100) {
			ZEPHIR_INIT_VAR(text);
			ZVAL_STRING(text, "Continue", 1);
			break;
		}
		if (code == 101) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Switching Protocols", 1);
			break;
		}
		if (code == 200) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "OK", 1);
			break;
		}
		if (code == 201) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Created", 1);
			break;
		}
		if (code == 202) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Accepted", 1);
			break;
		}
		if (code == 203) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Non-Authoritative Information", 1);
			break;
		}
		if (code == 204) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "No Content", 1);
			break;
		}
		if (code == 205) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Reset Content", 1);
			break;
		}
		if (code == 206) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Partial Content", 1);
			break;
		}
		if (code == 300) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Multiple Choices", 1);
			break;
		}
		if (code == 301) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Moved Permanently", 1);
			break;
		}
		if (code == 302) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Moved Temporarily", 1);
			break;
		}
		if (code == 303) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "See Other", 1);
			break;
		}
		if (code == 304) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Not Modified", 1);
			break;
		}
		if (code == 305) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Use Proxy", 1);
			break;
		}
		if (code == 400) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Bad Request", 1);
			break;
		}
		if (code == 401) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Unauthorized", 1);
			break;
		}
		if (code == 402) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Payment Required", 1);
			break;
		}
		if (code == 403) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Forbidden", 1);
			break;
		}
		if (code == 404) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Not Found", 1);
			break;
		}
		if (code == 405) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Method Not Allowed", 1);
			break;
		}
		if (code == 406) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Not Acceptable", 1);
			break;
		}
		if (code == 407) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Proxy Authentication Required", 1);
			break;
		}
		if (code == 408) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Request Time-out", 1);
			break;
		}
		if (code == 409) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Conflict", 1);
			break;
		}
		if (code == 410) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Gone", 1);
			break;
		}
		if (code == 411) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Length Required", 1);
			break;
		}
		if (code == 412) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Precondition Failed", 1);
			break;
		}
		if (code == 413) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Request Entity Too Large", 1);
			break;
		}
		if (code == 414) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Request-URI Too Large", 1);
			break;
		}
		if (code == 415) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Unsupported Media Type", 1);
			break;
		}
		if (code == 500) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Internal Server Error", 1);
			break;
		}
		if (code == 501) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Not Implemented", 1);
			break;
		}
		if (code == 502) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Bad Gateway", 1);
			break;
		}
		if (code == 503) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Service Unavailable", 1);
			break;
		}
		if (code == 504) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "Gateway Time-out", 1);
			break;
		}
		if (code == 505) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "HTTP Version not supported", 1);
			break;
		}
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_LONG(&_0, code);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SV(_1, "Unknown http status code ", &_0);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_LONG(&_2, 256);
		ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", &_3, _1, &_2);
		zephir_check_call_status();
	} while(0);

	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	if (zephir_array_isset_string(_SERVER, SS("SERVER_PROTOCOL"))) {
		ZEPHIR_OBS_VAR(protocol);
		zephir_array_fetch_string(&protocol, _SERVER, SL("SERVER_PROTOCOL"), PH_NOISY, "smce/http/httpexception.zep", 95 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(protocol);
		ZVAL_STRING(protocol, "HTTP/1.0", 1);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, code);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VSVSV(_4, protocol, " ", &_0, " ", text);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_5, _4);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

