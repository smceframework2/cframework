
extern zend_class_entry *smce_app_ce;

ZEPHIR_INIT_CLASS(Smce_app);

PHP_METHOD(Smce_app, __construct);
PHP_METHOD(Smce_app, __get);
PHP_METHOD(Smce_app, getIP);
PHP_METHOD(Smce_app, baseUrl);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_app___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_app_method_entry) {
	PHP_ME(Smce_app, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Smce_app, __get, arginfo_smce_app___get, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_app, getIP, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Smce_app, baseUrl, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
