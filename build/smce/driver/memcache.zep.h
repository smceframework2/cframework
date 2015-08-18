
extern zend_class_entry *smce_driver_memcache_ce;

ZEPHIR_INIT_CLASS(Smce_Driver_Memcache);

PHP_METHOD(Smce_Driver_Memcache, getMemcache);
PHP_METHOD(Smce_Driver_Memcache, setConfig);
PHP_METHOD(Smce_Driver_Memcache, getConfig);
PHP_METHOD(Smce_Driver_Memcache, connect);
PHP_METHOD(Smce_Driver_Memcache, get);
PHP_METHOD(Smce_Driver_Memcache, set);
PHP_METHOD(Smce_Driver_Memcache, add);
PHP_METHOD(Smce_Driver_Memcache, addServer);
PHP_METHOD(Smce_Driver_Memcache, close);
PHP_METHOD(Smce_Driver_Memcache, decrement);
PHP_METHOD(Smce_Driver_Memcache, delete);
PHP_METHOD(Smce_Driver_Memcache, flush);
PHP_METHOD(Smce_Driver_Memcache, getExtendedStats);
PHP_METHOD(Smce_Driver_Memcache, getServerStatus);
PHP_METHOD(Smce_Driver_Memcache, getStats);
PHP_METHOD(Smce_Driver_Memcache, getVersion);
PHP_METHOD(Smce_Driver_Memcache, increment);
PHP_METHOD(Smce_Driver_Memcache, pconnect);
PHP_METHOD(Smce_Driver_Memcache, replace);
PHP_METHOD(Smce_Driver_Memcache, setCompressThreshold);
PHP_METHOD(Smce_Driver_Memcache, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_driver_memcache_setconfig, 0, 0, 1)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_driver_memcache_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_driver_memcache_set, 0, 0, 4)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, bolen)
	ZEND_ARG_INFO(0, duration)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_driver_memcache_add, 0, 0, 3)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, bolen)
	ZEND_ARG_INFO(0, duration)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_driver_memcache_addserver, 0, 0, 2)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_driver_memcache_decrement, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, item)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_driver_memcache_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_driver_memcache_getserverstatus, 0, 0, 2)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_driver_memcache_increment, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, item)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_driver_memcache_pconnect, 0, 0, 2)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_driver_memcache_replace, 0, 0, 4)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, bol)
	ZEND_ARG_INFO(0, duration)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_driver_memcache_setcompressthreshold, 0, 0, 2)
	ZEND_ARG_INFO(0, i)
	ZEND_ARG_INFO(0, d)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_driver_memcache_method_entry) {
	PHP_ME(Smce_Driver_Memcache, getMemcache, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Memcache, setConfig, arginfo_smce_driver_memcache_setconfig, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Memcache, getConfig, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Memcache, connect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Memcache, get, arginfo_smce_driver_memcache_get, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Memcache, set, arginfo_smce_driver_memcache_set, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Memcache, add, arginfo_smce_driver_memcache_add, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Memcache, addServer, arginfo_smce_driver_memcache_addserver, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Memcache, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Memcache, decrement, arginfo_smce_driver_memcache_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Memcache, delete, arginfo_smce_driver_memcache_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Memcache, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Memcache, getExtendedStats, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Memcache, getServerStatus, arginfo_smce_driver_memcache_getserverstatus, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Memcache, getStats, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Memcache, getVersion, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Memcache, increment, arginfo_smce_driver_memcache_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Memcache, pconnect, arginfo_smce_driver_memcache_pconnect, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Memcache, replace, arginfo_smce_driver_memcache_replace, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Memcache, setCompressThreshold, arginfo_smce_driver_memcache_setcompressthreshold, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Driver_Memcache, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
