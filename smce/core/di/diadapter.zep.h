
extern zend_class_entry *smce_core_di_diadapter_ce;

ZEPHIR_INIT_CLASS(Smce_Core_Di_DiAdapter);

PHP_METHOD(Smce_Core_Di_DiAdapter, set);
PHP_METHOD(Smce_Core_Di_DiAdapter, get);
PHP_METHOD(Smce_Core_Di_DiAdapter, setAdapter);
PHP_METHOD(Smce_Core_Di_DiAdapter, isAdapter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_di_diadapter_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, duration)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_di_diadapter_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_di_diadapter_setadapter, 0, 0, 1)
	ZEND_ARG_INFO(0, adapter)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_core_di_diadapter_method_entry) {
	PHP_ME(Smce_Core_Di_DiAdapter, set, arginfo_smce_core_di_diadapter_set, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Di_DiAdapter, get, arginfo_smce_core_di_diadapter_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Di_DiAdapter, setAdapter, arginfo_smce_core_di_diadapter_setadapter, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Di_DiAdapter, isAdapter, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
