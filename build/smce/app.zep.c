
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/exit.h"


ZEPHIR_INIT_CLASS(Smce_App) {

	ZEPHIR_REGISTER_CLASS(Smce, App, smce, app, smce_app_method_entry, 0);

	zend_declare_property_null(smce_app_ce, SL("data"), ZEND_ACC_PRIVATE TSRMLS_CC);

	smce_app_ce->create_object = zephir_init_properties_Smce_App;
	return SUCCESS;

}

PHP_METHOD(Smce_App, __construct) {

	HashTable *_6$$3;
	HashPosition _5$$3;
	zval *config = NULL, *key = NULL, *value = NULL, *_0 = NULL, *_1, *_2, *_4, **_7$$3;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_SELF(&_0, "baseurl", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "baseurl", 1);
	zephir_update_property_array(this_ptr, SL("data"), _1, _0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getip", NULL, 4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "ip", 1);
	zephir_update_property_array(this_ptr, SL("data"), _2, _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&config, smce_core_eventmanager_ce, "pull", &_3, 5, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE(config)) {
		zephir_is_iterable(config, &_6$$3, &_5$$3, 0, 0, "smce/app.zep", 26);
		for (
		  ; zephir_hash_get_current_data_ex(_6$$3, (void**) &_7$$3, &_5$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6$$3, &_5$$3)
		) {
			ZEPHIR_GET_HMKEY(key, _6$$3, _5$$3);
			ZEPHIR_GET_HVALUE(value, _7$$3);
			zephir_update_property_array(this_ptr, SL("data"), key, value TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_App, __get) {

	zval *name, *_0 = NULL, *_1, *_2, _3, _4, *_5, *_6, *_7, _8, _9, *_10, *_11, *_12$$3, *_13$$3, *_14$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	_2 = zephir_fetch_static_property_ce(smce_core_smceframework_ce, SL("controller") TSRMLS_CC);
	zephir_fast_strtolower(_1, _2);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "controller", 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "", 0);
	zephir_fast_str_replace(&_0, &_3, &_4, _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_STRING(_5, "controller", 1);
	zephir_update_property_array(this_ptr, SL("data"), _5, _0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_INIT_VAR(_6);
	_7 = zephir_fetch_static_property_ce(smce_core_smceframework_ce, SL("action") TSRMLS_CC);
	zephir_fast_strtolower(_6, _7);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_STRING(&_8, "action", 0);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_STRING(&_9, "", 0);
	zephir_fast_str_replace(&_0, &_8, &_9, _6 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_STRING(_10, "action", 1);
	zephir_update_property_array(this_ptr, SL("data"), _10, _0 TSRMLS_CC);
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_0);
	zephir_fast_strtolower(_0, name);
	if (zephir_array_isset(_11, _0)) {
		_12$$3 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_14$$3);
		zephir_fast_strtolower(_14$$3, name);
		zephir_array_fetch(&_13$$3, _12$$3, _14$$3, PH_NOISY | PH_READONLY, "smce/app.zep", 38 TSRMLS_CC);
		RETURN_CTOR(_13$$3);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 *
 * @return ip addres
 */
PHP_METHOD(Smce_App, getIP) {

	zval *ip = NULL, *tmp = NULL, _0, *_1 = NULL, _3$$3, _4$$4, *_5$$4 = NULL, _6$$5 = zval_used_for_init, *_7$$5 = NULL, *_8$$6, _9$$7;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "HTTP_CLIENT_IP", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "getenv", &_2, 6, &_0);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_STRING(&_3$$3, "HTTP_CLIENT_IP", 0);
		ZEPHIR_CALL_FUNCTION(&ip, "getenv", &_2, 6, &_3$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_SINIT_VAR(_4$$4);
		ZVAL_STRING(&_4$$4, "HTTP_X_FORWARDED_FOR", 0);
		ZEPHIR_CALL_FUNCTION(&_5$$4, "getenv", &_2, 6, &_4$$4);
		zephir_check_call_status();
		if (zephir_is_true(_5$$4)) {
			ZEPHIR_SINIT_VAR(_6$$5);
			ZVAL_STRING(&_6$$5, "HTTP_X_FORWARDED_FOR", 0);
			ZEPHIR_CALL_FUNCTION(&ip, "getenv", &_2, 6, &_6$$5);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_6$$5);
			ZVAL_STRING(&_6$$5, ",", 0);
			ZEPHIR_CALL_FUNCTION(&_7$$5, "strstr", NULL, 7, ip, &_6$$5);
			zephir_check_call_status();
			if (zephir_is_true(_7$$5)) {
				ZEPHIR_INIT_VAR(tmp);
				zephir_fast_explode_str(tmp, SL(","), ip, LONG_MAX TSRMLS_CC);
				zephir_array_fetch_long(&_8$$6, tmp, 0, PH_NOISY | PH_READONLY, "smce/app.zep", 62 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(ip);
				zephir_fast_trim(ip, _8$$6, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
			}
		} else {
			ZEPHIR_SINIT_VAR(_9$$7);
			ZVAL_STRING(&_9$$7, "REMOTE_ADDR", 0);
			ZEPHIR_CALL_FUNCTION(&ip, "getenv", &_2, 6, &_9$$7);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(ip);

}

PHP_METHOD(Smce_App, redirect) {

	zephir_fcall_cache_entry *_2 = NULL;
	int term, ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *term_param = NULL, *_0$$3 = NULL, *_1$$3, _3$$4, *_4$$4 = NULL, *_5$$4;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &term_param);

	zephir_get_strval(str, str_param);
	if (!term_param) {
		term = 0;
	} else {
		term = zephir_get_intval(term_param);
	}


	if (term == 0) {
		ZEPHIR_CALL_SELF(&_0$$3, "baseurl", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_CONCAT_SVSV(_1$$3, "Location: ", _0$$3, "/", str);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_2, 3, _1$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_SINIT_VAR(_3$$4);
		ZVAL_LONG(&_3$$4, term);
		ZEPHIR_CALL_SELF(&_4$$4, "baseurl", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_5$$4);
		ZEPHIR_CONCAT_SVSVSV(_5$$4, "refresh:", &_3$$4, ";url=", _4$$4, "/", str);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_2, 3, _5$$4);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
	zephir_exit_empty();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_App, isAjax) {

	zend_bool _0, _2;
	zval *_SERVER, *_1, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	_0 = zephir_array_isset_string(_SERVER, SS("HTTP_X_REQUESTED_WITH"));
	if (_0) {
		ZEPHIR_OBS_VAR(_1);
		zephir_array_fetch_string(&_1, _SERVER, SL("HTTP_X_REQUESTED_WITH"), PH_NOISY, "smce/app.zep", 95 TSRMLS_CC);
		_0 = !(ZEPHIR_IS_EMPTY(_1));
	}
	_2 = _0;
	if (_2) {
		ZEPHIR_INIT_VAR(_3);
		zephir_array_fetch_string(&_4, _SERVER, SL("HTTP_X_REQUESTED_WITH"), PH_NOISY | PH_READONLY, "smce/app.zep", 95 TSRMLS_CC);
		zephir_fast_strtolower(_3, _4);
		_2 = ZEPHIR_IS_STRING(_3, "xmlhttprequest");
	}
	if (_2) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_App, isPost) {

	zend_bool _0;
	zval *_SERVER, *_1;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	_0 = zephir_array_isset_string(_SERVER, SS("REQUEST_METHOD"));
	if (_0) {
		zephir_array_fetch_string(&_1, _SERVER, SL("REQUEST_METHOD"), PH_NOISY | PH_READONLY, "smce/app.zep", 106 TSRMLS_CC);
		_0 = ZEPHIR_IS_STRING_IDENTICAL(_1, "POST");
	}
	if (_0) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_App, isGet) {

	zend_bool _0;
	zval *_SERVER, *_1;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	_0 = zephir_array_isset_string(_SERVER, SS("REQUEST_METHOD"));
	if (_0) {
		zephir_array_fetch_string(&_1, _SERVER, SL("REQUEST_METHOD"), PH_NOISY | PH_READONLY, "smce/app.zep", 117 TSRMLS_CC);
		_0 = ZEPHIR_IS_STRING_IDENTICAL(_1, "GET");
	}
	if (_0) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_App, baseUrl) {

	zval *_SERVER, *_0, _1, _2, *_3;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	zephir_array_fetch_string(&_0, _SERVER, SL("SCRIPT_NAME"), PH_NOISY | PH_READONLY, "smce/app.zep", 129 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "/index.php", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "", 0);
	ZEPHIR_INIT_VAR(_3);
	zephir_fast_str_replace(&_3, &_1, &_2, _0 TSRMLS_CC);
	RETURN_CCTOR(_3);

}

static zend_object_value zephir_init_properties_Smce_App(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("data"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

