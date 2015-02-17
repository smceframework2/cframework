
extern zend_class_entry *smce_core_di_ce;

ZEPHIR_INIT_CLASS(Smce_Core_Di);

PHP_METHOD(Smce_Core_Di, __construct);
PHP_METHOD(Smce_Core_Di, bind);
PHP_METHOD(Smce_Core_Di, resolve);
PHP_METHOD(Smce_Core_Di, singleton);
PHP_METHOD(Smce_Core_Di, remove);
PHP_METHOD(Smce_Core_Di, has);
PHP_METHOD(Smce_Core_Di, reset);
PHP_METHOD(Smce_Core_Di, getKeys);
PHP_METHOD(Smce_Core_Di, getAll);
PHP_METHOD(Smce_Core_Di, getCount);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_di___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, adapter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_di_bind, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_OBJ_INFO(0, class, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_di_resolve, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_di_singleton, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_OBJ_INFO(0, class, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_di_remove, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_di_has, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_core_di_method_entry) {
	PHP_ME(Smce_Core_Di, __construct, arginfo_smce_core_di___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Smce_Core_Di, bind, arginfo_smce_core_di_bind, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_Di, resolve, arginfo_smce_core_di_resolve, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Di, singleton, arginfo_smce_core_di_singleton, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_Di, remove, arginfo_smce_core_di_remove, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Di, has, arginfo_smce_core_di_has, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Di, reset, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Di, getKeys, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Di, getAll, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Di, getCount, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
