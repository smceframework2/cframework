
extern zend_class_entry *smce_components_output_ce;

ZEPHIR_INIT_CLASS(Smce_Components_Output);

PHP_METHOD(Smce_Components_Output, setContentType);
PHP_METHOD(Smce_Components_Output, setFileName);
PHP_METHOD(Smce_Components_Output, put);
PHP_METHOD(Smce_Components_Output, putFile);
PHP_METHOD(Smce_Components_Output, getHeader);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_output_setcontenttype, 0, 0, 0)
	ZEND_ARG_INFO(0, mimeType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_output_setfilename, 0, 0, 1)
	ZEND_ARG_INFO(0, fileName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_output_put, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_output_putfile, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_components_output_method_entry) {
	PHP_ME(Smce_Components_Output, setContentType, arginfo_smce_components_output_setcontenttype, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Output, setFileName, arginfo_smce_components_output_setfilename, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Output, put, arginfo_smce_components_output_put, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Output, putFile, arginfo_smce_components_output_putfile, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Output, getHeader, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
