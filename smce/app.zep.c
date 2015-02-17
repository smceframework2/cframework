
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/array.h"

ZEPHIR_INIT_CLASS(Smce_app) {

	ZEPHIR_REGISTER_CLASS(Smce, app, smce, app, smce_app_method_entry, 0);

	zend_declare_property_null(smce_app_ce, SL("data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Smce_app, __construct) {

	HashTable *_17;
	HashPosition _16;
	zephir_nts_static zephir_fcall_cache_entry *_15 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *config = NULL, *key = NULL, *value = NULL, *_1 = NULL, *_2, *_3, *_4 = NULL, *_5, *_6, _7, _8, *_9, *_10, *_11, _12, _13, *_14, **_18;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("data"), _0 TSRMLS_CC);
	ZEPHIR_CALL_SELF(&_1, "baseurl", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "baseurl", 1);
	zephir_update_property_array(this_ptr, SL("data"), _2, _1 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getip", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "ip", 1);
	zephir_update_property_array(this_ptr, SL("data"), _3, _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_OBS_VAR(_6);
	zephir_read_static_property_ce(&_6, smce_core_smceframework_ce, SL("controller") TSRMLS_CC);
	zephir_fast_strtolower(_5, _6);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, "controller", 0);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_STRING(&_8, "", 0);
	zephir_fast_str_replace(_4, &_7, &_8, _5 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_STRING(_9, "controller", 1);
	zephir_update_property_array(this_ptr, SL("data"), _9, _4 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_OBS_VAR(_11);
	zephir_read_static_property_ce(&_11, smce_core_smceframework_ce, SL("action") TSRMLS_CC);
	zephir_fast_strtolower(_10, _11);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_STRING(&_12, "action", 0);
	ZEPHIR_SINIT_VAR(_13);
	ZVAL_STRING(&_13, "", 0);
	zephir_fast_str_replace(_4, &_12, &_13, _10 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_14);
	ZVAL_STRING(_14, "action", 1);
	zephir_update_property_array(this_ptr, SL("data"), _14, _4 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&config, smce_core_eventmanager_ce, "pull", &_15, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE(config)) {
		zephir_is_iterable(config, &_17, &_16, 0, 0, "smce/app.zep", 27);
		for (
		  ; zephir_hash_get_current_data_ex(_17, (void**) &_18, &_16) == SUCCESS
		  ; zephir_hash_move_forward_ex(_17, &_16)
		) {
			ZEPHIR_GET_HMKEY(key, _17, _16);
			ZEPHIR_GET_HVALUE(value, _18);
			zephir_update_property_array(this_ptr, SL("data"), key, value TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_app, __get) {

	zval *name, *_0, *_1, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, name);
	if (zephir_array_isset(_0, _1)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_4);
		zephir_fast_strtolower(_4, name);
		zephir_array_fetch(&_3, _2, _4, PH_NOISY | PH_READONLY, "smce/app.zep", 35 TSRMLS_CC);
		RETURN_CTOR(_3);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 *
 * @return ip addres
 */
PHP_METHOD(Smce_app, getIP) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL;
	zval *ip = NULL, *tmp, _0 = zval_used_for_init, *_1 = NULL, *_3 = NULL, *_4 = NULL, *_6;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "HTTP_CLIENT_IP", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "getenv", &_2, &_0);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "HTTP_CLIENT_IP", 0);
		ZEPHIR_CALL_FUNCTION(&ip, "getenv", &_2, &_0);
		zephir_check_call_status();
	} else {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "HTTP_X_FORWARDED_FOR", 0);
		ZEPHIR_CALL_FUNCTION(&_3, "getenv", &_2, &_0);
		zephir_check_call_status();
		if (zephir_is_true(_3)) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_STRING(&_0, "HTTP_X_FORWARDED_FOR", 0);
			ZEPHIR_CALL_FUNCTION(&ip, "getenv", &_2, &_0);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_STRING(&_0, ",", 0);
			ZEPHIR_CALL_FUNCTION(&_4, "strstr", &_5, ip, &_0);
			zephir_check_call_status();
			if (zephir_is_true(_4)) {
				ZEPHIR_INIT_VAR(tmp);
				zephir_fast_explode_str(tmp, SL(","), ip, LONG_MAX TSRMLS_CC);
				ZEPHIR_INIT_NVAR(ip);
				zephir_array_fetch_long(&_6, tmp, 0, PH_NOISY | PH_READONLY, "smce/app.zep", 59 TSRMLS_CC);
				zephir_fast_trim(ip, _6, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
			}
		} else {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_STRING(&_0, "REMOTE_ADDR", 0);
			ZEPHIR_CALL_FUNCTION(&ip, "getenv", &_2, &_0);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(ip);

}

PHP_METHOD(Smce_app, baseUrl) {

	zval *_SERVER, *_0, _1, _2;


	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_array_fetch_string(&_0, _SERVER, SL("SCRIPT_NAME"), PH_NOISY | PH_READONLY, "smce/app.zep", 74 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "/index.php", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "", 0);
	zephir_fast_str_replace(return_value, &_1, &_2, _0 TSRMLS_CC);
	return;

}

