
extern zend_class_entry *smce_core_smceframework_ce;

ZEPHIR_INIT_CLASS(Smce_Core_SmceFramework);

PHP_METHOD(Smce_Core_SmceFramework, make);
PHP_METHOD(Smce_Core_SmceFramework, router);
PHP_METHOD(Smce_Core_SmceFramework, command);
PHP_METHOD(Smce_Core_SmceFramework, isController);
PHP_METHOD(Smce_Core_SmceFramework, controllerAction);
PHP_METHOD(Smce_Core_SmceFramework, runAction);

ZEPHIR_INIT_FUNCS(smce_core_smceframework_method_entry) {
	PHP_ME(Smce_Core_SmceFramework, make, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_SmceFramework, router, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Smce_Core_SmceFramework, command, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Smce_Core_SmceFramework, isController, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Smce_Core_SmceFramework, controllerAction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_SmceFramework, runAction, NULL, ZEND_ACC_PRIVATE)
  PHP_FE_END
};
