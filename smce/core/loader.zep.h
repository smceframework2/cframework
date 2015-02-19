
extern zend_class_entry *smce_core_loader_ce;

ZEPHIR_INIT_CLASS(Smce_Core_Loader);

PHP_METHOD(Smce_Core_Loader, setDir);
PHP_METHOD(Smce_Core_Loader, register);
PHP_METHOD(Smce_Core_Loader, autoLoad);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_loader_setdir, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, dir, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_loader_autoload, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_core_loader_method_entry) {
	PHP_ME(Smce_Core_Loader, setDir, arginfo_smce_core_loader_setdir, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_Loader, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_Loader, autoLoad, arginfo_smce_core_loader_autoload, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
