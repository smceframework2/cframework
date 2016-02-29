
extern zend_class_entry *smce_http_response_ce;

ZEPHIR_INIT_CLASS(Smce_Http_Response);

PHP_METHOD(Smce_Http_Response, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_http_response___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, httpCode)
	ZEND_ARG_INFO(0, msg)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_http_response_method_entry) {
	PHP_ME(Smce_Http_Response, __construct, arginfo_smce_http_response___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
