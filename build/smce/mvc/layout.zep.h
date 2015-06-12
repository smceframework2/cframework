
extern zend_class_entry *smce_mvc_layout_ce;

ZEPHIR_INIT_CLASS(Smce_Mvc_Layout);

PHP_METHOD(Smce_Mvc_Layout, setContentDirectory);
PHP_METHOD(Smce_Mvc_Layout, getContentDirectory);
PHP_METHOD(Smce_Mvc_Layout, setContent);
PHP_METHOD(Smce_Mvc_Layout, run);
PHP_METHOD(Smce_Mvc_Layout, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_mvc_layout_setcontentdirectory, 0, 0, 0)
	ZEND_ARG_INFO(0, contentDirectory)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_mvc_layout_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, view)
	ZEND_ARG_INFO(0, arr)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_mvc_layout_method_entry) {
	PHP_ME(Smce_Mvc_Layout, setContentDirectory, arginfo_smce_mvc_layout_setcontentdirectory, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Mvc_Layout, getContentDirectory, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Mvc_Layout, setContent, arginfo_smce_mvc_layout_setcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Mvc_Layout, run, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Mvc_Layout, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
