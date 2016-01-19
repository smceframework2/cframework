
extern zend_class_entry *smce_app_ce;

ZEPHIR_INIT_CLASS(Smce_App);

PHP_METHOD(Smce_App, __construct);
PHP_METHOD(Smce_App, __get);
PHP_METHOD(Smce_App, getIP);
PHP_METHOD(Smce_App, redirect);
PHP_METHOD(Smce_App, isAjax);
PHP_METHOD(Smce_App, isPost);
PHP_METHOD(Smce_App, isGet);
PHP_METHOD(Smce_App, baseUrl);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_app___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_app_redirect, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, term)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_app_method_entry) {
	PHP_ME(Smce_App, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Smce_App, __get, arginfo_smce_app___get, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_App, getIP, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Smce_App, redirect, arginfo_smce_app_redirect, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_App, isAjax, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_App, isPost, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_App, isGet, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_App, baseUrl, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
