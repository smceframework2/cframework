
extern zend_class_entry *smce_core_di_singleton_ce;

ZEPHIR_INIT_CLASS(Smce_Core_Di_Singleton);

PHP_METHOD(Smce_Core_Di_Singleton, __construct);
PHP_METHOD(Smce_Core_Di_Singleton, resolveWhen);
PHP_METHOD(Smce_Core_Di_Singleton, getSingleton);
PHP_METHOD(Smce_Core_Di_Singleton, getKeys);
PHP_METHOD(Smce_Core_Di_Singleton, getAll);
PHP_METHOD(Smce_Core_Di_Singleton, getCount);
PHP_METHOD(Smce_Core_Di_Singleton, controllerConstructorParamerters);
PHP_METHOD(Smce_Core_Di_Singleton, controllerMethodParamerters);
PHP_METHOD(Smce_Core_Di_Singleton, make);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_di_singleton___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, class)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_di_singleton_resolvewhen, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_di_singleton_getsingleton, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_di_singleton_controllerconstructorparamerters, 0, 0, 1)
	ZEND_ARG_INFO(0, controller)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_di_singleton_controllermethodparamerters, 0, 0, 2)
	ZEND_ARG_INFO(0, controller)
	ZEND_ARG_INFO(0, action)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_di_singleton_make, 0, 0, 2)
	ZEND_ARG_INFO(0, controller)
	ZEND_ARG_INFO(0, action)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_core_di_singleton_method_entry) {
	PHP_ME(Smce_Core_Di_Singleton, __construct, arginfo_smce_core_di_singleton___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Smce_Core_Di_Singleton, resolveWhen, arginfo_smce_core_di_singleton_resolvewhen, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_Di_Singleton, getSingleton, arginfo_smce_core_di_singleton_getsingleton, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Di_Singleton, getKeys, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Di_Singleton, getAll, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Di_Singleton, getCount, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Di_Singleton, controllerConstructorParamerters, arginfo_smce_core_di_singleton_controllerconstructorparamerters, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Di_Singleton, controllerMethodParamerters, arginfo_smce_core_di_singleton_controllermethodparamerters, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Di_Singleton, make, arginfo_smce_core_di_singleton_make, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
