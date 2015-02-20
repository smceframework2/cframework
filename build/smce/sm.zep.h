
extern zend_class_entry *smce_sm_ce;

ZEPHIR_INIT_CLASS(Smce_Sm);

PHP_METHOD(Smce_Sm, app);

ZEPHIR_INIT_FUNCS(smce_sm_method_entry) {
	PHP_ME(Smce_Sm, app, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
