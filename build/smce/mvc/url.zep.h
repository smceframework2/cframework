
extern zend_class_entry *smce_mvc_url_ce;

ZEPHIR_INIT_CLASS(Smce_Mvc_Url);

PHP_METHOD(Smce_Mvc_Url, setBaseUrl);
PHP_METHOD(Smce_Mvc_Url, getBaseUrl);
PHP_METHOD(Smce_Mvc_Url, get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_mvc_url_setbaseurl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_mvc_url_get, 0, 0, 1)
	ZEND_ARG_INFO(0, paramerter)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_mvc_url_method_entry) {
	PHP_ME(Smce_Mvc_Url, setBaseUrl, arginfo_smce_mvc_url_setbaseurl, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Mvc_Url, getBaseUrl, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Mvc_Url, get, arginfo_smce_mvc_url_get, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
