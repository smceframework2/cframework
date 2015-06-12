
extern zend_class_entry *smce_mvc_template_ce;

ZEPHIR_INIT_CLASS(Smce_Mvc_Template);

PHP_METHOD(Smce_Mvc_Template, setLayout);
PHP_METHOD(Smce_Mvc_Template, setLayoutDirectory);
PHP_METHOD(Smce_Mvc_Template, getLayout);
PHP_METHOD(Smce_Mvc_Template, getLayoutDirectory);
PHP_METHOD(Smce_Mvc_Template, setView);
PHP_METHOD(Smce_Mvc_Template, setViewDirectory);
PHP_METHOD(Smce_Mvc_Template, getView);
PHP_METHOD(Smce_Mvc_Template, getViewDirectory);
PHP_METHOD(Smce_Mvc_Template, run);
PHP_METHOD(Smce_Mvc_Template, adjustmentLayout);
PHP_METHOD(Smce_Mvc_Template, adjustmentView);
PHP_METHOD(Smce_Mvc_Template, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_mvc_template_setlayout, 0, 0, 0)
	ZEND_ARG_INFO(0, layout)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_mvc_template_setlayoutdirectory, 0, 0, 0)
	ZEND_ARG_INFO(0, layoutDirectory)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_mvc_template_setview, 0, 0, 0)
	ZEND_ARG_INFO(0, view)
	ZEND_ARG_INFO(0, arr)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_mvc_template_setviewdirectory, 0, 0, 0)
	ZEND_ARG_INFO(0, viewDirectory)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_mvc_template_adjustmentlayout, 0, 0, 1)
	ZEND_ARG_INFO(0, layoutFile)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_mvc_template_adjustmentview, 0, 0, 1)
	ZEND_ARG_INFO(0, viewFile)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_mvc_template_method_entry) {
	PHP_ME(Smce_Mvc_Template, setLayout, arginfo_smce_mvc_template_setlayout, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Mvc_Template, setLayoutDirectory, arginfo_smce_mvc_template_setlayoutdirectory, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Mvc_Template, getLayout, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Mvc_Template, getLayoutDirectory, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Mvc_Template, setView, arginfo_smce_mvc_template_setview, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Mvc_Template, setViewDirectory, arginfo_smce_mvc_template_setviewdirectory, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Mvc_Template, getView, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Mvc_Template, getViewDirectory, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Mvc_Template, run, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Mvc_Template, adjustmentLayout, arginfo_smce_mvc_template_adjustmentlayout, ZEND_ACC_PRIVATE)
	PHP_ME(Smce_Mvc_Template, adjustmentView, arginfo_smce_mvc_template_adjustmentview, ZEND_ACC_PRIVATE)
	PHP_ME(Smce_Mvc_Template, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
