
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"

ZEPHIR_INIT_CLASS(Smce_Driver_Redis) {

	ZEPHIR_REGISTER_CLASS(Smce\\Driver, Redis, smce, driver_redis, smce_driver_redis_method_entry, 0);

	/**
	 * @var array redis config
	 */
	zend_declare_property_null(smce_driver_redis_ce, SL("config"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var redis instance
	 */
	zend_declare_property_null(smce_driver_redis_ce, SL("redis"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/*
 * @return redis connect
 */
PHP_METHOD(Smce_Driver_Redis, getRedis) {


	RETURN_MEMBER(this_ptr, "redis");

}

/*
 * @return void
 */
PHP_METHOD(Smce_Driver_Redis, setConfig) {

	zval *config;

	zephir_fetch_params(0, 1, 0, &config);



	zephir_update_property_this(this_ptr, SL("config"), config TSRMLS_CC);

}

/*
 * @return array
 */
PHP_METHOD(Smce_Driver_Redis, getConfig) {


	RETURN_MEMBER(this_ptr, "config");

}

/**
 * @return void
 */
PHP_METHOD(Smce_Driver_Redis, connect) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _2;
	zval *_0, *_1, *_3, *_4, *_5, *_6, *_7 = NULL, *_8, *_9, *_10, *_11, *_12, *_13, *_14, *_15, *_16, *_17;

	ZEPHIR_MM_GROW();

	if (!(zephir_isset_property(this_ptr, SS("config") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "redis server configuration must have \"host\" and \"port\" values in array.", "smce/driver/redis.zep", 58);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_array_fetch_string(&_1, _0, SL("host"), PH_NOISY, "smce/driver/redis.zep", 61 TSRMLS_CC);
	_2 = ZEPHIR_IS_EMPTY(_1);
	if (_2) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_4);
		zephir_array_fetch_string(&_4, _3, SL("port"), PH_NOISY, "smce/driver/redis.zep", 61 TSRMLS_CC);
		_2 = !ZEPHIR_IS_EMPTY(_4);
	}
	if (_2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "redis server configuration must have \"host\" and \"port\" not empty", "smce/driver/redis.zep", 64);
		return;
	}
	ZEPHIR_INIT_VAR(_5);
	object_init_ex(_5, zephir_get_internal_ce(SS("redis") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("redis"), _5 TSRMLS_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_9, _8, SL("host"), PH_NOISY | PH_READONLY, "smce/driver/redis.zep", 70 TSRMLS_CC);
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_11, _10, SL("port"), PH_NOISY | PH_READONLY, "smce/driver/redis.zep", 70 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_7, _6, "connect", NULL, _9, _11);
	zephir_check_call_status();
	if (!zephir_is_true(_7)) {
		ZEPHIR_INIT_VAR(_12);
		object_init_ex(_12, zend_exception_get_default(TSRMLS_C));
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_14, _13, SL("host"), PH_NOISY | PH_READONLY, "smce/driver/redis.zep", 73 TSRMLS_CC);
		_15 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_16, _15, SL("port"), PH_NOISY | PH_READONLY, "smce/driver/redis.zep", 73 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_17);
		ZEPHIR_CONCAT_SVSV(_17, "Failed on connecting to redis server at ", _14, ":", _16);
		ZEPHIR_CALL_METHOD(NULL, _12, "__construct", NULL, _17);
		zephir_check_call_status();
		zephir_throw_exception_debug(_12, "smce/driver/redis.zep", 73 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string
 *
 * @return mixed
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
 * @param string
 * @param mixed
 * @param int
 *
 * @return set
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
 * @param string
 * @param mixed
 * @param int
 *
 * @return delete
 */
PHP_METHOD(Smce_Driver_Redis, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "delete", NULL, key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string
 * @param mixed
 *
 * @return lpush
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
 * @param string
 * @param long
 * @param long
 *
 * @return lrange
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

/**
 * @param string
 * @param string
 *
 * @return hdel
 */
PHP_METHOD(Smce_Driver_Redis, hdel) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *key2_param = NULL, *_0;
	zval *key = NULL, *key2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &key2_param);

	zephir_get_strval(key, key_param);
	zephir_get_strval(key2, key2_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "hdel", NULL, key, key2);
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

