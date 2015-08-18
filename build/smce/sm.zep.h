
extern zend_class_entry *smce_sm_ce;

ZEPHIR_INIT_CLASS(Smce_Sm);

PHP_METHOD(Smce_Sm, app);
PHP_METHOD(Smce_Sm, theme);
PHP_METHOD(Smce_Sm, t);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_sm_t, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_ARRAY_INFO(0, arr, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_sm_method_entry) {
	PHP_ME(Smce_Sm, app, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Sm, theme, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Sm, t, arginfo_smce_sm_t, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
