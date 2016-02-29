
extern zend_class_entry *smce_core_di_dicache_ce;

ZEPHIR_INIT_CLASS(Smce_Core_Di_DiCache);

PHP_METHOD(Smce_Core_Di_DiCache, __construct);
PHP_METHOD(Smce_Core_Di_DiCache, cache);
PHP_METHOD(Smce_Core_Di_DiCache, get);
PHP_METHOD(Smce_Core_Di_DiCache, remove);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_di_dicache___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, singletonKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_di_dicache_cache, 0, 0, 0)
	ZEND_ARG_INFO(0, duration)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_core_di_dicache_method_entry) {
	PHP_ME(Smce_Core_Di_DiCache, __construct, arginfo_smce_core_di_dicache___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Smce_Core_Di_DiCache, cache, arginfo_smce_core_di_dicache_cache, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_Di_DiCache, get, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_Di_DiCache, remove, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
