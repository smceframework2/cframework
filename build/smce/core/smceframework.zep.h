
extern zend_class_entry *smce_core_smceframework_ce;

ZEPHIR_INIT_CLASS(Smce_Core_Smceframework);

PHP_METHOD(Smce_Core_Smceframework, make);
PHP_METHOD(Smce_Core_Smceframework, router);
PHP_METHOD(Smce_Core_Smceframework, command);
PHP_METHOD(Smce_Core_Smceframework, isController);
PHP_METHOD(Smce_Core_Smceframework, controllerAction);
PHP_METHOD(Smce_Core_Smceframework, runAction);

ZEPHIR_INIT_FUNCS(smce_core_smceframework_method_entry) {
	PHP_ME(Smce_Core_Smceframework, make, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_Smceframework, router, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Smce_Core_Smceframework, command, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Smce_Core_Smceframework, isController, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Smce_Core_Smceframework, controllerAction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_Smceframework, runAction, NULL, ZEND_ACC_PRIVATE)
  PHP_FE_END
};
