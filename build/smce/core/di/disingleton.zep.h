
extern zend_class_entry *smce_core_di_disingleton_ce;

ZEPHIR_INIT_CLASS(Smce_Core_Di_DiSingleton);

PHP_METHOD(Smce_Core_Di_DiSingleton, __construct);
PHP_METHOD(Smce_Core_Di_DiSingleton, resolveWhen);
PHP_METHOD(Smce_Core_Di_DiSingleton, getSingleton);
PHP_METHOD(Smce_Core_Di_DiSingleton, getKeys);
PHP_METHOD(Smce_Core_Di_DiSingleton, getAll);
PHP_METHOD(Smce_Core_Di_DiSingleton, getCount);
PHP_METHOD(Smce_Core_Di_DiSingleton, controllerConstructorParamerters);
PHP_METHOD(Smce_Core_Di_DiSingleton, controllerMethodParamerters);
PHP_METHOD(Smce_Core_Di_DiSingleton, make);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_di_disingleton___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, class)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_di_disingleton_resolvewhen, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_di_disingleton_getsingleton, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_di_disingleton_controllerconstructorparamerters, 0, 0, 1)
	ZEND_ARG_INFO(0, controller)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_di_disingleton_controllermethodparamerters, 0, 0, 2)
	ZEND_ARG_INFO(0, controller)
	ZEND_ARG_INFO(0, action)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_di_disingleton_make, 0, 0, 2)
	ZEND_ARG_INFO(0, controller)
	ZEND_ARG_INFO(0, action)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_core_di_disingleton_method_entry) {
	PHP_ME(Smce_Core_Di_DiSingleton, __construct, arginfo_smce_core_di_disingleton___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Smce_Core_Di_DiSingleton, resolveWhen, arginfo_smce_core_di_disingleton_resolvewhen, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_Di_DiSingleton, getSingleton, arginfo_smce_core_di_disingleton_getsingleton, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Di_DiSingleton, getKeys, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Di_DiSingleton, getAll, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Di_DiSingleton, getCount, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Di_DiSingleton, controllerConstructorParamerters, arginfo_smce_core_di_disingleton_controllerconstructorparamerters, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Di_DiSingleton, controllerMethodParamerters, arginfo_smce_core_di_disingleton_controllermethodparamerters, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Di_DiSingleton, make, arginfo_smce_core_di_disingleton_make, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
