
extern zend_class_entry *smce_http_httpexception_ce;

ZEPHIR_INIT_CLASS(Smce_Http_HttpException);

PHP_METHOD(Smce_Http_HttpException, __construct);
PHP_METHOD(Smce_Http_HttpException, getMsg);
PHP_METHOD(Smce_Http_HttpException, getHttpCode);
PHP_METHOD(Smce_Http_HttpException, htppError);
PHP_METHOD(Smce_Http_HttpException, http_response_code);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_http_httpexception___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, httpCode)
	ZEND_ARG_INFO(0, msg)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_http_httpexception_http_response_code, 0, 0, 0)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_http_httpexception_method_entry) {
	PHP_ME(Smce_Http_HttpException, __construct, arginfo_smce_http_httpexception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Smce_Http_HttpException, getMsg, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Http_HttpException, getHttpCode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Http_HttpException, htppError, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Http_HttpException, http_response_code, arginfo_smce_http_httpexception_http_response_code, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
