
extern zend_class_entry *smce_driver_redis_ce;

ZEPHIR_INIT_CLASS(Smce_Driver_Redis);

PHP_METHOD(Smce_Driver_Redis, getRedis);
PHP_METHOD(Smce_Driver_Redis, setConfig);
PHP_METHOD(Smce_Driver_Redis, getConfig);
PHP_METHOD(Smce_Driver_Redis, connect);
PHP_METHOD(Smce_Driver_Redis, get);
PHP_METHOD(Smce_Driver_Redis, set);
PHP_METHOD(Smce_Driver_Redis, lpush);
PHP_METHOD(Smce_Driver_Redis, lrange);
PHP_METHOD(Smce_Driver_Redis, hdel);
PHP_METHOD(Smce_Driver_Redis, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_driver_redis_setconfig, 0, 0, 1)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_driver_redis_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_driver_redis_set, 0, 0, 3)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, duration)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_driver_redis_lpush, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_driver_redis_lrange, 0, 0, 3)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_driver_redis_hdel, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, key2)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_driver_redis_method_entry) {
	PHP_ME(Smce_Driver_Redis, getRedis, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Redis, setConfig, arginfo_smce_driver_redis_setconfig, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Redis, getConfig, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Redis, connect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Redis, get, arginfo_smce_driver_redis_get, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Redis, set, arginfo_smce_driver_redis_set, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Redis, lpush, arginfo_smce_driver_redis_lpush, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Redis, lrange, arginfo_smce_driver_redis_lrange, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Redis, hdel, arginfo_smce_driver_redis_hdel, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Redis, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
