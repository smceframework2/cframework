
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
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"

ZEPHIR_INIT_CLASS(Smce_Driver_Redis) {

	ZEPHIR_REGISTER_CLASS(Smce\\Driver, Redis, smce, driver_redis, smce_driver_redis_method_entry, 0);

	/**
	 * @var array redis config
	 */
	zend_declare_property_null(smce_driver_redis_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var redis instance
	 */
	zend_declare_property_null(smce_driver_redis_ce, SL("redis"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/*
 * @return redis connect
 */
PHP_METHOD(Smce_Driver_Redis, getRedis) {


	RETURN_MEMBER(this_ptr, "redis");

}

/*
 * @return redis setconfig
 */
PHP_METHOD(Smce_Driver_Redis, setConfig) {

	zval *config;

	zephir_fetch_params(0, 1, 0, &config);



	zephir_update_property_this(this_ptr, SL("config"), config TSRMLS_CC);
	RETURN_MEMBER(this_ptr, "config");

}

/*
 * @return redis getconfig
 */
PHP_METHOD(Smce_Driver_Redis, getConfig) {

	zval *config;

	zephir_fetch_params(0, 1, 0, &config);



	RETURN_MEMBER(this_ptr, "config");

}

/**
 * @return array redis server instance
 */
PHP_METHOD(Smce_Driver_Redis, connect) {

	zend_bool _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zend_class_entry *_1 = NULL, *_8 = NULL, *_15 = NULL;
	zval *_0 = NULL, *_2 = NULL, *_3, *_4, *_6, *_7, *_9, *_10 = NULL, *_11, *_12, *_13, *_14, *_16, *_17, *_18, *_19, *_20;

	ZEPHIR_MM_GROW();

	if (!(zephir_isset_property(this_ptr, SS("config") TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_0);
		if (!_1) {
			_1 = zend_fetch_class(SL("Smce\\Driver\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		}
		object_init_ex(_0, _1);
		if (zephir_has_constructor(_0 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_2);
			ZVAL_STRING(_2, "redis server configuration must have \"host\" and \"port\" values in array.", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(_0, "smce/driver/redis.zep", 58 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_4);
	zephir_array_fetch_string(&_4, _3, SL("host"), PH_NOISY, "smce/driver/redis.zep", 61 TSRMLS_CC);
	_5 = ZEPHIR_IS_EMPTY(_4);
	if (_5) {
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_7);
		zephir_array_fetch_string(&_7, _6, SL("port"), PH_NOISY, "smce/driver/redis.zep", 61 TSRMLS_CC);
		_5 = !ZEPHIR_IS_EMPTY(_7);
	}
	if (_5) {
		ZEPHIR_INIT_NVAR(_0);
		if (!_8) {
			_8 = zend_fetch_class(SL("Smce\\Driver\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		}
		object_init_ex(_0, _8);
		if (zephir_has_constructor(_0 TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "redis server configuration must have \"host\" and \"port\" not empty", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(_0, "smce/driver/redis.zep", 64 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(_0);
	object_init_ex(_0, zephir_get_internal_ce(SS("redis") TSRMLS_CC));
	if (zephir_has_constructor(_0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("redis"), _0 TSRMLS_CC);
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_12, _11, SL("host"), PH_NOISY | PH_READONLY, "smce/driver/redis.zep", 70 TSRMLS_CC);
	_13 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_14, _13, SL("port"), PH_NOISY | PH_READONLY, "smce/driver/redis.zep", 70 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_10, _9, "connect", NULL, _12, _14);
	zephir_check_call_status();
	if (zephir_is_true(_10)) {
		ZEPHIR_INIT_NVAR(_2);
		if (!_15) {
			_15 = zend_fetch_class(SL("Smce\\Driver\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		}
		object_init_ex(_2, _15);
		if (zephir_has_constructor(_2 TSRMLS_CC)) {
			_16 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
			zephir_array_fetch_string(&_17, _16, SL("host"), PH_NOISY | PH_READONLY, "smce/driver/redis.zep", 73 TSRMLS_CC);
			_18 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
			zephir_array_fetch_string(&_19, _18, SL("port"), PH_NOISY | PH_READONLY, "smce/driver/redis.zep", 73 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_20);
			ZEPHIR_CONCAT_SVSV(_20, "Failed on connecting to redis server at ", _17, ":", _19);
			ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, _20);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(_2, "smce/driver/redis.zep", 73 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @param $key
 *
 * @return $get
 */
PHP_METHOD(Smce_Driver_Redis, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param $key
 * @param $value
 * @param $duration
 *
 * @return $set
 */
PHP_METHOD(Smce_Driver_Redis, set) {

	int duration, ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value_param = NULL, *duration_param = NULL, *_0, *_1;
	zval *key = NULL, *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &key_param, &value_param, &duration_param);

	zephir_get_strval(key, key_param);
	zephir_get_strval(value, value_param);
	duration = zephir_get_intval(duration_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, duration);
	ZEPHIR_RETURN_CALL_METHOD(_0, "set", NULL, key, value, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param $key
 * @param $value
 * @param $duration
 *
 * @return $set
 */
PHP_METHOD(Smce_Driver_Redis, lpush) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value_param = NULL, *_0;
	zval *key = NULL, *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value_param);

	zephir_get_strval(key, key_param);
	zephir_get_strval(value, value_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "lpush", NULL, key, value);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param $key
 * @param $x
 * @param $y
 *
 * @return $set
 */
PHP_METHOD(Smce_Driver_Redis, lrange) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *x, *y, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &key_param, &x, &y);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "lrange", NULL, key, x, y);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Driver_Redis, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("config"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

