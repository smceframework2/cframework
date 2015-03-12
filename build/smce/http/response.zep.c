
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework 2
 * @github https://github.com/smceframework22
 */
ZEPHIR_INIT_CLASS(Smce_Http_Response) {

	ZEPHIR_REGISTER_CLASS_EX(Smce\\Http, Response, smce, http_response, smce_http_httpexception_ce, smce_http_response_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Smce_Http_Response, __construct) {

	zval *msg = NULL;
	zval *httpCode_param = NULL, *msg_param = NULL, *_0, *_1;
	int httpCode, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &httpCode_param, &msg_param);

	httpCode = zephir_get_intval(httpCode_param);
	zephir_get_strval(msg, msg_param);


	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, smce_http_httpexception_ce);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, httpCode);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _1, msg);
	zephir_check_call_status();
	zephir_throw_exception_debug(_0, "smce/http/response.zep", 24 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

